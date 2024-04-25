#pragma once

#include <sstream>
#include <string>

#include <../proto_src/intellireader/contact/card_slot.pb.h>

#include "../proto_src/intellireader/commands7.pb.h"

#include "myExceptions.h"

#define BLOCK_SIZE 16
#define PLACEHOLDER '*'

class Block;

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
protected:
    uint32_t id;
    contactless::token::Token *token;

public:
    ContactlessCard();
    ContactlessCard(contactless::token_type::TokenType newTokenType);
    virtual ~ContactlessCard();
    void set_card_ID(uint32_t newCardID);
    void set_token(contactless::token::Token &newToken);
    void set_token_ID(std::string newTokenID);
    void set_atqa(std::string newATQA);
    void set_sak(std::string newSAK);

    uint32_t get_id() const;
    const contactless::token::Token *get_card_token() const;

    const virtual std::string str() const;
};

class Iso_4A : public ContactlessCard
{

public:
    Iso_4A();
    ~Iso_4A();

    void set_answer_to_select(const std::string newATS);

    const std::string str() const;
};

class Iso_B : public ContactlessCard
{

public:
    Iso_B();
    ~Iso_B();

    const std::string str() const;
};

class MifareClassicCard : public ContactlessCard
{
public:
    enum m_classic_K
    {
        m_1K = 1,
        m_2K = 2,
        m_4K = 3,
        m_MINI = 4
    };

private:
    uint32_t iSector = UINT32_MAX; // index of authenticated sector
    std::vector<std::vector<Block *>> memorySectors;
    int32_t internalRegister;

public:
    MifareClassicCard();
    MifareClassicCard(MifareClassicCard::m_classic_K k);
    ~MifareClassicCard();

    void fill_memory(const std::vector<std::vector<Block *>> &newData);
    void fill_empty_memory();
    void write_sector(const std::vector<Block *> &newSector, uint32_t iSector);
    void write_data_block(const std::string &newData, uint32_t iBlock);
    void write_value_block(int32_t newValue, uint32_t iBlock);
    void set_internal_register(int32_t value);

    const std::string get_clear_key_A(uint32_t iSector) const;
    const std::string get_clear_key_B(uint32_t iSector) const;
    const std::string &get_block_data(uint32_t iBlock) const;
    int32_t get_block_value(uint32_t iBlock) const;
    int32_t get_internal_register() const;

    void authorize_sector(uint32_t iSector);
    void reset_sector();

    const std::string str() const;
};

class SmartWithMifareCard : public ContactlessCard
{
public:
    enum m_smart_k
    {
        m_1K = 1,
        m_4K = 2
    };

private:
    mifare::classic::auth::KeyType keyType;
    Iso_4A *isoToken;
    MifareClassicCard *mifareToken;

public:
    SmartWithMifareCard();
    SmartWithMifareCard(SmartWithMifareCard::m_smart_k k);
    ~SmartWithMifareCard();

    Iso_4A &get_iso_token();
    const Iso_4A &get_iso_token() const;

    void set_allocated_iso(Iso_4A *newIsoCard);
    void set_allocated_mifare(MifareClassicCard *newMifareCard);
    MifareClassicCard &get_mifare_token();
    const MifareClassicCard &get_mifare_token() const;

    const std::string str() const;
};

//////////////////////////////////////////////////////////////////////

//  memory block types of mifare classic

//  base
class Block
{
protected:
    bool isValue;
    virtual void meme_method() = 0;

public:
    Block();
    ~Block();
    bool is_value();

    virtual std::string str() const = 0;
};

//  block initilized for storing numeric values
class ValueBlock : public Block
{
private:
    int32_t value;
    void meme_method();

public:
    ValueBlock();
    ValueBlock(const int32_t newValue);
    ~ValueBlock();
    void set_value(const int32_t newValue);
    int32_t get_value() const;
    const std::string &get_data() const; //  get value as a string
    std::string str() const;
};

//  block initilized for storing byte data
class ByteBlock : public Block
{
private:
    std::string data;
    void meme_method();

public:
    // ByteBlock();
    ByteBlock(bool fill = false);
    ByteBlock(const std::string &newData);
    ~ByteBlock();
    void set_data(const std::string &newData);
    const std::string &get_data() const;
    std::string str() const;
};

///////////////////////////////////////////////////////////////////////////

//  memory page of mifare ultralight
#define PAGE_LENGTH 4 // how many bytes in one page

class Page
{
public:
    enum PageType
    {
        SERIAL_NUMBER = 1, //  for page #0 and #1
        DATA = 2,          // for pages #4 - #15
        OTP = 3,           //  for page #3
        PWD = 4,           //  for page #18
        CFG = 5,           // for pages #16, 17, (19)
        COUNTER = 6,       // for pages #20 and beyond
        LOCK = 7           //  for page #2
    };

private:
    std::vector<uint8_t> bytes;
    PageType type;
    bool readOnly = false;

public:
    Page();
    Page(Page::PageType newPageType, const std::vector<uint8_t> &newData);

    bool is_read_only() const;

    void set_data(const std::vector<uint8_t> &newData);
    void set_type(Page::PageType newPageType);
    void set_bit(uint8_t iBit); //  this method will be used for permanent writing. It can only set bit to 1

    const std::vector<uint8_t> &get_data() const;
    const std::string &get_data_str() const;
};

class MifareUltralightCard : public ContactlessCard
{
public:
    enum m_ul_type
    {
        m_EV1 = 1,
        m_C = 2
    };

private:
    m_ul_type type;
    std::vector<Page *> memoryPages;
    int32_t internalRegister; // exist?

public:
    MifareUltralightCard();
    MifareUltralightCard(MifareUltralightCard::m_ul_type newType);
    ~MifareUltralightCard();

    void fill_memory(const std::vector<Page *> &newData);
    void fill_empty_memory();
    void write_page(const Page &newPage, uint32_t iPage);
    void set_internal_register(int32_t value); //  exist?

    const Page &get_page(uint32_t iPage) const;
    int32_t get_internal_register() const; //  exist?

    const std::string str() const;
};

// class MifarePlusCard : public ContactlessCard
// {
// };