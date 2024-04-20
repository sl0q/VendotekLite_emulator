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
// class Step;

#include "myExceptions.h"
#include "scriptClass.h"
#include "cards.h"
#include "msg.h"

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

    // Device properties
    std::string serialNumber;
    std::string IntelliReaderVersion;
    misc::reboot::Reboot_OperationMode operationMode;
    misc::baudrate::Baudrate baudrate;
    uint32_t timeToRestart = 0;
    misc::device::Security *security;
    misc::lan_settings::LanSettings lanSettings;
    misc::leds::Leds leds;

    // Device collected data
    misc::stats::DeviceStatistic statistic;
    contactless::token::Token storedToken; // saved responce on contactless::poll_for_token command

    std::vector<const ContactlessCard *> cardsInField; // contactless cards in RF field of the terminal

    std::vector<Script *> scripts;
    uint32_t iScript,
        iCard,
        iStep;

public:
    Device();
    Device(std::string configFilePath);
    ~Device();

    bool is_config_loaded();
    bool is_script_loaded();

    void load_config(std::string configFilePath);
    void load_input_script_file(std::string inputScriptFilePath);
    misc::lwip::ProtocolStats *parseProtocolStatsJson(json &protocolStatsJson, const std::string protocolStatsName);
    misc::ethernet::PortStats *parsePortStatsJson(json &portStatsJson, const std::string portName);

    void _print_scripts();
    void execute_scripts();
    void load_default_state();
    void load_configured_state();
    void attach_contactless_card(uint32_t cardID);
    void remove_contactless_card(uint32_t cardID);
    const ContactlessCard *get_card_in_field();
    uint32_t how_many_cards();
    void wait(uint32_t timeToWait_ms);

    // if needed make a buzzer implimentation
    // until then messageClass::execute_make_sound() will print in terminal playing notes properties
    void set_leds_state(const misc::leds::Leds &newLedsState);
    void reboot(misc::reboot::Reboot_OperationMode operationMode);
    void set_baudrate(const misc::baudrate::Baudrate &newBaudrate);
    void set_lan_settings(const misc::lan_settings::LanSettings &newLanSettings);

    // make const return values
    DeviceInfoStruct get_device_info();
    DeviceStatusStruct get_device_status();
    misc::leds::Leds &get_leds_state();
    misc::reboot::Reboot_OperationMode &get_operation_mode();
    const misc::stats::DeviceStatistic &get_device_statistic();
    misc::baudrate::Baudrate &get_baudrate();
    misc::lan_settings::LanSettings &get_lan_settings();

    const contactless::token::Token &get_stored_token();
    void store_token(const contactless::token::Token &responce);
};