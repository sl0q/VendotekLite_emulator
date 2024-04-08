#include "scriptClass.h"

Script::Script()
{
}

Script::Script(std::string new_title)
{
    this->title = new_title;
    this->contactCard = nullptr;
}

// Script::Script(std::string new_title, std::vector<std::string> new_messages)
// {
//     this->title = new_title;
//     this->messages = new_messages;
// }

Script::~Script()
{
    if (this->contactCard != nullptr)
        delete this->contactCard;
    for (auto contactlessCard : this->cardsInFiled)
        if (contactlessCard != nullptr)
            delete contactlessCard;
    this->cardsInFiled.clear();
    for (auto &action : actions)
        if (action != nullptr)
            delete action;
}

void Script::setTitle(std::string newTitle)
{
    this->title = newTitle;
}

const std::string Script::getTitle()
{
    return this->title;
}

// void Script::addMessage(std::string newMessage)
// {
//     this->messages.push_back(newMessage);
// }

// const std::vector<std::string> Script::getMessages()
// {
//     return this->messages;
// }

void Script::set_contact_card(ContactCard *newContactCard)
{
    this->contactCard = newContactCard;
}

void Script::add_contactless_card(ContactlessCard *newContactlessCard)
{
    this->cardsInFiled.push_back(newContactlessCard);
}

void Script::add_action(Action *newAction)
{
    this->actions.push_back(newAction);
}

const ContactlessCard *Script::find_cl_card(const std::string cardID)
{
    for (auto &clCard : this->cardsInFiled)
        if (cardID == clCard->get_id())
            return clCard;
    return nullptr;
}

const ContactCard &Script::get_contact_card()
{
    return *this->contactCard;
}

const std::string Script::str()
{
    std::string s("Title: " + this->title + "\n" +
                  "Contact card:\n" + this->contactCard->str() + "\n" +
                  "Contactless cards:\n");
    for (auto &contactlessCard : this->cardsInFiled)
        s += "\t" + contactlessCard->str() + "\n";
    s += "Actions:\n";
    for (auto &action : this->actions)
        s += "\t" + action->str() + "\n";

    return s;
}

void Script::execute_script(Device &myDevice)
{
    std::cout << "Starting to execute [" << this->title << "]..." << std::endl;

    for (auto &action : this->actions)
    {
        std::cout << "Making action:\n"
                  << action->str() << std::endl;
        action->make_action(myDevice);
    }

    // for (std::string &strMessage : this->messages)
    // {
    //     MessageIR currentMessage(strMessage);
    //     if (currentMessage.is_command())
    //         currentMessage.execute_message(myDevice);
    // }

    std::cout << "Script [" << this->title << "] has been executed.\n\n";
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

CCardInserter::CCardInserter(const ContactCard &newCard)
{
    this->actionType = INSERT_CONTATC_CARD;
    this->cardToInsert = &newCard;
}

// CCardInserter::CCardInserter(const ContactCard &newCard)
// {
//     this->cardToInsert = &newCard;
// }

void CCardInserter::make_action(Device &myDevice)
{
    if (this->cardToInsert != nullptr)
        myDevice.insert_contact_card(*this->cardToInsert);
}

const std::string CCardInserter::str()
{
    return std::string("Insert contact card in card reader slot");
}

CCardRemover::CCardRemover()
{
    this->actionType = REMOVE_CONTACT_CARD;
}

void CCardRemover::make_action(Device &myDevice)
{
    myDevice.remove_contact_card();
}

const std::string CCardRemover::str()
{
    return std::string("Remove contact card from card reader slot");
}

// CLCardAttacher::CLCardAttacher(const ContactlessCard &newCard)
// {
//     this->cardToAttach = &newCard;
// }

CLCardAttacher::CLCardAttacher(const ContactlessCard &newCard)
{
    this->actionType = ATTACH_CONTACTLESS_CARD;
    this->cardToAttach = &newCard;
}

void CLCardAttacher::make_action(Device &myDevice)
{
    myDevice.attach_contactless_card(*this->cardToAttach);
}

void CLCardAttacher::set_card_to_attach(const ContactlessCard &newCard)
{
    this->cardToAttach = &newCard;
}

const std::string CLCardAttacher::str()
{
    return std::string("Attach card with id " + cardToAttach->get_id() + " to card reader RF-field");
}

// CLCardRemover::CLCardRemover(const ContactlessCard &newCard)
// {
//     this->cardToRemove = &newCard;
// }

CLCardRemover::CLCardRemover(const ContactlessCard &cardToRemove)
{
    this->actionType = REMOVE_CONTACTLESS_CARD;
    this->cardToRemove = &cardToRemove;
}

void CLCardRemover::make_action(Device &myDevice)
{
    myDevice.remove_contactless_card(*this->cardToRemove);
}

void CLCardRemover::set_card_to_remove(const ContactlessCard &newCard)
{
    this->cardToRemove = &newCard;
}

const std::string CLCardRemover::str()
{
    return std::string("Remove card with id " + cardToRemove->get_id() + " from card reader RF-field");
}

MessageExecuter::MessageExecuter()
{
    this->actionType = EXE_MESSAGES;
}

MessageExecuter::MessageExecuter(std::vector<std::string> &newMessages)
{
    this->actionType = EXE_MESSAGES;
    this->messages = &newMessages;
}

void MessageExecuter::make_action(Device &myDevice)
{
    for (std::string &strMessage : *this->messages)
    {
        MessageIR currentMessage(strMessage);
        if (currentMessage.is_command())
            currentMessage.execute_message(myDevice);
    }
}

void MessageExecuter::add_message(std::string newMessage)
{
    this->messages->push_back(newMessage);
}

const std::string MessageExecuter::str()
{
    std::string s("Encoded messages to execute:\n");
    for (auto &m : *this->messages)
        s += "\t" + m + "\n";
    s.pop_back(); // delete last \n
    return s;
}

Waiter::Waiter(uint32_t timeToWait_ms)
{
    this->actionType = WAIT_MS;
    this->timeToWait_ms = timeToWait_ms;
}

void Waiter::make_action(Device &myDevice)
{
    myDevice.wait(this->timeToWait_ms);
}

const std::string Waiter::str()
{
    return std::string("Wait for " + std::to_string(this->timeToWait_ms) + " ms");
}
