//
// Created by tmyro on 14.10.2019.
//

#ifndef LISTS_ARRAYLIST_H
#define LISTS_ARRAYLIST_H

#include "ListRealisation.h"

template<typename T>
class ArrayList : public ListRealisation<T> {
public:
    class Node : public NodeIterator<T> {
    public:
        Node();

        Node(T _val);

        NodeIterator<T> *getPrev();

        NodeIterator<T> *getNext();

        NodeIterator<T> *forward(int count);

        NodeIterator<T> *backward(int count);
    };

    ArrayList();

    void insert(NodeIterator<T> *pos, T data);

    T extract(NodeIterator<T> *pos);

    NodeIterator<T> *begin();

    NodeIterator<T> *end();

    ~ArrayList();

private:
    //>=2
    const unsigned int grow_rate;
    NodeIterator<T> *head;
    unsigned int reserved;

    //reserve more memory
    void grow();

    //release memory on empty
    void shrink();
};

#include "ArrayList.inl"

#endif //LISTS_ARRAYLIST_H
