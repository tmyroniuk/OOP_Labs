/**
 * @file IPv6_Subnet.cpp
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains definitions of IPv6_Subnet class methods.
 */

#include "IPv6_Subnet.h"

IPv6_Subnet::IPv6_Subnet() : Subnet() {}

/*
 * Creates Subnet from string "address/bits",
 * calls subparser method to get '/' position and
 * runs subnet constructor with IPv6 constructed from first part of string,
 * and bits as parameters.
 */
IPv6_Subnet::IPv6_Subnet(const std::string &string) :
                                        Subnet(new IPv6(string.substr(0, sub_parser(string))),
                                        std::stoi(string.substr(sub_parser(string) + 1,
                                        string.length()))) {}

IPv6_Subnet::IPv6_Subnet(const IPv6 &_address, uint8_t _bits) : Subnet(new IPv6(_address), _bits) {}
