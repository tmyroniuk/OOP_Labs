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
        temp[i] = head[i];
    reserved*=grow_rate;
    head = temp;
}

template<typename T>
void Array_List<T>::shrink() {
    if(len!=0) return;
    auto temp = new Node;
    *temp = *head;
    head = temp;
}

template<typename T>
Array_List<T>::Array_List() : List_Realisation(), grow_rate(2),  reserved(1), head(new Node<T>) {}

template<typename T>
void Array_List<T>::insert(NodeIterator<T> *pos, T data) {
    len++;
    if(len>=reserved) grow();
    auto i= head + len;
    while(i!=pos) {
        *i = *(i->getPrev());
        i--;
    }
    changeNode(i ,data);
}

template<typename T>
T Array_List<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if(pos!=end()) {
        len--;
        if (len == 0) shrink();
        for(auto i=pos;i!=end();i++) *i = *(i->getNext());
    }
    return temp;
}

template<typename T>
void Array_List<T>::changeNode(Node* from, T data) {
    from->T = data;
}

template<typename T>
typename Array_List<T>::Node *Array_List<T>::begin() {
    return head;
}

template<typename T>
typename Array_List<T>::Node *Array_List<T>::end() {
    return head+len;
}

