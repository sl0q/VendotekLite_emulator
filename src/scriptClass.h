#pragma once

#include <iostream>
#include <vector>
#include <string>

class Device;
class Step;
class MessageIR;
class Action;

#include "messageClass.h"
#include "deviceClass.h"
#include "cards.h"
#include "actionClass.h"

class Script
{
    using json = nlohmann::json;

private:
    static uint32_t scriptCount;
    uint32_t iScript;
    std::string title = "Untitled script";
    std::vector<Step *> steps;
    std::vector<ContactlessCard *> originalContactlessCards; // original cards images used to rewind changed cards after script is executed
    std::vector<ContactlessCard *> contactlessCards;         // Contactless cards in RF field of the terminal

public:
    Script();
    Script(std::string new_title);
    ~Script();

    const std::string str(); // return script data as a string to print

    void set_title(std::string newTitle);
    const std::string get_title();
    ContactlessCard *find_cl_card(uint32_t cardID);

    void parse_card(json cardJson);
    void parse_mifare_classic_card(json cardJson, MifareClassicCard &card);
    void parse_mifare_ultralight_card(json cardJson, MifareUltralightCard &card);
    void parse_mifare_ultralight_C_card(json cardJson, MfrUl_C_Card &card);
    void parse_mifare_ultralight_EV1_card(json cardJson, MfrUl_EV1_Card &card);
    void parse_iso_4a_card(json cardJson, Iso_4A &card);
    void parse_step(json stepJson);

    void add_contactless_card(ContactlessCard &newContactlessCard);
    void add_step(Step &newStep);

    void rewind_cards(); //  return cards in contactlessCards to default state

    void execute_script(Device &myDevice, std::ostream &logStream);
};
/////////////////////////////////////////////////////////////

class Step
{
    using json = nlohmann::json;

private:
    std::vector<Action *> preactions; // actions to do before executing aany messages on current step

    MessageIR *messageIR = nullptr;
    std::vector<MessageIR *> messagesIR;
    std::string origMsg;

public:
    Step();
    Step(const std::string newMsg);
    ~Step();
    const std::string str() const;
    void parse_preaction(json preactionJson);
    void parse_action(json actionJson);

    void set_message(const std::string newMsg);
    void add_message(const std::string newMsg);
    void add_preaction(Action &newPreaction);

    void execute_step(Device &myDevice, std::ostream &logStream);
};
