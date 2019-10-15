//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_BASELIST_H
#define LISTS_BASELIST_H

#include "List_Realisation/List_Realisation.h"
#include "Iterator.h"

template <typename T>
class BaseList {
public:
    explicit BaseList(List_Realisation<T>*);
    ~BaseList();
    Iterator<T> begin();
    Iterator<T> end();
    void insert(const Iterator<T>&, T);
    T extract(const Iterator<T>&);
    void push_back(T);
    T pop_back();
    void push_front(T);
    T pop_front();
    T& front();
    T& back();
    unsigned int size();
protected:
    List_Realisation<T>* realisation;
    NodeIterator<T>* getNode(const Iterator<T>&);
};
#include "BaseList.inl"

#endif //LISTS_BASELIST_H
