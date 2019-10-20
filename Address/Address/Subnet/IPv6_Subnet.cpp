//
// Created by tmyro on 20.10.2019.
//

#include "IPv6_Subnet.h"

IPv6_Subnet::IPv6_Subnet() : Subnet() {}

IPv6_Subnet::IPv6_Subnet(const std::string &string) : Subnet(new IPv6(string.substr(0, sub_parser(string))),
                                                             std::stoi(string.substr(sub_parser(string) + 1,
                                                                                     string.length()))) {}

IPv6_Subnet::IPv6_Subnet(const IPv6 &_address, uint8_t _bits) : Subnet(new IPv6(_address), _bits) {}
