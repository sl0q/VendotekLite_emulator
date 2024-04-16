#pragma once

#include <string>

#include <../proto_src/intellireader/contact/card_slot.pb.h>

#include "../proto_src/intellireader/contactless/token_type.pb.h"

#include "myExceptions.h"

// class ContactCard
// {
// private:
//     // std::string answerToReset;
//     std::string historicalBytes;
//     uint32_t expectedApduTrailer;
//     std::string expectedResponceBody;
//     contact::card_slot::CardSlot cardSlot;

// public:
//     ContactCard();
//     ContactCard(std::string newHistoricalBytes, uint32_t newExpectedApduTrailer, std::string newExpectedResponceBody, std::string newCardSlot);
//     const std::string &get_historical_bytes() const;
//     const uint32_t get_expected_apdu_trailer() const;
//     const std::string &get_expected_responce_body() const;
//     contact::card_slot::CardSlot get_card_slot();
//     const std::string str() const;
// };

class ContactlessCard
{
private:
    contactless::token_type::TokenType tokenType;
    uint32_t id;
    std::string tokenID;
    std::string answerToSelect;

public:
    ContactlessCard();
    ContactlessCard(uint32_t cardID,
                    const contactless::token_type::TokenType newTokenType,
                    const std::string newTokenID,
                    const std::string newAnswerToSelect);
    void set_card_ID(uint32_t newCardID);
    void set_token_type(contactless::token_type::TokenType newTokenType);
    void set_token_ID(std::string newTokenID);
    void set_answer_to_select(std::string newAnswerToSelect);
    uint32_t get_id() const;
    const std::string str() const;
};