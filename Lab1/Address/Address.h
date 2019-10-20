//
// Created by tmyro on 07.10.2019.
//

#ifndef LAB1_ADDRESS_H
#define LAB1_ADDRESS_H


#include "AddressHolder.h"

class Address {
protected:
    AddressHolder* address;
public:
    Address(const std::string&);
    Address(char*, int);
    Address(const Address&);
    std::unique_ptr <AddressHolder> get();
    Address& operator=(const Address&);
    bool operator==(const Address&);
    bool operator!=(const Address&);
    bool operator>=(const Address&);
    bool operator<=(const Address&);
    bool operator>(const Address&);
    bool operator<(const Address&);
};

#endif //LAB1_ADDRESS_H
