//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LISTREALISATION_H
#define LISTS_LISTREALISATION_H

#include "NodeIterator.h"

template<typename T>
class ListRealisation {
protected:
    unsigned int len;

    explicit ListRealisation();

public:
    virtual void insert(NodeIterator<T> *pos, T data) = 0;

    virtual T extract(NodeIterator<T> *pos) = 0;

    virtual NodeIterator<T> *begin() = 0;

    virtual NodeIterator<T> *end() = 0;

    unsigned int size();

    virtual ~ListRealisation() = default;
};

#include "ListRealisation.inl"

#endif //LISTS_LISTREALISATION_H
