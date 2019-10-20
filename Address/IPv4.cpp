//
// Created by tmyro on 16.10.2019.
//

#include "IPv4.h"

IPv4_Parser IPv4::parser;

IPv4::IPv4() : Address(32), data() {}

IPv4::IPv4(const IPv4 & that) : Address(32), data(that.data) {}

std::vector<bool> IPv4::as_bits() {
    return parser.as_bits(data);
}

std::string IPv4::as_string() {
    return parser.as_string(data);
}

IPv4::IPv4(const std::string &string) : Address(32), data(parser.data_from_string(string)){}

std::uint32_t IPv4::as_uint32() {
    return data;
}

IPv6 IPv4::as_IPv6() {
    uint32_t res[4] = {};
    res[3] = data;
    return IPv6(res);
}
