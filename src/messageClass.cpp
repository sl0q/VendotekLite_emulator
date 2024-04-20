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

    for (auto &preaction : this->preactions)
        if (preaction)
            delete preaction;
    this->preactions.clear();

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
    for (auto &preaction : this->preactions)
    {
        preaction->make_action(myDevice);
        std::cout << "Action {" << preaction->str() << "} was made\n";
    }

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

void MessageIR::add_preaction(Action &newPreaction)
{
    this->preactions.push_back(&newPreaction);
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
    bool res;
    Mifare mifareMessage = *(dynamic_cast<Mifare *>(this->msg));
    switch (mifareMessage.mifare_cmd_case())
    {
    case Mifare::kMfrClassicAuthOnClearKey:
        res = execute_mfr_classic_auth_on_clear_key(mifareMessage, myDevice);
        break;
    case Mifare::kMfrClassicAuthOnSamKey:
        res = execute_mfr_classic_auth_on_sam_key(mifareMessage, myDevice);
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

    return res;
}

bool MessageIR::execute_mfr_classic_auth_on_clear_key(Mifare &mifareMessage, Device &myDevice)
{
    std::cout << "Executing [mfr_classic_auth_on_clear_key]...\n\n";

    bool res;
    auto mfrAuth = mifareMessage.mfr_classic_auth_on_clear_key();
    auto storedToken = &myDevice.get_stored_token();

    const Msg *generatedResponce = nullptr;

    if (storedToken->type() != contactless::token_type::MIFARE_CLASSIC_1K &&
        storedToken->type() != contactless::token_type::MIFARE_CLASSIC_2K &&
        storedToken->type() != contactless::token_type::MIFARE_CLASSIC_4K &&
        storedToken->type() != contactless::token_type::MIFARE_CLASSIC_MINI)
    {
        generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Wrong token type"));
        res = false;
    }
    else
    {
        auto card = myDevice.get_card_in_field();

        switch (mfrAuth.key_type())
        {
        case mifare::classic::auth::TYPE_A:
            if (dynamic_cast<const MifareClassicCard *>(card)->get_clear_key_A().clear_key() != mfrAuth.clear_key())
            {
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Mismatch of clear key type_a"));
                res = false;
            }
            else
            {
                generatedResponce = &generate_responce(SUCCESS);
                res = true;
            }
            break;
        case mifare::classic::auth::TYPE_B:
            if (dynamic_cast<const MifareClassicCard *>(card)->get_clear_key_B().clear_key() != mfrAuth.clear_key())
            {
                generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Mismatch of clear key type_b"));
                res = false;
            }
            else
            {
                generatedResponce = &generate_responce(SUCCESS);
                res = true;
            }
            break;
        default:
            generatedResponce = &generate_responce(FAILURE, generate_failure_payload(common::failure::MFC_AUTHENTICATION_ERROR, "Unknown key type"));
            res = false;
        }
    }
    std::cout << "Finised execution.\n\n";

    std::cout << "Generated responce:" << std::endl;
    generatedResponce->print_MSG();

    delete generatedResponce;

    return res;
}

bool MessageIR::execute_mfr_classic_auth_on_sam_key(Mifare &mifareMessage, Device &myDevice)
{
    std::string errorMessage("Command [mfr_classic_auth_on_sam_key] of module [Mifare] is not supported. MSG_ID: " + std::to_string(this->msgID));
    Msg generatedResponce = generate_responce(FAILURE, generate_failure_payload(common::failure::UNSUPPORTED_COMMAND, errorMessage));
    std::cout << "Generated responce:" << std::endl;
    generatedResponce.print_MSG();

    return false;
}

const Payload &MessageIR::generate_failure_payload(common::failure::Error errorType, const std::string errorString)
{
    auto failureResponce = new common::failure::FailureResponse();
    failureResponce->set_error(errorType);
    if (!errorString.empty())
        failureResponce->set_error_string(errorString);

    std::vector<uint8_t> buf;
    buf.resize(failureResponce->ByteSizeLong());
    int buf_size = buf.size();
    failureResponce->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(failureResponce->DebugString(), buf));

    delete failureResponce;

    return generatedPayload;
}

const Payload &MessageIR::generate_log_notification_payload(common::notification::LogMessage_Importance importance, const std::string msgString)
{
    auto notifyResponce = new common::notification::LogMessage();
    notifyResponce->set_level(importance);
    if (!msgString.empty())
        notifyResponce->set_msg(msgString);

    std::vector<uint8_t> buf;
    buf.resize(notifyResponce->ByteSizeLong());
    int buf_size = buf.size();
    notifyResponce->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(notifyResponce->DebugString(), buf));

    delete notifyResponce;

    return generatedPayload;
}

const Payload &MessageIR::generate_user_notification_payload(common::notification::UserMessage_MessageId id)
{
    auto notifyResponce = new common::notification::UserMessage();
    notifyResponce->set_message_id(id);

    std::vector<uint8_t> buf;
    buf.resize(notifyResponce->ByteSizeLong());
    int buf_size = buf.size();
    notifyResponce->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(notifyResponce->DebugString(), buf));

    delete notifyResponce;

    return generatedPayload;
}

const Payload &MessageIR::generate_device_info_payload(Device &myDevice)
{
    std::vector<uint8_t> buf;
    misc::device::DeviceInfo *deviceInfo = new misc::device::DeviceInfo();

    DeviceInfoStruct deviceInfoStruct = myDevice.get_device_info();
    deviceInfo->set_serial_number(deviceInfoStruct.serialNumber);
    deviceInfo->set_intellireader_version(deviceInfoStruct.intellireaderVersion);

    buf.resize(deviceInfo->ByteSizeLong());
    int buf_size = buf.size();
    deviceInfo->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(deviceInfo->DebugString(), buf));

    delete deviceInfo;

    return generatedPayload;
}

const Payload &MessageIR::generate_device_status_payload(Device &myDevice)
{
    misc::device::DeviceStatus *deviceStatus = new misc::device::DeviceStatus();

    DeviceStatusStruct deviceStatusStruct = myDevice.get_device_status();
    deviceStatus->set_time_left_to_restart(deviceStatusStruct.timeToRestart);
    deviceStatus->set_allocated_security(&(deviceStatusStruct.security));

    std::cout << "Device status:" << std::endl
              << deviceStatus->DebugString() << std::endl;

    std::vector<uint8_t> buf;
    buf.resize(deviceStatus->ByteSizeLong());
    int buf_size = buf.size();
    deviceStatus->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(deviceStatus->DebugString(), buf));

    delete deviceStatus;

    return generatedPayload;
}

const Payload &MessageIR::generate_device_statistic_payload(Device &myDevice)
{
    auto deviceStatistic = myDevice.get_device_statistic();

    std::cout << "Device statistic:" << std::endl
              << deviceStatistic.DebugString() << std::endl;

    std::vector<uint8_t> buf;
    buf.resize(deviceStatistic.ByteSizeLong());
    int buf_size = buf.size();
    deviceStatistic.SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(deviceStatistic.DebugString(), buf));
    return generatedPayload;
}

const Payload &MessageIR::generate_echo_payload(uint32_t replySize, const std::string &data)
{
    misc::echo::Echo echo;
    echo.set_echo(data.substr(0, replySize));

    std::cout << "Echo reply:" << std::endl
              << echo.DebugString() << std::endl;

    std::vector<uint8_t> buf;
    buf.resize(echo.ByteSizeLong());
    int buf_size = buf.size();
    echo.SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(echo.DebugString(), buf));
    return generatedPayload;
}

const Payload &MessageIR::generate_lan_settings_payload(Device &myDevice)
{
    const misc::lan_settings::LanSettings &lanSettings = myDevice.get_lan_settings();
    std::cout << "Lan settings:" << std::endl
              << lanSettings.DebugString() << std::endl;

    std::vector<uint8_t> buf;
    buf.resize(lanSettings.ByteSizeLong());
    int buf_size = buf.size();
    lanSettings.SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(lanSettings.DebugString(), buf));
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
    auto responcePFT = myDevice.get_card_in_field()->get_card_token();

    if (responcePFT->type() == contactless::token_type::SMART_MX_WITH_MIFARE_1K ||
        responcePFT->type() == contactless::token_type::SMART_MX_WITH_MIFARE_4K)
    {
        if (preferMifare)
            responcePFT = (dynamic_cast<const SmartWithMifareCard *>(myDevice.get_card_in_field()))->get_mifare_token().get_card_token();
        else
            responcePFT = (dynamic_cast<const SmartWithMifareCard *>(myDevice.get_card_in_field()))->get_iso_token().get_card_token();
    }

    myDevice.store_token(*responcePFT);

    std::vector<uint8_t> buf;
    buf.resize(responcePFT->ByteSizeLong());
    int buf_size = buf.size();
    responcePFT->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(responcePFT->DebugString(), buf));

    return generatedPayload;
}

const Payload &MessageIR::generate_stored_poll_for_token_payload(Device &myDevice)
{
    auto storedToken = &myDevice.get_stored_token();

    std::vector<uint8_t> buf;
    buf.resize(storedToken->ByteSizeLong());
    int buf_size = buf.size();
    storedToken->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(storedToken->DebugString(), buf));

    return generatedPayload;
}

const Payload &MessageIR::generate_perform_transaction_payload(Device &myDevice, bool preferMifare)
{
    auto transactionResult = new contactless::transaction::TransactionResult();

    transactionResult->set_status(contactless::transaction::ONLINE_AUTHORIZATION_REQUIRED); // don't know what status to choose

    auto newToken = new contactless::token::Token(*myDevice.get_card_in_field()->get_card_token());
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

    std::vector<uint8_t> buf;
    buf.resize(transactionResult->ByteSizeLong());
    int buf_size = buf.size();
    transactionResult->SerializeToArray(buf.data(), buf_size);

    Payload &generatedPayload = *(new Payload(transactionResult->DebugString(), buf));

    // delete newToken;
    delete transactionResult;

    return generatedPayload;
}

const Msg &MessageIR::generate_responce(uint8_t responseType, const Payload &generatedPayload /* = Payload()*/)
{
    std::vector<uint8_t> buf;
    // 2. Append the IntelliReader header into the buffer:
    buf.push_back(0x49); // add 'I'
    buf.push_back(0x52); // add 'R'

    const uint16_t kHeaderLen = 3; // msg_id (1 byte) + module (1 byte) + type (1 byte)
    uint16_t payload_size = generatedPayload.getData().size();
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

    switch (responseType)
    {
    case SUCCESS: // Success
        newMessageType = SUCCESS;
        break;
    case FAILURE: // Failure
        newMessageType = FAILURE;
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

    buf.insert(buf.end(), generatedPayload.getData().begin(), generatedPayload.getData().end());
    uint16_t crc = crc::calcCrc16(buf);
    append_big_endian(buf, crc);

    return *(new Msg(generatedPayload.getDebugString(), buf));
}

void MessageIR::append_big_endian(std::vector<uint8_t> &buf, uint16_t n)
{
    buf.push_back((n & 0xFF00) >> 8); // добавили старший разряд
    buf.push_back(n & 0xFF);          // добавили младший разряд
}

/////////////////////////////////////////////////////////////////////////

Action::Action()
{
}

Action::Action(ActionType newActionType)
{
    this->actionType = newActionType;
}

const ActionType Action::get_type() const
{
    return this->actionType;
}

// void Action::make_action(Device &myDevice)
// {
//     switch(this->actionType)
//     {
//         case INSERT_CONTATC_CARD:
//             myDevice.insert_contact_card()
//     }
// }

CardAttacher::CardAttacher(uint32_t cardID)
{
    this->actionType = ATTACH_CARD;
    this->cardToAttachID = cardID;
}

bool CardAttacher::make_action(Device &myDevice)
{
    myDevice.attach_contactless_card(cardToAttachID);
    return true;
}

void CardAttacher::set_card_to_attach(uint32_t cardID)
{
    this->cardToAttachID = cardID;
}

const std::string CardAttacher::str() const
{
    return std::string("Attach card with id " + std::to_string(cardToAttachID) + " to card reader RF-field");
}

CardRemover::CardRemover(uint32_t cardID)
{
    this->actionType = REMOVE_CARD;
    this->cardToRemoveID = cardID;
}

bool CardRemover::make_action(Device &myDevice)
{
    myDevice.remove_contactless_card(cardToRemoveID);
    return true;
}

void CardRemover::set_card_to_remove(uint32_t cardID)
{
    this->cardToRemoveID = cardID;
}

const std::string CardRemover::str() const
{
    return std::string("Remove card with id " + std::to_string(cardToRemoveID) + " from card reader RF-field");
}

Canceller::Canceller()
{
    this->actionType = SEND_CANCEL_MESSAGE;
    this->cancelMessage = "SVIAAwAABvbu"; // encoded control IR message
}

Canceller::Canceller(const std::string newCancelMessage)
{
    this->actionType = SEND_CANCEL_MESSAGE;
    this->cancelMessage = newCancelMessage;
}

Canceller::~Canceller()
{
}

void Canceller::set_cancel_message(const std::string newCancelMessage)
{
    this->cancelMessage = newCancelMessage;
}

bool Canceller::make_action(Device &myDevice)
{
    //  if encoded message was provided in script check if it's valid
    if (!this->cancelMessage.empty())
    {
        auto msgBytes = bs64::base64_decode(this->cancelMessage);

        // check header
        if (msgBytes[0] != 'I' || msgBytes[1] != 'R')
        {
            std::cout << "Provided control message has wrong IR header. The cancel command will be ignored." << std::endl;
            return false;
        }

        // check message type
        if (msgBytes[6] != 0x06)
        {
            std::cout << "Provided control message has wrong message type ID. Expected message type for control message is 0x06. The cancel command will be ignored." << std::endl;
            return false;
        }

        // check checksum
        uint16_t checksum = (*(msgBytes.end() - 2) << 8) | *(msgBytes.end() - 1);
        std::vector<uint8_t> buf;
        buf.insert(buf.begin(), msgBytes.begin(), msgBytes.end() - 2);
        // вычисляем КС и сравниваем с полученной ранее
        if (checksum != crc::calcCrc16(buf))
        {
            std::cout << "Provided control message has incorrect checksum. The cancel command will be ignored." << std::endl;
            return false;
        }
    }

    return true;
}

const std::string Canceller::str() const
{
    return std::string("Cancel current operation");
}

// MessageExecuter::MessageExecuter()
// {
// }

// MessageExecuter::MessageExecuter(std::vector<std::string> &newMessages)
// {
//     this->messages = &newMessages;
// }

// void MessageExecuter::make_action(Device &myDevice)
// {
//     for (std::string &strMessage : *this->messages)
//     {
//         MessageIR currentMessage(strMessage);
//         if (currentMessage.is_command())
//             currentMessage.execute_message(myDevice);
//     }
// }

// void MessageExecuter::add_message(std::string newMessage)
// {
//     this->messages->push_back(newMessage);
// }

// const std::string MessageExecuter::str()
// {
//     std::string s("Encoded messages to execute:\n");
//     for (auto &m : *this->messages)
//         s += "\t" + m + "\n";
//     s.pop_back(); // delete last \n
//     return s;
// }

// Waiter::Waiter(uint32_t timeToWait_ms)
// {
//     this->timeToWait_ms = timeToWait_ms;
// }

// void Waiter::make_action(Device &myDevice)
// {
//     myDevice.wait(this->timeToWait_ms);
// }

// const std::string Waiter::str()
// {
//     return std::string("Wait for " + std::to_string(this->timeToWait_ms) + " ms");
// }
