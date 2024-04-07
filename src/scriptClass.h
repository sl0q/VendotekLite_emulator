#pragma once

#include <iostream>
#include <vector>
#include <string>

class Device;

#include "messageClass.h"
#include "deviceClass.h"
#include "cards.h"

class Script
{
private:
    std::string title = "Untitled script";
    std::vector<Action> actions;
    std::vector<std::string> messages;
    ContactCard *contactCard;
    std::vector<ContactlessCard *> cardsInFiled; // Contactless cards in RF field of the terminal

public:
    Script();
    Script(std::string new_title);
    Script(std::string new_title, std::vector<std::string> new_messages);
    ~Script();

    const std::string toString(); // return script data as a string to print

    void setTitle(std::string newTitle);
    const std::string getTitle();
    void addMessage(std::string newMessage);
    const std::vector<std::string> getMessages();

    void set_contact_card(ContactCard *newContactCard);
    void add_contactless_card(ContactlessCard *newContactlessCard);

    void execute_script(Device &myDevice);
    // void deserializeMessage();
};

enum ActionType
{
    INSERT_CONTATC_CARD = 1,
    REMOVE_CCONTACT_ARD = 2,
    ATTACH_CONTACTLESS_CARD = 3,
    REMOVE_CONTACTLESS_CARD = 4,
    SEND_MESSAGES = 5,
    WAIT_MS = 6
};

class Action
{
private:
    ActionType actionType;

public:
    Action();
    Action(ActionType newActionType);
    
};
