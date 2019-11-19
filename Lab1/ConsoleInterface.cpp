//
// Created by tmyro on 18.11.2019.
//

#include "ConsoleInterface.h"
#include "Address/Subnet/IPv4_Subnet.h"
#include "Address/Subnet/IPv6_Subnet.h"
#include "Address/Subnet/MAC_Subnet.h"


template<>
IPv4 ConsoleInterface<IPv4>::rand_val() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 255);
    std::string res = std::to_string(dist(rd));
    for (int i = 0; i < 3; i++) res += '.' + std::to_string(dist(rd));
    return IPv4(res);
}

template<>
MAC ConsoleInterface<MAC>::rand_val() {
    std::random_device rd;
    Parser parser;
    std::uniform_int_distribution<int> dist(0, 255);
    std::string res = parser.intToHex(dist(rd));
    for (int i = 0; i < 5; i++) res += ':' + parser.intToHex(dist(rd));
    return MAC(res);
}

template<>
IPv6 ConsoleInterface<IPv6>::rand_val() {
    std::random_device rd;
    Parser parser;
    std::uniform_int_distribution<uint16_t> dist(0, 65535);
    std::string res = parser.intToHex(dist(rd));
    for (int i = 0; i < 7; i++) res += ':' + parser.intToHex(dist(rd));
    return IPv6(res);
}

template<>
int ConsoleInterface<int>::rand_val() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(-255, 255);
    return dist(rd);
}

template<>
double ConsoleInterface<double>::rand_val() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 255);
    return double(dist(rd))/double(dist(rd));
}

template<>
std::string ConsoleInterface<std::string>::rand_val() {
    std::random_device rd;
    std::string res;
    std::uniform_int_distribution<int> len(1, 10);
    std::uniform_int_distribution<int> dist(int('a'), int('z'));
    for(int i = 0; i<len(rd); i++) res += char(dist(rd));
    return res;
}

template<>
int ConsoleInterface<int>::concrete_val(const std::string& str) { return std::stoi(str); }

template<>
double ConsoleInterface<double>::concrete_val(const std::string& str) { return std::stod(str); }

template<>
std::string ConsoleInterface<std::string>::concrete_val(const std::string& str) { return str; }

template<>
IPv4 ConsoleInterface<IPv4>::concrete_val(const std::string& str) { return IPv4(str); }

template<>
IPv6 ConsoleInterface<IPv6>::concrete_val(const std::string& str) { return IPv6(str); }

template<>
MAC ConsoleInterface<MAC>::concrete_val(const std::string& str) { return MAC(str); }

template <>
void ConsoleInterface<int>::print(const int &val, bool) { std::cout<<val<<" "; }

template <>
void ConsoleInterface<double>::print(const double &val, bool) { std::cout<<val<<" "; }

template <>
void ConsoleInterface<std::string>::print(const std::string &val, bool) { std::cout<<val<<" "; }

template <>
void ConsoleInterface<IPv4>::print(const IPv4 &val, bool spec) { std::cout<< ((spec) ? val.asIPv6().asString() : val.asString()) <<" "; }

template <>
void ConsoleInterface<MAC>::print(const MAC &val, bool spec) { std::cout<< ((spec) ? val.asIPv6().asString() : val.asString()) <<" "; }

template <>
void ConsoleInterface<IPv6>::print(const IPv6 &val, bool spec) { std::cout<< ((spec) ? val.asIPv6().asString() : val.asString()) <<" "; }

template<>
void ConsoleInterface<IPv4>::inSubnet(std::string &str) {
    int index = std::stoi(extractWord(str));
    if(IPv4_Subnet(extractWord(str)).contains(*(list->begin() + index))) std::cout<<"Yes.\n";
    else std::cout<<"No.\n";
}

template<>
void ConsoleInterface<IPv6>::inSubnet(std::string &str) {
    int index = std::stoi(extractWord(str));
    if(IPv6_Subnet(extractWord(str)).contains(*(list->begin() + index))) std::cout<<"Yes.\n";
    else std::cout<<"No.\n";
}

template<>
void ConsoleInterface<MAC>::inSubnet(std::string &str) {
    int index = std::stoi(extractWord(str));
    if(MAC_Subnet(extractWord(str)).contains(*(list->begin() + index))) std::cout<<"Yes.\n";
    else std::cout<<"No.\n";
}

template<>
void ConsoleInterface<int>::inSubnet(std::string &str) {std::cout<<"Not usable for this type.\n";}

template<>
void ConsoleInterface<double>::inSubnet(std::string &str) {std::cout<<"Not usable for this type.\n";}

template<>
void ConsoleInterface<std::string>::inSubnet(std::string &str) {std::cout<<"Not usable for this type.\n";}