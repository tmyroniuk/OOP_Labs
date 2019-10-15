//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LINKED_LIST_H
#define LISTS_LINKED_LIST_H


#include "List_Realisation.h"

template <typename T>
class Linked_List : public List_Realisation<T> {
public:
    class Node : public NodeIterator<T>{
    private:
        NodeIterator<T>* next;
        NodeIterator<T>* prev;
    public:
        Node();
        Node(T, NodeIterator<T>*, NodeIterator<T>*);
        NodeIterator<T>* getPrev();
        NodeIterator<T>* getNext();
        virtual void setPrev(NodeIterator<T>*);
        virtual void setNext(NodeIterator<T>*);
    };

    Linked_List();
    void insert(NodeIterator<T>*, T);
    T extract(NodeIterator<T>*);
    Node* begin();
    Node* end();
    ~Linked_List();
private:
    Node* head;
    Node* tail;
};

#include "Linked_List.inl"

#endif //LISTS_LINKED_LIST_H
