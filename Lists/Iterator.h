//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_ITERATOR_H
#define LISTS_ITERATOR_H


#include "NodeIterator.h"

template <typename T> class BaseList;

template <typename T>
class Iterator{
private:
    NodeIterator<T>* node;
public:
    friend NodeIterator<T>* BaseList<T>::getNode(const Iterator<T>&);
    Iterator();
    Iterator(const Iterator&);
    explicit Iterator(NodeIterator<T>*);
    Iterator& operator= (const Iterator&);
    Iterator& operator++ ();
    const Iterator operator++ (int);
    Iterator& operator-- ();
    const Iterator operator-- (int);
    bool operator== (const Iterator&);
    bool operator!= (const Iterator&);
    T &operator* ();
};


#endif //LISTS_ITERATOR_H
