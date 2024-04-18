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

ContactlessCard::~ContactlessCard()
{
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

void ContactlessCard::set_atqa(std::string newATQA)
{
    this->atqa = newATQA;
}

void ContactlessCard::set_sak(std::string newSAK)
{
    this->sak = newSAK;
}

uint32_t ContactlessCard::get_id() const
{
    return this->id;
}

contactless::token_type::TokenType ContactlessCard::get_token_type() const
{
    return this->tokenType;
}
std::string ContactlessCard::get_token_id() const
{
    return this->tokenID;
}

std::string ContactlessCard::get_answer_to_select() const
{
    return this->answerToSelect;
}

std::string ContactlessCard::get_atqa() const
{
    return this->atqa;
}

std::string ContactlessCard::get_sak() const
{
    return this->sak;
}

contactless::token::Token *ContactlessCard::get_card_as_token() const
{
    auto newToken = new contactless::token::Token();

    newToken->set_type(this->tokenType);
    newToken->set_id(this->tokenID);
    if (!this->answerToSelect.empty())
        newToken->set_answer_to_select(this->answerToSelect);
    if (!this->atqa.empty())
        newToken->set_atqa(this->atqa);
    if (!this->sak.empty())
        newToken->set_sak(this->sak);

    return newToken;
}

const std::string ContactlessCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->tokenType) + "\n" +
                       "TokenID: " + this->tokenID + "\n" +
                       "Answer to select: " + this->answerToSelect + "\n");
}
