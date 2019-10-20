//
// Created by tmyro on 20.10.2019.
//

#include "MAC.h"

MAC_Parser MAC::parser;

MAC::MAC() : Address (48), data() {}

MAC::MAC(const MAC &_that) : Address(48) {
    for(int i=0;i<3;i++)
        data[i]=_that.data[i];
}

MAC::MAC(std::string string) : Address(48) {
    for(int i=0;i<3;i++)
        data[i] = parser.block_from_string(string);
}

std::vector<bool> MAC::as_bits() {
    return parser.as_bits(data);
}

std::string MAC::as_string() {
    return parser.as_string(data);
}

IPv6 MAC::as_IPv6() {
    uint32_t res[4]={};
    res[3] = data[1];
    res[3] *= 65535;
    res[3] += data[2];
    res[2] = data[0];
    return IPv6(res);
}

