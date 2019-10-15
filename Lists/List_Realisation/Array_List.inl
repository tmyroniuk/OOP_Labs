//
// Created by tmyro on 14.10.2019.
//

#include "Array_List.h"


template<typename T>
Array_List<T>::Node::Node(T _val) : NodeIterator(_val) {}

template<typename T>
typename Array_List<T>::Node *Array_List<T>::Node::getPrev() {
    return (this-1);
}

template<typename T>
typename Array_List<T>::Node *Array_List<T>::Node::getNext() {
    return (this+1);
}

template<typename T>
void Array_List<T>::grow() {
    auto temp = new Node[reserved*grow_rate];
    for(int i=0; i<reserved; i++)
        temp->setVal(head->getVal());
    reserved*=grow_rate;
    head = temp;
}

template<typename T>
void Array_List<T>::shrink() {
    if(len!=0) return;
    auto temp = new Node;
    temp ->setVal(head->getVal());
    head = temp;
}

template<typename T>
Array_List<T>::Array_List() : List_Realisation(), grow_rate(2),  reserved(2), head(new Node()) {}

template<typename T>
void Array_List<T>::insert(NodeIterator<T> *pos, T data) {
    auto i = end();
    while(i!=pos) {
        i ->setVal(i->getPrev()->getVal());
        i--;
    }
    i->setVal(data);
    len++;
    if(len+1>=reserved) grow();
}

template<typename T>
T Array_List<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if(pos!=end()) {
        len--;
        if (len == 0)
            shrink();
        else
            for(auto i=pos;i!=end();i++) *i = *(i->getNext());
    }
    return temp;
}


template<typename T>
Array_List<T>::Node::Node() : NodeIterator() {}

template<typename T>
NodeIterator<T> *Array_List<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *Array_List<T>::end() {
    return head+len;
}

template<typename T>
Array_List<T>::~Array_List() {
    delete[] head;
    std::cout<<"deleted Array\n";
}

