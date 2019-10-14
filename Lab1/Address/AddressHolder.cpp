//
// Created by tmyro on 06.10.2019.
//

#include "AddressHolder.h"

AddressHolder::AddressHolder(uint8_t *data_, const int& size_, Type type_) : data(data_), size(size_), type(type_) {}

int AddressHolder::getSize() {
    return size;
}

uint8_t *AddressHolder::getData() {
    if (size==0) return nullptr;
    auto temp = new uint8_t [size];
    for(int i=0;i<size;i++) temp[i]=data[i];
    return temp;
}

AddressHolder::~AddressHolder() {
    if (data) delete[] data;
}

AddressHolder::Type AddressHolder::getType() {
    return type;
}

AddressHolder *AddressHolder::create(uint8_t *, AddressHolder::Type) {
    return nullptr;
}
