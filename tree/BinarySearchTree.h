#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexception.h"
#include <algorithm>
using namespace std;

template <typename Comparable>
class BinarySearchTree{
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &rhs);
        BinarySearchTree(BinarySearchTree &&rhs);
        ~BinarySearchTree();

        const Comparable &findMin() const;
        const Comparable &findMax() const;

        bool contains(const Comparable &x) const{
            return contains(x, root);
        }

        bool isEmpty() const{
            return root==nullptr;
        }
        void printTree(ostream & out = cout) const;

        void makeEmpty(){
        }
        void insert(const Comparable &x){
            insert(x, root);
        }
        void insert(Comparable &&x){
            insert(x, root)
        }
        void remove(const Comparable & x){
            remove(x, root);
        }

        BinarySearchTree & operator= (const BinarySearchTree &rhs);
        BinarySearchTree & operator= (BinarySearchTree &&rhs);
    
    private:
        struct Node{
            Comparable element;
            Node *left;
            Node *right;
            
            Node(const Comparable &theElement, Node *left, Node *right)
            : element(theElement), left(left), right(right) {}

            Node(Comparable &&theElement, Node *left, Node *right)
            : element(std::move(theElement)), left(left), right(right) {}
        };

        Node *root;

        void insert(const Comparable &x, Node *&t){
            if(isEmpty())
                t = new Node{x, nullptr, nullptr};
            else if (x < t->element)
                insert(x, t->left);
            else if (x > t->element)
                insert(x, t->right);
            else ;

        }

        void insert(Comparable &&x, Node *&t){
            if(isEmpty())
                t = new Node{std::move(x), nullptr, nullptr};
            else if (x < t->element)
                insert(x, t->left);
            else if (x > t->element)
                insert(x, t->right);
            else ;
        }

        void remove(const Comparable &x, Node *&t){
            if(isEmpty()) return;
            else if (x < t->element) remove(x, t->left);
            else if (x > t->element) remove(x, t->right);
            else if (t->left != nullptr && t->right != nullptr){
                t->element = findMin(t->right)->element;
                remove(t->element, t->right)
            }
            else
            {
                Node *oldNode = t;
                t= (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }
            
        }

        Node *findMax(Node *t) const{
            if(isEmpty()) return false;
            while(t->left != nullptr) t = t->left;
            return t
        }

        Node *findMin(Node *t) const{
            if(isEmpty()) return False;
            while(t->right != nullptr) t = t->right;
            return t;
        }

        bool contains(const Comparable &x, Node *t) const{
            if(isEmpty()) return false;
            else if(x < t->element) return contains(x, t->left);
            else if(x > t->element) return contains(x, t->right);
            else return true;
        }

        void makeEmpty(Node *&t);
        void printTree(Node *t, ostream &out) const;
        Node * clone(Node *t) const;
};

#endif
