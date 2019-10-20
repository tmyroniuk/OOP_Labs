//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LINKEDLIST_H
#define LISTS_LINKEDLIST_H


#include "ListRealisation.h"

template<typename T>
class LinkedList : public ListRealisation<T> {
public:
    class Node : public NodeIterator<T> {
    private:
        NodeIterator<T> *next;
        NodeIterator<T> *prev;
    public:
        Node();

        Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next);

        NodeIterator<T> *getPrev();

        NodeIterator<T> *getNext();

        NodeIterator<T> *forward(int count);

        NodeIterator<T> *backward(int count);

        virtual void setPrev(NodeIterator<T> *to);

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
