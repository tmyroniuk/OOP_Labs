//
// Created by tmyro on 20.10.2019.
//

#include "IPv4_Parser.h"

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

std::vector<bool> IPv4_Parser::asBits(uint32_t data) {
    return intToBits(data, 32);
}

std::string IPv4_Parser::asString(uint32_t data) {
    std::string res;
    for (int i = 0; i < 4; i++) {
        res = "." + std::to_string(data % 256) + res;
        data /= 256;
    }
    res.erase(0, 1);
    return res;
}
