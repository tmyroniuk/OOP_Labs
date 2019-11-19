//
// Created by tmyro on 18.11.2019.
//

#include "VectorList.h"

template<typename T>
VectorList<T>::Node::Node(T _val) : NodeIterator(_val) {}

template<typename T>
NodeIterator<T> *VectorList<T>::Node::getPrev() {
    return (this - 1);
}

template<typename T>
NodeIterator<T> *VectorList<T>::Node::getNext() {
    return (this + 1);
}

template<typename T>
NodeIterator<T> *VectorList<T>::Node::backward(int count) {
    return (this - count);
}

template<typename T>
NodeIterator<T> *VectorList<T>::Node::forward(int count) {
    return (this + count);
}

template<typename T>
VectorList<T>::VectorList() : ListRealisation(), body(new std::vector<Node>(1)) {}

template<typename T>
void VectorList<T>::insert(NodeIterator<T> *pos, T data) {
    T temp;
    if (pos == end()) temp = data;
    else {
        temp = body->back().getVal();
        auto i = end() - 1;
        while (i != pos) {
            i->setVal(i->getPrev()->getVal());
            i--;
        }
        i->setVal(data);
    }
    len++;
    body->push_back(Node(temp));
}

template<typename T>
T VectorList<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if (pos != end())
        for (auto i = pos; i != end(); i++)
            *i = *(i->getNext());
    body->pop_back();
    len--;
    return temp;
}


template<typename T>
VectorList<T>::Node::Node() : NodeIterator() {}

template<typename T>
NodeIterator<T> *VectorList<T>::begin() {
    return &(body->front());
}

template<typename T>
NodeIterator<T> *VectorList<T>::end() {
    return &(body->back());
}

template<typename T>
VectorList<T>::~VectorList() {
    delete body;
}
