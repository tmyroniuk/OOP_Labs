//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_BASELIST_H
#define LISTS_BASELIST_H

#include "List_Realisation/ListRealisation.h"
#include "Iterator.h"

template<typename T>
class BaseList {
public:
    explicit BaseList(ListRealisation<T> *type);

    virtual ~BaseList();

    Iterator<T> begin();

    Iterator<T> end();

    void insert(const Iterator<T> &pos, T data);

    T extract(const Iterator<T> &pos);

    void push_back(T data);

    T pop_back();

    void push_front(T data);

    T pop_front();

    T &front();

    T &back();

    unsigned int size();

    bool empty();

protected:
    ListRealisation<T> *realisation;

    NodeIterator<T> *getNode(const Iterator<T> &_iterator);
};

#include "BaseList.inl"

#endif //LISTS_BASELIST_H
