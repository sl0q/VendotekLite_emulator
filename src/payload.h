#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <google/protobuf/message.h>

class Payload
{
private:
    std::string debugString;
    std::vector<uint8_t> data;
    google::protobuf::Message *responceMsg = nullptr;

public:
    Payload();
    Payload(google::protobuf::Message *newResponceData);
    Payload(const Payload &otherPayload);
    ~Payload();

    const std::string &get_debug_string() const;
    const std::vector<uint8_t> &get_data() const;
    const google::protobuf::Message *get_responce_msg() const;
};