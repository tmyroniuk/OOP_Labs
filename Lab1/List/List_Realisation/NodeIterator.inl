/**
 * @file NodeIterator.inl
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of NodeIterator class methods.
 */

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
