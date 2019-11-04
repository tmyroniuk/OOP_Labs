/**
 * @file IPv6_Parser.cpp
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains definitions of IPv6_Parser class methods.
 */

#include "IPv6_Parser.h"

/*
 * Converts first two hex numbers divided by ':' symbol from string
 * of such blocks into uint32 and removes them from input string.
 *
 * Creates string with first number and uses parent parser to convert
 * into uint32. Multiplies result by 65546. Converts second number into string
 * and adds to the result. Removes leading ':' and returns result.
 */
uint32_t IPv6_Parser::blockFromString(std::string &string) {
    uint32_t res = 0;
    std::string temp;
    while (string[0] != ':') {
        temp += string[0];
        string.erase(0, 1);
    }
    res = hexToInt(temp) * 65536;
    temp.clear();
    if (!string.empty()) string.erase(0, 1);
    while (!string.empty() && string[0] != ':') {
        temp += string[0];
        string.erase(0, 1);
    }
    res += hexToInt(temp);
    if (!string.empty()) string.erase(0, 1);
    return res;
}

/*
 * Converts each number into vector using parent class method and
 * connects them to get result.
 */
std::vector<bool> IPv6_Parser::asBits(const uint32_t data[4]) {
    std::vector<bool> res, temp;
    res.reserve(128);
    for (int i = 0; i < 4; i++) {
        temp = intToBits(data[i], 32);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}

/*
 * Uses parent class method to convert numbers into hex blocks
 * and connects them into string dividing them with ':'.
 * Removes leading ':' before result returned.
 */
std::string IPv6_Parser::asString(const uint32_t data[4]) {
    std::string res;
    for (int i = 0; i < 4; i++)
        res += ":" + intToHex(data[i] / 65536) + ":" + intToHex(data[i] % 65536);
    res.erase(0, 1);
    return res;
}