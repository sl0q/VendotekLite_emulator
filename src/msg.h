#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

#include "base64.h"

class Msg
{
private:
    std::string debugString;
    std::vector<uint8_t> data;
    std::string encodedData;

public:
    Msg();
    Msg(const std::string &newDebugString, const std::vector<uint8_t> &newData);
    ~Msg();

    bool is_empty() const;
    void clear();

    const std::string &get_debug_string() const;
    const std::vector<uint8_t> &get_data() const;
    const std::string get_data_as_string() const;
    const std::string &get_encoded_data() const;
    void print_MSG() const;
};