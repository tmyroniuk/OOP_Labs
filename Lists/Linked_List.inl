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
        //fix tail
        tail->setPrev(head);
    }
    else{
        auto temp= new Node(data, pos->getPrev(), pos);
        //fix right
        pos->setPrev(temp);
        //in case it is not head fix left
        if(pos->getPrev())
            temp->getPrev()->setNext(temp);
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
            pos->getPrev()->setNext(pos->getNext());
        //fix right
        pos->getNext()->setPrev(pos->getPrev());
        delete pos;
        len--;
    }
    return temp;
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
Linked_List<T>::~Linked_List() {
    for(auto i = head; i!=tail; i=i->getNext()) delete i;
    delete tail;
}

template<typename T>
Linked_List<T>::Node::Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next) : NodeIterator(data), prev(_prev), next(_next) {}

template<typename T>
NodeIterator<T> *Linked_List<T>::Node::getPrev() {
    return prev;
}

template<typename T>
NodeIterator<T> *Linked_List<T>::Node::getNext() {
    return next;
}

template<typename T>
void Linked_List<T>::Node::setPrev(NodeIterator<T> *to) {
    prev = to;
}

template<typename T>
void Linked_List<T>::Node::setNext(NodeIterator<T> *to) {
    next = to;
}
