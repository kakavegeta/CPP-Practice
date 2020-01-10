#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H 

#include "dsexception.hpp"

#include <vector>
#include <algorithm>


template <typename T>
class LeftistHeap
{
    public:
        LeftistHeap(): root{nullptr} {}

        LeftistHeap(const LeftistHeap& rhs):
        root{nullptr} {root = clone(rhs.root);}

        LeftistHeap(LeftistHeap&& rhs):
        root{rhs.root} {rhs.root = nullptr;}

        ~LeftistHeap()
        {
            make_empty();
        }

        LeftistHeap& operator=(const LeftistHeap& rhs)
        {
            LeftistHeap copy = rhs;
            std::swap(copy, *this);
            return *this;
        }
        LeftistHeap& operator=(LeftistHeap&& rhs)
        {
            std::swap(root, rhs.root);
            return *this;
        }

        bool is_empty() const
        {
            return root == nullptr;
        }

        const T& find_min() const
        {
            if(is_empty()) throw UnderflowException{};
            return root->val;
        }

        void insert(const T& x)
        {
            root = merge(root, new Node(x));
        }
        void insert(T&& x)
        {
            root = merge(root, new Node(std::move(x)));
        }
        void delete_min()
        {
            if(is_empty()) throw UnderflowException{};
            Node* old = root;
            root = merge(root->left, root->right);
            delete old;
        }
        void delete_min(T& x)
        {
            if(is_empty()) throw UnderflowException{};
            Node* old = root;
            x = root->val;
            root = merge(root->left, root->right);
            delete old;
        }
        void make_empty()
        {
            reclaim_memory(root);
            root = nullptr;
        }

        void merge(LeftistHeap& rhs)
        {
            if(this == &rhs) return; // disallow rhs.merge(rhs)
            root = merge(root, rhs.root);
            rhs.root = nullptr;
        }

    private:
        struct Node
        {
            T val;
            Node* left;
            Node* right;
            int npl;

            Node(const T& v, Node* l = nullptr, Node* r = nullptr, int n = 0):
            val{v}, left{l}, right{r}, npl{n} {}

            Node(const T&& v, Node* l = nullptr, Node* r = nullptr, int n=0):
            val{std::move(v)}, left{l}, right{r}, npl{n} {}
        };

        Node* root;

        Node* merge(Node* lhs, Node* rhs)
        {
            if(lhs == nullptr) return rhs;
            if(rhs == nullptr) return lhs;
            if(rhs->val > lhs->val) merge_recur(lhs, rhs);
            else merge_recur(rhs, lhs);
            
        }

        Node* merge_recur(Node* lhs, Node* rhs) // assume lhs->val is the smaller one
        {
            if(lhs->left == nullptr) lhs->left = rhs;
            else
            {
                lhs->right = merge(lhs->right, rhs);
                if(lhs->left->npl < lhs->right->npl) swap_children(lhs);
                lhs->npl = lhs->right->npl + 1;
            }
            return lhs;
        }

        void swap_children(Node* t)
        {
            std::swap(t->left, t->right);
        }

        void reclaim_memory(Node* t)
        {
            if(t!=nullptr){
                reclaim_memory(t->left);
                reclaim_memory(t->right);
                delete t;
            }
        }

        Node* clone(Node* t) const
        {
            if(t==nullptr) return t;
            else return new Node(t->val, clone(t->left), clone(t->right), t->npl);
        }

};

#endif
