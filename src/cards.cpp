#include "cards.h"

ContactCard::ContactCard()
{
}

ContactCard::ContactCard(std::string newHistoricalBytes, uint32_t newExpectedApduTrailer, std::string newExpectedResponceData, std::string newCardSlot)
{
    this->historicalBytes = newHistoricalBytes;
    this->expectedApduTrailer = newExpectedApduTrailer;
    this->expectedResponceBody = newExpectedResponceData;
    if (!contact::card_slot::CardSlot_Parse(newCardSlot, &this->cardSlot))
        throw std::invalid_argument(std::string("Invalid card slot value: " + newCardSlot));
}

const std::string &ContactCard::get_historical_bytes() const
{
    return this->historicalBytes;
}

const uint32_t ContactCard::get_expected_apdu_trailer() const
{
    return this->expectedApduTrailer;
}

const std::string &ContactCard::get_expected_responce_body() const
{
    return this->expectedResponceBody;
}

contact::card_slot::CardSlot ContactCard::get_card_slot()
{
    return this->cardSlot;
}

const std::string ContactCard::str() const
{
    return std::string("Historical bytes: " + this->historicalBytes + "\n" +
                       "Expected Apdu trailer: " + std::to_string(this->expectedApduTrailer) + "\n" +
                       "Expected responce body: " + this->expectedResponceBody + "\n" +
                       "Card slot: " + contact::card_slot::CardSlot_Name(this->cardSlot) + "\n");
}

////////////////////////////////////////////////////////////////////////////

ContactlessCard::ContactlessCard()
{
    this->tokenType = contactless::token_type::UNKNOWN;
}

ContactlessCard::ContactlessCard(const contactless::token_type::TokenType newTokenType, const std::string newID, const std::string newAnswerToSelect)
{
    this->tokenType = newTokenType;
    this->id = newID;
    this->answerToSelect = newAnswerToSelect;
}

const std::string ContactlessCard::get_id() const
{
    return this->id;
}

const std::string ContactlessCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->tokenType) + "\n" +
                       "ID: " + this->id + "\n" +
                       "Answer to select: " + this->answerToSelect + "\n");
}
