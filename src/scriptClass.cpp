#include "scriptClass.h"

uint32_t Script::scriptCount;

Script::Script()
{
    iScript = Script::scriptCount++;
}

Script::Script(std::string new_title)
{
    iScript = Script::scriptCount++;
    this->title = new_title;
    // this->contactCard = nullptr;
}

Script::~Script()
{
    for (auto &contactlessCard : this->contactlessCards)
        if (contactlessCard != nullptr)
            delete contactlessCard;
    for (auto &step : this->steps)
        if (step)
            delete step;
    this->contactlessCards.clear();
    this->steps.clear();
}

void Script::set_title(std::string newTitle)
{
    this->title = newTitle;
}

const std::string Script::get_title()
{
    return this->title;
}

void Script::add_contactless_card(ContactlessCard &newContactlessCard)
{
    this->contactlessCards.push_back(&newContactlessCard);
}

void Script::add_step(Step &newStep)
{
    this->steps.push_back(&newStep);
}

const ContactlessCard *Script::find_cl_card(uint32_t cardID)
{
    for (auto &clCard : this->contactlessCards)
        if (cardID == clCard->get_id())
            return clCard;
    return nullptr;
}

void Script::parse_card(json cardJson)
{
    if (cardJson.count("cardID") == 0)
        throw ex::JsonParsingException("Could not find required [cardID] field");

    uint32_t newCardID = cardJson.at("cardID").get<uint32_t>();
    if (this->find_cl_card(newCardID))
        throw std::invalid_argument("Card with [cardID: " + std::to_string(newCardID) + "] already exsists.");

    if (cardJson.count("tokenType") == 0)
        throw ex::JsonParsingException("Could not find required [tokenType] field");
    if (cardJson.count("tokenID") == 0)
        throw ex::JsonParsingException("Could not find required [tokenID] field");

    auto newCard = new ContactlessCard();

    newCard->set_card_ID(newCardID);

    contactless::token_type::TokenType newTokenType;
    if (!contactless::token_type::TokenType_Parse(cardJson.at("tokenType").get<std::string>(), &newTokenType))
        throw std::invalid_argument("Failed to parse [tokenType] parameter correctly");
    newCard->set_token_type(newTokenType);
    newCard->set_token_ID(cardJson.at("tokenID").get<std::string>());

    if (cardJson.count("answerToSelect") != 0)
        newCard->set_answer_to_select(cardJson.at("answerToSelect").get<std::string>());

    if (cardJson.count("atqa") != 0)
        newCard->set_atqa(cardJson.at("atqa").get<std::string>());

    if (cardJson.count("sak") != 0)
        newCard->set_sak(cardJson.at("sak").get<std::string>());

    this->contactlessCards.push_back(newCard);
}

void Script::parse_step(json stepJson)
{
    /*
 {
                     "message": "SVIACgEDAQoFCOgHIAJqhw==",
                     "actions":
                     [
                         {"attach_contactless_card": 1},
                         {"attach_contactless_card": 2},
                         {"wait": ""},
                         {"remove_card": 2}
                     ]

                 }
 */
    if (stepJson.count("message") == 0)
        throw ex::JsonParsingException("Could not find required [message] field");

    auto newStep = new Step();
    newStep->set_message(stepJson.at("message").get<std::string>());

    if (stepJson.count("preactions") != 0)
        for (auto &preactionJson : stepJson["preactions"])
            newStep->parse_preaction(preactionJson);

    if (stepJson.count("actions") != 0)
        for (auto &actionJson : stepJson["actions"])
            newStep->parse_action(actionJson);

    this->steps.push_back(newStep);
}

const std::string Script::str()
{
    std::string s("Title: " + this->title + "\n" +
                  "Contactless cards:\n");
    for (auto &contactlessCard : this->contactlessCards)
        s += "\t" + contactlessCard->str() + "\n";
    s += "Steps:\n";
    for (auto &step : this->steps)
        s += "\t" + step->str() + "\n";

    return s;
}

void Script::execute_script(Device &myDevice)
{
    std::cout << "Starting to execute script [" << this->title << "]..." << std::endl;

    int iStep = 0;
    for (auto &step : this->steps)
    {
        std::cout << "Executing step #" << iStep << ":\n"
                  << step->str() << std::endl;
        step->execute_step(myDevice);
        ++iStep;
    }

    std::cout << "Script [" << this->title << "] has been executed.\n\n";
}

/////////////////////////////////////////////////////////////////////////

Step::Step()
{
}

Step::Step(const std::string newMsg)
{
    set_message(newMsg);
}

Step::~Step()
{
}

const std::string Step::str() const
{
    std::string s = "Message:\n";
    s += this->origMsg + "\n";
    // инфа о сообщении
    // ...
    // s += "\t" + messageIR->str() + "\n";
    return s;
}

void Step::parse_preaction(json preactionJson)
{
    Action *newPreaction;
    if (preactionJson.count("attach_card") != 0)
        newPreaction = new CardAttacher(preactionJson.at("attach_card").get<uint32_t>());
    else if (preactionJson.count("remove_card") != 0)
        newPreaction = new CardRemover(preactionJson.at("remove_card").get<uint32_t>());

    this->messageIR->add_preaction(*newPreaction);
}

void Step::parse_action(json actionJson)
{
    Action *newAction = nullptr;
    if (actionJson.count("attach_card") != 0)
        newAction = new CardAttacher(actionJson.at("attach_card").get<uint32_t>());
    else if (actionJson.count("remove_card") != 0)
        newAction = new CardRemover(actionJson.at("remove_card").get<uint32_t>());
    else if (actionJson.count("send_cancel_message") != 0)
        newAction = new Canceller(actionJson.at("send_cancel_message").get<std::string>());
    else
        throw ex::JsonParsingException("Could not parse [action] correctly");

    this->messageIR->add_action(*newAction);
}

void Step::set_message(const std::string newMsg)
{
    this->origMsg = newMsg;
    this->messageIR = new MessageIR(newMsg);
}

void Step::execute_step(Device &myDevice)
{
    this->messageIR->execute_message(myDevice);
}
