//
// Created by tmyro on 13.10.2019.
//

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() : ListRealisation(), head(new Node()), tail(head) {}

template<typename T>
LinkedList<T>::Node::Node() : NodeIterator(), prev(nullptr), next(nullptr) {}

template<typename T>
LinkedList<T>::Node::Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next) : NodeIterator(data), prev(_prev),
                                                                                    next(_next) {}

template<typename T>
void LinkedList<T>::insert(NodeIterator<T> *pos, T data) {
    if (len == 0) {
        //create head
        head = new Node(data, nullptr, tail);
        //fix tail
        tail->setPrev(head);
    } else {
        Node *temp = new Node(data, pos->getPrev(), pos);
        //fix right
        pos->setPrev(temp);
        //in case it is not head fix left
        if (pos != head) {
            temp->getPrev()->setNext(temp);
        } else head = temp;
    }
    len++;
}

template<typename T>
T LinkedList<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    //we shouldn't delete tail
    if (pos != tail) {
        //in case it is not head fix left
        if (pos != head)
            pos->getPrev()->setNext(pos->getNext());
        else head = pos->getNext();
        //fix right
        pos->getNext()->setPrev(pos->getPrev());
        delete pos;
        len--;
    }
    return temp;
}

template<typename T>
NodeIterator<T> *LinkedList<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *LinkedList<T>::end() {
    return tail;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    for (auto i = head; i != tail; i = i->getNext()) delete i;
    delete tail;
}

template<typename T>
NodeIterator<T> *LinkedList<T>::Node::getPrev() {
    return prev;
}

template<typename T>
NodeIterator<T> *LinkedList<T>::Node::backward(int count) {
    if (count < 0) forward(-count);
    NodeIterator *temp = this;
    for (int i = 0; i < count; i++) {
        temp = temp->getPrev();
    }
    return temp;
}

template<typename T>
NodeIterator<T> *LinkedList<T>::Node::getNext() {
    return next;
}

template<typename T>
NodeIterator<T> *LinkedList<T>::Node::forward(int count) {
    if (count < 0) backward(-count);
    NodeIterator<T> *temp = this;
    for (int i = 0; i < count; i++) {
        temp = temp->getNext();
    }
    return temp;
}

template<typename T>
void LinkedList<T>::Node::setPrev(NodeIterator<T> *to) {
    prev = to;
}

template<typename T>
void LinkedList<T>::Node::setNext(NodeIterator<T> *to) {
    next = to;
}
