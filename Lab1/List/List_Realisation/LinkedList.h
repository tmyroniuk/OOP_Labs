//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LINKEDLIST_H
#define LISTS_LINKEDLIST_H


#include "ListRealisation.h"

//implements ListRealisation as array list
template<typename T>
class LinkedList : public ListRealisation<T> {
public:
    //implements NodeIterator for array list
    //behaves as node and iterator over itself
    class Node : public NodeIterator<T> {
    private:
        //ptr to next node
        NodeIterator<T> *next;
        //ptr to prev node
        NodeIterator<T> *prev;
    public:
        Node();

        Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next);

        //return ptr to previous node
        NodeIterator<T> *getPrev();

        //return pointer to next node
        NodeIterator<T> *getNext();

        //return ptr to node that <count> positions after this
        NodeIterator<T> *forward(int count);

        //return ptr to node that <count> positions before this
        NodeIterator<T> *backward(int count);

        //set previous node to <to>
        virtual void setPrev(NodeIterator<T> *to);

        //set next node data to <to>
        virtual void setNext(NodeIterator<T> *to);
    };

    LinkedList();

    void insert(NodeIterator<T> *pos, T data);

    T extract(NodeIterator<T> *pos);

    NodeIterator<T> *begin();

    NodeIterator<T> *end();

    virtual ~LinkedList();

private:
    NodeIterator<T> *head;
    NodeIterator<T> *tail;
};

#include "LinkedList.inl"

#endif //LISTS_LINKEDLIST_H
