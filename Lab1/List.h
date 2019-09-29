//
// Created by tmyro on 29.09.2019.
//

#ifndef LAB1_LIST_H
#define LAB1_LIST_H

#include "ListNode.h"
#include "CList.h"

template <typename T>
class List: CList<T> {
private:
    ListNode<T>* head, tail;
public:
    List();
    ~List();
    class Iterator{
    private:
        ListNode<T>* current = nullptr;
    public:
        Iterator(ListNode<T>*);
        List::Iterator& operator= (const Iterator&);
        T& operator* ();
        void operator++ ();
        void operator-- ();
        List::Iterator operator+ (const int&);
        List::Iterator operator- (const int&);
        void operator+= (const int&);
        void operator-= (const int&);
    };

    List::Iterator end();
    List::Iterator begin();
};


#endif //LAB1_LIST_H
