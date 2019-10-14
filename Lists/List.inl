//
// Created by tmyro on 13.10.2019.
//

#include "List.h"
#include "List_Proporties.h"
#include "Linked_List.h"
#include "Array_List.h"

template<typename T>
NodeIterator<T> *List<T>::getNode(const List::Iterator &_iterator) {
    return _iterator.node;
}

template<typename T>
typename List<T>::Iterator List<T>::begin() {
    return List::Iterator(realisation->begin());
}

template<typename T>
typename List<T>::Iterator List<T>::end() {
    return List::Iterator(realisation->end());
}

template<typename T>
List<T>::Iterator::Iterator() : node(nullptr) {}

template<typename T>
List<T>::Iterator::Iterator(const List::Iterator &_that) : node(_that.node) {}

template<typename T>
List<T>::Iterator::Iterator(const NodeIterator<T> *_node) : node(_node){}

template<typename T>
typename List<T>::Iterator &List<T>::Iterator::operator=(const List::Iterator &_that) {
    node = _that.node;
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    node = node->getNext();
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    node = node->getPrev();
    return *this;
}

template<typename T>
const typename List<T>::Iterator  List<T>::Iterator::operator++(int) {
    auto temp = *this;
    node = node->getNext();
    return temp;
}

template<typename T>
const typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    auto temp = *this
    node = node->getPrev();
    return temp;
}

template<typename T>
bool List<T>::Iterator::operator==(const List::Iterator &_that) {
    return _that.node == node;
}

template<typename T>
bool List<T>::Iterator::operator!=(const List::Iterator &_that) {
    return _that.node != node;
}

template<typename T>
T &List<T>::Iterator::operator*() {
    return node->getVal();
}
template<typename T>
void List<T>::insert(const List::Iterator &pos, T data) {
    realisation->insert(getNode(pos), data);
}

template<typename T>
T List<T>::extract(const List::Iterator &pos) {
    return realisation->extract(getNode(pos));
}

template<typename T>
unsigned int List<T>::size() {
    return realisation->size();
}

template<typename T>
List<T>::List() {
    switch (List_Proporties::type) {
        case List_Proporties::Type::Linked :{
            realisation = new Linked_List<T>();
            break;
        }
        case List_Proporties::Type::Array :{
            realisation = new Array_List<T>();
            break;
        }
    }
}

template<typename T>
void List<T>::push_back(T data) {
    realisation->insert(realisation->end(), data);
}

template<typename T>
void List<T>::push_front(T data) {
    realisation->insert(realisation->begin(), data);
}

template<typename T>
T List<T>::pop_back() {
    return realisation->extract(realisation->end()->getPrev());
}

template<typename T>
T List<T>::pop_front() {
    return realisation->extract(realisation->begin());
}

template<typename T>
T &List<T>::front() {
    return realisation->begin()->getVal();
}

template<typename T>
T &List<T>::back() {
    return realisation->end()->getPrev()->getVal();
}
