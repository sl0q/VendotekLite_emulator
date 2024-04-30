#include "msg.h"

Msg::Msg()
{
}

Msg::Msg(const Payload &newPayload, const std::vector<uint8_t> &newMsgBytes, std::string &typeStr, bool isFailure)
{
    this->isFailure = isFailure;
    this->payload = *(new Payload(newPayload));
    this->msgBytes = newMsgBytes;
    this->encodedMsgBytes = bs64::base64_encode(newMsgBytes);
    this->typeStr = typeStr;
}

Msg::Msg(const Msg &otherMsg)
{
    this->msgBytes.clear();
    for (auto &byte : otherMsg.msgBytes)
        this->msgBytes.push_back(byte);

    this->encodedMsgBytes = otherMsg.encodedMsgBytes;
    this->typeStr = otherMsg.typeStr;
    this->payload = otherMsg.payload;
    this->isFailure = otherMsg.isFailure;
}

Msg::~Msg()
{
}

bool Msg::is_empty() const
{
    return this->encodedMsgBytes.empty();
}

bool Msg::is_failure() const
{
    return isFailure;
}

void Msg::clear()
{
    // this->debugString = "";
    this->msgBytes.clear();
    this->encodedMsgBytes = "";
}

const std::string &Msg::get_debug_string() const
{
    return this->payload.get_debug_string();
}

const std::vector<uint8_t> &Msg::get_msg_bytes() const
{
    return this->msgBytes;
}

const std::string Msg::get_msg_bytes_as_string() const
{
    char hex[2];
    std::stringstream buf;
    for (auto &e : this->msgBytes)
    {
        sprintf(hex, "%X", e);
        buf << "0x" << hex << ' ';
    }
    return buf.str();
}

const std::string &Msg::get_encoded_msg_bytes() const
{
    return this->encodedMsgBytes;
}

const std::string &Msg::get_type_str() const
{
    return typeStr;
}

const Payload &Msg::get_payload() const
{
    return this->payload;
}

void Msg::print_MSG() const
{
    std::cout << this->typeStr << std::endl
              << this->get_debug_string() << std::endl
              << this->get_msg_bytes_as_string() << std::endl
              << this->encodedMsgBytes << std::endl
              << std::endl;
}
