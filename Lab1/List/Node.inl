//
// Created by tmyro on 06.10.2019.
//

template<typename T>
List<T>::Node::Node(T val_, Node* prev_, Node* next_) : val(val_), prev(prev_), next(next_) {}

template<typename T>
List<T>::Node::Node() : val(), prev(nullptr), next(nullptr) {}

template<typename T>
void List<T>::Node::RecursiveDestructor() {
    if(next) next->RecursiveDestructor();
    delete this;
}