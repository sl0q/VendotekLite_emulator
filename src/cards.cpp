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

ContactlessCard::ContactlessCard(const ContactlessCard &otherCard)
{
    this->id = otherCard.id;

    if (this->token != nullptr)
        delete this->token;
    this->token = new contactless::token::Token(*otherCard.token);
    // this->token = new contactless::token::Token();
    // this->token->set_answer_to_select(otherCard.token->answer_to_select());
    // this->token->set_atqa(otherCard.token->atqa());
    // this->token->set_id(otherCard.token->id());
    // this->token->set_sak(otherCard.token->sak());
    // this->token->set_type(otherCard.token->type());
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

void ContactlessCard::deauth()
{
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

void Iso_4A::deauth()
{
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

void Iso_B::deauth()
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

MifareClassicCard::MifareClassicCard(const MifareClassicCard &otherCard)
    : ContactlessCard(otherCard)
{
    this->iSector = otherCard.iSector;
    this->internalRegister = otherCard.internalRegister;

    //  delete old memory blocks
    for (auto &sector : memorySectors)
        for (auto &block : sector)
            delete block;
    this->memorySectors.clear();

    // init new
    for (auto &otherSector : otherCard.memorySectors)
    {
        this->memorySectors.push_back(std::vector<Block *>());
        for (auto &otherBlock : otherSector)
        {
            if (otherBlock->is_value())
                (this->memorySectors.end() - 1)->push_back(new ValueBlock(*dynamic_cast<const ValueBlock *>(otherBlock)));
            else
                (this->memorySectors.end() - 1)->push_back(new ByteBlock(*dynamic_cast<const ByteBlock *>(otherBlock)));
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

bool MifareClassicCard::write_data_block(const std::string &newData, uint32_t iBlock)
{
    // check if sector is authenticated OR is index is out of range
    if (iSector > this->memorySectors.size())
        return false;
    if (iBlock > this->memorySectors[iSector].size())
        return false;

    //  check if the block is a value block
    if (this->memorySectors[iSector][iBlock]->is_value())
    {
        delete this->memorySectors[iSector][iBlock];
        this->memorySectors[iSector][iBlock] = new ByteBlock(newData);
    }
    else
    {
        //  reinit block as a regular block
        dynamic_cast<ByteBlock *>(this->memorySectors[iSector][iBlock])->set_data(newData);
    }
    return true;
}

bool MifareClassicCard::write_value_block(int32_t newValue, uint32_t iBlock)
{
    if (iSector > this->memorySectors.size())
        return false;
    if (iBlock > this->memorySectors[iSector].size())
        return false;

    //  check if the block is a value block
    if (this->memorySectors[iSector][iBlock]->is_value())
    {
        dynamic_cast<ValueBlock *>(this->memorySectors[iSector][iBlock])->set_value(newValue);
    }
    else
    {
        //  reinitilize block as value block
        delete this->memorySectors[iSector][iBlock];
        this->memorySectors[iSector][iBlock] = new ValueBlock(newValue);
    }
    return true;
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

// const std::string &MifareClassicCard::get_block_data(uint32_t iBlock) const
// {
//     if (this->iSector > this->memorySectors.size())
//         throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");
//     if (iBlock > this->memorySectors[this->iSector].size())
//         throw std::out_of_range("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " is out of range of mifare card memory map");
//     if (memorySectors[iSector][iBlock]->is_value())
//         throw ex::BadType("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " stores a numeric value");

//     return dynamic_cast<ByteBlock *>(memorySectors[iSector][iBlock])->get_data();
// }

// int32_t MifareClassicCard::get_block_value(uint32_t iBlock) const
// {
//     if (this->iSector > this->memorySectors.size())
//         throw std::out_of_range("Memory sector " + std::to_string(iSector) + " is unauthorized or located outside of range of mifare card memory map");
//     if (iBlock > this->memorySectors[this->iSector].size())
//         throw std::out_of_range("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " is out of range of mifare card memory map");
//     if (!memorySectors[iSector][iBlock]->is_value())
//         throw ex::BadType("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " stores byte data");

//     return dynamic_cast<ValueBlock *>(memorySectors[iSector][iBlock])->get_value();
// }

int32_t MifareClassicCard::get_internal_register() const
{
    return internalRegister;
}

void MifareClassicCard::authorize_sector(uint32_t iSector)
{
    this->iSector = iSector;
}

const Block *MifareClassicCard::read_block(uint32_t iBlock)
{
    //  if sector is out of range OR is not authenticated
    if (this->iSector > this->memorySectors.size())
        return nullptr;
    if (iBlock > this->memorySectors[this->iSector].size())
        return nullptr;
    // if (memorySectors[iSector][iBlock]->is_value())
    //     throw ex::BadType("Memory block " + std::to_string(iSector) + " of sector " + std::to_string(iSector) + " stores a numeric value");

    return memorySectors[iSector][iBlock];
}

void MifareClassicCard::deauth()
{
    reset_sector();
}

void MifareClassicCard::reset_sector()
{
    this->iSector = UINT32_MAX;
}

const std::string MifareClassicCard::str() const
{
    std::stringstream buf(ContactlessCard::str(), std::ios::app | std::ios::out);

    buf << "Memory:" << std::endl;

    int iSector = 0;
    for (auto &sector : memorySectors)
    {
        buf << "\tSector #" << iSector++ << ":\n";
        int iBlock = 0;
        for (auto &block : sector)
            buf << "\t\tBlock #" << iBlock++ << ": " << block->get_data() << std::endl;
    }

    return buf.str();
}

SmartWithMifareCard::SmartWithMifareCard()
{
    this->token = new contactless::token::Token();
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

SmartWithMifareCard::SmartWithMifareCard(const SmartWithMifareCard &otherCard)
    : ContactlessCard(otherCard)
{
    this->keyType = otherCard.keyType;

    if (this->isoToken != nullptr)
        delete this->isoToken;
    if (this->mifareToken != nullptr)
        delete this->mifareToken;

    this->isoToken = new Iso_4A(*otherCard.isoToken);
    this->mifareToken = new MifareClassicCard(*otherCard.mifareToken);
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

void SmartWithMifareCard::deauth()
{
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

bool Block::is_value() const
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

const std::string ValueBlock::get_data() const
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

const std::string ByteBlock::get_data() const
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

Page::Page(const std::vector<uint8_t> &newData)
{
    bytes.resize(PAGE_LENGTH);
    int iByte = 0;
    for (auto &byte : this->bytes)
        byte = newData[iByte++];
}

bool Page::is_readable() const
{
    return readable;
}

bool Page::is_writable() const
{
    return writable;
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

void Page::set_readable(bool value)
{
    readable = value;
}

void Page::set_writable(bool value)
{
    writable = value;
}

const std::vector<uint8_t> &Page::get_data() const
{
    return bytes;
}

const std::string Page::get_data_str() const
{
    char hex[2];
    std::stringstream buf;
    for (auto &byte : bytes)
    {
        sprintf(hex, "%X", byte);
        buf << "0x" << hex << ' ';
        // buf << std::endl;
    }
    return buf.str();
}

MifareUltralightCard::MifareUltralightCard()
{
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::MIFARE_UL_OR_ULC);
    type = m_C;
    memoryPages.resize(16);
    this->version = "No version";
}

MifareUltralightCard::MifareUltralightCard(const MifareUltralightCard &otherCard)
    : ContactlessCard(otherCard)
{
    this->version = otherCard.version;
    this->type = otherCard.type;
    this->isAuth = otherCard.isAuth;
    this->internalRegister = otherCard.internalRegister;

    //  delete old pages;
    for (auto &page : this->memoryPages)
        delete page;
    this->memoryPages.clear();

    for (auto &otherPage : otherCard.memoryPages)
        this->memoryPages.push_back(new Page(*otherPage));
}

MifareUltralightCard::~MifareUltralightCard()
{
    for (auto &page : memoryPages)
        if (page != nullptr)
            delete page;
    memoryPages.clear();
}

void MifareUltralightCard::fill_memory(const std::vector<Page *> &newData)
{
    memoryPages = newData;
}

void MifareUltralightCard::fill_empty_memory()
{
    for (auto &page : memoryPages)
        if (page == nullptr)
            page = new Page();
}

void MifareUltralightCard::set_internal_register(int32_t value)
{
    internalRegister = value;
}

void MifareUltralightCard::set_type(MifareUltralightCard::m_ul_type newType)
{
    type = newType;

    for (auto &page : memoryPages)
        if (page != nullptr)
            delete page;

    switch (type)
    {
    case m_C:
        memoryPages.resize(16);
        break;
    case m_EV1:
        memoryPages.resize(20);
        break;
    default:
        throw ex::BadType("Unknown carddmifare ultralight type");
    }
}

void MifareUltralightCard::set_version(const std::string &newVersion)
{
    version = newVersion;
}

MifareUltralightCard::m_ul_type MifareUltralightCard::get_type() const
{
    return this->type;
}

const Page *MifareUltralightCard::read_page(uint32_t iPage) const
{

    if (iPage < memoryPages.size() && isAuth && memoryPages[iPage]->is_readable())
        return memoryPages[iPage];

    return nullptr;
}

int32_t MifareUltralightCard::get_internal_register() const
{
    return internalRegister;
}

const std::string &MifareUltralightCard::get_version() const
{
    return version;
}

const std::string MifareUltralightCard::str() const
{
    std::stringstream buf(ContactlessCard::str(), std::ios::app | std::ios::out);

    buf << "Type: " << (type == m_C ? "m_C" : "m_EV1") << std::endl
        << "Memory:" << std::endl;

    char hex[2];
    int index = 0;
    for (auto &page : memoryPages)
    {
        buf << "\tPage #" << index++ << ": ";
        for (auto &byte : page->get_data())
        {
            sprintf(hex, "%X", byte);
            buf << "0x" << hex << ' ';
        }
        buf << std::endl;
    }

    return buf.str();
}

CounterPage::CounterPage()
{
    value = 0;
}

CounterPage::CounterPage(uint32_t newValue)
{
    value = newValue;
}

void CounterPage::shrink_to_24b()
{
    value <<= 2;
    value >>= 2;
}

uint32_t CounterPage::get_value() const
{
    return value;
}

std::vector<uint8_t> CounterPage::get_value_hex() const
{
    uint32_t temp = value;
    std::vector<uint8_t> buf;

    for (int i = 0; i < 3; ++i)
    {
        uint8_t byte = temp;
        buf.push_back(byte);
        temp >>= 2;
    }

    return buf;
}

std::string CounterPage::get_value_hex_str() const
{
    std::stringstream buf;
    char hex[2];
    for (auto &byte : get_value_hex())
    {
        sprintf(hex, "%X", byte);
        buf << "0x" << hex << ' ';
        // buf << std::endl;
    }
    return buf.str();
}

void CounterPage::set_value(uint32_t newValue)
{
    value = newValue;
}

void CounterPage::modify_value(uint32_t operand)
{
    value += operand;
}

const std::vector<uint8_t> &MfrUl_EV1_Card::get_password() const
{
    if (this->memoryPages[18] == nullptr)
        throw std::runtime_error("Attempt to access undefined memory page of a Mifare Ultralight EV1 card");

    //  page 18 stores password
    return this->memoryPages[18]->get_data();
}

MfrUl_EV1_Card::MfrUl_EV1_Card()
{
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::MIFARE_UL_OR_ULC);
    type = m_EV1;
    memoryPages.resize(20);
    this->version = "No version";

    for (int i = 0; i < 3; ++i)
        counters.push_back(new CounterPage());
}

MfrUl_EV1_Card::MfrUl_EV1_Card(const MfrUl_EV1_Card &otherCard)
    : MifareUltralightCard(otherCard)
{
    for (auto &counter : this->counters)
        delete counter;
    counters.clear();

    for (auto &otherCounter : otherCard.counters)
        this->counters.push_back(new CounterPage(*otherCounter));
}

MfrUl_EV1_Card::~MfrUl_EV1_Card()
{
    for (auto &counter : counters)
        delete counter;
    counters.clear();
}

//  auth using password
bool MfrUl_EV1_Card::auth(const std::string &token)
{
    //  password as byte string ("\0xff\0xff..."))
    std::stringstream bytesString(token); // string with all password bytes
    std::string byteStr;                  // single byte as hex string
    std::vector<uint8_t> byteArray;
    char delimiter = '\\';
    while (std::getline(bytesString, byteStr, delimiter) && byteArray.size() < 4)
    {
        //  convert hex string to uint8
        if (byteStr.empty())
            continue;
        uint8_t byte = std::stoul(byteStr, nullptr, 16);

        byteArray.push_back(byte);
    }

    return auth(byteArray);
}

//  auth using password
bool MfrUl_EV1_Card::auth(const std::vector<uint8_t> &token)
{
    this->isAuth = false;

    if (type != MifareUltralightCard::m_EV1)
        return false;

    if (token.size() != 4)
        return false;

    int iByte = 0;
    for (auto &byte : this->get_password())
        if (byte != token[iByte++])
            return false;

    this->isAuth = true;
    return true;
}

void MfrUl_EV1_Card::deauth()
{
    isAuth = false;
}

bool MfrUl_EV1_Card::write_page(const Page &newPage, uint32_t iPage)
{
    if (iPage > 19)
        return false;

    // if it is initialization of a completly new page
    if (memoryPages[iPage] == nullptr)
    {
        memoryPages[iPage] = new Page(newPage);

        //  set permanent read/write rules
        if (iPage < 2)
        {
            memoryPages[iPage]->set_type(Page::SERIAL_NUMBER);
            memoryPages[iPage]->set_writable(false);
        }
        else if (iPage == 2)
            memoryPages[iPage]->set_type(Page::LOCK);
        else if (iPage == 3)
            memoryPages[iPage]->set_type(Page::OTP);
        else if (iPage < 16)
            memoryPages[iPage]->set_type(Page::DATA);
        else if (iPage < 18 || iPage == 19)
        {
            memoryPages[iPage]->set_type(Page::CFG);
            memoryPages[iPage]->set_writable(false);
        }
        else if (iPage == 18)
        {
            memoryPages[iPage]->set_type(Page::PWD);
            memoryPages[iPage]->set_writable(false);
            memoryPages[iPage]->set_readable(false);
        }
        else if (iPage == 19)
        {
            memoryPages[iPage]->set_type(Page::PACK);
            memoryPages[iPage]->set_writable(false);
            memoryPages[iPage]->set_readable(false);
        }

        return true;
    }

    if (memoryPages[iPage]->is_writable() && isAuth)
    {
        //  safe to delete, since we already checked if it's a nullptr
        delete memoryPages[iPage];
        memoryPages[iPage] = new Page(newPage);
    }
    else
        return false;

    return true;
}

void MfrUl_EV1_Card::set_counter(uint32_t iCounter, uint32_t newInitialValue)
{
    if (iCounter > 2)
        throw std::invalid_argument("There are only 3 counters");
    counters[iCounter]->set_value(newInitialValue);
}

bool MfrUl_EV1_Card::increment_counter(uint32_t iCounter, uint32_t operand)
{
    if (iCounter > 2)
        throw std::invalid_argument("There are only 3 counters");

    if (!isAuth)
        return false;

    //  check for overflow
    if (counters[iCounter]->get_value() + operand > 0x00FFFFFF)
        return false;

    counters[iCounter]->modify_value(operand);
    return true;
}

uint32_t MfrUl_EV1_Card::get_counter(uint32_t iCounter)
{
    if (iCounter > 2)
        throw std::invalid_argument("There are only 3 counters");

    return counters[iCounter]->get_value();
}

const std::vector<uint8_t> MfrUl_EV1_Card::get_pack() const
{
    std::vector<uint8_t> pack;
    if (!isAuth)
        return pack;

    //  first 2 bytes of page 19 store PACK
    pack.push_back(this->memoryPages[19]->get_data()[0]);
    pack.push_back(this->memoryPages[19]->get_data()[1]);

    return pack;
}

const std::string MfrUl_EV1_Card::get_pack_str() const
{
    std::stringstream buf;
    char hex[2];
    for (auto &byte : get_pack())
    {
        sprintf(hex, "%X", byte);
        buf << "\\"
            << "0x" << hex;
        // buf << std::endl;
    }
    return buf.str();
}

const std::string MfrUl_EV1_Card::str() const
{
    std::stringstream buf(MifareUltralightCard::str(), std::ios::app | std::ios::out);
    buf << "Counters: " << std::endl;
    int index = 0;
    for (auto &counter : counters)
        buf << "\tCounter #" << index++ << ": " << counter->get_value() << std::endl;

    return buf.str();
}

std::vector<uint8_t> MfrUl_C_Card::get_key() const
{
    std::vector<uint8_t> clearKey;
    clearKey.reserve(16);
    clearKey.insert(clearKey.end(), this->memoryPages[44]->get_data().begin(), this->memoryPages[44]->get_data().end());
    clearKey.insert(clearKey.end(), this->memoryPages[45]->get_data().begin(), this->memoryPages[45]->get_data().end());
    clearKey.insert(clearKey.end(), this->memoryPages[46]->get_data().begin(), this->memoryPages[46]->get_data().end());
    clearKey.insert(clearKey.end(), this->memoryPages[47]->get_data().begin(), this->memoryPages[47]->get_data().end());
    return clearKey;
}

MfrUl_C_Card::MfrUl_C_Card()
{
    protectionType = WRITE;
    protectedPage = 48; //  no protection
    this->token = new contactless::token::Token();
    this->token->set_type(contactless::token_type::MIFARE_UL_OR_ULC);
    type = m_C;
    memoryPages.resize(48);
    this->version = "No version";
}

MfrUl_C_Card::MfrUl_C_Card(const MfrUl_C_Card &otherCard)
    : MifareUltralightCard(otherCard)
{
    this->protectionType = otherCard.protectionType;
    this->protectedPage = otherCard.protectedPage;
}

MfrUl_C_Card::~MfrUl_C_Card()
{
}

bool MfrUl_C_Card::auth(const std::string &token)
{
    //  clear Key as byte string ("\0xff\0xff..."))
    std::stringstream bytesString(token); // string with all clear key bytes
    std::string byteStr;                  // single byte as hex string
    std::vector<uint8_t> byteArray;
    char delimiter = '\\';

    // get a single byte from the string
    while (std::getline(bytesString, byteStr, delimiter) && byteArray.size() < 16)
    {
        //  convert hex string to uint8
        if (byteStr.empty())
            continue;
        uint8_t byte = std::stoul(byteStr, nullptr, 16);

        byteArray.push_back(byte);
    }

    return auth(byteArray);
}

bool MfrUl_C_Card::auth(const std::vector<uint8_t> &token)
{
    isAuth = false;

    if (token.size() < 16)
        return false;

    int iByte = 0;
    for (auto &thisByte : this->get_key())
        if (thisByte != token[iByte++])
            return false;

    isAuth = true;
    return true;
}

void MfrUl_C_Card::deauth()
{
    isAuth = false;
}

bool MfrUl_C_Card::write_page(const Page &newPage, uint32_t iPage)
{
    if (iPage > 47)
        return false;

    // if it is initialization of a completely new page
    if (memoryPages[iPage] == nullptr)
    {
        memoryPages[iPage] = new Page(newPage);

        //  set permanent read/write rules
        if (iPage < 2)
        {
            memoryPages[iPage]->set_type(Page::SERIAL_NUMBER);
            memoryPages[iPage]->set_writable(false);
        }
        else if (iPage == 2 || iPage == 40)
            memoryPages[iPage]->set_type(Page::LOCK);
        else if (iPage == 3)
            memoryPages[iPage]->set_type(Page::OTP);
        else if (iPage < 40 || iPage == 41)
            memoryPages[iPage]->set_type(Page::DATA);
        else if (iPage < 44)
        {
            memoryPages[iPage]->set_type(Page::CFG);
            memoryPages[iPage]->set_writable(false);
        }
        else // from 44 to 47
        {
            memoryPages[iPage]->set_type(Page::KEY);
            memoryPages[iPage]->set_writable(false);
            memoryPages[iPage]->set_readable(false);
        }

        return true;
    }

    ////////////////////
    //  lambda for writing page
    auto write = [](Page *thisPage, const Page &newPage)
    {
        //  safe to delete, since we already checked if it's a nullptr
        delete thisPage;
        thisPage = new Page(newPage);
    };
    //////////////////////

    if (memoryPages[iPage]->is_writable())
    {
        if (iPage < protectedPage) //  if the page is protected by auth
            write(memoryPages[iPage], newPage);
        else if (isAuth) // if it IS protected, check auth
            write(memoryPages[iPage], newPage);
        else
            return false;
    }
    else
        return false;

    return true;
}

void MfrUl_C_Card::set_protection()
{
    protectedPage = memoryPages[42]->get_data()[0];

    //  check only the smallest bit
    if (memoryPages[43]->get_data()[0] % 2)
        //  if the bit was 1
        protectionType = WRITE;
    else
        // if the bit was 0
        protectionType = READ_WRITE;
}

uint16_t MfrUl_C_Card::get_counter() const
{
    // big endian. byte0 is less sugnificant than byte1
    return memoryPages[41]->get_data()[0] | (memoryPages[41]->get_data()[1] << 8);
}

const Page *MfrUl_C_Card::read_page(uint32_t iPage) const
{
    if (memoryPages[iPage]->is_readable()) //  clear key pages are unreadable
    {
        if (iPage < protectedPage)
            return memoryPages[iPage];
        else if (protectionType == WRITE) // if auth protection effects only write rights
            return memoryPages[iPage];
        else if (isAuth) // if read right are also effected
            return memoryPages[iPage];
    }

    return nullptr;
}

const std::string MfrUl_C_Card::str() const
{
    std::stringstream buf(MifareUltralightCard::str(), std::ios::app | std::ios::out);

    buf << "Protection type: " << ((protectionType == WRITE) ? "WRITE" : "READ_WRITE") << std::endl
        << "Protect from page: " << protectedPage << std::endl;

    return buf.str();
}
