#pragma once

#include <iostream>
#include <string>
#include <ostream>

#include <google/protobuf/message.h>
// #include <google/protobuf/text_format.h>
// #include <google/protobuf/util/json_util.h>

#include "../proto_src/common/failure.pb.h"

#include "../proto_src/intellireader/commands.pb.h"
#include "../proto_src/intellireader/misc/leds.pb.h"
#include "../proto_src/intellireader/misc/device.pb.h"
#include "../proto_src/intellireader/misc/reboot.pb.h"
#include "../proto_src/intellireader/misc/buzzer.pb.h"
#include "../proto_src/intellireader/misc/stats.pb.h"
#include "../proto_src/intellireader/misc/echo.pb.h"
#include "../proto_src/intellireader/misc/baudrate.pb.h"
#include "../proto_src/intellireader/misc/lan_settings.pb.h"

class Device;

#include "base64.h"
#include "checksum.h"
#include "myExceptions.h"
#include "deviceClass.h"
#include "payload.h"
#include "msg.h"

#define IR "IR"

class MessageIR
{
public:
    enum MsgType
    {
        COMMAND = 0x01,
        SUCCESS = 0x02,
        FAILURE = 0x03,
        PENDING = 0x04,
        NOTIFICATION = 0x05,
        CONTROL = 0x06
    };

private:
    std::vector<uint8_t> origMsg;
    uint8_t msgID;
    uint8_t moduleID;
    uint8_t messageType;
    uint16_t length;
    std::vector<uint8_t> payload;
    uint16_t checksum;

    google::protobuf::Message *msg; // pointer to protobuf message

    std::string moduleNameStr; // depends on moduleID

    google::protobuf::Message *find_protobuf_module();

    bool verify_checksum();
    bool parse_payload();

    void append_big_endian(std::vector<uint8_t> &buf, uint16_t n);

    void execute_misc(google::protobuf::Message *message, Device &myDevice);
    void execute_leds(Miscellaneous &miscMessage, Device &myDevice); // returns messageType of future response message
    void execute_read_device_info(Miscellaneous &miscMessage, Device &myDevice);
    void execute_reboot_device(Miscellaneous &miscMessage, Device &myDevice);
    void execute_get_device_status(Miscellaneous &miscMessage, Device &myDevice);
    void execute_make_sound(Miscellaneous &miscMessage, Device &myDevice);
    void execute_get_device_statistic(Miscellaneous &miscMessage, Device &myDevice);
    void execute_get_echo(Miscellaneous &miscMessage, Device &myDevice);
    void execute_change_baudrate(Miscellaneous &miscMessage, Device &myDevice);
    void execute_change_lan_settings(Miscellaneous &miscMessage, Device &myDevice);

    const Payload &generate_failure_payload(common::failure::Error errorType, const std::string errorString = "");

    const Payload &generate_device_info_payload(Device &myDevice);
    const Payload &generate_device_status_payload(Device &myDevice);
    const Payload &generate_device_statistic_payload(Device &myDevice);
    const Payload &generate_echo_payload(uint32_t replySize, const std::string &data);
    const Payload &generate_lan_settings_payload(Device &myDevice);

    const Msg &generate_responce(uint8_t responseType, const Payload &generatedPayload = Payload());

public:
    MessageIR();
    MessageIR(std::string encodedStringMessage);
    ~MessageIR();

    bool is_command();
    bool is_control();

    void execute_message(Device &myDevice);
};