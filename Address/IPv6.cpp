//
// Created by tmyro on 20.10.2019.
//

#include "IPv6.h"

IPv6_Parser IPv6::parser;

IPv6::IPv6() : Address(128), data() {}

IPv6::IPv6(uint32_t _data[4]) : Address(128){
    for(int i=0;i<4;i++) data[i]=_data[i];
}

IPv6::IPv6(const IPv6 &_that) : Address(128){
    for(int i=0;i<4;i++)
        data[i] = _that.data[i];
}

IPv6::IPv6(std::string string) : Address(128){
    for(int i=0;i<4;i++)
        data[i] = parser.block_from_string(string);
}

std::vector<bool> IPv6::as_bits() {
    return parser.as_bits(data);
}

std::string IPv6::as_string() {
    return parser.as_string(data);
}

IPv6 IPv6::as_IPv6() {
    return *this;
}

