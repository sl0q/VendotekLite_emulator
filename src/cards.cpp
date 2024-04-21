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
    this->memorySectors.resize(16);
    for (auto &sector : this->memorySectors)
        sector.resize(4);
}

MifareClassicCard::MifareClassicCard(MifareClassicCard::m_classic_K k)
{
    this->token = new contactless::token::Token();
    switch (k)
    {
    case m_1K:
        //  16 sectors * 4 blocks * 16 bytes = 1 kB
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_1K);
        this->memorySectors.resize(16);
        for (auto &sector : this->memorySectors)
        {
            sector.resize(4);
            for (auto &block : sector)
                block.resize(16, '*');
        }
        break;
    case m_2K:
        //  32 sectors * 4 blocks * 16 bytes = 2 kB
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_2K);
        this->memorySectors.resize(32);
        for (auto &sector : this->memorySectors)
        {
            sector.resize(4);
            for (auto &block : sector)
                block.resize(16, '*');
        }
        break;
    case m_4K:
        //  32 sectors * 4 blocks * 16 bytes + 8 sectors * 16 blocks * 16 bytes = 4 kB
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_4K);
        this->memorySectors.resize(40);
        for (int i = 0; i < 32; ++i)
        {
            memorySectors[i].resize(4);
            for (auto &block : memorySectors[i])
                block.resize(16, '*');
        }
        for (int i = 32; i < 40; ++i)
        {
            memorySectors[i].resize(16);
            for (auto &block : memorySectors[i])
                block.resize(16, '*');
        }

        break;
    case m_MINI:
        //  5 sectors * 4 blocks * 16 bytes = 320 bytes
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_MINI);
        this->memorySectors.resize(5);
        for (auto &sector : this->memorySectors)
        {
            sector.resize(4);
            for (auto &block : sector)
                block.resize(16, '*');
        }
        break;
    default:
        //  16 sectors * 4 blocks * 16 bytes = 1 kB
        this->token->set_type(contactless::token_type::MIFARE_CLASSIC_1K);
        this->memorySectors.resize(16);
        for (auto &sector : this->memorySectors)
        {
            sector.resize(4);
            for (auto &block : sector)
                block.resize(16, '*');
        }
    }
}

MifareClassicCard::~MifareClassicCard()
{
}

// void MifareClassicCard::set_key_type(mifare::classic::auth::KeyType newKeyType)
// {
//     this->keyType = newKeyType;
// }

// void MifareClassicCard::set_clear_key_A(mifare::classic::auth::ClearKey &newClearKey)
// {
//     this->clearKey_A = newClearKey;
// }

// void MifareClassicCard::set_clear_key_B(mifare::classic::auth::ClearKey &newClearKey)
// {
//     this->clearKey_B = newClearKey;
// }

// // void MifareClassicCard::set_clear_key_A(const std::string &newClearKey)
// // {
// //     this->clearKey_A.set_clear_key(newClearKey);
// // }

// // void MifareClassicCard::set_clear_key_B(const std::string &newClearKey)
// // {
// //     this->clearKey_B.set_clear_key(newClearKey);
// // }

void MifareClassicCard::fill_memory(const std::vector<std::vector<std::string>> &newData)
{
    auto iThisSector = this->memorySectors.begin();
    for (auto &sector : newData)
    {
        auto iThisBlock = iThisSector->begin();
        for (auto &block : sector)
        {
            *iThisBlock = block;
            // if(iThisBlock->length() != 16)
            iThisBlock->resize(16, '*');
            ++iThisBlock;
            if (iThisBlock == iThisSector->end())
                break;
        }
        ++iThisSector;
        if (iThisSector == this->memorySectors.end())
            break;
    }
}

void MifareClassicCard::write_sector(const std::vector<std::string> &newSector, uint32_t iSector)
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Provided memory sector index is out of range of mifare card memory map.");
    this->memorySectors[iSector] = newSector;
}

void MifareClassicCard::write_block(const std::string &newBlock, uint32_t iSector, uint32_t iBlock)
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Provided memory sector index is out of range of mifare card memory map.");
    if (iBlock > this->memorySectors[iSector].size())
        throw std::out_of_range("Provided memory block index is out of range of mifare card memory map.");

    this->memorySectors[iSector][iBlock] = newBlock;
    if (this->memorySectors[iSector][iBlock].size() != BLOCK_SIZE)
        this->memorySectors[iSector][iBlock].resize(16, '*');
}

const std::string MifareClassicCard::get_clear_key_A(uint32_t iSector) const
{
    return (this->memorySectors[iSector].end() - 1)->substr(0, 6);
}

const std::string MifareClassicCard::get_clear_key_B(uint32_t iSector) const
{
    return (this->memorySectors[iSector].end() - 1)->substr(10, 6);
}

const std::string &MifareClassicCard::get_data_block(uint32_t iBlock)
{
    if (this->iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is out of range of mifare card memory map.");
    if (iBlock > this->memorySectors[this->iSector].size())
        throw std::out_of_range("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " is out of range of mifare card memory map.");

    return this->memorySectors[this->iSector][iBlock];
}

void MifareClassicCard::authorize_sector(uint32_t iSector)
{
    this->iSector = iSector;
}

void MifareClassicCard::reset_sector()
{
    this->iSector = UINT32_MAX;
}

const std::string MifareClassicCard::str() const
{
    return std::string("TokenType: " + contactless::token_type::TokenType_Name(this->token->type()) + "\n" +
                       "TokenID: " + this->token->id() + "\n" +
                       "ATQA: " + this->token->atqa() + "\n" +
                       "SAK: " + this->token->sak() + "\n");
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
