//
// Created by tmyro on 20.10.2019.
//

#include "Subnet.h"

uint8_t Subnet::get_bits() {
    return bits;
}

bool Subnet::contains(const Address& _address) {
    auto first = address->as_bits();
    auto second = _address.as_bits();
    int i=0;
    while(i<first.size()-bits){
        if(first[i]!=second[i])
            return false;
        i++;
    }
    return true;
}

Subnet::Subnet() : bits(), address() {}

Subnet::Subnet(Address *_address, uint8_t _bits) : bits(_bits), address(_address) {}

Address::Type Subnet::type() {
    return address->get_Type();
}

int Subnet::sub_parser(const std::string &string) {
    int i=0;
    for(;i<string.size() && string[i]!='/'; i++);
    return i;
}

Subnet::~Subnet() {
    delete address;
}
