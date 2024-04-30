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
#include "msg.h"

struct ContactCardSlots
{
    bool MAIN_SLOT,
        SAM2_SLOT,
        SAM3_SLOT,
        SAM4_SLOT,
        SAM5_SLOT;
};

class StoredDeviceInfo
{
private:
    std::string serialNumber;
    std::string intellireaderVersion;

public:
    StoredDeviceInfo();
    StoredDeviceInfo(const std::string &newSerialNumber, const std::string newIRVersion);

    void set_serial_number(const std::string &newSerialNumber);
    void set_IR_version(const std::string &newIRVersion);

    const std::string &get_serial_number() const;
    const std::string &get_IR_version() const;
};

class StoredDeviceStatus
{
private:
    uint32_t timeToRestart;
    misc::device::Security *security = nullptr;

public:
    StoredDeviceStatus();
    StoredDeviceStatus(uint32_t newTimeToRestart, misc::device::Security *newSecurity);
    ~StoredDeviceStatus();

    void set_time_to_restart(uint32_t newTimeToRestart);
    void set_security(misc::device::Security *newSecurity);

    uint32_t get_time_to_restart() const;
    const misc::device::Security &get_security() const;
};

class Device
{
    using json = nlohmann::json;

private:
    std::string configFilePath;
    std::string inputFilePath;

    // Device properties
    StoredDeviceInfo deviceInfo;
    StoredDeviceStatus deviceStatus;

    misc::reboot::Reboot_OperationMode operationMode;
    misc::baudrate::Baudrate baudrate;
    misc::lan_settings::LanSettings lanSettings;
    misc::leds::Leds leds;

    // Device collected data
    misc::stats::DeviceStatistic statistic;
    contactless::token::Token storedToken; // saved responce on contactless::poll_for_token command

    std::vector<ContactlessCard *> cardsInField; // contactless cards in RF field of the terminal

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
    std::vector<std::string> load_input_script_file(std::string inputScriptFilePath);
    misc::lwip::ProtocolStats *parseProtocolStatsJson(json &protocolStatsJson, const std::string protocolStatsName);
    misc::ethernet::PortStats *parsePortStatsJson(json &portStatsJson, const std::string portName);

    void _print_scripts();
    void execute_scripts(std::ostream &logStream);
    void load_default_state();
    void load_configured_state();
    void attach_contactless_card(uint32_t cardID);
    void remove_contactless_card(uint32_t cardID);
    ContactlessCard *get_card_in_field();
    uint32_t how_many_cards();
    void wait(uint32_t timeToWait_ms);

    // if needed make a buzzer implimentation
    // until then messageClass::execute_make_sound() will print in terminal playing notes properties
    void set_leds_state(const misc::leds::Leds &newLedsState);
    void reboot(misc::reboot::Reboot_OperationMode operationMode);
    void set_baudrate(const misc::baudrate::Baudrate &newBaudrate);
    void set_lan_settings(const misc::lan_settings::LanSettings &newLanSettings);

    // make const return values
    const StoredDeviceInfo &get_device_info();
    const StoredDeviceStatus &get_device_status();
    const misc::leds::Leds &get_leds_state();
    const misc::reboot::Reboot_OperationMode &get_operation_mode();
    const misc::stats::DeviceStatistic &get_device_statistic();
    const misc::baudrate::Baudrate &get_baudrate();
    const misc::lan_settings::LanSettings &get_lan_settings();

    const contactless::token::Token &get_stored_token();
    void store_token(const contactless::token::Token &responce);
};
