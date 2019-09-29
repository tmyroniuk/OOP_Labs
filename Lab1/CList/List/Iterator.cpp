//
// Created by tmyro on 29.09.2019.
//

#include "Iterator.h"

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
List<T>::Iterator::Iterator(Node * a): current(a) {}