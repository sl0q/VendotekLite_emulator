#include "msg.h"

Msg::Msg()
{
}

Msg::Msg(const std::string &newDebugString, const std::vector<uint8_t> &newData)
{
    this->debugString = newDebugString;
    this->data = newData;
    this->encodedData = bs64::base64_encode(newData);
}

Msg::~Msg()
{
}

const std::string &Msg::get_debug_string() const
{
    return this->debugString;
}

const std::vector<uint8_t> &Msg::get_data() const
{
    return this->data;
}

const std::string Msg::get_data_as_string() const
{
    char hex[2];
    std::stringstream buf;
    for (auto &e : this->data)
    {
        sprintf(hex, "%X", e);
        buf << "0x" << hex << ' ';
    }
    return buf.str();
}

const std::string &Msg::get_encoded_data() const
{
    return this->encodedData;
}

void Msg::print_MSG() const
{
    std::cout << this->debugString << std::endl
              << this->get_data_as_string() << std::endl
              << this->encodedData << std::endl
              << std::endl;
}
