#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H 

#include "dsexception.hpp"

#include <vector>
#include <algorithm>


template <typename T>
class LeftistHeap
{
    public:
        LeftistHeap();
        LeftistHeap(const LeftistHeap& rhs);
        LeftistHeap(LeftistHeap&& rhs);

        ~LeftistHeap();

        LeftistHeap& operator=(const LeftistHeap& rhs);
        LeftistHeap& operator=(LeftistHeap&& rhs);

        bool is_empty() const;

        const T& find_min() const;

        void insert(const T& x);
        void insert(T&& x);
        void delete_min();
        void delete_min(T& x);
        void make_empty();
        void merge(Node* rhs, bool recur = 1);

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
        Node* merge(Node* lhs, Node* rhs, bool recur = 1);
        Node* merge(Node* lhs, Node* rhs, bool recur = 0);
        void swap_children(Node* t);
        void reclam_memory(Node* t);
        Node* clone(Node* t) const;

};

#endif
