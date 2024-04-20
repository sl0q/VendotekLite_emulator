#include "cards.h"

ContactlessCard::ContactlessCard()
{
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::UNKNOWN);
}

ContactlessCard::ContactlessCard(contactless::token_type::TokenType newTokenType)
{

    this->token = new contactless::token::Token();
    this->token->set_type(newTokenType);
}

ContactlessCard::~ContactlessCard()
{
    delete this->token;
}

void ContactlessCard::set_card_ID(uint32_t newCardID)
{
    this->id = newCardID;
}

void ContactlessCard::set_token(contactless::token::Token &newToken)
{
    this->token = &newToken;
}

void ContactlessCard::set_token_ID(std::string newTokenID)
{
    this->token->set_id(newTokenID);
}

void ContactlessCard::set_atqa(std::string newATQA)
{
    this->token->set_atqa(newATQA);
}

void ContactlessCard::set_sak(std::string newSAK)
{
    this->token->set_sak(newSAK);
}

uint32_t ContactlessCard::get_id() const
{
    return this->id;
}

const contactless::token::Token *ContactlessCard::get_card_token() const
{
    return this->token;
}

const std::string ContactlessCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->token->type()) + "\n" +
                       "TokenID: " + this->token->id() + "\n" +
                       "ATQA: " + this->token->atqa() + "\n" +
                       "SAK: " + this->token->sak() + "\n");
}

Iso_4A::Iso_4A()
{
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::ISO_14443_4A);
}

Iso_4A::~Iso_4A()
{
}

void Iso_4A::set_answer_to_select(const std::string newATS)
{
    this->token->set_answer_to_select(newATS);
}

const std::string Iso_4A::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->token->type()) + "\n" +
                       "TokenID: " + this->token->id() + "\n" +
                       "Answer to select: " + this->token->answer_to_select() + "\n" +
                       "ATQA: " + this->token->atqa() + "\n" +
                       "SAK: " + this->token->sak() + "\n");
}

Iso_B::Iso_B()
{
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::ISO_14443_4B);
}

Iso_B::~Iso_B()
{
}

const std::string Iso_B::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->token->type()) + "\n" +
                       "TokenID: " + this->token->id() + "\n" +
                       "ATQA: " + this->token->atqa() + "\n" +
                       "SAK: " + this->token->sak() + "\n");
}

MifareClassicCard::MifareClassicCard()
{
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::MIFARE_CLASSIC_1K);
}

MifareClassicCard::MifareClassicCard(MifareClassicCard::m_classic_K k)
{
    this->token = new contactless::token::Token();
    switch (k)
    {
    case m_1K:
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_1K);
        break;
    case m_2K:
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_2K);
        break;
    case m_4K:
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_4K);
        break;
    case m_MINI:
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_MINI);
        break;
    default:
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_1K);
    }
}

MifareClassicCard::~MifareClassicCard()
{
}

// void MifareClassicCard::set_key_type(mifare::classic::auth::KeyType newKeyType)
// {
//     this->keyType = newKeyType;
// }

void MifareClassicCard::set_clear_key_A(mifare::classic::auth::ClearKey &newClearKey)
{
    this->clearKey_A = newClearKey;
}

void MifareClassicCard::set_clear_key_B(mifare::classic::auth::ClearKey &newClearKey)
{
    this->clearKey_B = newClearKey;
}

void MifareClassicCard::set_clear_key_A(const std::string &newClearKey)
{
    this->clearKey_A.set_clear_key(newClearKey);
}

void MifareClassicCard::set_clear_key_B(const std::string &newClearKey)
{
    this->clearKey_B.set_clear_key(newClearKey);
}

// const mifare::classic::auth::KeyType &MifareClassicCard::get_key_type() const
// {
//     return this->keyType;
// }

const mifare::classic::auth::ClearKey &MifareClassicCard::get_clear_key_A() const
{
    return this->clearKey_A;
}

const mifare::classic::auth::ClearKey &MifareClassicCard::get_clear_key_B() const
{
    return this->clearKey_B;
}

const std::string MifareClassicCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->token->type()) + "\n" +
                       "TokenID: " + this->token->id() + "\n" +
                       "ATQA: " + this->token->atqa() + "\n" +
                       "SAK: " + this->token->sak() + "\n" +
                       "ClearKey_A: " + this->clearKey_A.clear_key() + "\n" +
                       "ClearKey_B: " + this->clearKey_B.clear_key() + "\n");
}

SmartWithMifareCard::SmartWithMifareCard()
{
    this->token->set_type(contactless::token_type::SMART_MX_WITH_MIFARE_1K);
    this->isoToken = nullptr;
    this->mifareToken = nullptr;
}

SmartWithMifareCard::SmartWithMifareCard(SmartWithMifareCard::m_smart_k k)
{
    this->isoToken = new Iso_4A();
    switch (k)
    {
    case m_1K:
        this->token->set_type(contactless::token_type::SMART_MX_WITH_MIFARE_1K);
        this->mifareToken = new MifareClassicCard(MifareClassicCard::m_1K);
        break;
    case m_4K:
        this->token->set_type(contactless::token_type::SMART_MX_WITH_MIFARE_4K);
        this->mifareToken = new MifareClassicCard(MifareClassicCard::m_4K);

        break;
    default:
        this->token->set_type(contactless::token_type::SMART_MX_WITH_MIFARE_1K);
        this->mifareToken = new MifareClassicCard(MifareClassicCard::m_1K);
    }
}

SmartWithMifareCard::~SmartWithMifareCard()
{
    delete this->isoToken;
    delete this->mifareToken;
}

Iso_4A &SmartWithMifareCard::get_iso_token()
{
    return *this->isoToken;
}

const Iso_4A &SmartWithMifareCard::get_iso_token() const
{
    return *this->isoToken;
}

void SmartWithMifareCard::set_allocated_iso(Iso_4A *newIsoCard)
{
    this->isoToken = newIsoCard;
}

void SmartWithMifareCard::set_allocated_mifare(MifareClassicCard *newMifareCard)
{
    this->mifareToken = newMifareCard;
}

MifareClassicCard &SmartWithMifareCard::get_mifare_token()
{
    return *this->mifareToken;
}

const MifareClassicCard &SmartWithMifareCard::get_mifare_token() const
{
    return *this->mifareToken;
}

const std::string SmartWithMifareCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->token->type()) + "\n" +
                       "TokenID: " + this->token->id() + "\n" +
                       "ATQA: " + this->token->atqa() + "\n" +
                       "SAK: " + this->token->sak() + "\n\n" +
                       "ISO14443-4A token: \n" +
                       this->isoToken->str() + "\n" +
                       "Mifare Classic token:" + "\n" +
                       this->mifareToken->str() + "\n");
}
