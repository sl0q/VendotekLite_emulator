#include "messageClass.h"

MessageIR::MessageIR()
{
}

MessageIR::MessageIR(std::string encodedStringMessage)
{
    this->origMsg = bs64::base64_decode(encodedStringMessage);

    // check header
    if (this->origMsg[0] != 'I' || this->origMsg[1] != 'R')
    {
        std::string errorMessage("Message has unexpected header.");
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNEXPECTED_HEADER, errorMessage));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
        throw ex::InvalidMessageIR(errorMessage);
    }

    // get length
    this->length = (this->origMsg[2] << 8) | this->origMsg[3];
    // get message ID
    this->msgID = this->origMsg[4];
    // get module ID
    this->moduleID = this->origMsg[5];
    // get message type
    this->messageType = this->origMsg[6];
    // get payload
    this->payload.insert(this->payload.begin(), this->origMsg.begin() + 7, this->origMsg.end() - 2);
    // get checksum
    this->checksum = (*(this->origMsg.end() - 2) << 8) | *(this->origMsg.end() - 1);

    if (!verify_checksum())
    {
        std::string errorMessage("Message has invalid checksum.");
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::CHECKSUM_MISMATCH, errorMessage));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
        throw ex::InvalidMessageIR(errorMessage);
    }

    switch (this->messageType)
    {
    case 1: // command
        if (!parse_payload())
        {
            std::string errorMessage("Failed to parse message payload\nMSG_ID: " + std::to_string(this->msgID));
            Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::PAYLOAD_PARSING_ERROR, errorMessage));
            std::cout << "Generated responce:" << std::endl;
            generatedResponce.print_MSG();
            throw ex::InvalidMessageIR(errorMessage);
        }
        break;
    case 2: // success
        break;
    case 6: // control
        break;
    default:
        std::cout << "Message type " << this->messageType << " not found\n";
    }
}

MessageIR::~MessageIR()
{
    for (auto &action : this->actions)
        if (action)
            delete action;
    this->actions.clear();

    if (this->msg)
        delete this->msg;
}

bool MessageIR::is_command()
{
    return this->messageType == 1;
}

bool MessageIR::is_control()
{
    return this->messageType == 6;
}

google::protobuf::Message *MessageIR::find_protobuf_module()
{
    switch (this->moduleID)
    {
    case 1: // Miscellaneous
        return new Miscellaneous();
    case 2:
        // про ContactLevel2 в документации ничего нет
        return new ContactLevel1();
    case 3:
        return new ContactlessLevel1();
    case 4:
        return new ContactlessLevel2();
    case 5:
        return new Mifare();

        // case 6:
        //     return new PinPad();

        // case 7:
        //     return new Service();

        // case 8:
        //     return new StmCard();

        // case 9:
        //     return new NtagCard();

        // case 0x0a:
        //     return new Gui();

        // case 0x0b:
        //     return new Touchscreen();

        // case 0x0c:
        //     return new Complex();

        // case 0x0d:
        //     return new QrCode();

        // case 0x0e:
        //     return new Cipurse();

        // case 0x10:
        //     return new Turnstile();

        // case 0x11:
        //     return new MifareExtended();

        // case 0x12:
        //     return new Troika();

    default:
        std::cout << "Module " << this->moduleID << " not found.\n";
        return NULL;
    }
}

bool MessageIR::verify_checksum()
{
    std::vector<uint8_t> buf;
    buf.insert(buf.begin(), this->origMsg.begin(), this->origMsg.end() - 2);

    // вычисляем КС и сравниваем с полученной ранее
    if (checksum != crc::calcCrc16(buf))
    {
        std::cout << "Message integrity is compromised\n";
        return false;
    }

    std::cout << "Checksum is valid\n";
    return true;
}

bool MessageIR::parse_payload()
{
    this->msg = this->find_protobuf_module();
    if (this->msg)
    {
        if (!this->msg->ParseFromArray(this->payload.data(), this->payload.size()))
            return false;
        this->moduleNameStr = this->msg->GetTypeName();

        std::cout << "\nDebug protobuf message:\n";
        std::cout << "Module: " << this->moduleNameStr << std::endl;
        this->msg->PrintDebugString();
    }
    else
        return false;

    return true;
}

bool MessageIR::execute_message(Device &myDevice)
{
    bool res;

    switch (this->moduleID)
    {
    case 1:
        res = execute_misc(myDevice);
        break;
    case 2:
    {
        res = execute_contact();
    }
    case 3:
        res = execute_contactless_1(myDevice);
        break;
    case 4:
        res = execute_contactless_2(myDevice);
        break;
    case 5:
        res = execute_mifare(myDevice);
        break;
    default:
        res = false;
        std::ostringstream errorMessage;
        errorMessage << "Failed to execute command message. Unrecognised [moduleID]."
                     << "\nModuleID: " << std::to_string(this->moduleID)
                     << "\nMSG_ID: " << std::to_string(this->msgID);
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage.str()));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
        throw ex::FailedExecution(errorMessage.str());
    }
    return res;
}

void MessageIR::add_action(Action &newAction)
{
    this->actions.push_back(&newAction);
}

const std::string MessageIR::str() const
{
    return "executed message information here";
}

bool MessageIR::execute_misc(Device &myDevice)
{
    bool res;
    Miscellaneous miscMessage = *(dynamic_cast<Miscellaneous *>(this->msg));
    switch (miscMessage.misc_cmd_case())
    {
    case Miscellaneous::kSetLedsState:
        res = execute_leds(miscMessage, myDevice);
        break;
    case Miscellaneous::kReadDeviceInfo:
        res = execute_read_device_info(miscMessage, myDevice);
        break;

    case Miscellaneous::kRebootDevice:
        res = execute_reboot_device(miscMessage, myDevice);
        break;

    case Miscellaneous::kGetDeviceStatus:
        // no info in docs, go see device.proto
        res = execute_get_device_status(miscMessage, myDevice);
        break;

    case Miscellaneous::kMakeSound:
        res = execute_make_sound(miscMessage, myDevice);
        break;

    case Miscellaneous::kGetDeviceStatistic:
        res = execute_get_device_statistic(miscMessage, myDevice);
        break;

    case Miscellaneous::kGetEcho:
        res = execute_get_echo(miscMessage, myDevice);
        break;

    case Miscellaneous::kChangeBaudrate:
        res = execute_change_baudrate(miscMessage, myDevice);
        break;

    case Miscellaneous::kChangeLanSettings:
        res = execute_change_lan_settings(miscMessage, myDevice);
        break;

    default:
        res = false;
        std::string errorMessage("Unrecognised [command]. [Miscellaneous] module. MSG_ID: " + std::to_string(this->msgID) +
                                 ". misc_cmd_case: " + std::to_string(miscMessage.misc_cmd_case()));
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
    }
    return res;
}

bool MessageIR::execute_leds(Miscellaneous &miscMessage, Device &myDevice)
{
    const misc::leds::Leds &ledsState = myDevice.get_leds_state();
    std::cout << "Executing [set_leds_state]...\n\n"
              << "Original leds state:\n"
              << "blue: " << ledsState.has_blue() << std::endl
              << "red: " << ledsState.has_red() << std::endl
              << "yellow: " << ledsState.has_yellow() << std::endl
              << "green: " << ledsState.has_green() << std::endl
              << "lcd_backlight: " << ledsState.has_lcd_backlight() << std::endl
              << std::endl;

    myDevice.set_leds_state(miscMessage.set_leds_state());
    // ledsState = myDevice.get_leds_state();

    std::cout << "New leds state:\n"
              << "blue: " << ledsState.has_blue() << std::endl
              << "red: " << ledsState.has_red() << std::endl
              << "yellow: " << ledsState.has_yellow() << std::endl
              << "green: " << ledsState.has_green() << std::endl
              << "lcd_backlight: " << ledsState.has_lcd_backlight() << std::endl
              << std::endl;
    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS);

    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_read_device_info(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [read_device_info]...\n\n";
    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS, generate_device_info_payload(myDevice));

    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_reboot_device(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [reboot_device]...\n\n";
    misc::reboot::Reboot *reboot = new misc::reboot::Reboot();

    std::cout << "Original operation mode:" << std::endl;
    switch (myDevice.get_operation_mode())
    {
    case misc::reboot::Reboot_OperationMode_NORMAL_MODE:
        std::cout << "NORMAL" << std::endl;
        break;
    case misc::reboot::Reboot_OperationMode_MANAGEMENT_MODE:
        std::cout << "MANAGEMENT" << std::endl;
        break;
    case misc::reboot::Reboot_OperationMode_FACTORY_MODE:
        std::cout << "FACTORY" << std::endl;
        break;
    default:
        throw new std::invalid_argument(std::string("ERROR: Unknown operation mode ID: " + myDevice.get_operation_mode()));
    }

    myDevice.reboot(miscMessage.reboot_device().mode());

    std::cout << "New operation mode:" << std::endl;
    switch (myDevice.get_operation_mode())
    {
    case misc::reboot::Reboot_OperationMode_NORMAL_MODE:
        std::cout << "NORMAL" << std::endl;
        break;
    case misc::reboot::Reboot_OperationMode_MANAGEMENT_MODE:
        std::cout << "MANAGEMENT" << std::endl;
        break;
    case misc::reboot::Reboot_OperationMode_FACTORY_MODE:
        std::cout << "FACTORY" << std::endl;
        break;
    default:
        throw new std::invalid_argument(std::string("ERROR: Unknown operation mode ID: " + myDevice.get_operation_mode()));
    }

    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS);

    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_get_device_status(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [get_device_status]...\n\n";
    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS, generate_device_status_payload(myDevice));

    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_make_sound(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [make_sound]...\n\n";

    misc::buzzer::MakeSound makeSound = miscMessage.make_sound();
    int melodySize = makeSound.melody_size();

    std::cout << "Notes:" << std::endl;
    for (int i = 0; i < melodySize; ++i)
    {
        misc::buzzer::Note tempNote = makeSound.melody(i);
        std::cout << "Note #" << i
                  << "\tduration_ms: " << tempNote.duration_ms() << std::endl
                  << "\tfrequency_hz: " << tempNote.frequency_hz() << std::endl
                  << "\tsilence_duration_ms: " << tempNote.silence_duration_ms() << std::endl;
    }

    // ??? myDevice.make_sound_for_real() ???
    std::cout << "Finised execution. The sound would play on background.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS);
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_get_device_statistic(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [get_device_statistic]...\n\n";
    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS, generate_device_statistic_payload(myDevice));

    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_get_echo(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [get_echo]...\n\n";
    misc::echo::GetEcho getEcho = miscMessage.get_echo();

    if (getEcho.send_pending())
    {
        Msg generatedPending = generate_responce(PENDING);
        std::cout << "Generated pending:" << std::endl;
        generatedPending.print_MSG();
    }
    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS, generate_echo_payload(getEcho.reply_size(), getEcho.data()));

    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_change_baudrate(Miscellaneous &miscMessage, Device &myDevice)
{
    const misc::baudrate::ChangeBaudrate &changeBaudrate = miscMessage.change_baudrate();
    std::cout << "Executing [change_baudrate]...\n\n"

              << "Original baudrate: " << misc::baudrate::Baudrate_Name(myDevice.get_baudrate()) << std::endl;
    myDevice.set_baudrate(changeBaudrate.baudrate());
    std::cout << "New baudrate: " << misc::baudrate::Baudrate_Name(myDevice.get_baudrate()) << std::endl;

    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS);
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_change_lan_settings(Miscellaneous &miscMessage, Device &myDevice)
{
    std::cout << "Executing [change_lan_settings]...\n\n"

              << "Original lan settings:\n"
              << myDevice.get_lan_settings().DebugString() << std::endl;
    myDevice.set_lan_settings(miscMessage.change_lan_settings().lan_settings());
    std::cout << "New lan settings: " << myDevice.get_lan_settings().DebugString() << std::endl;

    std::cout << "Finised execution.\n\n";

    Msg generatedResponce = generate_responce(SUCCESS, generate_lan_settings_payload(myDevice));
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_contact()
{
    std::string errorMessage("Module [Contact] is not supported. MSG_ID: " + std::to_string(this->msgID));
    Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage));
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return false;
}

// void MessageIR::execute_contact(Device &myDevice)
// {
//     ContactLevel1 contactLvl1Message = *(dynamic_cast<ContactLevel1 *>(this->msg));
//     switch (contactLvl1Message.contact_level1_cmd_case())
//     {
//     case ContactLevel1::kPowerOnCard:
//         execute_power_on(contactLvl1Message, myDevice);
//         break;
//     case ContactLevel1::kPowerOffCard:
//         execute_power_off(contactLvl1Message, myDevice);
//         break;

//     case ContactLevel1::kTransmitApdu:
//         execute_transmit_apdu(contactLvl1Message, myDevice);
//         break;
//     default:
//         std::ostringstream errorMessage;
//         errorMessage << "Failed to execute [ContactLevel1] command message. Unrecognised [command]."
//                      << "\nMSG_ID: " << std::to_string(this->msgID)
//                      << "\ncontact_level1_cmd_case: " << std::to_string(contactLvl1Message.contact_level1_cmd_case());
//         Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage.str()));
//         std::cout << "Generated responce:" << std::endl;
//         generatedResponce.print_MSG();
//         throw ex::FailedExecution(errorMessage.str());
//     }
// }

// void MessageIR::execute_power_on(ContactLevel1 &contactLvl1Message, Device &myDevice)
// {
//     std::cout << "Executing [power_on_card]...\n\n";

//     auto powerOnCard = contactLvl1Message.power_on_card();

//     if (!myDevice.is_contact_card_present())
//     {
//         std::string errorMessage = "Contact card in not present.";
//         Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::ICC_IS_NOT_PRESENT, errorMessage));
//         std::cout << "Generated responce:" << std::endl;
//         generatedResponce.print_MSG();
//         std::cout << "Finised execution.\n\n";
//         return;
//     }

//     std::cout << "Original power state on card slots:\n"
//               << "\tMAIN_SLOT: " << myDevice.get_contact_cards_slots_power().MAIN_SLOT << std::endl
//               << "\tSAM2_SLOT: " << myDevice.get_contact_cards_slots_power().SAM2_SLOT << std::endl
//               << "\tSAM3_SLOT: " << myDevice.get_contact_cards_slots_power().SAM3_SLOT << std::endl
//               << "\tSAM4_SLOT: " << myDevice.get_contact_cards_slots_power().SAM4_SLOT << std::endl
//               << "\tSAM5_SLOT: " << myDevice.get_contact_cards_slots_power().SAM5_SLOT << std::endl;

//     myDevice.set_contact_card_slot(powerOnCard.slot(), true);

//     std::cout << "New power state on card slots:\n"
//               << "\tMAIN_SLOT: " << myDevice.get_contact_cards_slots_power().MAIN_SLOT << std::endl
//               << "\tSAM2_SLOT: " << myDevice.get_contact_cards_slots_power().SAM2_SLOT << std::endl
//               << "\tSAM3_SLOT: " << myDevice.get_contact_cards_slots_power().SAM3_SLOT << std::endl
//               << "\tSAM4_SLOT: " << myDevice.get_contact_cards_slots_power().SAM4_SLOT << std::endl
//               << "\tSAM5_SLOT: " << myDevice.get_contact_cards_slots_power().SAM5_SLOT << std::endl;

//     std::cout << "Finised execution.\n\n";

//     Msg generatedResponce = generate_responce(SUCCESS, generate_power_on_payload(myDevice));

//     std::cout << "Generated responce:" << std::endl;
//     generatedResponce.print_MSG();
// }

// void MessageIR::execute_power_off(ContactLevel1 &contactLvl1Message, Device &myDevice)
// {
//     std::cout << "Executing [power_off_card]...\n\n";

//     auto powerOffCard = contactLvl1Message.power_off_card();

//     std::cout << "Original power state on card slots:\n"
//               << "\tMAIN_SLOT: " << myDevice.get_contact_cards_slots_power().MAIN_SLOT << std::endl
//               << "\tSAM2_SLOT: " << myDevice.get_contact_cards_slots_power().SAM2_SLOT << std::endl
//               << "\tSAM3_SLOT: " << myDevice.get_contact_cards_slots_power().SAM3_SLOT << std::endl
//               << "\tSAM4_SLOT: " << myDevice.get_contact_cards_slots_power().SAM4_SLOT << std::endl
//               << "\tSAM5_SLOT: " << myDevice.get_contact_cards_slots_power().SAM5_SLOT << std::endl;

//     myDevice.set_contact_card_slot(powerOffCard.slot(), false);

//     std::cout << "New power state on card slots:\n"
//               << "\tMAIN_SLOT: " << myDevice.get_contact_cards_slots_power().MAIN_SLOT << std::endl
//               << "\tSAM2_SLOT: " << myDevice.get_contact_cards_slots_power().SAM2_SLOT << std::endl
//               << "\tSAM3_SLOT: " << myDevice.get_contact_cards_slots_power().SAM3_SLOT << std::endl
//               << "\tSAM4_SLOT: " << myDevice.get_contact_cards_slots_power().SAM4_SLOT << std::endl
//               << "\tSAM5_SLOT: " << myDevice.get_contact_cards_slots_power().SAM5_SLOT << std::endl;

//     std::cout << "Finised execution.\n\n";

//     Msg generatedResponce = generate_responce(SUCCESS);

//     std::cout << "Generated responce:" << std::endl;
//     generatedResponce.print_MSG();
// }

// void MessageIR::execute_transmit_apdu(ContactLevel1 &contactLvl1Message, Device &myDevice)
// {
//     std::cout << "Executing [power_transmit_apdu]...\n\n";

//     auto transmitApdu = contactLvl1Message.transmit_apdu();

//     if (!myDevice.is_contact_card_present())
//     {
//         std::string errorMessage = "Contact card in not present.";
//         Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::ICC_IS_NOT_PRESENT, errorMessage));
//         std::cout << "Generated responce:" << std::endl;
//         generatedResponce.print_MSG();
//         std::cout << "Finised execution.\n\n";
//         return;
//     }

//     if (!myDevice.get_single_contact_card_slot_power(transmitApdu.slot()))
//     {
//         std::ostringstream errorMessage;
//         errorMessage << "Contact card in slot ["
//                      << contact::card_slot::CardSlot_Name(transmitApdu.slot()) << "]"
//                      << " is not powered";
//         Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::ICC_IS_NOT_READY, errorMessage.str()));
//         std::cout << "Generated responce:" << std::endl;
//         generatedResponce.print_MSG();
//         std::cout << "Finised execution.\n\n";
//         return;
//     }

//     std::cout
//         << "Apdu command:\t" << transmitApdu.command_apdu() << std::endl
//         << "For slot:\t" << contact::card_slot::CardSlot_Name(transmitApdu.slot()) << std::endl;

//     std::cout << "Finised execution.\n\n";

//     Msg generatedResponce = generate_responce(SUCCESS, generate_transmit_apdu_payload(myDevice.get_card_in_slot()));

//     std::cout << "Generated responce:" << std::endl;
//     generatedResponce.print_MSG();
// }

bool MessageIR::execute_contactless_1(Device &myDevice)
{
    bool res;
    ContactlessLevel1 contactlessLvl1Message = *(dynamic_cast<ContactlessLevel1 *>(this->msg));
    switch (contactlessLvl1Message.contactless_level1_cmd_case())
    {
    case ContactlessLevel1::kPollForToken:
        res = execute_poll_for_token(contactlessLvl1Message, myDevice);
        break;
    case ContactlessLevel1::kEmvRemoval:
        res = execute_emv_removal(contactlessLvl1Message, myDevice);
        break;
    // case ContactlessLevel1::kTsvBitArray:
    //     res = execute_tsv_bit_array(contactlessLvl1Message, myDevice);
    //     break;
    // case ContactlessLevel1::kIso144434Command:
    //     res = execute_tsv_iso_command(contactlessLvl1Message, myDevice);
    //     break;
    case ContactlessLevel1::kPowerOffField:
        res = execute_power_off_rf(contactlessLvl1Message, myDevice);
        break;
    // case ContactlessLevel1::kRequestForAts:
    //     res = execute_rats(contactlessLvl1Message, myDevice);
    //     break;
    default:
        res = false;
        std::ostringstream errorMessage;
        errorMessage << "Failed to execute [ContactlessLevel1] command message. Unrecognised [command]."
                     << "\nMSG_ID: " << std::to_string(this->msgID)
                     << "\ncontactless_level1_cmd_case: " << std::to_string(contactlessLvl1Message.contactless_level1_cmd_case());
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage.str()));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
        throw ex::FailedExecution(errorMessage.str());
    }

    return res;
}

bool MessageIR::execute_poll_for_token(ContactlessLevel1 &miscMessage, Device &myDevice)
{
    std::cout << "Executing [poll_for_token]...\n\n";

    bool res;
    auto pollForToken = miscMessage.poll_for_token();

    if (pollForToken.has_light_up_led())
    {
        misc::leds::Leds newLeds;
        newLeds.set_blue(true);
        myDevice.set_leds_state(newLeds);
        std::cout << "blue led is ON" << std::endl;
    }

    std::cout << "Returning Pending message..." << std::endl;
    generate_responce(PENDING).print_MSG();

    const Msg *generatedResponce = nullptr;

    bool preferMifare = pollForToken.prefer_mifare();

    if (pollForToken.has_timeout())
    {
        // it there is timeout field

        if (pollForToken.timeout() == 0)
        {
            // if timeout == 0 - return previous result
            generatedResponce = &generate_responce(SUCCESS, generate_stored_poll_for_token_payload(myDevice));
            res = true;
        }
        else
        {
            if (myDevice.how_many_cards() > 1) // send notification
            {
                std::cout << "Returning Notification message..." << std::endl;
                generate_responce(NOTIFICATION, generate_user_notification_payload(common::notification::UserMessage_MessageId_PRESENT_ONE_CARD_ONLY)).print_MSG();
            }

            if (myDevice.how_many_cards() == 1) // get token, send success message
            {
                generatedResponce = &generate_responce(SUCCESS, generate_poll_for_token_payload(myDevice, preferMifare));
                res = true;
            }
            else
                for (auto &action : this->actions)
                {
                    bool actionSuccess = action->make_action(myDevice);
                    std::cout << "Action {" << action->str() << "} was made\n";

                    if (action->get_type() == SEND_CANCEL_MESSAGE && actionSuccess) // if cancelation was successful
                    {
                        std::cout << "[poll_for_token] was canceled by HOST" << std::endl;
                        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::PROCESSING_STOPPED, "Execution was canceled"));
                        res = false;
                        break;
                    }
                    else if (myDevice.how_many_cards() > 1) // send notification
                    {
                        std::cout << "Returning Notification message..." << std::endl;
                        generatedResponce = &generate_responce(NOTIFICATION, generate_user_notification_payload(common::notification::UserMessage_MessageId_PRESENT_ONE_CARD_ONLY));
                    }
                    else if (myDevice.how_many_cards() == 1)
                    {
                        // get token and break, send success message
                        generatedResponce = &generate_responce(SUCCESS, generate_poll_for_token_payload(myDevice, preferMifare));
                        res = true;
                        break;
                    }
                }
        }
    }
    else
    {
        // if there is no timeout - poll forever
        if (myDevice.how_many_cards() > 1) // send notification
        {
            std::cout << "Returning Notification message..." << std::endl;
            generate_responce(NOTIFICATION, generate_user_notification_payload(common::notification::UserMessage_MessageId_PRESENT_ONE_CARD_ONLY)).print_MSG();
        }

        if (myDevice.how_many_cards() == 1)
        {
            generatedResponce = &generate_responce(SUCCESS, generate_poll_for_token_payload(myDevice, preferMifare));
            res = true;
        }
        else if (this->actions.empty())
        {
            std::cout << "In the script command [poll_for_token] had no timeout, did not get card token and was eventualy canceled by HOST" << std::endl;
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::PROCESSING_STOPPED, "Execution was canceled"));
            res = false;
            // report what terminal has stuck in poll mode and command was canceled by HOST with cancel message. send failure(processing_stopped)
        }
        else
        {
            for (auto &action : this->actions)
            {
                bool actionSuccess = action->make_action(myDevice);
                std::cout << "Action {" << action->str() << "} was made\n";

                if (action->get_type() == SEND_CANCEL_MESSAGE && actionSuccess) // if cancelation was successful
                {
                    std::cout << "[poll_for_token] was canceled by HOST" << std::endl;
                    generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::PROCESSING_STOPPED, "Execution was canceled"));
                    res = false;
                    break;
                }
                else if (myDevice.how_many_cards() > 1) // send notification
                {
                    std::cout << "Returning Notification message..." << std::endl;
                    generatedResponce = &generate_responce(NOTIFICATION, generate_user_notification_payload(common::notification::UserMessage_MessageId_PRESENT_ONE_CARD_ONLY));
                }
                else if (myDevice.how_many_cards() == 1)
                {
                    generatedResponce = &generate_responce(SUCCESS, generate_poll_for_token_payload(myDevice, preferMifare));
                    res = true;
                    break;
                    // get token and break, send success message
                }
            }

            if (generatedResponce == nullptr)
            {
                std::cout << "In current script command [poll_for_token] had no timeout, did not get card token and was eventualy canceled by HOST" << std::endl;
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::PROCESSING_STOPPED, "Execution was canceled"));
                res = false;
            }
        }
    }

    if (generatedResponce == nullptr)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::TIMEOUT_EXPIRED, "Timeout has expired"));
        res = false;
    }

    if (pollForToken.has_light_up_led())
    {
        misc::leds::Leds newLeds;
        newLeds.set_blue(false);
        myDevice.set_leds_state(newLeds);
        std::cout << "blue led is OFF" << std::endl;
    }

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();
    delete generatedResponce;

    return res;
}

bool MessageIR::execute_emv_removal(ContactlessLevel1 &miscMessage, Device &myDevice)
{
    std::cout << "Executing [emv_removal]...\n\n";

    bool res;
    auto emvRemoval = miscMessage.emv_removal();

    std::cout << "Returning Pending message..." << std::endl;
    generate_responce(PENDING).print_MSG();

    const Msg *generatedResponce = nullptr;

    for (auto &action : this->actions)
    {
        bool actionSuccess = action->make_action(myDevice);
        std::cout << "Action {" << action->str() << "} was made\n";

        if (action->get_type() == SEND_CANCEL_MESSAGE && actionSuccess) // if cancelation was successful
        {
            std::cout << "[emv_removal] was canceled by HOST" << std::endl;
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::PROCESSING_STOPPED, "Execution was canceled"));
            res = false;
            break;
        }
    }

    if (generatedResponce == nullptr)
    {
        if (!emvRemoval.has_timeout())
        {
            generatedResponce = &generate_responce(SUCCESS);
            res = true;
        }
        else
        {
            if (myDevice.how_many_cards() > 0)
            {
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::TIMEOUT_EXPIRED));
                res = false;
            }
            else
            {
                generatedResponce = &generate_responce(SUCCESS);
                res = true;
            }
        }
    }

    std::cout << "RF-field is powered off." << std::endl;

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();
    delete generatedResponce;

    return res;
}

bool MessageIR::execute_tsv_bit_array(ContactlessLevel1 &contactlessMessage, Device &myDevice)
{
    return false;
}

bool MessageIR::execute_power_off_rf(ContactlessLevel1 &contactlessMessage, Device &myDevice)
{
    std::cout << "Executing [emv_removal]...\n\n";

    std::cout << "RF-field is powered off." << std::endl;

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    Msg generatedResponce = generate_responce(SUCCESS);
    generatedResponce.print_MSG();

    return true;
}

bool MessageIR::execute_contactless_2(Device &myDevice)
{
    bool res;
    ContactlessLevel2 contactlessLvl2Message = *(dynamic_cast<ContactlessLevel2 *>(this->msg));
    switch (contactlessLvl2Message.contactless_level2_cmd_case())
    {
    case ContactlessLevel2::kPerformTransaction:
        res = execute_perform_transaction(contactlessLvl2Message, myDevice);
        break;
    default:
        res = false;
        std::ostringstream errorMessage;
        errorMessage << "Failed to execute [ContactlessLevel2] command message. Unrecognised [command]."
                     << "\nMSG_ID: " << std::to_string(this->msgID)
                     << "\ncontactless_level2_cmd_case: " << std::to_string(contactlessLvl2Message.contactless_level2_cmd_case());
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage.str()));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
        throw ex::FailedExecution(errorMessage.str());
    }

    return res;
}

bool MessageIR::execute_perform_transaction(ContactlessLevel2 &contactlessMessage, Device &myDevice)
{
    std::cout << "Executing [perform_transaction]...\n\n";

    bool res;
    std::cout << "Returning Pending message..." << std::endl;
    generate_responce(PENDING).print_MSG();

    const Msg *generatedResponce = nullptr;
    for (auto &action : this->actions)
    {
        bool actionSuccess = action->make_action(myDevice);
        std::cout << "Action {" << action->str() << "} was made\n";

        if (action->get_type() == SEND_CANCEL_MESSAGE && actionSuccess) // if cancelation was successful
        {
            std::cout << "[perform_transaction] was canceled by HOST" << std::endl;
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::PROCESSING_STOPPED, "Execution was canceled"));
            res = false;
            break;
        }
    }
    if (generatedResponce == nullptr)
    {
        bool preferMifare = contactlessMessage.perform_transaction().poll_for_token().prefer_mifare();
        generatedResponce = &generate_responce(SUCCESS, generate_perform_transaction_payload(myDevice, preferMifare));
        res = true;
    }

    // retry case is not implemented

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    delete generatedResponce;

    return res;
}

bool MessageIR::execute_mifare(Device &myDevice)
{
    const Msg *responce = nullptr;
    bool res;
    Mifare mifareMessage = *(dynamic_cast<Mifare *>(this->msg));
    switch (mifareMessage.mifare_cmd_case())
    {
        //  Classic
    case Mifare::kMfrClassicAuthOnClearKey:
        responce = &execute_mfr_classic_auth_on_clear_key(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicAuthOnSamKey:
        responce = &execute_mfr_classic_auth_on_sam_key(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicReadBlocks:
        responce = &execute_mfr_classic_read_blocks(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicWriteBlocks:
        responce = &execute_mfr_classic_write_blocks(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicGetCounter:
        responce = &execute_mfr_classic_get_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicSetCounter:
        responce = &execute_mfr_classic_set_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicModifyCounter:
        responce = &execute_mfr_classic_modify_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicCopyCounter:
        responce = &execute_mfr_classic_copy_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicCommitCounter:
        responce = &execute_mfr_classic_commit_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrClassicBulkOperation:
        responce = &execute_mfr_classic_bulk_operation(mifareMessage, myDevice);
        res = responce->is_failure();
        break;

        // Ultralight
    case Mifare::kMfrUlReadPages:
        responce = &execute_mfr_ul_read_pages(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlWritePages:
        responce = &execute_mfr_ul_write_pages(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlGetVersion:
        responce = &execute_mfr_ul_get_version(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlGetCounter:
        responce = &execute_mfr_ul_get_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlIncrementCounter:
        responce = &execute_mfr_ul_increment_counter(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlBulkOperation:
        responce = &execute_mfr_ul_bulk_operation(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlAuthOnClearKey:
        responce = &execute_mfr_ul_auth_on_clear_key(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlAuthOnSamKey:
        responce = &execute_mfr_ul_auth_on_sam_key(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlAuthClearPassword:
        responce = &execute_mfr_ul_auth_clear_password(mifareMessage, myDevice);
        res = responce->is_failure();
        break;
    case Mifare::kMfrUlAuthSamPassword:
        responce = &execute_mfr_ul_auth_sam_password(mifareMessage, myDevice);
        res = responce->is_failure();
        break;

    default:
        res = false;
        std::ostringstream errorMessage;
        errorMessage << "Failed to execute [Mifare] command message. Unrecognised [command]."
                     << "\nMSG_ID: " << std::to_string(this->msgID)
                     << "\nmifare_cmd_case: " << std::to_string(mifareMessage.mifare_cmd_case());
        Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage.str()));
        std::cout << "Generated responce:" << std::endl;
        generatedResponce.print_MSG();
        throw ex::FailedExecution(errorMessage.str());
    }

    if (responce != nullptr)
        delete responce;

    return res;
}

const Msg &MessageIR::execute_mfr_classic_auth_on_clear_key(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_auth_on_clear_key]...\n\n";

    auto mfrAuth = mifareMessage.mfr_classic_auth_on_clear_key();
    auto storedToken = &myDevice.get_stored_token();

    const Msg *generatedResponce = nullptr;

    if (storedToken->type() != contactless::token_type::MIFARE_CLASSIC_1K &&
        storedToken->type() != contactless::token_type::MIFARE_CLASSIC_2K &&
        storedToken->type() != contactless::token_type::MIFARE_CLASSIC_4K &&
        storedToken->type() != contactless::token_type::MIFARE_CLASSIC_MINI)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Wrong token type"));
    }
    else
    {
        auto card = myDevice.get_card_in_field();

        switch (mfrAuth.key_type())
        {
        case mifare::classic::auth::TYPE_A:
            if (dynamic_cast<MifareClassicCard *>(card)->get_clear_key_A(mfrAuth.sector_number()) != mfrAuth.clear_key())
            {
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Mismatch of clear key type_a"));
            }
            else
            {
                generatedResponce = &generate_responce(SUCCESS);
                dynamic_cast<MifareClassicCard *>(card)->authorize_sector(mfrAuth.sector_number());
                std::cout << "Authenticated sector " << mfrAuth.sector_number() << std::endl;
            }
            break;
        case mifare::classic::auth::TYPE_B:
            if (dynamic_cast<const MifareClassicCard *>(card)->get_clear_key_B(mfrAuth.sector_number()) != mfrAuth.clear_key())
            {
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Mismatch of clear key type_b"));
            }
            else
            {
                generatedResponce = &generate_responce(SUCCESS);
                dynamic_cast<MifareClassicCard *>(card)->authorize_sector(mfrAuth.sector_number());
                std::cout << "Authenticated sector " << mfrAuth.sector_number() << std::endl;
            }
            break;
        default:
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Unknown key type"));
        }
    }
    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_auth_on_sam_key(const Mifare &mifareMessage, Device &myDevice)
{
    std::string errorMessage("Command [mfr_classic_auth_on_sam_key] of module [Mifare] is not supported. MSG_ID: " + std::to_string(this->msgID));
    const Msg &generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_FEATURE, errorMessage));
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_read_blocks(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_read_blocks]...\n\n";

    auto mfrReadBlocks = mifareMessage.mfr_classic_read_blocks();
    auto card = myDevice.get_card_in_field();

    std::string readData = "";
    const Msg *generatedResponce = nullptr;
    for (int i = 0; i < mfrReadBlocks.block_count(); ++i)
    {
        // auth and read rights will be checked inside read_page()
        auto block = dynamic_cast<MifareClassicCard *>(card)->read_block(mfrReadBlocks.start_block() + i);

        //  if reading failed
        if (block == nullptr)
        {
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Failed to read block"));
            break;
        }
        // else
        readData += block->get_data();
        std::cout << "readData: " << readData << std::endl;
    }
    if (generatedResponce == nullptr)
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_classic_read_blocks_payload(readData));

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_write_blocks(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_write_blocks]...\n\n";

    auto mfrWriteBlocks = mifareMessage.mfr_classic_write_blocks();
    auto card = dynamic_cast<MifareClassicCard *>(myDevice.get_card_in_field());

    const Msg *generatedResponce = nullptr;
    uint32_t numBlocks = (mfrWriteBlocks.data().length() + BLOCK_SIZE - 1) / BLOCK_SIZE; // number of blocks to write
    for (uint32_t i = 0; i < numBlocks; ++i)
    {
        std::cout << "Block " << mfrWriteBlocks.start_block() + i << ": " << card->get_block_data(mfrWriteBlocks.start_block() + i) << std::endl;
        size_t startIndex = i * BLOCK_SIZE;
        size_t endIndex = std::min(startIndex + BLOCK_SIZE, mfrWriteBlocks.data().length());

        if (!card->write_data_block(mfrWriteBlocks.data().substr(startIndex, endIndex - startIndex), mfrWriteBlocks.start_block() + i))
        {
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Failed to write block"));
            break;
        }
        std::cout << "Rewrited\n";
        std::cout << "Block " << mfrWriteBlocks.start_block() + i << ": " << card->get_block_data(mfrWriteBlocks.start_block() + i) << std::endl;
    }

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce = &generate_responce(SUCCESS);
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_get_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_get_counter]...\n\n";

    auto mfrGetCounter = mifareMessage.mfr_classic_get_counter();
    auto card = dynamic_cast<MifareClassicCard *>(myDevice.get_card_in_field());

    const Msg *generatedResponce = nullptr;

    auto block = card->read_block(mfrGetCounter.src_block());
    if (block == nullptr)
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Failed to read block"));
    else if (!block->is_value())
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::CONFIGURATION_ERROR, "Block is not a counter"));
    else
    {
        int counter;
        counter = dynamic_cast<const ValueBlock *>(block)->get_value();
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_classic_get_counter_payload(counter));
    }

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_set_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_set_counter]...\n\n";

    auto mfrSetCounter = mifareMessage.mfr_classic_set_counter();
    auto card = dynamic_cast<MifareClassicCard *>(myDevice.get_card_in_field());

    card->write_value_block(mfrSetCounter.value(), mfrSetCounter.dst_block());

    std::cout << "Finised execution.\n\n";

    const Msg &generatedResponce = generate_responce(SUCCESS);
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_modify_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_modify_counter]...\n\n";

    auto mfrModCounter = mifareMessage.mfr_classic_modify_counter();
    auto card = dynamic_cast<MifareClassicCard *>(myDevice.get_card_in_field());

    int32_t counterValue = card->get_block_value(mfrModCounter.src_block());

    counterValue += mfrModCounter.operand();

    if (mfrModCounter.has_dst_block())
        card->write_value_block(counterValue, mfrModCounter.dst_block());
    else
        card->set_internal_register(counterValue);

    std::cout << "Finised execution.\n\n";

    const Msg &generatedResponce = generate_responce(SUCCESS);
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_copy_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_copy_counter]...\n\n";

    auto mfrCopyCounter = mifareMessage.mfr_classic_copy_counter();
    auto card = dynamic_cast<MifareClassicCard *>(myDevice.get_card_in_field());
    int counter;

    const Msg *generatedResponce = nullptr;
    try
    {
        counter = card->get_block_value(mfrCopyCounter.src_block());
    }
    catch (const ex::BadType &ex)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::CONFIGURATION_ERROR, "Block is not a counter"));
    }

    if (generatedResponce == nullptr)
    {
        if (mfrCopyCounter.has_dst_block())
            card->write_value_block(counter, mfrCopyCounter.dst_block());
        else
            card->set_internal_register(counter);
        generatedResponce = &generate_responce(SUCCESS);
    }

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_commit_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_commit_counter]...\n\n";

    auto mfrCommitCounter = mifareMessage.mfr_classic_commit_counter();
    auto card = dynamic_cast<MifareClassicCard *>(myDevice.get_card_in_field());

    card->write_value_block(card->get_internal_register(), mfrCommitCounter.dst_block());

    std::cout << "Finised execution.\n\n";

    const Msg &generatedResponce = generate_responce(SUCCESS);
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return generatedResponce;
}

const Msg &MessageIR::execute_mfr_classic_bulk_operation(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_bulk_operation]...\n\n";

    auto mfrBulk = mifareMessage.mfr_classic_bulk_operation();
    const Msg *generatedResponce = nullptr;
    auto results = new mifare::classic::bulk::BulkResult();

    for (auto &operation : mfrBulk.operations())
    {
        switch (operation.MfrCmd_case())
        {
        case mifare::classic::bulk::Command::kAuthOnClearKey:
        {
            std::cout << "[auth_on_clear_key]\n"
                      << operation.auth_on_clear_key().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::auth::ClearKey(operation.auth_on_clear_key());
            tempMifare->set_allocated_mfr_classic_auth_on_clear_key(tempCommand);
            auto responce = execute_mfr_classic_auth_on_clear_key(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::classic::bulk::Command::kAuthOnSamKey:
        {
            std::cout << "[auth_on_sam_key]\n"
                      << operation.auth_on_sam_key().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::auth::SamKey(operation.auth_on_sam_key());
            tempMifare->set_allocated_mfr_classic_auth_on_sam_key(tempCommand);
            auto responce = execute_mfr_classic_auth_on_sam_key(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::classic::bulk::Command::kReadBlocks:
        {
            std::cout << "[read_blocks]\n"
                      << operation.read_blocks().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::read::ReadBlocks(operation.read_blocks());
            tempMifare->set_allocated_mfr_classic_read_blocks(tempCommand);
            auto responce = execute_mfr_classic_read_blocks(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
            {
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());
                break;
            }

            // get read data from responce of exe method
            auto commandResult = results->add_results();
            auto newBlocks = new mifare::classic::read::Blocks();
            commandResult->set_allocated_read_blocks(newBlocks);

            newBlocks->set_data(dynamic_cast<const mifare::classic::read::Blocks *>(responce.get_payload().get_responce_msg())->data());

            break;
        }
        case mifare::classic::bulk::Command::kWriteBlocks:
        {
            std::cout << "[write_blocks]\n"
                      << operation.write_blocks().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::write::WriteBlocks(operation.write_blocks());
            tempMifare->set_allocated_mfr_classic_write_blocks(tempCommand);
            auto responce = execute_mfr_classic_write_blocks(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::classic::bulk::Command::kGetCounter:
        {
            std::cout << "[get_counter]\n"
                      << operation.get_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::counter::get::GetCounter(operation.get_counter());
            tempMifare->set_allocated_mfr_classic_get_counter(tempCommand);
            auto responce = execute_mfr_classic_get_counter(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed return error
            if (responce.is_failure())
            {
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());
                break;
            }

            //  get counter value from responce of exe method
            auto commandResult = results->add_results();
            auto newCounter = new mifare::classic::counter::get::Counter();
            commandResult->set_allocated_get_counter(newCounter);
            newCounter->set_value(dynamic_cast<const mifare::classic::counter::get::Counter *>(responce.get_payload().get_responce_msg())->value());

            break;
        }
        case mifare::classic::bulk::Command::kSetCounter:
        {
            std::cout << "[set_counter]\n"
                      << operation.set_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::counter::set::SetCounter(operation.set_counter());
            tempMifare->set_allocated_mfr_classic_set_counter(tempCommand);
            auto responce = execute_mfr_classic_set_counter(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::classic::bulk::Command::kModifyCounter:
        {
            std::cout << "[modify_counter]\n"
                      << operation.modify_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::counter::modify::ModifyCounter(operation.modify_counter());
            tempMifare->set_allocated_mfr_classic_modify_counter(tempCommand);
            auto responce = execute_mfr_classic_modify_counter(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::classic::bulk::Command::kCopyCounter:
        {
            std::cout << "[copy_counter]\n"
                      << operation.copy_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::counter::copy::CopyCounter(operation.copy_counter());
            tempMifare->set_allocated_mfr_classic_copy_counter(tempCommand);
            auto responce = execute_mfr_classic_copy_counter(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::classic::bulk::Command::kCommitCounter:
        {
            std::cout << "[commit_counter]\n"
                      << operation.commit_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::classic::counter::commit::CommitCounter(operation.commit_counter());
            tempMifare->set_allocated_mfr_classic_commit_counter(tempCommand);
            auto responce = execute_mfr_classic_commit_counter(*tempMifare, myDevice);

            delete tempMifare;

            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        default:
        {
            // failure UNSUPPORTED COMMAND
            std::cout << "Unsupported command" << std::endl;
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, "Bulk operation has unsupported command"));
        }
        }

        //  if failure responce already was generated (failure occurred): exit loop
        if (generatedResponce != nullptr)
        {
            delete results;
            break;
        }
    }

    //  if there was no failure
    if (generatedResponce == nullptr)
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_classic_bulk_operation_payload(*results));

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_read_pages(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_read_pages]...\n\n";

    auto mfrReadPages = mifareMessage.mfr_ul_read_pages();

    auto card = myDevice.get_card_in_field();

    // mifare ul C allows to read no more than 4 pages at once
    uint32_t numberOfPagesToRead = (dynamic_cast<MifareUltralightCard *>(card)->get_type() == MifareUltralightCard::m_C ? 4 : mfrReadPages.page_count());

    std::string readData = "";

    const Msg *generatedResponce = nullptr;
    for (int i = 0; i < numberOfPagesToRead; ++i)
    {
        // auth and read rights will be checked inside read_page()
        auto page = dynamic_cast<MifareUltralightCard *>(card)->read_page(mfrReadPages.start_address() + i);

        //  if reading failed
        if (page == nullptr)
        {
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Failed to read page"));
            break;
        }

        readData += page->get_data_str();
        std::cout << "readData: " << readData << std::endl;
    }

    //  if failure didn't occurred
    if (generatedResponce == nullptr)
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_ul_read_pages_payload(readData));

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    // delete generatedResponce;

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_write_pages(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_write_pages]...\n\n";

    auto mfrWritePages = mifareMessage.mfr_ul_write_pages();

    auto card = dynamic_cast<MifareUltralightCard *>(myDevice.get_card_in_field());

    const Msg *generatedResponce = nullptr;

    std::vector<uint8_t> byteArray;
    std::stringstream bytesString(mfrWritePages.data());
    std::string byteStr;
    char delimiter = '\\';
    int iPage = mfrWritePages.start_address();

    while (std::getline(bytesString, byteStr, delimiter))
    {
        //  convert hex string to uint8
        if (byteStr.empty())
            continue;
        uint8_t byte = std::stoul(byteStr, nullptr, 16);

        byteArray.push_back(byte);
        if (byteArray.size() == 4)
        {
            if (!card->write_page(Page(byteArray), iPage))
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Failed to write page"));

            byteArray.clear();
            ++iPage;
        }
    }

    //  if at the end there were less than 4 bytes - fill to 4 with 0x00 and write the last page
    if (byteArray.size() > 0)
    {
        while (byteArray.size() < 4)
            byteArray.push_back(0);
        if (!card->write_page(Page(byteArray), iPage))
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Failed to write page"));
    }

    //  if failure didn't occurred
    if (generatedResponce == nullptr)
        generatedResponce = &generate_responce(SUCCESS);

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_get_version(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_get_version]...\n\n";

    auto mfrGetVersion = mifareMessage.mfr_ul_get_version();

    auto card = myDevice.get_card_in_field();

    const Msg *generatedResponce = nullptr;
    if (dynamic_cast<MifareUltralightCard *>(card)->get_type() != MifareUltralightCard::m_EV1)
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_FEATURE, "Wrong type of Mfr UL"));
    else
    {
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_ul_get_version_payload(dynamic_cast<MfrUl_EV1_Card *>(card)->get_version()));
    }

    std::cout
        << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_get_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_get_counter]...\n\n";

    auto mfrGetCounter = mifareMessage.mfr_ul_get_counter();

    auto card = myDevice.get_card_in_field();

    const Msg *generatedResponce = nullptr;
    if (dynamic_cast<MifareUltralightCard *>(card)->get_type() != MifareUltralightCard::m_EV1)
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_FEATURE, "Wrong type of Mfr UL"));
    else
    {
        uint32_t value;
        switch (mfrGetCounter.counter_number())
        {
        case mifare::ultralight::counter::number::FIRST:
            value = dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(0);
            break;
        case mifare::ultralight::counter::number::SECOND:
            value = dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(1);
            break;
        case mifare::ultralight::counter::number::THIRD:
            value = dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(2);
            break;
        }
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_ul_get_counter_payload(value));
    }

    std::cout
        << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_increment_counter(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_increment_counter]...\n\n";

    auto mfrIncCounter = mifareMessage.mfr_ul_increment_counter();

    auto card = myDevice.get_card_in_field();

    const Msg *generatedResponce = nullptr;
    if (dynamic_cast<MifareUltralightCard *>(card)->get_type() != MifareUltralightCard::m_EV1)
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_FEATURE, "Wrong type of Mfr UL"));
    else
    {
        std::cout << "Old counters:\n"
                  << dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(0) << std::endl
                  << dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(1) << std::endl
                  << dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(2) << std::endl;

        switch (mfrIncCounter.counter_number())
        {
        case mifare::ultralight::counter::number::FIRST:
            if (!dynamic_cast<MfrUl_EV1_Card *>(card)->increment_counter(0, mfrIncCounter.operand()))
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Failed to increment"));
            break;
        case mifare::ultralight::counter::number::SECOND:
            if (!dynamic_cast<MfrUl_EV1_Card *>(card)->increment_counter(1, mfrIncCounter.operand()))
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Failed to increment"));
            break;
        case mifare::ultralight::counter::number::THIRD:
            if (!dynamic_cast<MfrUl_EV1_Card *>(card)->increment_counter(2, mfrIncCounter.operand()))
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Failed to increment"));
            break;
        }
        std::cout << "New counters:\n"
                  << dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(0) << std::endl
                  << dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(1) << std::endl
                  << dynamic_cast<MfrUl_EV1_Card *>(card)->get_counter(2) << std::endl;

        //  if failure was not occurred
        if (generatedResponce == nullptr)
            generatedResponce = &generate_responce(SUCCESS);
    }

    std::cout
        << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_bulk_operation(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_bulk_operation]...\n\n";

    auto mfrBulk = mifareMessage.mfr_ul_bulk_operation();
    const Msg *generatedResponce = nullptr;
    auto results = new mifare::ultralight::bulk::BulkResult(); //  no need to delete this one, since it will be passed to generatedResponce

    for (auto &operation : mfrBulk.operations())
    {
        switch (operation.MfrCmd_case())
        {
        case mifare::ultralight::bulk::Command::kReadPages:
        {
            std::cout << "[read_pages]\n"
                      << operation.read_pages().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::read::ReadPages(operation.read_pages());
            tempMifare->set_allocated_mfr_ul_read_pages(tempCommand);
            auto responce = execute_mfr_ul_read_pages(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
            {
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());
                break;
            }

            // get read data from responce of exe method
            auto commandResult = results->add_results();
            auto newPages = new mifare::ultralight::read::Pages();
            commandResult->set_allocated_pages(newPages);
            newPages->set_data(dynamic_cast<const mifare::ultralight::read::Pages *>(responce.get_payload().get_responce_msg())->data());

            break;
        }
        case mifare::ultralight::bulk::Command::kWritePages:
        {
            std::cout << "[write_pages]\n"
                      << operation.write_pages().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::write::WritePages(operation.write_pages());
            tempMifare->set_allocated_mfr_ul_write_pages(tempCommand);
            auto responce = execute_mfr_ul_write_pages(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::ultralight::bulk::Command::kGetCounter:
        {
            std::cout << "[get_counter]\n"
                      << operation.get_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::counter::get::GetCounter(operation.get_counter());
            tempMifare->set_allocated_mfr_ul_get_counter(tempCommand);
            auto responce = execute_mfr_ul_get_counter(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
            {
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());
                break;
            }

            // else
            //   get counter value from responce of exe method
            auto commandResult = results->add_results();
            auto newCounterValue = new mifare::ultralight::counter::get::CounterValue();
            commandResult->set_allocated_counter_value(newCounterValue);
            newCounterValue->set_value(dynamic_cast<const mifare::ultralight::counter::get::CounterValue *>(responce.get_payload().get_responce_msg())->value());

            break;
        }
        case mifare::ultralight::bulk::Command::kIncrementCounter:
        {
            std::cout << "[increment_counter]\n"
                      << operation.increment_counter().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::counter::increment::IncrementCounter(operation.increment_counter());
            tempMifare->set_allocated_mfr_ul_increment_counter(tempCommand);
            auto responce = execute_mfr_ul_increment_counter(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::ultralight::bulk::Command::kAuthOnClearKey:
        {
            std::cout << "[auth_on_clear_key]\n"
                      << operation.auth_on_clear_key().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::auth::ClearKey(operation.auth_on_clear_key());
            tempMifare->set_allocated_mfr_ul_auth_on_clear_key(tempCommand);
            auto responce = execute_mfr_ul_auth_on_clear_key(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::ultralight::bulk::Command::kAuthOnSamKey:
        {
            std::cout << "[auth_on_sam_key]\n"
                      << operation.auth_on_sam_key().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::auth::SamKey(operation.auth_on_sam_key());
            tempMifare->set_allocated_mfr_ul_auth_on_sam_key(tempCommand);
            auto responce = execute_mfr_ul_auth_on_sam_key(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error (it will fail anyway)
            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            break;
        }
        case mifare::ultralight::bulk::Command::kAuthClearPassword:
        {
            std::cout << "[auth_clear_password]\n"
                      << operation.auth_clear_password().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::password::ClearPassword(operation.auth_clear_password());
            tempMifare->set_allocated_mfr_ul_auth_clear_password(tempCommand);
            auto responce = execute_mfr_ul_auth_clear_password(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            //  bulk operation results don't need PACK value

            break;
        }
        case mifare::ultralight::bulk::Command::kAuthSamPassword:
        {
            std::cout << "[auth_sam_password]\n"
                      << operation.auth_sam_password().DebugString() << std::endl;
            //  extract mifare command from operation and pass it to exe method
            auto tempMifare = new Mifare();
            auto tempCommand = new mifare::ultralight::password::SamPassword(operation.auth_sam_password());
            tempMifare->set_allocated_mfr_ul_auth_sam_password(tempCommand);
            auto responce = execute_mfr_ul_auth_sam_password(*tempMifare, myDevice);

            delete tempMifare;

            //  if failed - return error
            if (responce.is_failure())
                generatedResponce = &generate_responce(FAILURE, responce.get_payload());

            //  bulk operation results don't need PACK value

            break;
        }
        default:
        {
            // failure UNSUPPORTED COMMAND
            std::cout << "Unsupported command" << std::endl;
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, "Bulk operation has unsupported command"));
        }
        }

        //  if failure responce already was generated (failure occurred): exit loop
        if (generatedResponce != nullptr)
        {
            delete results;
            break;
        }
    }

    //  if there was no failure
    if (generatedResponce == nullptr)
        generatedResponce = &generate_responce(SUCCESS, generate_mfr_ul_bulk_operation_payload(*results));

    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_auth_on_clear_key(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_auth_on_clear_key]...\n\n";

    auto mfrAuth = mifareMessage.mfr_ul_auth_on_clear_key();
    auto storedToken = &myDevice.get_stored_token();

    const Msg *generatedResponce = nullptr;
    auto card = myDevice.get_card_in_field();

    if (storedToken->type() != contactless::token_type::MIFARE_UL_OR_ULC)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Wrong token type"));
    }
    else if (dynamic_cast<MifareUltralightCard *>(card)->get_type() != MifareUltralightCard::m_C)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Wrong type of Mfr UL"));
    }
    else
    {
        if (dynamic_cast<MfrUl_C_Card *>(card)->auth(mfrAuth.clear_key()))
        {
            std::cout << "Authenticated successfully" << std::endl;
            generatedResponce = &generate_responce(SUCCESS);
        }
        else
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Wrong clear key"));
    }
    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_auth_on_sam_key(const Mifare &mifareMessage, Device &myDevice)
{
    std::string errorMessage("Command [mfr_ul_auth_on_sam_key] of module [Mifare] is not supported. MSG_ID: " + std::to_string(this->msgID));
    const Msg &generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage));
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_auth_clear_password(const Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_ul_auth_clear_password]...\n\n";

    auto mfrAuth = mifareMessage.mfr_ul_auth_clear_password();
    auto storedToken = &myDevice.get_stored_token();

    const Msg *generatedResponce = nullptr;
    auto card = dynamic_cast<MifareUltralightCard *>(myDevice.get_card_in_field());

    if (storedToken->type() != contactless::token_type::MIFARE_UL_OR_ULC)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Wrong token type"));
    }
    else if (card->get_type() != MifareUltralightCard::m_EV1)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Wrong type of Mfr UL"));
    }
    else
    {
        card->auth(mfrAuth.password());

        auto packStr = dynamic_cast<MfrUl_EV1_Card *>(card)->get_pack_str();
        if (packStr.empty())
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MIFARE_CARD_NOT_ACKNOWLEDGE_COMMAND, "Wrong password"));
        else
        {
            std::cout << "Authenticated successfully" << std::endl;
            generatedResponce = &generate_responce(SUCCESS, generate_mfr_ul_auth_clear_password_payload(packStr));
        }
    }
    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    return *generatedResponce;
}

const Msg &MessageIR::execute_mfr_ul_auth_sam_password(const Mifare &mifareMessage, Device &myDevice)
{
    std::string errorMessage("Command [mfr_ul_auth_sam_password] of module [Mifare] is not supported. MSG_ID: " + std::to_string(this->msgID));
    const Msg &generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage));
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return generatedResponce;
}

const Payload &MessageIR::generate_failure_payload(common::failure::Error errorType, const std::string errorString)
{
    auto failureResponce = new common::failure::FailureResponse();
    failureResponce->set_error(errorType);
    if (!errorString.empty())
        failureResponce->set_error_string(errorString);

    Payload *generatedPayload = new Payload(failureResponce);
    // Payload &generatedPayload = *(new Payload(failureResponce));

    return *generatedPayload;
}

const Payload &MessageIR::generate_log_notification_payload(common::notification::LogMessage_Importance importance, const std::string msgString)
{
    auto notifyResponce = new common::notification::LogMessage();
    notifyResponce->set_level(importance);
    if (!msgString.empty())
        notifyResponce->set_msg(msgString);

    Payload &generatedPayload = *(new Payload(notifyResponce));

    return generatedPayload;
}

const Payload &MessageIR::generate_user_notification_payload(common::notification::UserMessage_MessageId id)
{
    auto notifyResponce = new common::notification::UserMessage();
    notifyResponce->set_message_id(id);

    Payload &generatedPayload = *(new Payload(notifyResponce));

    return generatedPayload;
}

const Payload &MessageIR::generate_device_info_payload(Device &myDevice)
{
    auto deviceInfo = new misc::device::DeviceInfo();

    deviceInfo->set_serial_number(myDevice.get_device_info().get_serial_number());
    deviceInfo->set_intellireader_version(myDevice.get_device_info().get_IR_version());

    Payload &generatedPayload = *(new Payload(deviceInfo));

    return generatedPayload;
}

const Payload &MessageIR::generate_device_status_payload(Device &myDevice)
{
    auto deviceStatus = new misc::device::DeviceStatus();

    deviceStatus->set_time_left_to_restart(myDevice.get_device_status().get_time_to_restart());
    auto newSecurity = new misc::device::Security(myDevice.get_device_status().get_security());
    deviceStatus->set_allocated_security(newSecurity);

    Payload &generatedPayload = *(new Payload(deviceStatus));

    return generatedPayload;
}

const Payload &MessageIR::generate_device_statistic_payload(Device &myDevice)
{
    auto deviceStatistic = new misc::stats::DeviceStatistic(myDevice.get_device_statistic());

    Payload &generatedPayload = *(new Payload(deviceStatistic));

    return generatedPayload;
}

const Payload &MessageIR::generate_echo_payload(uint32_t replySize, const std::string &data)
{
    auto echo = new misc::echo::Echo();
    echo->set_echo(data.substr(0, replySize));

    Payload &generatedPayload = *(new Payload(echo));

    return generatedPayload;
}

const Payload &MessageIR::generate_lan_settings_payload(Device &myDevice)
{
    auto lanSettings = new misc::lan_settings::LanSettings(myDevice.get_lan_settings());

    Payload &generatedPayload = *(new Payload(lanSettings));
    return generatedPayload;
}

// const Payload &MessageIR::generate_power_on_payload(Device &myDevice)
// {
//     auto contactCard = new contact::power_on::ContactCard();

//     contactCard->set_historical_bytes(myDevice.get_card_in_slot().get_historical_bytes());

//     std::cout << "Historical bytes:" << std::endl
//               << contactCard->DebugString() << std::endl;

//     std::vector<uint8_t> buf;
//     buf.resize(contactCard->ByteSizeLong());
//     int buf_size = buf.size();
//     contactCard->SerializeToArray(buf.data(), buf_size);

//     Payload &generatedPayload = *(new Payload(contactCard->DebugString(), buf));
//     return generatedPayload;
// }

// const Payload &MessageIR::generate_transmit_apdu_payload(const ContactCard &card)
// {
//     auto responceApdu = new contact::iso7816_4::ResponseApdu();

//     responceApdu->set_trailer(card.get_expected_apdu_trailer());
//     responceApdu->set_body(card.get_expected_responce_body());

//     std::cout << "Apdu responce: " << std::endl
//               << responceApdu->DebugString() << std::endl;

//     std::vector<uint8_t> buf;
//     buf.resize(responceApdu->ByteSizeLong());
//     int buf_size = buf.size();
//     responceApdu->SerializeToArray(buf.data(), buf_size);

//     Payload &generatedPayload = *(new Payload(responceApdu->DebugString(), buf));
//     return generatedPayload;
// }

const Payload &MessageIR::generate_poll_for_token_payload(Device &myDevice, bool preferMifare)
{
    auto responcePFT = new contactless::token::Token(*myDevice.get_card_in_field()->get_card_token());

    if (responcePFT->type() == contactless::token_type::SMART_MX_WITH_MIFARE_1K ||
        responcePFT->type() == contactless::token_type::SMART_MX_WITH_MIFARE_4K)
    {
        delete responcePFT;
        if (preferMifare)
            responcePFT = new contactless::token::Token(*(dynamic_cast<const SmartWithMifareCard *>(myDevice.get_card_in_field()))->get_mifare_token().get_card_token());
        else
            responcePFT = new contactless::token::Token(*(dynamic_cast<const SmartWithMifareCard *>(myDevice.get_card_in_field()))->get_iso_token().get_card_token());
    }

    myDevice.store_token(*responcePFT);

    Payload &generatedPayload = *(new Payload(responcePFT));

    return generatedPayload;
}

const Payload &MessageIR::generate_stored_poll_for_token_payload(Device &myDevice)
{
    auto storedToken = new contactless::token::Token(myDevice.get_stored_token());

    Payload &generatedPayload = *(new Payload(storedToken));

    return generatedPayload;
}

const Payload &MessageIR::generate_perform_transaction_payload(Device &myDevice, bool preferMifare)
{
    auto transactionResult = new contactless::transaction::TransactionResult();

    transactionResult->set_status(contactless::transaction::ONLINE_AUTHORIZATION_REQUIRED); // don't know what status to choose

    auto newToken = new contactless::token::Token(*myDevice.get_card_in_field()->get_card_token());

    //  if it is double card, get one of its tokens
    if (newToken->type() == contactless::token_type::SMART_MX_WITH_MIFARE_1K ||
        newToken->type() == contactless::token_type::SMART_MX_WITH_MIFARE_4K)
    {
        delete newToken;
        if (preferMifare)
            newToken = new contactless::token::Token(*(dynamic_cast<const SmartWithMifareCard *>(myDevice.get_card_in_field()))->get_mifare_token().get_card_token());
        else
            newToken = new contactless::token::Token(*(dynamic_cast<const SmartWithMifareCard *>(myDevice.get_card_in_field()))->get_iso_token().get_card_token());
    }
    transactionResult->set_allocated_token(newToken);

    // some emv tags
    auto newEmvTag1 = transactionResult->add_emv_tags();
    newEmvTag1->set_number(0x9F35);
    auto newEmvTag2 = transactionResult->add_emv_tags();
    newEmvTag2->set_number(0x9F21);

    if (false)
        transactionResult->set_last_cmd("last cmd sent to the cart");
    if (false)
        transactionResult->set_last_sw_bytes("sw bytes");
    if (transactionResult->status() == contactless::transaction::NON_EMV_CARD)
        transactionResult->set_error_reason("error reason: non emv card");
    if (transactionResult->status() == contactless::transaction::UNABLE_PERFORM_TRANSACTION)
        transactionResult->set_error_reason("error reason: unable to perform transaction");
    if (false)
        transactionResult->set_encrypted_sensitive_data("some sensitive data");

    Payload &generatedPayload = *(new Payload(transactionResult));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_classic_read_blocks_payload(std::string &data)
{
    auto blocks = new mifare::classic::read::Blocks;

    blocks->set_data(data);

    Payload &generatedPayload = *(new Payload(blocks));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_classic_get_counter_payload(int32_t counterValue)
{
    auto getCounter = new mifare::classic::counter::get::Counter();
    getCounter->set_value(counterValue);

    Payload &generatedPayload = *(new Payload(getCounter));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_classic_bulk_operation_payload(mifare::classic::bulk::BulkResult &results)
{
    Payload &generatedPayload = *(new Payload(&results));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_ul_read_pages_payload(std::string &newData)
{
    auto pages = new mifare::ultralight::read::Pages();
    pages->set_data(newData);

    Payload &generatedPayload = *(new Payload(pages));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_ul_get_counter_payload(uint32_t counterValue)
{
    auto counterResponce = new mifare::ultralight::counter::get::CounterValue();
    counterResponce->set_value(counterValue);

    Payload &generatedPayload = *(new Payload(counterResponce));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_ul_get_version_payload(const std::string &version)
{
    auto getVersion = new mifare::ultralight::version::Version();
    getVersion->set_raw_version_data(version);

    Payload &generatedPayload = *(new Payload(getVersion));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_ul_auth_clear_password_payload(const std::string &newPack)
{
    auto pack = new mifare::ultralight::password::PasswordAcknowledge();
    pack->set_password_ack(newPack);

    Payload &generatedPayload = *(new Payload(pack));

    return generatedPayload;
}

const Payload &MessageIR::generate_mfr_ul_bulk_operation_payload(mifare::ultralight::bulk::BulkResult &results)
{
    Payload &generatedPayload = *(new Payload(&results));

    return generatedPayload;
}

const Msg &MessageIR::generate_responce(uint8_t responseType, const Payload &generatedPayload /* = Payload()*/)
{
    std::vector<uint8_t> buf;
    // 2. Append the IntelliReader header into the buffer:
    buf.push_back(0x49); // add 'I'
    buf.push_back(0x52); // add 'R'

    const uint16_t kHeaderLen = 3; // msg_id (1 byte) + module (1 byte) + type (1 byte)
    uint16_t payload_size = generatedPayload.get_data().size();
    uint16_t msg_len = kHeaderLen + payload_size;
    append_big_endian(buf, msg_len);

    uint8_t newMsgID,
        newModuleID,
        newMessageType;

    if (NOTIFICATION == responseType)
    {
        newMsgID = 0;
        newModuleID = 0;
    }
    else
    {
        newMsgID = this->msgID;
        newModuleID = this->moduleID;
    }

    bool isFailure = false;
    switch (responseType)
    {
    case SUCCESS: // Success
        newMessageType = SUCCESS;
        break;
    case FAILURE: // Failure
        newMessageType = FAILURE;
        isFailure = true;
        break;
    case PENDING: // Pending
        newMessageType = PENDING;
        break;
    case NOTIFICATION:
        newMessageType = NOTIFICATION;
        break;
    default: // Command, Control or unrecognised
        throw new std::invalid_argument(std::string("Cannot create responce message with type ID 0x" + responseType));
    }

    buf.push_back(newMsgID);
    buf.push_back(newModuleID);
    buf.push_back(newMessageType);

    buf.insert(buf.end(), generatedPayload.get_data().begin(), generatedPayload.get_data().end());
    uint16_t crc = crc::calcCrc16(buf);
    append_big_endian(buf, crc);

    return *(new Msg(generatedPayload, buf, isFailure));
}

void MessageIR::append_big_endian(std::vector<uint8_t> &buf, uint16_t n)
{
    buf.push_back((n & 0xFF00) >> 8); // добавили старший разряд
    buf.push_back(n & 0xFF);          // добавили младший разряд
}
