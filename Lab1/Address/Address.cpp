//
// Created by tmyro on 07.10.2019.
//

#include <memory>
#include "Address.h"

Address::Address(const std::string& string) {
    address = AddressHolder::create(string);
}

Address::Address(char * string, int size) {
    address = AddressHolder::create(string, size);
}

Address::Address(const Address & that)  {
    address = AddressHolder::create (that.address->getData(), that.address->getType());
}

std::unique_ptr <AddressHolder> Address::get() {
    return std::unique_ptr<AddressHolder>(AddressHolder::create(address->getData(), address->getType()));
}

Address &Address::operator=(const Address & that) {
    address = AddressHolder::create(that.address->getData(), that.address->getType());
    return *this;
}

bool Address::operator==(const Address & that) {
    return (*address == *(that.address));
}

bool Address::operator>(const Address &) {
    return false;
}
