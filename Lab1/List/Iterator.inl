//
// Created by tmyro on 15.10.2019.
//

#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator() : node(nullptr) {}

template<typename T>
Iterator<T>::Iterator(const Iterator &that) : node(that.node) {}

template<typename T>
Iterator<T>::Iterator(NodeIterator<T> *_node) : node(_node) {}

template<typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator &that) {
    node = that.node;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    node = node->getNext();
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator--() {
    node = node->getPrev();
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
    auto temp = *this;
    node = node->getNext();
    return temp;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
    auto temp = *this;
    node = node->getPrev();
    return temp;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator &that) {
    return that.node == node;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator &that) {
    return that.node != node;
}

template<typename T>
T &Iterator<T>::operator*() {
    return node->getVal();
}

template<typename T>
Iterator<T> Iterator<T>::operator+(int _val) {
    return Iterator(node->forward(_val));
}

template<typename T>
Iterator<T> Iterator<T>::operator-(int _val) {
    return Iterator(node->backward(_val));
}

template<typename T>
Iterator<T> &Iterator<T>::operator+=(int _val) {
    node = node->forward(_val);
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator-=(int _val) {
    node = node->backward(_val);
    return *this;
}