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
        Node* next;
        Node* prev;
    public:
        friend void Linked_List<T>::changeNode(Node*, Node*, Node*);
        Node();
        Node(T, Node*, Node*);
        Node* getPrev();
        Node* getNext();
    };

    Linked_List();
    void insert(NodeIterator<T>*, T);
    T extract(NodeIterator<T>*);
    Node* begin();
    Node* end();
private:
    void changeNode(Node*, Node*, Node*);
    Node* head;
    Node* tail;
};

#include "Linked_List.inl"

#endif //LISTS_LINKED_LIST_H
