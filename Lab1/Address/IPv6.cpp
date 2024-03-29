/**
 * @file MAC.cpp
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains definitions of IPv6 class methods.
 */

#include "IPv6.h"

IPv6_Parser IPv6::parser;

IPv6::IPv6() : Address(128, IPv6_t), data() {}

IPv6::IPv6(uint32_t _data[4]) : Address(128, IPv6_t) {
    for (int i = 0; i < 4; i++) data[i] = _data[i];
}

IPv6::IPv6(const IPv6 &_that) : Address(128, IPv6_t) {
    for (int i = 0; i < 4; i++)
        data[i] = _that.data[i];
}

IPv6::IPv6(std::string string) : Address(128, IPv6_t) {
    for (int i = 0; i < 4; i++)
        data[i] = parser.blockFromString(string);
}

std::vector<bool> IPv6::asBits() const {
    return parser.asBits(data);
}

std::string IPv6::asString() const {
    return parser.asString(data);
}

IPv6 IPv6::asIPv6() const {
    return *this;
}

bool IPv6::operator==(const IPv6 &that) const {
    for (int i = 0; i < 4; i++)
        if (data[i] != that.data[i]) return false;
    return true;
}

bool IPv6::operator!=(const IPv6 &that) const {
    for (int i = 0; i < 4; i++)
        if (data[i] != that.data[i]) return true;
    return false;
}

bool IPv6::operator>(const IPv6 &that) const {
    for (int i = 0; i < 4; i++)
        if (data[i] > that.data[i]) return true;
        else if (data[i] < that.data[i]) return false;
    return false;
}

bool IPv6::operator<(const IPv6 &that) const {
    for (int i = 0; i < 4; i++)
        if (data[i] < that.data[i]) return true;
        else if (data[i] > that.data[i]) return false;
    return false;
}

bool IPv6::operator>=(const IPv6 &that) const {
    for (int i = 0; i < 4; i++)
        if (data[i] > that.data[i]) return true;
        else if (data[i] < that.data[i]) return false;
    return true;
}

bool IPv6::operator<=(const IPv6 &that) const {
    for (int i = 0; i < 4; i++)
        if (data[i] < that.data[i]) return true;
        else if (data[i] > that.data[i]) return false;
    return true;
}

IPv6 &IPv6::operator=(const IPv6 &that) {
    for (int i = 0; i < 4; i++)
        data[i] = that.data[i];
    return *this;
}