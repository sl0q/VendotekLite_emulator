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
    {
        sector.resize(4);
        for (auto &block : sector)
            block = new ByteBlock(true);
    }
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
                block = new ByteBlock(true);
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
                block = new ByteBlock(true);
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
                block = new ByteBlock(true);
        }
        for (int i = 32; i < 40; ++i)
        {
            memorySectors[i].resize(16);
            for (auto &block : memorySectors[i])
                block = new ByteBlock(true);
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
                block = new ByteBlock(true);
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
                block = new ByteBlock(true);
        }
    }
}

MifareClassicCard::~MifareClassicCard()
{
    for (auto &sector : memorySectors)
        for (auto &block : sector)
            delete block;
}

void MifareClassicCard::fill_memory(const std::vector<std::vector<Block *>> &newData)
{
    auto iThisSector = this->memorySectors.begin();

    for (auto &newSector : newData)
    {
        auto iThisBlock = iThisSector->begin();

        for (auto &newBlock : newSector)
        {
            // copy pointers
            *iThisBlock = newBlock;
            ++iThisBlock;
        }

        if (newSector.size() < iThisSector->size())
        {
            //  fill with default data
            while (iThisBlock != iThisSector->end())
            {
                *iThisBlock = new ByteBlock(true);
                ++iThisBlock;
            }
        }

        ++iThisSector;
    }

    if (newData.size() < this->memorySectors.size())
    {
        //  fill with default data
        while (iThisSector != this->memorySectors.end())
        {
            auto iThisBlock = iThisSector->begin();
            while (iThisBlock != iThisSector->end())
            {
                *iThisBlock = new ByteBlock(true);
                ++iThisBlock;
            }
            ++iThisSector;
        }
    }
}

void MifareClassicCard::fill_empty_memory()
{
    for (int iSector = 0; iSector < memorySectors.size(); ++iSector)
    {
        for (int iBlock = 0; iBlock < memorySectors[iSector].size(); ++iBlock)
        {
            if (memorySectors[iSector][iBlock] == nullptr)
                memorySectors[iSector][iBlock] = new ByteBlock(true);
        }
    }
}

void MifareClassicCard::write_sector(const std::vector<Block *> &newSector, uint32_t iSector)
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");

    uint32_t iNewBlock = 0;
    for (auto &thisBlock : this->memorySectors[iSector])
    {
        if (thisBlock != nullptr)
            delete thisBlock;
        thisBlock = newSector[iNewBlock];
        ++iNewBlock;
    }
}

void MifareClassicCard::write_data_block(const std::string &newData, uint32_t iBlock)
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");
    if (iBlock > this->memorySectors[iSector].size())
        throw std::out_of_range("Provided memory block index is out of range of mifare card memory map");

    if (this->memorySectors[iSector][iBlock]->is_value())
    {
        delete this->memorySectors[iSector][iBlock];
        this->memorySectors[iSector][iBlock] = new ByteBlock(newData);
    }
    else
    {
        dynamic_cast<ByteBlock *>(this->memorySectors[iSector][iBlock])->set_data(newData);
    }
}

void MifareClassicCard::write_value_block(int32_t newValue, uint32_t iBlock)
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");
    if (iBlock > this->memorySectors[iSector].size())
        throw std::out_of_range("Provided memory block index is out of range of mifare card memory map");

    //  check if the block is a value block
    if (this->memorySectors[iSector][iBlock]->is_value())
    {
        auto ffsPointer = this->memorySectors[iSector][iBlock];
        dynamic_cast<ValueBlock *>(ffsPointer)->set_value(newValue);
    }
    else
    {
        //  reinitilize block as value block
        delete this->memorySectors[iSector][iBlock];
        this->memorySectors[iSector][iBlock] = new ValueBlock(newValue);
    }
}

void MifareClassicCard::set_internal_register(int32_t value)
{
    internalRegister = value;
}

const std::string MifareClassicCard::get_clear_key_A(uint32_t iSector) const
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is outside of range of mifare card memory map");
    return dynamic_cast<ByteBlock *>(*(memorySectors[iSector].end() - 1))->get_data().substr(0, 6);
}

const std::string MifareClassicCard::get_clear_key_B(uint32_t iSector) const
{
    if (iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is outside of range of mifare card memory map");
    return dynamic_cast<ByteBlock *>(*(memorySectors[iSector].end() - 1))->get_data().substr(10, 6);
}

const std::string &MifareClassicCard::get_block_data(uint32_t iBlock) const
{
    if (this->iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");
    if (iBlock > this->memorySectors[this->iSector].size())
        throw std::out_of_range("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " is out of range of mifare card memory map");
    if (memorySectors[iSector][iBlock]->is_value())
        throw ex::BadType("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " stores a numeric value");

    return dynamic_cast<ByteBlock *>(memorySectors[iSector][iBlock])->get_data();
}

int32_t MifareClassicCard::get_block_value(uint32_t iBlock) const
{
    if (this->iSector > this->memorySectors.size())
        throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");
    if (iBlock > this->memorySectors[this->iSector].size())
        throw std::out_of_range("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " is out of range of mifare card memory map");
    if (!memorySectors[iSector][iBlock]->is_value())
        throw ex::BadType("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " stores byte data");

    return dynamic_cast<ValueBlock *>(memorySectors[iSector][iBlock])->get_value();
}

int32_t MifareClassicCard::get_internal_register() const
{
    return internalRegister;
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

Block::Block()
{
    isValue = false;
}

Block::~Block()
{
}

bool Block::is_value()
{
    return isValue;
}

void ValueBlock::meme_method()
{
}

ValueBlock::ValueBlock()
{
    isValue = true;
    value = 0;
}

ValueBlock::ValueBlock(int32_t newValue)
{
    isValue = true;
    value = newValue;
}

ValueBlock::~ValueBlock()
{
    std::cout << "Value: " << value << std::endl;
}

void ValueBlock::set_value(int32_t newValue)
{
    value = newValue;
}

int32_t ValueBlock::get_value() const
{
    return value;
}

const std::string &ValueBlock::get_data() const
{
    std::string s(std::to_string(this->value));
    s.resize(16, PLACEHOLDER);
    return s;
}

std::string ValueBlock::str() const
{
    return std::to_string(this->value);
}

// ByteBlock::ByteBlock()
// {
//     isValue = false;
//     data = "";
// }

void ByteBlock::meme_method()
{
}

ByteBlock::ByteBlock(bool fill)
{
    isValue = false;
    data = "he";
    if (fill)
        for (uint32_t i = 0; i < BLOCK_SIZE; ++i)
            data += PLACEHOLDER;
}

ByteBlock::ByteBlock(const std::string &newData)
{
    isValue = false;
    data = newData;
    data.resize(BLOCK_SIZE, PLACEHOLDER);
}

ByteBlock::~ByteBlock()
{
    std::cout << "Bytes: " << data << std::endl;
}

void ByteBlock::set_data(const std::string &newData)
{
    data = newData;
    data.resize(16, PLACEHOLDER);
}

const std::string &ByteBlock::get_data() const
{
    return this->data;
}

std::string ByteBlock::str() const
{
    return this->data;
}

Page::Page()
{
    bytes.resize(PAGE_LENGTH);
    type = DATA;
}

Page::Page(Page::PageType newPageType, const std::vector<uint8_t> &newData)
{
    type = newPageType;
    bytes.resize(PAGE_LENGTH);
    int iByte = 0;
    for (auto &byte : this->bytes)
        byte = newData[iByte++];
}

bool Page::is_read_only() const
{
    return readOnly;
}

void Page::set_data(const std::vector<uint8_t> &newData)
{
    int iByte = 0;
    for (auto &byte : this->bytes)
        byte = newData[iByte++];
}

void Page::set_type(Page::PageType newPageType)
{
    type = newPageType;
}

void Page::set_bit(uint8_t iBit)
{
    uint8_t i = iBit % 32;
    bytes[i / 8] |= (1 << (i % 8));
}

const std::vector<uint8_t> &Page::get_data() const
{
    return bytes;
}

const std::string &Page::get_data_str() const
{
    char hex[2];
    std::stringstream buf;
    for (auto &byte : bytes)
    {
        sprintf(hex, "%X", byte);
        buf << "0x" << hex << ' ';
    }
    return buf.str();
}
