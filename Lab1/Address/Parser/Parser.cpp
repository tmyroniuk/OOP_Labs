//
// Created by tmyro on 16.10.2019.
//

#include "Parser.h"
//

std::vector<bool> Parser::intToBits(uint32_t data, uint8_t bits) {
    std::vector<bool> res;
    res.reserve(bits);
    uint32_t temp = data;
    for (uint8_t i = 0; i < bits; i++) {
        res.insert(res.begin(), temp % 2);
        temp /= 2;
    }
    return res;
}

uint32_t Parser::hexToInt(const std::string &data) {
    uint32_t res = 0;
    for (uint8_t i = 0; i < data.length(); i++) {
        res *= 16;
        res += data[i];
        if (data[i] > '9') {
            res -= 'a';
            res += 10;
        } else res -= '0';
    }
    return res;
}

std::string Parser::intToHex(uint32_t data) {
    std::string res;
    int temp;
    do {
        temp = data % 16;
        if (temp > 9) res = char('a' + temp - 10) + res;
        else res = std::to_string(temp) + res;
        data /= 16;
    } while (data > 0);
    return res;
}