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
NodeIterator<T>::NodeIterator() : val() {}

template<typename T>
void NodeIterator<T>::setVal(T _val) {
    val = _val;
}

template<typename T>
void NodeIterator<T>::setPrev(NodeIterator *to) {
    //Does nothing
    return;
}

template<typename T>
void NodeIterator<T>::setNext(NodeIterator *to) {
    //Does nothing
    return;
}
