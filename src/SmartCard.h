#pragma once

#include <string>

#include <../proto_src/intellireader/contact/card_slot.pb.h>

#include "myExceptions.h"

class SmartCard
{
private:
    // std::string answerToReset;
    std::string historicalBytes;
    uint32_t expectedApduTrailer;
    std::string expectedResponceBody;
    contact::card_slot::CardSlot cardSlot;

public:
    SmartCard();
    SmartCard(std::string newHistoricalBytes, uint32_t newExpectedApduTrailer, std::string newExpectedResponceBody, std::string newCardSlot);
    const std::string &get_historical_bytes() const;
    const uint32_t get_expected_apdu_trailer() const;
    const std::string &get_expected_responce_body() const;
    const contact::card_slot::CardSlot get_card_slot();
};