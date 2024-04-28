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
    for (auto &card : this->originalContactlessCards)
        if (card != nullptr)
            delete card;
    for (auto &contactlessCard : this->contactlessCards)
        if (contactlessCard != nullptr)
            delete contactlessCard;
    for (auto &step : this->steps)
        if (step)
            delete step;
    this->originalContactlessCards.clear();
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
    this->originalContactlessCards.push_back(&newContactlessCard);
}

void Script::add_step(Step &newStep)
{
    this->steps.push_back(&newStep);
}

// copies cards from originalContactlessCards to contactlessCards
void Script::rewind_cards()
{
    for (auto &card : this->contactlessCards)
        delete card;
    this->contactlessCards.clear();

    for (auto &origCard : this->originalContactlessCards)
    {
        switch (origCard->get_card_token()->type())
        {
        case contactless::token_type::ISO_14443_4A:
            this->contactlessCards.push_back(new Iso_4A(*dynamic_cast<Iso_4A *>(origCard)));
            break;
        case contactless::token_type::ISO_14443_4B:
            this->contactlessCards.push_back(new Iso_B(*dynamic_cast<Iso_B *>(origCard)));
            break;
        case contactless::token_type::MIFARE_CLASSIC_1K:
            this->contactlessCards.push_back(new MifareClassicCard(*dynamic_cast<MifareClassicCard *>(origCard)));
            break;
        case contactless::token_type::MIFARE_CLASSIC_2K:
            this->contactlessCards.push_back(new MifareClassicCard(*dynamic_cast<MifareClassicCard *>(origCard)));
            break;
        case contactless::token_type::MIFARE_CLASSIC_4K:
            this->contactlessCards.push_back(new MifareClassicCard(*dynamic_cast<MifareClassicCard *>(origCard)));
            break;
        case contactless::token_type::MIFARE_CLASSIC_MINI:
            this->contactlessCards.push_back(new MifareClassicCard(*dynamic_cast<MifareClassicCard *>(origCard)));
            break;
        case contactless::token_type::SMART_MX_WITH_MIFARE_1K:
            this->contactlessCards.push_back(new SmartWithMifareCard(*dynamic_cast<SmartWithMifareCard *>(origCard)));
            break;
        case contactless::token_type::SMART_MX_WITH_MIFARE_4K:
            this->contactlessCards.push_back(new SmartWithMifareCard(*dynamic_cast<SmartWithMifareCard *>(origCard)));
            break;
        case contactless::token_type::MIFARE_UL_OR_ULC:
            switch (dynamic_cast<MifareUltralightCard *>(origCard)->get_type())
            {
            case MifareUltralightCard::m_C:
                this->contactlessCards.push_back(new MfrUl_C_Card(*dynamic_cast<MfrUl_C_Card *>(origCard)));
                break;
            case MifareUltralightCard::m_EV1:
                this->contactlessCards.push_back(new MfrUl_EV1_Card(*dynamic_cast<MfrUl_EV1_Card *>(origCard)));
                break;
            default:
                throw std::invalid_argument("Unknown Mifare Ultralight card type");
            }
            break;
        default:
            this->contactlessCards.push_back(new ContactlessCard(*dynamic_cast<ContactlessCard *>(origCard)));
            break;
        }
    }
}

ContactlessCard *Script::find_cl_card(uint32_t cardID)
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

    contactless::token_type::TokenType newTokenType;
    if (!contactless::token_type::TokenType_Parse(cardJson.at("tokenType").get<std::string>(), &newTokenType))
        throw std::invalid_argument("Failed to parse [tokenType] parameter correctly");

    ContactlessCard *newCard = nullptr;
    switch (newTokenType)
    {
    case contactless::token_type::ISO_14443_4A:
    {
        newCard = new Iso_4A();
        parse_iso_4a_card(cardJson, dynamic_cast<Iso_4A &>(*newCard));
        break;
    }
    case contactless::token_type::ISO_14443_4B:
    {
        newCard = new Iso_B();
        break;
    }
    case contactless::token_type::MIFARE_CLASSIC_1K:
    {
        newCard = new MifareClassicCard(MifareClassicCard::m_1K);
        parse_mifare_classic_card(cardJson, dynamic_cast<MifareClassicCard &>(*newCard));
        break;
    }
    case contactless::token_type::MIFARE_CLASSIC_2K:
    {
        newCard = new MifareClassicCard(MifareClassicCard::m_2K);
        parse_mifare_classic_card(cardJson, dynamic_cast<MifareClassicCard &>(*newCard));
        break;
    }
    case contactless::token_type::MIFARE_CLASSIC_4K:
    {
        newCard = new MifareClassicCard(MifareClassicCard::m_4K);
        parse_mifare_classic_card(cardJson, dynamic_cast<MifareClassicCard &>(*newCard));
        break;
    }
    case contactless::token_type::MIFARE_CLASSIC_MINI:
    {
        newCard = new MifareClassicCard(MifareClassicCard::m_MINI);
        parse_mifare_classic_card(cardJson, dynamic_cast<MifareClassicCard &>(*newCard));
        break;
    }
    case contactless::token_type::SMART_MX_WITH_MIFARE_1K:
    {
        if (cardJson.count("iso_4a") == 0)
            throw ex::JsonParsingException("Could not find required [iso_4a] field for card with [SMART_MX_WITH_MIFARE_1K] token type");
        if (cardJson.count("mifare") == 0)
            throw ex::JsonParsingException("Could not find required [mifare] field for card with [SMART_MX_WITH_MIFARE_1K] token type");

        auto newIsoCard = new Iso_4A();
        parse_iso_4a_card(cardJson["iso_4a"], *newIsoCard);

        auto newMifareCard = new MifareClassicCard(MifareClassicCard::m_1K);
        parse_mifare_classic_card(cardJson["mifare"], *newMifareCard);

        newCard = new SmartWithMifareCard();
        dynamic_cast<SmartWithMifareCard *>(newCard)->set_allocated_iso(newIsoCard);
        dynamic_cast<SmartWithMifareCard *>(newCard)->set_allocated_mifare(newMifareCard);
        break;
    }
    case contactless::token_type::SMART_MX_WITH_MIFARE_4K:
    {
        if (cardJson.count("iso_4a") == 0)
            throw ex::JsonParsingException("Could not find required [iso_4a] field for card with [SMART_MX_WITH_MIFARE_4K] token type");
        if (cardJson.count("mifare") == 0)
            throw ex::JsonParsingException("Could not find required [mifare] field for card with [SMART_MX_WITH_MIFARE_4K] token type");

        auto newIsoCard = new Iso_4A();
        parse_iso_4a_card(cardJson["iso_4a"], *newIsoCard);

        auto newMifareCard = new MifareClassicCard(MifareClassicCard::m_4K);
        parse_mifare_classic_card(cardJson["mifare"], *newMifareCard);

        newCard = new SmartWithMifareCard();
        dynamic_cast<SmartWithMifareCard *>(newCard)->set_allocated_iso(newIsoCard);
        dynamic_cast<SmartWithMifareCard *>(newCard)->set_allocated_mifare(newMifareCard);
        break;
    }
    case contactless::token_type::MIFARE_UL_OR_ULC:
    {
        std::string ulTypeStr;
        if (cardJson.count("ev1_c") != 0)
        {
            ulTypeStr = cardJson.at("ev1_c").get<std::string>();
            if ("EV1" == ulTypeStr)
                newCard = new MfrUl_EV1_Card();
            else if ("C" == ulTypeStr)
                newCard = new MfrUl_C_Card();
            else
                throw std::invalid_argument("Failed to parse [ev1_c] parameter correctly");
        }
        else
            newCard = new MfrUl_C_Card();

        parse_mifare_ultralight_card(cardJson, dynamic_cast<MifareUltralightCard &>(*newCard));
        std::cout << newCard->str() << std::endl;
        break;
    }
    default:
    {
        newCard = new ContactlessCard(newTokenType);
        break;
    }
    }

    newCard->set_card_ID(newCardID);
    newCard->set_token_ID(cardJson.at("tokenID").get<std::string>());

    if (cardJson.count("atqa") != 0)
        newCard->set_atqa(cardJson.at("atqa").get<std::string>());

    if (cardJson.count("sak") != 0)
        newCard->set_sak(cardJson.at("sak").get<std::string>());

    this->originalContactlessCards.push_back(newCard);
}

void Script::parse_mifare_classic_card(json cardJson, MifareClassicCard &card)
{
    if (cardJson.count("memorySectors") != 0)
    {
        uint32_t iSector = 0;
        for (auto &sectorJson : cardJson["memorySectors"])
        {
            if (sectorJson.count("blocks") != 0)
            {
                // building a sector
                uint32_t iBlock = 0;
                std::vector<Block *> newSector;
                for (auto &blockJson : sectorJson["blocks"])
                    if (blockJson.is_string())
                        newSector.push_back(new ByteBlock(blockJson.get<std::string>()));
                    else if (blockJson.is_number_integer())
                        newSector.push_back(new ValueBlock(blockJson.get<int32_t>()));
                    else
                    {
                        newSector.push_back(new ByteBlock(true));
                        std::cout << "WARNING: Sector " << iSector << ", Block " << iBlock << " unexpected type. The block will be filled with placeholder data.\n";
                    }

                try
                {
                    card.write_sector(newSector, iSector);
                }
                catch (std::out_of_range &ex)
                {
                    std::cout << "WARNING: " << ex.what() << std::endl;
                    continue;
                }
            }
            ++iSector;
        }
    }
}

void Script::parse_mifare_ultralight_card(json cardJson, MifareUltralightCard &card)
{
    if (cardJson.count("version") != 0)
        card.set_version(cardJson.at("version").get<std::string>());

    //  parse memory pages
    if (cardJson.count("memoryPages") != 0)
    {
        uint32_t iPage = 0;
        for (auto &pageJson : cardJson["memoryPages"])
        {
            if (pageJson.count("pageNumber") != 0)
                iPage = pageJson.at("pageNumber").get<uint32_t>();

            std::vector<uint8_t> byteArray;
            if (pageJson.count("bytes") != 0)
            {
                std::stringstream bytesString(pageJson.at("bytes").get<std::string>());
                std::string byteStr;
                char delimiter = '\\';
                while (std::getline(bytesString, byteStr, delimiter) && byteArray.size() < 4)
                {
                    //  convert hex string to uint8
                    if (byteStr.empty())
                        continue;
                    uint8_t byte = std::stoul(byteStr, nullptr, 16);

                    byteArray.push_back(byte);
                }
            }
            //  if read less than 4 bytes - fill the rest with 0x00
            while (byteArray.size() < 4)
                byteArray.push_back(0);

            // Page newPage(iPage, byteArray);
            card.write_page(Page(byteArray), iPage);

            ++iPage;
        }
    }
    card.fill_empty_memory(); //  fill undefined pages with default data (0x00)

    //  parse counters for ev1 card
    if (card.get_type() == MifareUltralightCard::m_EV1)
        parse_mifare_ultralight_EV1_card(cardJson, *dynamic_cast<MfrUl_EV1_Card *>(&card));
    if (card.get_type() == MifareUltralightCard::m_C)
        parse_mifare_ultralight_C_card(cardJson, *dynamic_cast<MfrUl_C_Card *>(&card));
}

void Script::parse_mifare_ultralight_C_card(json cardJson, MfrUl_C_Card &card)
{
    card.set_protection();
}

void Script::parse_mifare_ultralight_EV1_card(json cardJson, MfrUl_EV1_Card &card)
{
    //  parse counters
    if (cardJson.count("counters") != 0)
        for (auto &counterJson : cardJson["counters"])
        {
            uint32_t newInitialValue = 0;
            if (counterJson.count("initialValue") != 0)
                newInitialValue = counterJson.at("initialValue").get<uint32_t>();
            card.add_counter(newInitialValue);
        }
}

void Script::parse_iso_4a_card(json cardJson, Iso_4A &card)
{
    if (cardJson.count("answerToSelect") == 0)
        throw ex::JsonParsingException("Could not find required [answerToSelect] field for card with [ISO_14443_4A] token type");
    card.set_answer_to_select(cardJson.at("answerToSelect").get<std::string>());
}

void Script::parse_step(json stepJson)
{
    auto newStep = new Step();

    if (stepJson.count("message") != 0)
        newStep->set_message(stepJson.at("message").get<std::string>());
    else if (stepJson.count("messages") != 0)
        for (auto &messageJson : stepJson["messages"])
            newStep->add_message(messageJson);

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
    for (auto &contactlessCard : this->originalContactlessCards)
        s += "\t" + contactlessCard->str() + "\n";
    s += "Steps:\n";
    for (auto &step : this->steps)
        s += "\t" + step->str() + "\n";

    return s;
}

void Script::execute_script(Device &myDevice)
{
    std::cout << "Starting to execute script [" << this->title << "]..." << std::endl;

    rewind_cards();

    std::cout << "Cards rewinded to original state" << std::endl;

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
    for (auto &preaction : this->preactions)
        delete preaction;
    this->preactions.clear();

    for (auto &m : this->messagesIR)
        delete m;
    this->messagesIR.clear();

    if (messageIR != nullptr)
        delete messageIR;
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

    this->add_preaction(*newPreaction);
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

void Step::add_message(const std::string newMsg)
{
    this->messagesIR.push_back(new MessageIR(newMsg));
}

void Step::add_preaction(Action &newPreaction)
{
    this->preactions.push_back(&newPreaction);
}

void Step::execute_step(Device &myDevice)
{
    //  exe preacitons
    for (auto &preaction : this->preactions)
    {
        preaction->make_action(myDevice);
        std::cout << "Action {" << preaction->str() << "} was made\n";
    }

    //  if there is a single message
    if (this->messageIR != nullptr)
        this->messageIR->execute_message(myDevice);
    else if (!messagesIR.empty())
    {
        //  if there is a message barrage
        auto message = messagesIR.begin();

        // execute messages until one of them is successful (returns TRUE)
        while (!(*message)->execute_message(myDevice) && message != messagesIR.end())
            ++message;
    }
}
