#ifndef RBTREE_H
#define RBTREE_H

#include <algorithm>
#include <vector>
#include <iostream>
#include "dsexception.h"

template<typename T>
class RBTree{
    public:
    

    private:
    struct Node{
        T element;
        Node* left;
        Node* right;
        Node* parent;
        bool color;

        Node(const T& ele, Node* lt, Node* rt, bool clr):
        element{ele}, left{lt}, right{rt}, color{clr} {}

        Node(const T&& ele, Node* lt, Node* rt, bool clr): 
        element{std::move(ele)}, left{lt}, right{rt}, color{clr} {} 
    };

    Node* root;

    void insert(const T& ele, Node*& t){ }

    void delete(const T& ele, Node*& t){ }

    void left_rotate(Node*& t){
        Node* y = t->right;
        t->right = y->left;
        y->left = x;
        

    }
    

    
};

#endif