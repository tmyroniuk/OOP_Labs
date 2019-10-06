//
// Created by tmyro on 06.10.2019.
//

#include "List.h"

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const List<T>::Iterator& that) {
    current = that.current;
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    List<T>::Iterator temp(*this);
    operator++();
    return temp;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    current = current->prev;
    return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    List<T>::Iterator temp(*this);
    operator--();
    return temp;
}

template<typename T>
void List<T>::Iterator::operator+=(const int &that) {
    if(that<0) (*this) -= (-that);
    else
        for(int i=0; i<that; i++) ++(*this);
}

template<typename T>
void List<T>::Iterator::operator-=(const int &that) {
    if(that<0) (*this) += (-that);
    else
        for(int i=0; i<that; i++, (*this)--);
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(const int &that) {
    List<T>::Iterator temp = (*this);
    temp-=that;
    return temp;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(const int &that) {
    List<T>::Iterator temp = (*this);
    temp+=that;
    return temp;
}

template<typename T>
List<T>::Iterator::Iterator(const Iterator& that): current(that.current) {}

template<typename T>
bool List<T>::Iterator::operator==(const List<T>::Iterator & that) {
    return current == that.current;
}

template<typename T>
bool List<T>::Iterator::operator!=(const List<T>::Iterator & that) {
    return current == that.current;
}

template<typename T>
List<T>::Iterator::Iterator(): current(nullptr) {}
