#pragma once

#include <iostream>
#include <string>
#include <ostream>

#include <google/protobuf/message.h>

#include "../proto_src/common/failure.pb.h"
#include "../proto_src/common/notification.pb.h"

// #include "../proto_src/intellireader/commands4.pb.h"
#include "../proto_src/intellireader/commands7.pb.h"

class Device;
class Action;

#include "base64.h"
#include "checksum.h"
#include "myExceptions.h"
#include "deviceClass.h"
#include "payload.h"
#include "msg.h"
#include "cards.h"
#include "actionClass.h"

#define IR "IR"

// implement str() method

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
    std::vector<Action *> actions; // actions to do until timeout of IR message runs out if there is any

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

    //  Miscelaneous
    bool execute_misc(Device &myDevice);
    bool execute_leds(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_read_device_info(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_reboot_device(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_get_device_status(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_make_sound(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_get_device_statistic(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_get_echo(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_change_baudrate(Miscellaneous &miscMessage, Device &myDevice);
    bool execute_change_lan_settings(Miscellaneous &miscMessage, Device &myDevice);

    bool execute_contact();

    //  ContactlessLevel1
    bool execute_contactless_1(Device &myDevice);
    bool execute_poll_for_token(ContactlessLevel1 &contactlessMessage, Device &myDevice);
    bool execute_emv_removal(ContactlessLevel1 &contactlessMessage, Device &myDevice);
    bool execute_tsv_bit_array(ContactlessLevel1 &contactlessMessage, Device &myDevice);   //  not implemented
    bool execute_tsv_iso_command(ContactlessLevel1 &contactlessMessage, Device &myDevice); // not implemented
    bool execute_power_off_rf(ContactlessLevel1 &contactlessMessage, Device &myDevice);
    bool execute_rats(ContactlessLevel1 &contactlessMessage, Device &myDevice); // not implemented

    //  ContactlessLevel2
    bool execute_contactless_2(Device &myDevice);
    bool execute_perform_transaction(ContactlessLevel2 &contactlessMessage, Device &myDevice);

    //  Mifare
    bool execute_mifare(Device &myDevice);

    //  Classic
    const Msg &execute_mfr_classic_auth_on_clear_key(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_auth_on_sam_key(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_read_blocks(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_write_blocks(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_get_counter(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_set_counter(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_modify_counter(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_copy_counter(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_commit_counter(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_classic_bulk_operation(const Mifare &mifareMessage, Device &myDevice);

    //  Ultralight
    // const Msg &execute_mfr_ul_read_pages(const Mifare &mifareMessage, Device &myDevice);
    // const Msg &execute_mfr_ul_write_pages(const Mifare &mifareMessage, Device &myDevice);
    // const Msg &execute_mfr_ul_get_version(const Mifare &mifareMessage, Device &myDevice);
    // const Msg &execute_mfr_ul_get_counter(const Mifare &mifareMessage, Device &myDevice);
    // const Msg &execute_mfr_ul_increment_counter(const Mifare &mifareMessage, Device &myDevice);
    // const Msg &execute_mfr_ul_bulk_operation(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_ul_auth_on_clear_key(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_ul_auth_on_sam_key(const Mifare &mifareMessage, Device &myDevice);
    const Msg &execute_mfr_ul_auth_clear_password(const Mifare &mifareMessage, Device &myDevice);
    // const Msg &execute_mfr_ul_auth_sam_password(const Mifare &mifareMessage, Device &myDevice);

    const Payload &generate_failure_payload(common::failure::Error errorType, const std::string errorString = "");
    const Payload &generate_log_notification_payload(common::notification::LogMessage_Importance importance, const std::string msgString = "");
    const Payload &generate_user_notification_payload(common::notification::UserMessage_MessageId id);

    // Misc util
    const Payload &generate_device_info_payload(Device &myDevice);
    const Payload &generate_device_status_payload(Device &myDevice);
    const Payload &generate_device_statistic_payload(Device &myDevice);
    const Payload &generate_echo_payload(uint32_t replySize, const std::string &data);
    const Payload &generate_lan_settings_payload(Device &myDevice);

    // const Payload &generate_power_on_payload(Device &myDevice);
    // const Payload &generate_transmit_apdu_payload(const ContactCard &card);

    //  Contactless 1 util
    const Payload &generate_poll_for_token_payload(Device &myDevice, bool preferMifare);
    const Payload &generate_stored_poll_for_token_payload(Device &myDevice);

    //  Contactless 2 util
    const Payload &generate_perform_transaction_payload(Device &myDevice, bool preferMifare);

    // Mifare classic util
    const Payload &generate_mfr_classic_read_blocks_payload(std::string &data);
    const Payload &generate_mfr_classic_get_counter_payload(int32_t counterValue);
    const Payload &generate_mfr_classic_bulk_operation_payload(mifare::classic::bulk::BulkResult &results);

    // Mifare ultralight util
    const Payload &generate_mfr_ul_auth_clear_password_payload(std::string &newPack);

    const Msg &generate_responce(uint8_t responseType, const Payload &generatedPayload = Payload());

public:
    MessageIR();
    MessageIR(std::string encodedStringMessage);
    ~MessageIR();

    bool is_command();
    bool is_control();

    bool execute_message(Device &myDevice);
    void add_action(Action &newAction);
    const std::string str() const;
};
