#include "SmartCard.h"

SmartCard::SmartCard()
{
}

SmartCard::SmartCard(std::string newHistoricalBytes, uint32_t newExpectedApduTrailer, std::string newExpectedResponceData, std::string newCardSlot)
{
    this->historicalBytes = newHistoricalBytes;
    this->expectedApduTrailer = newExpectedApduTrailer;
    this->expectedResponceBody = newExpectedResponceData;
    if (!contact::card_slot::CardSlot_Parse(newCardSlot, &this->cardSlot))
        throw std::invalid_argument(std::string("Invalid card slot value: " + newCardSlot));
}

const std::string &SmartCard::get_historical_bytes() const
{
    return this->historicalBytes;
}

const uint32_t SmartCard::get_expected_apdu_trailer() const
{
    return this->expectedApduTrailer;
}

const std::string &SmartCard::get_expected_responce_body() const
{
    return this->expectedResponceBody;
}

const contact::card_slot::CardSlot SmartCard::get_card_slot()
{
    return this->cardSlot;
}
