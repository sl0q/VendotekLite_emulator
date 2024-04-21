#pragma once

#include <string>

#include <../proto_src/intellireader/contact/card_slot.pb.h>

#include "../proto_src/intellireader/commands7.pb.h"

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
    // mifare::classic::auth::KeyType keyType;
    // mifare::classic::auth::ClearKey clearKey_A; //  key a of current sector
    // mifare::classic::auth::ClearKey clearKey_B; //  key b of current sector
    uint32_t iSector = UINT32_MAX; // index of authenticated sector
    std::vector<std::vector<std::string>> memorySectors;

public:
    MifareClassicCard();
    MifareClassicCard(MifareClassicCard::m_classic_K k);
    ~MifareClassicCard();

    // void set_key_type(mifare::classic::auth::KeyType newKeyType);
    // void set_clear_key_A(mifare::classic::auth::ClearKey &newClearKey);
    // void set_clear_key_B(mifare::classic::auth::ClearKey &newClearKey);
    // void set_clear_key_A(const std::string &newClearKey);
    // void set_clear_key_B(const std::string &newClearKey);
    void fill_memory(const std::vector<std::vector<std::string>> &newData);
    void write_sector(const std::vector<std::string> &newSector, uint32_t iSector);
    void write_block(const std::string &newBlock, uint32_t iSector, uint32_t iBlock);

    // const mifare::classic::auth::KeyType &get_key_type() const;
    const std::string get_clear_key_A(uint32_t iSector) const;
    const std::string get_clear_key_B(uint32_t iSector) const;
    const std::string &get_data_block(uint32_t iSector, uint32_t iBlock);

    void authorize_sector(uint32_t iSector);
    void reset_sector();

    const std::string str() const;
};

// class MifarePlusCard : public ContactlessCard
// {
// };

// class MifareUltralightCard : public ContactlessCard
// {

// };

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