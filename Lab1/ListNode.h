//
// Created by tmyro on 29.09.2019.
//

#ifndef LAB1_LISTNODE_H
#define LAB1_LISTNODE_H

template <typename T>
class ListNode {
public:
    ListNode(T, ListNode*, ListNode*);
    void RecursiveDestructor();
    explicit ListNode(T);
    T val;
    ListNode* next=nullptr, prev=nullptr;
};


#endif //LAB1_LISTNODE_H
