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

#include "nlohmann/json.hpp"

class Script;

#include "myExceptions.h"
#include "scriptClass.h"

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
    // bool lanMode; // true - dhcp; false - manual
    // std::string localAddress;
    // std::string netmask;
    // std::string gateway;

    misc::leds::Leds leds;

    misc::stats::DeviceStatistic statistic;

    std::vector<Script> scripts;

public:
    Device();
    Device(std::string configFilePath);

    DeviceInfoStruct get_device_info();
    DeviceStatusStruct get_device_status();

    bool isConfigLoaded();
    bool isScriptLoaded();

    void loadConfig(std::string configFilePath);
    void loadInputScriptFile(std::string inputScriptFilePath);
    misc::lwip::ProtocolStats *parseProtocolStatsJson(json &protocolStatsJson, const std::string protocolStatsName);
    misc::ethernet::PortStats *parsePortStatsJson(json &portStatsJson, const std::string portName);

    void _print_scripts();
    void execute_scripts();

    // if needed make a buzzer implimentation
    // until then messageClass::execute_make_sound() will print in terminal playing notes properties
    void set_leds_state(const misc::leds::Leds &newLedsState);
    void reboot(misc::reboot::Reboot_OperationMode operationMode);
    void set_baudrate(const misc::baudrate::Baudrate &newBaudrate);
    void set_lan_settings(const misc::lan_settings::LanSettings &newLanSettings);

    // make const return values
    misc::leds::Leds &get_leds_state();
    misc::reboot::Reboot_OperationMode &get_operation_mode();
    misc::stats::DeviceStatistic &get_device_statistic();
    misc::baudrate::Baudrate &get_baudrate();
    misc::lan_settings::LanSettings &get_lan_settings();
};

class Statistic
{
private:
};