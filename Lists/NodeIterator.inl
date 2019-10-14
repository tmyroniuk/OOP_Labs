//
// Created by tmyro on 13.10.2019.
//

#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator(T data) : val(data) {}

template<typename T>
T &NodeIterator<T>::getVal() {
    return val;
}

template<typename T>
NodeIterator<T>::NodeIterator() : T() {}