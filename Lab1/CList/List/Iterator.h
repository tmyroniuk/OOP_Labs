//
// Created by tmyro on 29.09.2019.
//

#ifndef LAB1_ITERATOR_H
#define LAB1_ITERATOR_H

#include "List.h"

template <typename T>
class List<T>::Iterator {
private:
    Node* current = nullptr;
public:
    Iterator(Node*);
    Iterator& operator= (const Iterator&);
    T& operator* ();
    void operator++ ();
    void operator-- ();
    Iterator operator+ (const int&);
    Iterator operator- (const int&);
    void operator+= (const int&);
    void operator-= (const int&);
};


#endif //LAB1_ITERATOR_H
