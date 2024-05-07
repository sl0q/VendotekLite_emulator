#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

#include "byteConvertion.h"
#include "payload.h"

class Msg
{
private:
    std::vector<uint8_t> msgBytes;
    std::string encodedMsgBytes;
    std::string typeStr; // Success/Failure/pending/notification/control
    Payload payload;
    bool isFailure = false;

public:
    Msg();
    Msg(const Payload &newPayload, const std::vector<uint8_t> &newData, std::string &typeStr, bool isFailure = false);
    Msg(const Msg &otherMsg);
    ~Msg();

    bool is_empty() const;
    bool is_failure() const;
    void clear();

    const std::string &get_debug_string() const;
    const std::vector<uint8_t> &get_msg_bytes() const;
    const std::string get_msg_bytes_as_string() const;
    const std::string &get_encoded_msg_bytes() const;
    const std::string &get_type_str() const;
    const Payload &get_payload() const;
    void print_MSG() const;
};