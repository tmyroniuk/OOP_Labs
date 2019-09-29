//
// Created by tmyro on 29.09.2019.
//

#include "List.h"

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const Iterator& a) {
    current = a.current;
    return *this;
}

template<typename T>
T & List<T>::Iterator::operator*() {
    return current->val;
}

template<typename T>
void List<T>::Iterator::operator++() {
    current = current->next;
}

template<typename T>
void List<T>::Iterator::operator--() {
    current = current->prev;
}

template<typename T>
void List<T>::Iterator::operator+=(const int & a) {
    if(a<0) this-= (-a);
    for(int i=0; i<a; i++) this++;
}

template<typename T>
void List<T>::Iterator::operator-=(const int & a) {
    if(a<0) this+= (-a);
    for(int i=0; i<a; i++) this--;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(const int & a) {
    List::Iterator temp == this;
    temp+=a;
    return temp;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(const int & a) {
    List::Iterator temp == this;
    temp-=a;
    return temp;
}

template<typename T>
List<T>::Iterator::Iterator(ListNode<T> * a): current(a) {}

template<typename T>
List<T>::List() {
    head = new ListNode<T>();
    tail = new ListNode<T>();
    tail->prev = head;
    head->prev = tail;
}

template<typename T>
List<T>::~List() {
    head->RecursiveDestructor();
}

template<typename T>
typename List<T>::Iterator List<T>::end() {
    return List::Iterator(tail);
}

template<typename T>
typename List<T>::Iterator List<T>::begin() {
    return List::Iterator(head);
}
