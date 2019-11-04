/**
 * @file IPv4_Parser.cpp
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains definitions of IPv4_Parser class methods.
 */

#include "IPv4_Parser.h"

/*
 * Used as parser for IPv4 address.
 * Reads numbers divided by '.' symbol, each less than 256, and converts
 * them into one uint32.
 */
uint32_t IPv4_Parser::dataFromString(const std::string &string) {
    uint32_t i = 0, res = 0;
    std::string temp;
    while (i < string.size()) {
        temp.clear();
        while (i < string.size() && string[i] != '.') {
            temp += string[i];
            i++;
        }
        res *= 256;
        res += std::stoi(temp);
        i++;
    }
    return res;
}

/*
 * Just use same function in parent class with 32 bit vector size.
 */
std::vector<bool> IPv4_Parser::asBits(uint32_t data) {
    return intToBits(data, 32);
}

/*
 * Converts int32 into IPv4 address computing rest division by
 * 256.
 */
std::string IPv4_Parser::asString(uint32_t data) {
    std::string res;
    for (int i = 0; i < 4; i++) {
        res = "." + std::to_string(data % 256) + res;
        data /= 256;
    }
    res.erase(0, 1);
    return res;
}
