/**
 * @file IPv4_Subnet.cpp
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains definitions of IPv4_Subnet class methods.
 */

#include "IPv4_Subnet.h"

IPv4_Subnet::IPv4_Subnet() : Subnet() {}

/*
 * Creates Subnet from string "address/bits",
 * calls subparser method to get '/' position and
 * runs subnet constructor with IPv4 constructed from first part of string,
 * and bits as parameters.
 */
IPv4_Subnet::IPv4_Subnet(const std::string &string) :
                Subnet(new IPv4(string.substr(0, sub_parser(string))),
                std::stoi(string.substr(sub_parser(string) + 1,
                string.length()))) {}

IPv4_Subnet::IPv4_Subnet(const IPv4 &_address, uint8_t _bits) : Subnet(new IPv4(_address), _bits) {}
