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
        friend void Array_List<T>::changeNode(Node*, T);
        Node(T);
        Node* getPrev();
        Node* getNext();
    };

    Array_List();
    void insert(NodeIterator<T>*, T);
    T extract(NodeIterator<T>*);
    Node* begin();
    Node* end();
private:
    //>=2
    const unsigned int grow_rate = 2;
    Node* head;
    unsigned int reserved;
    //reserve more memory
    void grow();
    //release memory on empty
    void shrink();
    void changeNode(Node*, T);
};

#include "Array_List.inl"

#endif //LISTS_ARRAY_LIST_H
