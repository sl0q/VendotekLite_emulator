#include "deviceClass.h"

Device::Device()
{
    this->serialNumber = "CL4P7R4P";
    this->IntelliReaderVersion = "1.50";
    this->operationMode = misc::reboot::Reboot_OperationMode::Reboot_OperationMode_NORMAL_MODE;
    this->baudrate = misc::baudrate::BPS_115200;

    this->timeToRestart = 0;
    this->security = new misc::device::Security();
    this->security->set_enabled(true);
    this->security->set_pci_pts_functions_permitted(true);
    this->security->set_restrictions_reason("");
    this->security->set_anti_removal_protection(misc::device::AntiRemovalProtState::ACTIVATED);

    misc::lan_settings::Dhcp dhcp;
    this->lanSettings.set_allocated_dhcp(&dhcp);

    this->contactCardSlots = {false, false, false, false, false};

    this->cardInSlot = nullptr;
    // this->lanMode = true; // true - dhcp; false - manual
}

Device::Device(std::string configFilePath)
{
    loadConfig(configFilePath);
    this->contactCardSlots = {false, false, false, false, false};
}

Device::~Device()
{
    for (auto script : this->scripts)
    {
        if (script != nullptr)
            delete script;
    }
}

DeviceInfoStruct Device::get_device_info()
{
    return {this->serialNumber, this->IntelliReaderVersion};
}

DeviceStatusStruct Device::get_device_status()
{
    return {this->timeToRestart, *this->security};
}

const ContactCardSlots &Device::get_contact_cards_slots_power()
{
    return this->contactCardSlots;
}

bool Device::get_single_contact_card_slot_power(contact::card_slot::CardSlot cardSlot)
{
    switch (cardSlot)
    {
    case contact::card_slot::MAIN_SLOT:
        return this->contactCardSlots.MAIN_SLOT;
    case contact::card_slot::SAM2_SLOT:
        return this->contactCardSlots.SAM2_SLOT;
    case contact::card_slot::SAM3_SLOT:
        return this->contactCardSlots.SAM3_SLOT;
    case contact::card_slot::SAM4_SLOT:
        return this->contactCardSlots.SAM4_SLOT;
    case contact::card_slot::SAM5_SLOT:
        return this->contactCardSlots.SAM5_SLOT;
    default:
        return false;
    }
}

const ContactCard &Device::get_card_in_slot()
{
    return *this->cardInSlot;
}

bool Device::is_config_loaded()
{
    return !this->configFilePath.empty();
}

bool Device::is_script_loaded()
{
    return !this->inputFilePath.empty();
}

bool Device::is_contact_card_present()
{
    return this->cardInSlot != nullptr;
}

void Device::loadConfig(std::string configFilePath)
{
    // открыть JSON
    std::ifstream file(configFilePath);
    if (!file.is_open())
        throw ex::CantOpenFile("Failed to open file [" + configFilePath + "]");

    // записать данные в переменную
    json json_content;
    file >> json_content;

    file.close();

    // парсинг
    std::string tempStr;

    if (json_content.count("inputFile") != 0)
        loadInputScriptFile(json_content.at("inputFile").get<std::string>());
    else
        std::cout << "WARNING: Input script file was not provided.";

    if (json_content.count("device") == 0)
        throw ex::JsonParsingException("Could not find required [device] field in [" + configFilePath + "] file.");

    json deviceJson = json_content["device"];

    if (deviceJson.count("serialNumber") != 0)
        this->serialNumber = deviceJson.at("serialNumber").get<std::string>();
    else
        this->serialNumber = "CL4P7R4P";

    if (deviceJson.count("IntelliReaderVersion") != 0)
        this->IntelliReaderVersion = deviceJson.at("IntelliReaderVersion").get<std::string>();
    else
        this->IntelliReaderVersion = "1.50";

    if (deviceJson.count("operationMode") != 0)
    {
        if (!misc::reboot::Reboot_OperationMode_Parse(deviceJson.at("operationMode").get<std::string>(), &this->operationMode))
            throw ex::JsonParsingException("Field [device:operationMode] has unknown value.");
    }
    else
        this->operationMode = misc::reboot::Reboot_OperationMode::Reboot_OperationMode_NORMAL_MODE;

    if (deviceJson.count("baudrate") != 0)
    {
        if (!misc::baudrate::Baudrate_Parse(deviceJson.at("baudrate").get<std::string>(), &this->baudrate))
            throw ex::JsonParsingException("Field [device:baudrate] has unknown value.");
    }
    else
        this->baudrate = misc::baudrate::BPS_115200;

    this->security = new misc::device::Security();
    if (deviceJson.count("security") != 0)
    {
        if (deviceJson["security"].count("enabled") == 0)
            throw ex::JsonParsingException("Could not find required [device:security:enabled] field in [" + configFilePath + "] file.");
        this->security->set_enabled(deviceJson["security"].at("enabled").get<bool>());

        if (deviceJson["security"].count("pciPtsFunctionsPermitted") == 0)
            throw ex::JsonParsingException("Could not find required [device:security:pciPtsFunctionPermitted] field in [" + configFilePath + "] file.");
        this->security->set_pci_pts_functions_permitted(deviceJson["security"].at("pciPtsFunctionsPermitted").get<bool>());

        if (deviceJson["security"].count("restrictionsReason") != 0)
            this->security->set_restrictions_reason(deviceJson["security"].at("restrictionsReason").get<std::string>());

        if (deviceJson["security"].count("antiRemovalProtection") != 0)
        {
            std::string tempStr = deviceJson["security"].at("antiRemovalProtection").get<std::string>();
            if ("ACTIVATED" == tempStr)
                this->security->set_anti_removal_protection(misc::device::ACTIVATED);
            else if ("DEACTIVATED" == tempStr)
                this->security->set_anti_removal_protection(misc::device::DEACTIVATED);
        }
        else
            this->security->set_anti_removal_protection(misc::device::DEACTIVATED);
    }
    else
    {
        this->security->set_enabled(true);
        this->security->set_pci_pts_functions_permitted(true);
        this->security->set_restrictions_reason("");
        this->security->set_anti_removal_protection(misc::device::AntiRemovalProtState::ACTIVATED);
    }

    if (deviceJson.count("lanSettings") != 0)
    {
        if (deviceJson["lanSettings"].count("manual") != 0)
        {
            misc::lan_settings::ManualSettings *manualSettings = new misc::lan_settings::ManualSettings();
            // this->lanMode = false; // false means manual lan mode
            if (this->lanSettings.has_dhcp())
                this->lanSettings.release_dhcp();
            this->lanSettings.set_allocated_manual(manualSettings);

            json manualJson = deviceJson["lanSettings"]["manual"];

            if (manualJson.count("localAddress") == 0)
                throw ex::JsonParsingException("Could not find required [device:lanSettngs:manual:localAddress] field in [" + configFilePath + "] file.");
            if (manualJson.count("netmask") == 0)
                throw ex::JsonParsingException("Could not find required [device:lanSettngs:manual:netmask] field in [" + configFilePath + "] file.");
            if (manualJson.count("gateway") == 0)
                throw ex::JsonParsingException("Could not find required [device:lanSettngs:manual:gateway] field in [" + configFilePath + "] file.");

            manualSettings->set_local_address(manualJson.at("localAddress").get<std::string>());
            manualSettings->set_netmask(manualJson.at("netmask").get<std::string>());
            manualSettings->set_gateway(manualJson.at("gateway").get<std::string>());
            // this->localAddress = manualJson.at("localAddress").get<std::string>();
            // this->netmask = manualJson.at("netmask").get<std::string>();
            // this->gateway = manualJson.at("gateway").get<std::string>();
        }
        else
        {
            misc::lan_settings::Dhcp dhcp;
            if (this->lanSettings.has_manual())
                this->lanSettings.release_manual();
            this->lanSettings.set_allocated_dhcp(&dhcp);
            // this->lanMode = true; // means dhcp lan mode
        }
    }
    else
    {
        misc::lan_settings::Dhcp dhcp;
        if (this->lanSettings.has_manual())
            this->lanSettings.release_manual();
        this->lanSettings.set_allocated_dhcp(&dhcp);
        // this->lanMode = true; // means dhcp lan mode
    }

    if (deviceJson.count("statistic") != 0)
    {
        if (deviceJson["statistic"].count("lwip") != 0)
        {
            misc::lwip::Statistic *lwip = new misc::lwip::Statistic();
            this->statistic.set_allocated_lwip(lwip);

            if (deviceJson["statistic"]["lwip"].count("link") == 0)
                throw ex::JsonParsingException("Could not find required [device:statistic:lwip:link] field in [" + configFilePath + "] file.");
            // misc::lwip::ProtocolStats *link = new misc::lwip::ProtocolStats();
            misc::lwip::ProtocolStats *link = parseProtocolStatsJson(deviceJson["statistic"]["lwip"]["link"], "link");
            lwip->set_allocated_link(link);

            if (deviceJson["statistic"]["lwip"].count("arp") == 0)
                throw ex::JsonParsingException("Could not find required [device:statistic:lwip:arp] field in [" + configFilePath + "] file.");
            misc::lwip::ProtocolStats *arp = parseProtocolStatsJson(deviceJson["statistic"]["lwip"]["arp"], "arp");
            lwip->set_allocated_arp(arp);

            if (deviceJson["statistic"]["lwip"].count("ip") == 0)
                throw ex::JsonParsingException("Could not find required [device:statistic:lwip:ip] field in [" + configFilePath + "] file.");
            misc::lwip::ProtocolStats *ip = parseProtocolStatsJson(deviceJson["statistic"]["lwip"]["ip"], "ip");
            lwip->set_allocated_ip(ip);

            if (deviceJson["statistic"]["lwip"].count("tcp") == 0)
                throw ex::JsonParsingException("Could not find required [device:statistic:lwip:tcp] field in [" + configFilePath + "] file.");
            misc::lwip::ProtocolStats *tcp = parseProtocolStatsJson(deviceJson["statistic"]["lwip"]["tcp"], "tcp");
            lwip->set_allocated_tcp(tcp);
        }
        if (deviceJson["statistic"].count("events") != 0)
        {
            int i = 0;
            for (json &eventJson : deviceJson["statistic"]["events"])
            {
                misc::event::Event *newEvent = this->statistic.add_events();
                if (eventJson.count("eventType") == 0)
                    throw ex::JsonParsingException("Could not find required [device:statistic:events:" + std::to_string(i) + ":eventType] field in [" + configFilePath + "] file.");

                misc::event::EventType eventType;
                misc::event::EventType_Parse(eventJson.at("eventType").get<std::string>(), &eventType);

                newEvent->set_event_type(eventType);

                if (eventJson.count("eventTimeOffset") == 0)
                    throw ex::JsonParsingException("Could not find required [device:statistic:events:" + std::to_string(i) + ":eventTimeOffset] field in [" + configFilePath + "] file.");
                newEvent->set_event_time_offset(eventJson.at("eventTimeOffset").get<uint32_t>());

                if (eventJson.count("eventInfo") != 0)
                    newEvent->set_event_info(eventJson.at("eventInfo").get<std::string>());

                ++i;
            }
        }
        if (deviceJson["statistic"].count("ethernet") != 0)
        {
            if (deviceJson["statistic"]["ethernet"].count("port1") != 0)
            {
                misc::ethernet::Statistic *ethernet = new misc::ethernet::Statistic();

                this->statistic.set_allocated_ethernet(ethernet);

                if (deviceJson["statistic"]["ethernet"].count("port1") == 0)
                    throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:port1] field in [" + configFilePath + "] file.");
                misc::ethernet::PortStats *port1 = parsePortStatsJson(deviceJson["statistic"]["ethernet"]["port1"], "port1");
                ethernet->set_allocated_port1(port1);

                if (deviceJson["statistic"]["ethernet"].count("port2") == 0)
                    throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:port2] field in [" + configFilePath + "] file.");
                misc::ethernet::PortStats *port2 = parsePortStatsJson(deviceJson["statistic"]["ethernet"]["port2"], "port2");
                ethernet->set_allocated_port2(port2);

                if (deviceJson["statistic"]["ethernet"].count("port3") == 0)
                    throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:port3] field in [" + configFilePath + "] file.");
                misc::ethernet::PortStats *port3 = parsePortStatsJson(deviceJson["statistic"]["ethernet"]["port3"], "port3");
                ethernet->set_allocated_port3(port3);
            }
        }
    }

    std::cout << "Configuration file was successfuly loaded." << std::endl;
    this->configFilePath = configFilePath;
}

void Device::loadInputScriptFile(std::string inputScriptFilePath)
{
    // открыть JSON
    std::ifstream file(inputScriptFilePath);
    if (!file.is_open())
        throw ex::CantOpenFile("Failed to open file [" + inputScriptFilePath + "]");

    // записать данные в переменную
    json json_content;
    file >> json_content;

    file.close();

    // достать scripts
    if (json_content.count("scripts") == 0)
        throw ex::JsonParsingException("Could not find required [scripts] field in [" + inputScriptFilePath + "] file.");

    if (this->scripts.size())
    {
        this->scripts.clear();
        std::cout << "Old scripts were deleted.\n";
    }

    for (const auto &scriptJson : json_content["scripts"])
    {
        std::vector<std::string> readedMessages;

        if (scriptJson.count("messages") != 0)
            for (auto &m : scriptJson["messages"]) //&m ВОЗМОЖНО НЕ string
                readedMessages.push_back(m);

        std::string newTitle;
        if (scriptJson.count("title") != 0)
            newTitle = scriptJson.at("title").get<std::string>();
        else
            newTitle = "Unnamed script";

        auto newScript = new Script(newTitle, readedMessages);

        if (scriptJson.count("card") != 0)
        {
            if (scriptJson["card"].count("contact") == 0)
                throw ex::JsonParsingException("Could not find required [scripts:card:contact] field in [" + inputScriptFilePath + "] file.");
            if (scriptJson["card"].at("contact").get<bool>()) // if it is contact
            {
                if (scriptJson["card"].count("expectedHistoricalBytes") == 0)
                    throw ex::JsonParsingException("Could not find required [scripts:card:expectedHistoricalBytes] field in [" + inputScriptFilePath + "] file.");
                if (scriptJson["card"].count("expectedApduTrailer") == 0)
                    throw ex::JsonParsingException("Could not find required [scripts:card:expectedApduTrailer] field in [" + inputScriptFilePath + "] file.");
                if (scriptJson["card"].count("expectedResponceBody") == 0)
                    throw ex::JsonParsingException("Could not find required [scripts:card:expectedResponceBody] field in [" + inputScriptFilePath + "] file.");
                if (scriptJson["card"].count("cardSlot") == 0)
                    throw ex::JsonParsingException("Could not find required [scripts:card:cardSlot] field in [" + inputScriptFilePath + "] file.");

                ContactCard *newContactCard = new ContactCard(scriptJson["card"].at("expectedHistoricalBytes").get<std::string>(),
                                                              scriptJson["card"].at("expectedApduTrailer").get<uint32_t>(),
                                                              scriptJson["card"].at("expectedResponceBody").get<std::string>(),
                                                              scriptJson["card"].at("cardSlot").get<std::string>());

                newScript->set_contact_card(newContactCard);
            }
            else //  if it is contactless
            {
            }
        }

        this->scripts.push_back(newScript);
    }

    std::cout << "Scripts were successfuly loaded." << std::endl;
    this->inputFilePath = inputScriptFilePath;
}

misc::lwip::ProtocolStats *Device::parseProtocolStatsJson(json &protocolStatsJson, const std::string protocolStatsName)
{
    misc::lwip::ProtocolStats *protocolStats = new misc::lwip::ProtocolStats();

    if (protocolStatsJson.count("xmit") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":xmit] field in [" + configFilePath + "] file.");
    protocolStats->set_xmit(protocolStatsJson.at("xmit").get<uint32_t>());

    if (protocolStatsJson.count("recv") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":recv] field in [" + configFilePath + "] file.");
    protocolStats->set_recv(protocolStatsJson.at("recv").get<uint32_t>());

    if (protocolStatsJson.count("fw") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":fw] field in [" + configFilePath + "] file.");
    protocolStats->set_fw(protocolStatsJson.at("fw").get<uint32_t>());

    if (protocolStatsJson.count("drop") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":drop] field in [" + configFilePath + "] file.");
    protocolStats->set_drop(protocolStatsJson.at("drop").get<uint32_t>());

    if (protocolStatsJson.count("chkerr") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":chkerr] field in [" + configFilePath + "] file.");
    protocolStats->set_chkerr(protocolStatsJson.at("chkerr").get<uint32_t>());

    if (protocolStatsJson.count("lenerr") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":lenerr] field in [" + configFilePath + "] file.");
    protocolStats->set_lenerr(protocolStatsJson.at("lenerr").get<uint32_t>());

    if (protocolStatsJson.count("memerr") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":memerr] field in [" + configFilePath + "] file.");
    protocolStats->set_memerr(protocolStatsJson.at("memerr").get<uint32_t>());

    if (protocolStatsJson.count("rterr") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":rterr] field in [" + configFilePath + "] file.");
    protocolStats->set_rterr(protocolStatsJson.at("rterr").get<uint32_t>());

    if (protocolStatsJson.count("proterr") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":proterr] field in [" + configFilePath + "] file.");
    protocolStats->set_proterr(protocolStatsJson.at("proterr").get<uint32_t>());

    if (protocolStatsJson.count("opterr") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":opterr] field in [" + configFilePath + "] file.");
    protocolStats->set_opterr(protocolStatsJson.at("opterr").get<uint32_t>());

    if (protocolStatsJson.count("err") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:lwip:" + protocolStatsName + ":err] field in [" + configFilePath + "] file.");
    protocolStats->set_err(protocolStatsJson.at("err").get<uint32_t>());

    return protocolStats;
}

misc::ethernet::PortStats *Device::parsePortStatsJson(json &portStatsJson, const std::string portName)
{
    misc::ethernet::PortStats *portStats = new misc::ethernet::PortStats();

    if (portStatsJson.count("tx_packets") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:" + portName + ":tx_packets] field in [" + configFilePath + "] file.");
    portStats->set_tx_packets(portStatsJson.at("tx_packets").get<uint32_t>());

    if (portStatsJson.count("rx_packets") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:" + portName + ":rx_packets] field in [" + configFilePath + "] file.");
    portStats->set_rx_packets(portStatsJson.at("rx_packets").get<uint32_t>());

    if (portStatsJson.count("rx_errors") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:" + portName + ":rx_errors] field in [" + configFilePath + "] file.");
    portStats->set_rx_errors(portStatsJson.at("rx_errors").get<uint32_t>());

    if (portStatsJson.count("txrx_dropped") == 0)
        throw ex::JsonParsingException("Could not find required [device:statistic:ethernet:" + portName + ":txrx_dropped] field in [" + configFilePath + "] file.");
    portStats->set_txrx_dropped(portStatsJson.at("txrx_dropped").get<uint32_t>());

    return portStats;
}

void Device::_print_scripts()
{
    for (auto &s : this->scripts)
    {
        std::cout << "Title: " << s->getTitle() << std::endl
                  << "Messages: " << std::endl;
        for (auto &m : s->getMessages())
            std::cout << "\t" << m << std::endl;
        std::cout << std::endl;
    }
}

void Device::execute_scripts()
{
    if (this->scripts.size() == 0)
    {
        std::cout << "No scripts are available" << std::endl;
        return;
    }
    int i = 1;
    for (auto &s : this->scripts)
    {
        std::cout << "Script #" << i++ << ":\n";
        s->execute_script(*this);
    }
}

void Device::insert_contact_card(const ContactCard &newCard)
{
    this->cardInSlot = &newCard;
}

void Device::remove_contact_card()
{
    this->contactCardSlots = {false, false, false, false, false};
    this->cardInSlot = nullptr;
}

void Device::attach_contactless_card(const ContactlessCard &newCard)
{
    this->cardsInField.push_back(&newCard);
}

void Device::remove_contactless_card(const std::string cardID)
{
    int i = 0;
    for (auto card : this->cardsInField)
        if (cardID == card->get_id())
            this->cardsInField.erase(this->cardsInField.begin() + i);
}

void Device::set_leds_state(const misc::leds::Leds &newLedsState)
{
    this->leds = newLedsState;
}

void Device::reboot(misc::reboot::Reboot_OperationMode operationMode)
{
    this->operationMode = operationMode;
}

void Device::set_baudrate(const misc::baudrate::Baudrate &newBaudrate)
{
    this->baudrate = newBaudrate;
}

void Device::set_lan_settings(const misc::lan_settings::LanSettings &newLanSettings)
{
    this->lanSettings = newLanSettings;
}

void Device::set_contact_card_slot(contact::card_slot::CardSlot cardSlot, bool value)
{
    switch (cardSlot)
    {
    case contact::card_slot::MAIN_SLOT:
        this->contactCardSlots.MAIN_SLOT = value;
        break;
    case contact::card_slot::SAM2_SLOT:
        this->contactCardSlots.SAM2_SLOT = value;
        break;
    case contact::card_slot::SAM3_SLOT:
        this->contactCardSlots.SAM3_SLOT = value;
        break;
    case contact::card_slot::SAM4_SLOT:
        this->contactCardSlots.SAM4_SLOT = value;
        break;
    case contact::card_slot::SAM5_SLOT:
        this->contactCardSlots.SAM5_SLOT = value;
        break;
    default:
        std::cout << "Unknown contact card slot." << std::endl;
    }
}

misc::leds::Leds &Device::get_leds_state()
{
    return this->leds;
}

misc::reboot::Reboot_OperationMode &Device::get_operation_mode()
{
    return this->operationMode;
}

misc::stats::DeviceStatistic &Device::get_device_statistic()
{
    return this->statistic;
}

misc::baudrate::Baudrate &Device::get_baudrate()
{
    return this->baudrate;
}

misc::lan_settings::LanSettings &Device::get_lan_settings()
{
    return this->lanSettings;
}
