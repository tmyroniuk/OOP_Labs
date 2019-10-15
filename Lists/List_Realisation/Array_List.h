//
// Created by tmyro on 14.10.2019.
//

#ifndef LISTS_ARRAY_LIST_H
#define LISTS_ARRAY_LIST_H


#include "List_Realisation.h"

template <typename T>
class Array_List : public List_Realisation<T> {
public:
    class Node : public NodeIterator<T>{
    public:
        Node();
        Node(T);
        Node* getPrev();
        Node* getNext();
    };

    Array_List();
    void insert(NodeIterator<T>*, T);
    T extract(NodeIterator<T>*);
    NodeIterator<T>* begin();
    NodeIterator<T>* end();
    ~Array_List();
private:
    //>=2
    const unsigned int grow_rate;
    NodeIterator<T>* head;
    unsigned int reserved;
    //reserve more memory
    void grow();
    //release memory on empty
    void shrink();
};

#include "Array_List.inl"

#endif //LISTS_ARRAY_LIST_H
