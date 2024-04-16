#include "cards.h"

ContactlessCard::ContactlessCard()
{
    this->tokenType = contactless::token_type::UNKNOWN;
}

ContactlessCard::ContactlessCard(uint32_t cardID,
                                 const contactless::token_type::TokenType newTokenType,
                                 const std::string newTokenID,
                                 const std::string newAnswerToSelect)
{
    this->id = cardID;
    this->tokenType = newTokenType;
    this->tokenID = newTokenID;
    this->answerToSelect = newAnswerToSelect;
}

void ContactlessCard::set_card_ID(uint32_t newCardID)
{
    this->id = newCardID;
}

void ContactlessCard::set_token_type(contactless::token_type::TokenType newTokenType)
{
    this->tokenType = newTokenType;
}

void ContactlessCard::set_token_ID(std::string newTokenID)
{
    this->tokenID = newTokenID;
}

void ContactlessCard::set_answer_to_select(std::string newAnswerToSelect)
{
    this->answerToSelect = newAnswerToSelect;
}

uint32_t ContactlessCard::get_id() const
{
    return this->id;
}

const std::string ContactlessCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->tokenType) + "\n" +
                       "TokenID: " + this->tokenID + "\n" +
                       "Answer to select: " + this->answerToSelect + "\n");
}
