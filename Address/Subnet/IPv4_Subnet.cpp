//
// Created by tmyro on 20.10.2019.
//

#include "IPv4_Subnet.h"

IPv4_Subnet::IPv4_Subnet() : Subnet() {}

IPv4_Subnet::IPv4_Subnet(const std::string &string) : Subnet(new IPv4(string.substr(0, sub_parser(string))),
                                                             std::stoi(string.substr(sub_parser(string) + 1,
                                                                                     string.length()))) {}

IPv4_Subnet::IPv4_Subnet(const IPv4 &_address, uint8_t _bits) : Subnet(new IPv4(_address), _bits) {}
