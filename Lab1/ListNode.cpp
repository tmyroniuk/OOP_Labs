//
// Created by tmyro on 29.09.2019.
//

#include "ListNode.h"

template<typename T>
ListNode<T>::ListNode(T val, ListNode* prev, ListNode* next) {
    this.val = val;
    this.next=next;
    this.prev=prev;
}

template<typename T>
ListNode<T>::ListNode(T val): val(val) {}

template<typename T>
void ListNode<T>::RecursiveDestructor() {
    if(next) next->RecursiveDestructor();
    if(prev) prev.RecursiveDestructor();
    delete this;
}
