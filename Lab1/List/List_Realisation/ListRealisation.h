//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LISTREALISATION_H
#define LISTS_LISTREALISATION_H

#include "NodeIterator.h"

//implements ListRealisation as LinkedList
template<typename T>
class ListRealisation {
protected:
    //elements in list
    unsigned int len;

    //default ctor
    explicit ListRealisation();

public:
    //inserts <data> before <pos>
    virtual void insert(NodeIterator<T> *pos, T data) = 0;

    //return data on <pos> and delete it
    virtual T extract(NodeIterator<T> *pos) = 0;

    //return head ptr
    virtual NodeIterator<T> *begin() = 0;

    //return tail ptr
    virtual NodeIterator<T> *end() = 0;

    //return amount of elements in list
    unsigned int size();

    virtual ~ListRealisation() = default;
};

#include "ListRealisation.inl"

#endif //LISTS_LISTREALISATION_H
