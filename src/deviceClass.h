#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "../proto_src/intellireader/misc/reboot.pb.h"
#include "../proto_src/intellireader/misc/baudrate.pb.h"
#include "../proto_src/intellireader/misc/leds.pb.h"
#include "../proto_src/intellireader/misc/stats.pb.h"
#include "../proto_src/intellireader/misc/lwip.pb.h"
#include "../proto_src/intellireader/misc/event.pb.h"
#include "../proto_src/intellireader/misc/ethernet.pb.h"

#include "../proto_src/intellireader/contact/power_on.pb.h"
#include "../proto_src/intellireader/contact/power_off.pb.h"
#include "../proto_src/intellireader/contact/card_slot.pb.h"
#include "../proto_src/intellireader/contact/iso7816_4.pb.h"

#include "nlohmann/json.hpp"

class Script;

#include "myExceptions.h"
#include "scriptClass.h"
#include "cards.h"

struct DeviceInfoStruct
{
    std::string serialNumber;
    std::string intellireaderVersion;
};

struct DeviceStatusStruct
{
    uint32_t timeToRestart;
    misc::device::Security security;
};

struct ContactCardSlots
{
    bool MAIN_SLOT,
        SAM2_SLOT,
        SAM3_SLOT,
        SAM4_SLOT,
        SAM5_SLOT;
};

class Device
{
    using json = nlohmann::json;

private:
    std::string configFilePath;
    std::string inputFilePath;

    std::string serialNumber;
    std::string IntelliReaderVersion;
    misc::reboot::Reboot_OperationMode operationMode;
    misc::baudrate::Baudrate baudrate;
    uint32_t timeToRestart = 0;
    misc::device::Security *security;
    misc::lan_settings::LanSettings lanSettings;
    misc::leds::Leds leds;
    misc::stats::DeviceStatistic statistic;

    ContactCardSlots contactCardSlots;
    const ContactCard *cardInSlot;

    std::vector<const ContactlessCard *> cardsInField; // contactless cards in RF field of the terminal

    std::vector<Script *> scripts;

public:
    Device();
    Device(std::string configFilePath);
    ~Device();

    bool is_config_loaded();
    bool is_script_loaded();
    bool is_contact_card_present();

    void loadConfig(std::string configFilePath);
    void loadInputScriptFile(std::string inputScriptFilePath);
    misc::lwip::ProtocolStats *parseProtocolStatsJson(json &protocolStatsJson, const std::string protocolStatsName);
    misc::ethernet::PortStats *parsePortStatsJson(json &portStatsJson, const std::string portName);

    void _print_scripts();
    void execute_scripts();
    void insert_contact_card(const ContactCard &newCard);
    void remove_contact_card();
    void attach_contactless_card(const ContactlessCard &newCard);
    void remove_contactless_card(const std::string cardID);

    // if needed make a buzzer implimentation
    // until then messageClass::execute_make_sound() will print in terminal playing notes properties
    void set_leds_state(const misc::leds::Leds &newLedsState);
    void reboot(misc::reboot::Reboot_OperationMode operationMode);
    void set_baudrate(const misc::baudrate::Baudrate &newBaudrate);
    void set_lan_settings(const misc::lan_settings::LanSettings &newLanSettings);
    void set_contact_card_slot(contact::card_slot::CardSlot cardSlot, bool value);

    // make const return values
    DeviceInfoStruct get_device_info();
    DeviceStatusStruct get_device_status();
    const ContactCardSlots &get_contact_cards_slots_power();
    bool get_single_contact_card_slot_power(contact::card_slot::CardSlot cardSlot);
    const ContactCard &get_card_in_slot();
    misc::leds::Leds &get_leds_state();
    misc::reboot::Reboot_OperationMode &get_operation_mode();
    misc::stats::DeviceStatistic &get_device_statistic();
    misc::baudrate::Baudrate &get_baudrate();
    misc::lan_settings::LanSettings &get_lan_settings();
};