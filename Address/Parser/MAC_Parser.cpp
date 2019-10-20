//
// Created by tmyro on 20.10.2019.
//

#include "MAC_Parser.h"

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

std::vector<bool> MAC_Parser::asBits(const uint16_t data[3]) {
    std::vector<bool> res, temp;
    res.reserve(48);
    for (int i = 0; i < 3; i++) {
        temp = intToBits(data[i], 16);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}

std::string MAC_Parser::asString(const uint16_t data[3]) {
    std::string res;
    for (int i = 0; i < 3; i++)
        res += ":" + intToHex(data[i] / 256) + ":" + intToHex(data[i] % 256);
    res.erase(0, 1);
    return res;
}
