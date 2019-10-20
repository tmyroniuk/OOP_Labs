//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_NODEITERATOR_H
#define LISTS_NODEITERATOR_H

template<typename T>
class NodeIterator {
protected:
    T val;
public:
    NodeIterator();

    explicit NodeIterator(T data);

    virtual NodeIterator *getPrev() = 0;

    virtual NodeIterator *getNext() = 0;

    virtual NodeIterator *forward(int count) = 0;

    virtual NodeIterator *backward(int count) = 0;

    virtual T &getVal();

    virtual void setVal(T _val);

    //does nothing by default
    virtual void setPrev(NodeIterator *to);

    //does nothing by default
    virtual void setNext(NodeIterator *to);
};

#include "NodeIterator.inl"

#endif //LISTS_NODEITERATOR_H
