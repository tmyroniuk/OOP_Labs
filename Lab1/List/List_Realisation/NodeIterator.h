//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_NODEITERATOR_H
#define LISTS_NODEITERATOR_H

//abstract class
//behaves as node and iterator over itself
template<typename T>
class NodeIterator {
protected:
    //stored data
    T val;
public:
    NodeIterator();

    explicit NodeIterator(T data);

    //return pointer to previous node
    virtual NodeIterator *getPrev() = 0;

    //return pointer to next node
    virtual NodeIterator *getNext() = 0;

    //return prt to node <count> positions after this
    virtual NodeIterator *forward(int count) = 0;

    //return prt to node <count> positions before this
    virtual NodeIterator *backward(int count) = 0;

    //returns value reference
    virtual T &getVal();

    //sets data to _val
    virtual void setVal(T _val);

    //does nothing by default
    virtual void setPrev(NodeIterator *to) = 0;

    //does nothing by default
    virtual void setNext(NodeIterator *to) = 0;
};

#include "NodeIterator.inl"

#endif //LISTS_NODEITERATOR_H
