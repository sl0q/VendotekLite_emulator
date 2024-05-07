#include "actionClass.h"

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
        // auto msgBytes = bc::base64_decode(this->cancelMessage);
        auto msgBytes = bc::hex_string_decode(this->cancelMessage);

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
