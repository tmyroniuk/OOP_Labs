//
// Created by tmyro on 20.10.2019.
//

#include "Subnet.h"

bool Subnet::contains(const Address &_address) {
    auto first = address->asBits();
    auto second = _address.asBits();
    uint8_t i = 0;
    while (i < first.size() - bits) {
        if (first[i] != second[i])
            return false;
        i++;
    }
    return true;
}

Subnet::Subnet() : bits(), address() {}

Subnet::Subnet(Address *_address, uint8_t _bits) : bits(_bits), address(_address) {}

Address::Type Subnet::type() {
    return address->getType();
}

int Subnet::sub_parser(const std::string &string) {
    uint8_t i = 0;
    for (; i < string.size() && string[i] != '/'; i++);
    return i;
}

Subnet::~Subnet() {
    delete address;
}
