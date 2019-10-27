//
// Created by tmyro on 14.10.2019.
//

#ifndef LISTS_ARRAYLIST_H
#define LISTS_ARRAYLIST_H

#include "ListRealisation.h"

//realisation of array-based list
template<typename T>
class ArrayList : public ListRealisation<T> {
public:
    //Implements Node-iterator for array-base list
    //Behaves as node and as iterator over itself
    class Node : public NodeIterator<T> {
    public:
        //default ctor
        Node();

        Node(T _val);

        //return pointer to previous node
        NodeIterator<T> *getPrev();

        //return pointer to next node
        NodeIterator<T> *getNext();

        //return pointer to node <count> positions after this
        NodeIterator<T> *forward(int count);

        //return pointer to node <count> positions before this
        NodeIterator<T> *backward(int count);

        //does nothing. Cannot use =delete
        void setPrev(NodeIterator<T> *to) {};

        //does nothing. Cannot use =delete
        void setNext(NodeIterator<T> *to) {};
    };

    //default ctor
    ArrayList();

    //insert node with <data> before <pos> node
    void insert(NodeIterator<T> *pos, T data);

    //return data pd <pos> node and removes it
    T extract(NodeIterator<T> *pos);

    //return pointer to head
    NodeIterator<T> *begin();

    //return pointer to tail (head + size)
    NodeIterator<T> *end();

    ~ArrayList();

private:
    //reserved memory increasement int in times
    const unsigned int grow_rate;
    //head ptr
    NodeIterator<T> *head;
    //memory reserved
    unsigned int reserved;

    //reserve more memory
    void grow();

    //release memory on empty
    void shrink();
};

#include "ArrayList.inl"

#endif //LISTS_ARRAYLIST_H
