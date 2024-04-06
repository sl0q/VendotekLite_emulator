#pragma once

#include <iostream>
#include <vector>

namespace crc
{
    uint16_t updateCrc16(uint16_t crc, const char data);

    uint16_t calcCrc16(const std::vector<uint8_t> &buffer);
}