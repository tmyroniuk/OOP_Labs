/**
 * @file IPv4.cpp
 * @author tmyroniuk
 * @date 16.10.2019
 * @brief Contains definitions of IPv4 class methods.
 */

#include "IPv4.h"

IPv4_Parser IPv4::parser;

IPv4::IPv4() : Address(32, IPv4_t), data(0) {}

IPv4::IPv4(const IPv4 &that) : Address(32, IPv4_t), data(that.data) {}

std::vector<bool> IPv4::asBits() const {
    return parser.asBits(data);
}

std::string IPv4::asString() const {
    return parser.asString(data);
}

IPv4::IPv4(const std::string &string) : Address(32, IPv4_t), data(parser.dataFromString(string)) {}

std::uint32_t IPv4::asUint32() {
    return data;
}

IPv6 IPv4::asIPv6() const {
    uint32_t res[4] = {};
    res[3] = data;
    return IPv6(res);
}

bool IPv4::operator==(const IPv4 &that) const {
    return data == that.data;
}

bool IPv4::operator!=(const IPv4 &that) const {
    return data != that.data;
}

bool IPv4::operator>(const IPv4 &that) const {
    return data > that.data;
}

bool IPv4::operator<(const IPv4 &that) const {
    return data < that.data;
}

bool IPv4::operator>=(const IPv4 &that) const {
    return data >= that.data;
}

bool IPv4::operator<=(const IPv4 &that) const {
    return data <= that.data;
}

IPv4 &IPv4::operator=(const IPv4 &that) {
    data = that.data;
    return *this;
}
