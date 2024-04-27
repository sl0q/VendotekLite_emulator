#pragma once

#include <iostream>

#include "deviceClass.h"

enum ActionType
{
    UNKNOWN = 1,
    ATTACH_CARD = 4,
    REMOVE_CARD = 5,
    SEND_CANCEL_MESSAGE = 6,
    EXE_MESSAGES = 7,
    WAIT_MS = 8
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

    virtual bool make_action(Device &myDevice) = 0;
    virtual const std::string str() const = 0;
};

////////////////////////////////////////////////////////////////////////

class CardAttacher : public Action
{
private:
    uint32_t cardToAttachID;

public:
    CardAttacher(uint32_t cardID);
    // CLCardAttacher(const ContactlessCard &newCard);
    bool make_action(Device &myDevice);
    void set_card_to_attach(uint32_t cardID);
    const std::string str() const;
};

/////////////////////////////////////////////////////////////////////////////

class CardRemover : public Action
{
private:
    uint32_t cardToRemoveID;

public:
    CardRemover(uint32_t cardID);
    bool make_action(Device &myDevice);
    void set_card_to_remove(uint32_t cardID);
    const std::string str() const;
};

/////////////////////////////////////////////////////////////////////////////////

class Canceller : public Action
{
private:
    std::string cancelMessage;

public:
    Canceller();
    Canceller(const std::string newCancelMessage);
    ~Canceller();
    void set_cancel_message(const std::string newCancelMessage);
    bool make_action(Device &myDevice);
    const std::string str() const;
};

/////////////////////////////////////////////////////////////////////////////////

// class MessageExecuter : public Action
// {
// private:
//     std::vector<std::string> *messages;

// public:
//     MessageExecuter();
//     MessageExecuter(std::vector<std::string> &newMessages);

//     void make_action(Device &myDevice);
//     void add_message(std::string newMessage);
//     const std::string str();
// };

// /////////////////////////////////////////////////////////////////////////////////

// class Waiter : public Action
// {
// private:
//     uint32_t timeToWait_ms{};

// public:
//     Waiter(uint32_t timeToWait_ms);
//     void make_action(Device &myDevice);
//     const std::string str();
// };