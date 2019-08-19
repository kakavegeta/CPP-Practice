#ifndef AVLTREE_H
#define AVLTREE_H

#include <algorithm>
#include <vector>
#include <iostream>
#include "dsexception.h"



template<typename Comparable>
class AVLTree{
    public:
        AVLTree( ): root{nullptr}
        { }

        AVLTree(const AVLTree &rhs): root{nullptr}
        {root = clone(rhs.root);}

        AVLTree(AVLTree &&rhs): root{rhs.root}
        {rhs.root = nullptr;}

        ~AVLTree( ){
            make_empty( );
        }

        AVLTree & operator=(const AVLTree &rhs){
            std::swap(root, rhs.root);
            return *this;
        }

        const Comparable &find_min( ) const{
            if(is_empty())
                throw UnderflowException{ };
            return find_min(root)->element;
        }

        const Comparable &find_max( ) const{
            if(is_empty())
                throw UnderflowException{ };
            return find_max(root)->element;
        }

        bool contains(const Comparable &x) const{
            return contains(root, x);
        }

        bool is_empty() const{
            return root==nullptr;
        }

        void print_tree( ) const {
            if(is_empty()){
                cout<<"Empty Tree"<<endl;
            } else {
                print_tree(root);
            }
        }

        void make_empty( ){
            make_empty(root);
        } 

    
    private:
        struct AVLNode{
            Comparable element;
            AVLNode *left;
            AVLNode *right;
            int height;

            AVLNode(const Comparable &ele, AVLNode *lt, AVLNode *rt, int h=0):
            element{ele}, left{lt}, right{rt}, height{h} { }

            AVLNode(const Comparable &&ele, AVLNode *lt, AVLNode *rt, int h=0):
            element{std::move(ele)}, left{lt}, right{rt}, height{h} { }
        };

        AVLNode *root;

        void insert(const Comparable &x, AVLNode *&t){
            if (t==nullptr)
                t = new AVLNode{x, nullptr, nullptr};
            else if(x < t->element)
                insert(x, t->left);
            else if(x > t->element)
                insert(x, t->right);
            balance(t);
        }

        void insert(const Comparable &&x, AVLNode *&t){
            if (t==nullptr)
                t = new AVLNode{std::move(x), nullptr, nullptr};
            else if(x < t->element)
                insert(std::move(x), t->left);
            else if(x > t->element)
                insert(std::move(x), t->right);
            balance(t);
        }



        void remove(const Comparable &x, AVLNode *&t) {
            if (t==nullptr){
                return;
            }
            if (x < t->element){
                remove(x, t->left);
            } else if (x > t->element){
                remove(x, t->right);
            } else if (t->left != nullptr && t->left != nullptr){
                t->element = find_min(t->right)->element;
                remove(t->element, t->right);
            } else {
                AVLNode *old = t;
                t = (t->left!=nullptr)? t->left:t->right;
                delete old;
            }
            balance(t);
        }

        static const int ALLOWED_IMBALANCE = 1;

        void balance(AVLNode *&t){
            if(t==nullptr)
                return;
            if(height(t->left)-height(t->right)>ALLOWED_IMBALANCE){
                if(height(t->left->left)>=height(t->left->right)){
                    rotate_right(t);
                }else{
                    rotate_left_right(t);
                }
            }else{
                if(height(t->right->right)>=height(t->right->left)){
                    rotate_left(t);
                }else{
                    rotate_left_right(t);
                }
            }
            t->height = max(height(t->left), height(t->right)) + 1;
        }

        bool contains(AVLNode *t, const Comparable &x) const{
            while (t!=nullptr){
                if(t->element>x) 
                    t = t->left;
                else if(t->element<x) 
                    t = t->right;
                else 
                    return true;
            }
            return false;
        }

        void make_empty(AVLNode *&t){
            if(t!=nullptr){
                make_empty(t->left);
                make_empty(t->right);
                delete t;
            }
            t = nullptr;
        }

        void print_tree(AVLNode *t) const{
            if(t!=nullptr){
                print_tree(t->left);
                cout<<t->element<<endl;
                print_tree(t->right);
            }
        }

        AVLNode* clone(AVLNode *t) const{
            if(t==nullptr){
                return nullptr;
            }
            else{
                return new AVLNode{t->element, clone(t->left), clone(t->right), t->height};
            }
        }

        int height(AVLNode *t) const{
            return t==nullptr? -1:t->height;
        }

        int max(int lhs, int rhs) const{
            return lhs > rhs? lhs:rhs;
        }

        void rotate_left(AVLNode *&x){
            AVLNode *y = x->right;
            x->right = y->left;
            y->left = x;
            x->height = max(height(x->left), height(x->right))+1;
            y->height = max(height(y->left), height(y->right))+1;
            x = y;
        }

        void rotate_right(AVLNode *&x){
            AVLNode *y = x->left;
            x->left = y->right;
            y->right = x;
            x->height = max(height(x->left), height(x->right))+1;
            y->height = max(height(y->left), height(y->right))+1;
            x = y;
        }

        void rotate_left_right(AVLNode *&x){
            rotate_left(x->right);
            rotate_right(x);
        }

        void rotate_right_left(AVLNode *&x){
            rotate_right(x->left);
            rotate_left(x);
        }

};

#endif