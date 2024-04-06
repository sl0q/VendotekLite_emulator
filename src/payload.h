#pragma once

#include <iostream>
#include <vector>
#include <string>

class Payload
{
private:
    std::string debugString;
    std::vector<uint8_t> data;

public:
    Payload();
    Payload(const std::string &newDebugString, const std::vector<uint8_t> &newData);
    ~Payload();

    const std::string &getDebugString() const;
    const std::vector<uint8_t> &getData() const;
};