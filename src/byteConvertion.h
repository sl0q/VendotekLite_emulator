#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace bc //  bc for Byte Convertion
{
    typedef unsigned char BYTE;

    static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    static inline bool is_base64(BYTE c)
    {
        return (isalnum(c) || (c == '+') || (c == '/'));
    }

    inline std::string base64_encode(const std::vector<BYTE> &buf)
    {
        std::string ret;
        int i = 0;
        int j = 0;
        BYTE char_array_3[3];
        BYTE char_array_4[4];

        for (auto &c : buf)
        {
            char_array_3[i++] = c;
            if (i == 3)
            {
                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (i = 0; (i < 4); i++)
                    ret += base64_chars[char_array_4[i]];
                i = 0;
            }
        }

        if (i)
        {
            for (j = i; j < 3; j++)
                char_array_3[j] = '\0';

            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (j = 0; (j < i + 1); j++)
                ret += base64_chars[char_array_4[j]];

            while ((i++ < 3))
                ret += '=';
        }

        return ret;
    }

    inline std::vector<BYTE> base64_decode(std::string const &encoded_string)
    {
        int in_len = encoded_string.size();
        int i = 0;
        int j = 0;
        int in_ = 0;
        BYTE char_array_4[4], char_array_3[3];
        std::vector<BYTE> ret;

        while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
        {
            char_array_4[i++] = encoded_string[in_];
            in_++;
            if (i == 4)
            {
                for (i = 0; i < 4; i++)
                    char_array_4[i] = base64_chars.find(char_array_4[i]);

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                for (i = 0; (i < 3); i++)
                    ret.push_back(char_array_3[i]);
                i = 0;
            }
        }

        if (i)
        {
            for (j = i; j < 4; j++)
                char_array_4[j] = 0;

            for (j = 0; j < 4; j++)
                char_array_4[j] = base64_chars.find(char_array_4[j]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (j = 0; (j < i - 1); j++)
                ret.push_back(char_array_3[j]);
        }

        return ret;
    }

    inline std::vector<uint8_t> hex_string_decode(std::string const &hexString)
    {
        std::vector<uint8_t> buf;
        char hex[3];
        hex[2] = '\0';
        uint8_t byte;
        for (int i = 0; i < hexString.length() >> 1; ++i)
        {
            hex[0] = hexString[i * 2];
            hex[1] = hexString[i * 2 + 1];
            sscanf(hex, "%x", &byte);
            buf.push_back(byte);
        }

        return buf;
    }

    inline std::string hex_string_encode(std::vector<uint8_t> const &byteVector)
    {
        char hex[2];
        std::stringstream buf;
        for (auto &e : byteVector)
        {
            sprintf(hex, "%X", e);
            buf << (e < 0x10 ? "0" : "") << hex;
        }
        return buf.str();
    }
}