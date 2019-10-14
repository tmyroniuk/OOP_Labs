//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LIST_REALISATION_H
#define LISTS_LIST_REALISATION_H

#include "NodeIterator.h"

template <typename T>
class List_Realisation {
protected:
    unsigned int len;
    explicit List_Realisation();
public:
    virtual void insert(NodeIterator<T>*, T) =0;
    virtual T extract(NodeIterator<T>*) =0;
    virtual NodeIterator<T>* begin()=0;
    virtual NodeIterator<T>* end()=0;
    unsigned int size();
};

#include "List_Realisation.inl"

#endif //LISTS_LIST_REALISATION_H
