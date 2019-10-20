//
// Created by tmyro on 20.10.2019.
//

#include "IPv6_Parser.h"

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

std::vector<bool> IPv6_Parser::asBits(const uint32_t data[4]) {
    std::vector<bool> res, temp;
    res.reserve(128);
    for (int i = 0; i < 4; i++) {
        temp = intToBits(data[i], 32);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}

std::string IPv6_Parser::asString(const uint32_t data[4]) {
    std::string res;
    for (int i = 0; i < 4; i++)
        res += ":" + intToHex(data[i] / 65536) + ":" + intToHex(data[i] % 65536);
    res.erase(0, 1);
    return res;
}