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

const contact::card_slot::CardSlot ContactCard::get_card_slot()
{
    return this->cardSlot;
}

////////////////////////////////////////////////////////////////////////////

ContactlessCard::ContactlessCard()
{
    this->tokenType = contactless::token_type::UNKNOWN;
}

ContactlessCard::ContactlessCard(contactless::token_type::TokenType newTokenType, std::string newAnswerToSelect)
{
    this->tokenType = newTokenType;
    this->answerToSelect = newAnswerToSelect;
}

const std::string ContactlessCard::get_id() const
{
    return this->id;
}
