#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexception.hpp"
#include <algorithm>

template <typename Comparable>
class BinarySearchTree{
    public:
        BinarySearchTree() : root(nullptr) {};
        BinarySearchTree(const BinarySearchTree &rhs): root(nullptr) {
            root = clone(rhs.root);
        }
        BinarySearchTree(BinarySearchTree &&rhs): root{rhs.root}{
            rhs.root = nullptr;
        }
        ~BinarySearchTree(){
            makeEmpty();
        }

        BinarySearchTree & operator=(const BinarySearchTree &rhs){
            BinarySearchTree copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        BinarySearchTree & operator=(BinarySearchTree &&rhs){
            std::swap(root, rhs.root);
            return *this;
        }

        const Comparable &findMin() const{
            if(isEmpty()) throw UnderflowException{};
            return findMin(root)->element;
        }
        const Comparable &findMax() const{
            if(isEmpty()) throw UnderflowException{};
            return findMax(root)->element;
        }

        bool contains(const Comparable &x) const{
            return contains(x, root);
        }

        bool isEmpty() const{
            return root==nullptr;
        }

        void printTree(ostream & out = cout) const{
            if(isEmpty()) out<<"Empty tree"<<endl;
            else printTree(root, out);
        }

        void makeEmpty(){
            makeEmpty(root);
        }

        void insert(const Comparable &x){
            insert(x, root);
        }

        void insert(Comparable &&x){
            insert(std::move(x), root);
        }

        void remove(const Comparable & x){
            remove(x, root);
        }

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

        void insert(const Comparable &x, Node * & t){
            if(isEmpty())
                t = new Node{x, nullptr, nullptr};
            else if (x < t->element)
                insert(x, t->left);
            else if (x > t->element)
                insert(x, t->right);
            else ;

        }

        void insert(Comparable && x, Node * & t){
            if(t==nullptr)
                t = new Node{std::move(x), nullptr, nullptr};
            else if (x < t->element)
                insert(std::move(x), t->left);
            else if (x > t->element)
                insert(std::move(x), t->right);
            else ;
        }

        void remove(const Comparable &x, Node *&t){
            if(isEmpty()) return;
            else if (x < t->element) remove(x, t->left);
            else if (x > t->element) remove(x, t->right);
            else if (t->left != nullptr && t->right != nullptr){
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
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
            return t;
        }

        Node *findMin(Node *t) const{
            if(isEmpty()) return false;
            while(t->right != nullptr) t = t->right;
            return t;
        }

/******************************************************************
        bool contains(const Comparable &x, Node *t) const{
            if(isEmpty()) return false;
            else if(x < t->element) return contains(x, t->left);
            else if(x > t->element) return contains(x, t->right);
            else return true;
        }
*******************************************************************/

        bool contains(const Comparable &x, Node *t) const {
            while(t!=nullptr){
                if(x < t->element) t = t->left;
                else if (x > t->element) t = t->right;
                else return true;
            }
            return false;
        }

        void makeEmpty(Node *&t){
            if (t!=nullptr){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = nullptr;
        }
        void printTree(Node *t, ostream &out) const{
            if (t!=nullptr){
                printTree(t->left, out);
                out<< t->element<< endl;
                printTree(t->right, out);
            }
        }

        Node * clone(Node *t) const{
            if (t!=nullptr)
                return new Node{t->element, clone(t->left), clone(t->right)};
            else
                return nullptr;
        }
};

#endif
