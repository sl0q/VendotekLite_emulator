#pragma once

#include <iostream>
#include <vector>
#include <string>

class Device;
class Action;
class CCardInserter;
class CCardRemover;
class CLCardAttacher;
class CLCardRemover;
class MessageExecuter;
class Waiter;

#include "messageClass.h"
#include "deviceClass.h"
#include "cards.h"

class Script
{
private:
    std::string title = "Untitled script";
    std::vector<Action *> actions;
    // std::vector<std::string> messages;
    ContactCard *contactCard;
    std::vector<ContactlessCard *> cardsInFiled; // Contactless cards in RF field of the terminal

public:
    Script();
    Script(std::string new_title);
    // Script(std::string new_title, std::vector<std::string> new_messages);
    ~Script();

    const std::string str(); // return script data as a string to print

    void setTitle(std::string newTitle);
    const std::string getTitle();
    // void addMessage(std::string newMessage);
    // const std::vector<std::string> getMessages();

    void set_contact_card(ContactCard *newContactCard);
    void add_contactless_card(ContactlessCard *newContactlessCard);
    void add_action(Action *newAction);

    const ContactlessCard *find_cl_card(const std::string cardID);
    const ContactCard &get_contact_card();

    void execute_script(Device &myDevice);
    // void deserializeMessage();
};
/////////////////////////////////////////////////////////////

enum ActionType
{
    UNKNOWN = 1,
    INSERT_CONTATC_CARD = 2,
    REMOVE_CONTACT_CARD = 3,
    ATTACH_CONTACTLESS_CARD = 4,
    REMOVE_CONTACTLESS_CARD = 5,
    EXE_MESSAGES = 6,
    WAIT_MS = 7
};

///////////////////////////////////////////////////////////////////////

class Action
{
protected:
    ActionType actionType;

public:
    Action();
    explicit Action(ActionType newActionType);

    const ActionType get_type() const;

    virtual void make_action(Device &myDevice) = 0;
    virtual const std::string str() = 0;
};

/////////////////////////////////////////////////////////////////

class CCardInserter : public Action
{
private:
    const ContactCard *cardToInsert;

public:
    CCardInserter(const ContactCard &newCard);
    // CCardInserter(const ContactCard &newCard);
    void make_action(Device &myDevice);
    const std::string str();
};

////////////////////////////////////////////////////////////////////////

class CCardRemover : public Action
{
public:
    CCardRemover();
    void make_action(Device &myDevice);
    const std::string str();
};

////////////////////////////////////////////////////////////////////////

class CLCardAttacher : public Action
{
private:
    const ContactlessCard *cardToAttach;

public:
    CLCardAttacher(const ContactlessCard &newCard);
    // CLCardAttacher(const ContactlessCard &newCard);
    void make_action(Device &myDevice);
    void set_card_to_attach(const ContactlessCard &newCard);
    const std::string str();
};

/////////////////////////////////////////////////////////////////////////////

class CLCardRemover : public Action
{
private:
    const ContactlessCard *cardToRemove;

public:
    CLCardRemover(const ContactlessCard &cardToRemove);
    // CLCardRemover(const ContactlessCard &newCard);
    void make_action(Device &myDevice);
    void set_card_to_remove(const ContactlessCard &cardToRemove);
    const std::string str();
};

/////////////////////////////////////////////////////////////////////////////////

class MessageExecuter : public Action
{
private:
    std::vector<std::string> *messages;

public:
    MessageExecuter();
    MessageExecuter(std::vector<std::string> &newMessages);

    void make_action(Device &myDevice);
    void add_message(std::string newMessage);
    const std::string str();
};

/////////////////////////////////////////////////////////////////////////////////

class Waiter : public Action
{
private:
    uint32_t timeToWait_ms{};

public:
    Waiter(uint32_t timeToWait_ms);
    void make_action(Device &myDevice);
    const std::string str();
};