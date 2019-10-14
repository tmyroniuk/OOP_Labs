//
// Created by tmyro on 13.10.2019.
//

#include "Linked_List.h"

template<typename T>
Linked_List<T>::Linked_List() : List_Realisation(), head(new Node()), tail(head) {}

template<typename T>
Linked_List<T>::Node::Node() : NodeIterator(), prev(nullptr), next(nullptr) {}

template<typename T>
void Linked_List<T>::insert(NodeIterator<T> *pos, T data) {
    if(len == 0){
        //create head
        head = new Node(data, nullptr, tail);
        changeNode(tail, head, nullptr);
    }
    else{
        auto temp= new Node(data, pos->getPrev(), pos);
        //fix right
        changeNode(pos, temp, pos->getNext());
        //in case it is not head fix left
        if(pos->getPrev()) changeNode(temp->getPrev(), temp->getPrev()->getPrev(), temp);
    }
    len++;
}

template<typename T>
T Linked_List<T>::extract(NodeIterator<T> * pos) {
    T temp = pos->getVal();
    //we shouldn't delete tail
    if(pos!=tail) {
        //in case it is not head fix left
        if(pos->getPrev())
            changeNode(pos->getPrev(), pos->getPrev()->getPrev(), pos->getNext());
        //fix right
        changeNode(pos->getNext(), pos->getPrev(), pos->getNext()->getNext());
        delete pos;
        len--;
    }
    return temp;
}

template<typename T>
void Linked_List<T>::changeNode(Linked_List::Node * from, Linked_List::Node * _prev, Linked_List::Node *_next) {
    (from->prev) = _prev;
    (fron->next) = _next;
}

template<typename T>
typename Linked_List<T>::Node *Linked_List<T>::begin() {
    return head;
}

template<typename T>
typename Linked_List<T>::Node *Linked_List<T>::end() {
    return tail;
}

template<typename T>
Linked_List<T>::Node::Node(T data, Linked_List::Node *_prev, Linked_List::Node *_next) : NodeIterator(data), prev(_prev), next(_next) {}

template<typename T>
typename Linked_List<T>::Node *Linked_List<T>::Node::getPrev() {
    return prev;
}

template<typename T>
typename Linked_List<T>::Node *Linked_List<T>::Node::getNext() {
    return next;
}
