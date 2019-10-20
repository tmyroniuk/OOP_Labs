//
// Created by tmyro on 20.10.2019.
//

#include "IPv6_Parser.h"

uint32_t IPv6_Parser::block_from_string(std::string &string) {
    uint32_t res=0;
    std::string temp;
    while(string[0]!=':'){
        temp+=string[0];
        string.erase(0, 1);
    }
    res = hex_to_int(temp) * 65536;
    temp.clear();
    if(!string.empty()) string.erase(0, 1);
    while(!string.empty() && string[0]!=':') {
        temp += string[0];
        string.erase(0, 1);
    }
    res += hex_to_int(temp);
    if(!string.empty()) string.erase(0, 1);
    return res;
}

std::vector<bool> IPv6_Parser::as_bits(const uint32_t data[4]) {
    std::vector<bool> res, temp;
    res.reserve(128);
    for(int i=0;i<4;i++) {
        temp = int_to_bits(data[i], 32);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}

std::string IPv6_Parser::as_string(const uint32_t data[4]) {
    std::string res;
    for(int i=0;i<4;i++)
        res += ":" + int_to_hex(data[i]/65536) + ":" + int_to_hex(data[i]%65536);
    res.erase(0, 1);
    return res;
}