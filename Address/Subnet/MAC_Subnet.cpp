//
// Created by tmyro on 20.10.2019.
//

#include "MAC_Subnet.h"

MAC_Subnet::MAC_Subnet() : Subnet() {}

MAC_Subnet::MAC_Subnet(const std::string& string) : Subnet(new MAC(string.substr(0, sub_parser(string))),
                                                             std::stoi(string.substr(sub_parser(string)+1, string.length()))) {}

MAC_Subnet::MAC_Subnet(const MAC &_address, uint8_t _bits) : Subnet(new MAC(_address), _bits) {}
