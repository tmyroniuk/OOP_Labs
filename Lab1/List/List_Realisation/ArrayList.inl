/**
 * @file ArrayList.inl
 * @author tmyroniuk
 * @date 14.10.2019
 * @brief Contains definition of ArrayList class methods.
 */

#include "ArrayList.h"


template<typename T>
ArrayList<T>::Node::Node(T _val) : NodeIterator(_val) {}

template<typename T>
NodeIterator<T> *ArrayList<T>::Node::getPrev() {
    return (this - 1);
}

template<typename T>
NodeIterator<T> *ArrayList<T>::Node::getNext() {
    return (this + 1);
}

template<typename T>
NodeIterator<T> *ArrayList<T>::Node::backward(int count) {
    return (this - count);
}

template<typename T>
NodeIterator<T> *ArrayList<T>::Node::forward(int count) {
    return (this + count);
}

template<typename T>
void ArrayList<T>::grow() {
    reserved*=grow_rate;
    auto temp = new Node[reserved];
    for (unsigned int i = 0; i < len; i++) {
        temp[i].setVal(head[i].getVal());
    }
    head = temp;
}

template<typename T>
void ArrayList<T>::shrink() {
    if (len != 0) return;
    auto temp = new Node;
    temp->setVal(head->getVal());
    head = temp;
}

template<typename T>
ArrayList<T>::ArrayList() : ListRealisation(), grow_rate(2), reserved(2), head(new Node()) {}

template<typename T>
void ArrayList<T>::insert(NodeIterator<T> *pos, T data) {
    auto i = end();
    while (i != pos) {
        i->setVal(i->getPrev()->getVal());
        i--;
    }
    i->setVal(data);
    len++;
    if (len + 1 >= reserved) grow();
}

template<typename T>
T ArrayList<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if (pos != end()) {
        len--;
        if (len == 0)
            shrink();
        else
            for (auto i = pos; i != end(); i++) *i = *(i->getNext());
    }
    return temp;
}


template<typename T>
ArrayList<T>::Node::Node() : NodeIterator() {}

template<typename T>
NodeIterator<T> *ArrayList<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *ArrayList<T>::end() {
    return head + len;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] head;
}

