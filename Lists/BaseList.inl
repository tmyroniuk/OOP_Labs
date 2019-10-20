//
// Created by tmyro on 13.10.2019.
//

#include "BaseList.h"
#include "List_Realisation/LinkedList.h"
#include "List_Realisation/ArrayList.h"

template<typename T>
NodeIterator<T> *BaseList<T>::getNode(const Iterator<T> &_iterator) {
    return _iterator.node;
}

template<typename T>
typename Iterator<T> BaseList<T>::begin() {
    return BaseList::Iterator(realisation->begin());
}

template<typename T>
typename Iterator<T> BaseList<T>::end() {
    return BaseList::Iterator(realisation->end());
}


template<typename T>
void BaseList<T>::insert(const Iterator<T> &pos, T data) {
    realisation->insert(getNode(pos), data);
}

template<typename T>
T BaseList<T>::extract(const Iterator<T> &pos) {
    return realisation->extract(getNode(pos));
}

template<typename T>
unsigned int BaseList<T>::size() {
    return realisation->size();
}

template<typename T>
BaseList<T>::BaseList(ListRealisation<T> *type) : realisation(type) {}

template<typename T>
void BaseList<T>::push_back(T data) {
    realisation->insert(realisation->end(), data);
}

template<typename T>
void BaseList<T>::push_front(T data) {
    realisation->insert(realisation->begin(), data);
}

template<typename T>
T BaseList<T>::pop_back() {
    return realisation->extract(realisation->end()->getPrev());
}

template<typename T>
T BaseList<T>::pop_front() {
    return realisation->extract(realisation->begin());
}

template<typename T>
T &BaseList<T>::front() {
    return realisation->begin()->getVal();
}

template<typename T>
T &BaseList<T>::back() {
    return realisation->end()->getPrev()->getVal();
}

template<typename T>
BaseList<T>::~BaseList() {
    delete realisation;
}

template<typename T>
bool BaseList<T>::empty() {
    return len == 0;
}
