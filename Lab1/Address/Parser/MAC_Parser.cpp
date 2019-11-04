//
// Created by tmyro on 20.10.2019.
//

#include "MAC_Parser.h"

/*
 * Converts first two hex numbers divided by ':' symbol from string
 * of such blocks into uint16 and removes them from input string.
 *
 * Creates string with first number and uses parent parser to convert
 * into uint16. Multiplies result by 256. Converts second number into string
 * and adds to the result. Removes leading ':' and returns result.
 */
uint16_t MAC_Parser::blockFromString(std::string &string) {
    uint16_t res;
    std::string temp;
    while (!string.empty() && string[0] != ':') {
        temp += string[0];
        string.erase(0, 1);
    }
    res = hexToInt(temp) * 256;
    if (!string.empty()) string.erase(0, 1);
    temp.clear();
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
std::vector<bool> MAC_Parser::asBits(const uint16_t data[3]) {
    std::vector<bool> res, temp;
    res.reserve(48);
    for (int i = 0; i < 3; i++) {
        temp = intToBits(data[i], 16);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}

/*
 * Uses parent class method to convert numbers into hex blocks
 * and connects them into string dividing them with ':'.
 * Removes leading ':' before result returned.
 */
std::string MAC_Parser::asString(const uint16_t data[3]) {
    std::string res;
    for (int i = 0; i < 3; i++)
        res += ":" + intToHex(data[i] / 256) + ":" + intToHex(data[i] % 256);
    res.erase(0, 1);
    return res;
}
