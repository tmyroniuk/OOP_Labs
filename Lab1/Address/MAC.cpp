/**
 * @file MAC.cpp
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains definitions of MAC class methods.
 */

#include "MAC.h"

MAC_Parser MAC::parser;

MAC::MAC() : Address(48, MAC_t), data() {}`

MAC::MAC(const MAC &_that) : Address(48, MAC_t) {
    for (int i = 0; i < 3; i++)
        data[i] = _that.data[i];
}

MAC::MAC(std::string string) : Address(48, MAC_t) {
    for (int i = 0; i < 3; i++)
        data[i] = parser.blockFromString(string);
}

std::vector<bool> MAC::asBits() const {
    return parser.asBits(data);
}

std::string MAC::asString() const {
    return parser.asString(data);
}

IPv6 MAC::asIPv6() const {
    uint32_t res[4] = {};
    res[3] = data[1];
    res[3] *= 65535;
    res[3] += data[2];
    res[2] = data[0];
    return IPv6(res);
}

bool MAC::operator==(const MAC &that) const {
    for (int i = 0; i < 3; i++)
        if (data[i] != that.data[i]) return false;
    return true;
}

bool MAC::operator!=(const MAC &that) const {
    for (int i = 0; i < 3; i++)
        if (data[i] != that.data[i]) return true;
    return false;
}

bool MAC::operator>(const MAC &that) const {
    for (int i = 0; i < 3; i++)
        if (data[i] > that.data[i]) return true;
        else if (data[i] < that.data[i]) return false;
    return false;
}

bool MAC::operator<(const MAC &that) const {
    for (int i = 0; i < 3; i++)
        if (data[i] < that.data[i]) return true;
        else if (data[i] > that.data[i]) return false;
    return false;
}

bool MAC::operator>=(const MAC &that) const {
    for (int i = 0; i < 3; i++)
        if (data[i] > that.data[i]) return true;
        else if (data[i] < that.data[i]) return false;
    return true;
}

bool MAC::operator<=(const MAC &that) const {
    for (int i = 0; i < 3; i++)
        if (data[i] < that.data[i]) return true;
        else if (data[i] > that.data[i]) return false;
    return true;
}

MAC &MAC::operator=(const MAC &that) {
    for (int i = 0; i < 3; i++)
        data[i] = that.data[i];
    return *this;
}