#pragma once

#include <string>

#include <../proto_src/intellireader/contact/card_slot.pb.h>

#include "../proto_src/intellireader/contactless/token_type.pb.h"

#include "myExceptions.h"

class ContactCard
{
private:
    // std::string answerToReset;
    std::string historicalBytes;
    uint32_t expectedApduTrailer;
    std::string expectedResponceBody;
    contact::card_slot::CardSlot cardSlot;

public:
    ContactCard();
    ContactCard(std::string newHistoricalBytes, uint32_t newExpectedApduTrailer, std::string newExpectedResponceBody, std::string newCardSlot);
    const std::string &get_historical_bytes() const;
    const uint32_t get_expected_apdu_trailer() const;
    const std::string &get_expected_responce_body() const;
    const contact::card_slot::CardSlot get_card_slot();
};

class ContactlessCard
{
private:
    contactless::token_type::TokenType tokenType;
    std::string id;
    std::string answerToSelect;

public:
    ContactlessCard();
    ContactlessCard(contactless::token_type::TokenType newTokenType, std::string newAnswerToSelect);
    const std::string get_id() const;
};