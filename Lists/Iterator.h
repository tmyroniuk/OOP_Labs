//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_ITERATOR_H
#define LISTS_ITERATOR_H


#include "List_Realisation/NodeIterator.h"

template<typename T>
class BaseList;

template<typename T>
class Iterator {
private:
    NodeIterator<T> *node;
public:
    friend NodeIterator<T> *BaseList<T>::getNode(const Iterator<T> &_iterator);

    Iterator();

    Iterator(const Iterator &_that);

    explicit Iterator(NodeIterator<T> *_node);

    Iterator &operator=(const Iterator &that);

    Iterator &operator++();

    Iterator operator++(int);

    Iterator &operator--();

    Iterator operator--(int);

    bool operator==(const Iterator &that);

    bool operator!=(const Iterator &that);

    Iterator operator+(int _val);

    Iterator operator-(int _val);

    Iterator &operator+=(int _val);

    Iterator &operator-=(int _val);

    T &operator*();
};


#endif //LISTS_ITERATOR_H
