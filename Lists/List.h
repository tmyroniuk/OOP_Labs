//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H

#include "List_Realisation.h"

template <typename T>
class List {
public:
    class Iterator{
    private:
        NodeIterator<T>* node;
    public:
        friend NodeIterator<T>* List::getNode(const Iterator&);
        Iterator();
        Iterator(const Iterator&);
        explicit Iterator(NodeIterator<T>*);
        Iterator& operator= (const Iterator&);
        Iterator& operator++ ();
        const Iterator operator++ (int);
        Iterator& operator-- ();
        const Iterator operator-- (int);
        bool operator== (const Iterator&);
        bool operator!= (const Iterator&);
        T &operator* ();
    };
    enum Type {Linked, Array};
    struct TypeHolder{
        TypeHolder();
        Type type;
    };


    List();
    Iterator begin();
    Iterator end();
    void insert(const Iterator&, T);
    T extract(const Iterator&);
    void push_back(T);
    T pop_back();
    void push_front(T);
    T pop_front();
    T& front();
    T& back();
    unsigned int size();
private:
    TypeHolder type;
    List_Realisation<T>* realisation;
    NodeIterator<T>* getNode(const Iterator&);
};
#include "List.inl"

#endif //LISTS_LIST_H
