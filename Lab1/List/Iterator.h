//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_ITERATOR_H
#define LISTS_ITERATOR_H


#include "List_Realisation/NodeIterator.h"

template<typename T>
class BaseList;

//Implementation of iterator over base list
template<typename T>
class Iterator {
private:
    //Node it points to
    NodeIterator<T> *node;
public:
    //Allows list to access node
    friend BaseList<T>;

    Iterator();

    //Copy ctor
    Iterator(const Iterator &_that);

    explicit Iterator(NodeIterator<T> *_node);

    //Copy assignment
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

    //return node data reference
    T &operator*();
};

#include "Iterator.inl"

#endif //LISTS_ITERATOR_H
