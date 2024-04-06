#include "checksum.h"

uint16_t crc::updateCrc16(uint16_t crc, const char data)
{
    crc ^= static_cast<uint16_t>(data) << 8;
    for (int i = 0; i < 8; i++)
    {
        if (crc & 0x8000)
        {
            crc <<= 1;
            crc ^= 0x1021;
        }
        else
        {
            crc <<= 1;
        }
    }
    return crc;
}

uint16_t crc::calcCrc16(const std::vector<uint8_t> &buffer)
{
    uint16_t size = buffer.size();
    uint16_t crc = 0;
    for (int i = 0; i < size; ++i)
        crc = updateCrc16(crc, *(buffer.begin() + i));
    return crc;
}