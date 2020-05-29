#ifndef RBTREE_H
#define RBTREE_H

#include <algorithm>
#include <vector>
#include <iostream>
#include "dsexception.h"

enum Color {RED, BLACK, DOUBLE_BLACK};

template<typename T>
class RBTree{
    public:
    

    private:
    struct Node{
        T key;
        Node* left;
        Node* right;
        Node* parent;
        int color;

        Node(const T& k): 
        key{k}, left{nullptr}, right{nullptr}, parent{nullptr}, color{RED} {}

        Node(const T&& k): 
        key{std::move(k)}, left{nullptr}, right{nullptr}, parent{nullptr}, color{RED} {}
        
        Node(const T& k, Node* lt, Node* rt, Node* p, bool clr):
        key{k}, left{lt}, right{rt}, parent{p}, color{clr} {}

        Node(const T&& k, Node* lt, Node* rt, Node* p, bool clr): 
        key{std::move(k)}, left{lt}, right{rt}, parent{p}, color{clr} {} 
    };

    Node* root;

    void insert(const T& key, Node*& t);

    void delete(const T& key, Node*& t);

    void left_rotate(Node*& x){
        Node* y = x->right;
        x->right = y->left;
        if(y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if(x==x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void right_rotate(Node*& x){
        Node* y = x->left;
        x->left = y->right;
        if(y->right != nullptr) y->right->parent = x;
        y->parent = x->parent;
        if(x->parent == nullptr) root = y;
        else if(x->parent->left == x) x->parent->left = y;
        else x->parent->right = y;
        y->right = x;
        x->parent = y;
    }

    void insert(Node*& z){
        Node* x = root;
        Node* y = nullptr;
        while(x != nullptr){
            y = x;
            if(z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if(y == nullptr) root = z;
        else if(z->key < y->key) y->left = z;
        else y->right = z;
        z->left = nullptr;
        z->right = nullptr;
        z->color = RED;
        rb_insert_fixup(z);
    }

    void rb_insert_fixup(Node*& z){
        Node* y;
        while(z->parent->color == RED){
            if (z->parent == z->parent->parent->left){
               y = z->parent->parent->right; 
               if(y->color == RED){
                   z->parent->color = BLACK;
                   y->color = BLACK;
                   z->parent->parent->color = RED;
                   z = z->parent->parent;
               }
               else if(z == z->parent->right){
                   z = z->parent;
                   left_rotate(z);
               }
               z->parent->color = BLACK;
               z->parent->parent->color = RED;
               right_rotate(z->parent->parent);
            }else{
                y = z->parent->parent->left;
                if(y->color == RED){
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else if(z == z->parent->left){
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(z->parent->parent);
            }
        }
    }
};

#endif