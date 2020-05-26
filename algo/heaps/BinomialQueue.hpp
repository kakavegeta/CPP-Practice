#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H 

#include "dsexception.hpp"

#include <vector>


template <typename T> // T is comparable
class BinomialQueue
{
    public:
        BinomialQueue()
        : Trees(DEFAULT_TREE_NUM)
        {
            for(auto& root:Trees) root = nullptr;
            curret_size = 0;
        }

        BinomialQueue(const T& x)
        : Trees(1), current_size{1}
        {
            Trees[0] = new Node(x);
        }

        BinomialQueue(const BinomialQueue& rhs)
        : Trees(rhs.Trees.size()), current_size{rhs.current_size}
        {
            for(int i=0; i < rhs.Trees.size(); ++i)
            {
                Trees[i] = clone(rhs.Trees[i]);
            }
        }

        BinomialQueue(BinomialQueue&& rhs)
        : Trees{std::move(rhs.Trees)}, current_size{rhs.current_size}{};

        BinomialQueue& operator=(const BinomialQueue& rhs)
        {
            BinomialQueue copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        BinomialQueue& operator=(BinomialQueue&& rhs)
        {
            if(this != &rhs)
            {
                Trees = rhs.Trees;
                current_size = rhs.current_size;
                rhs.make_empty();
                rhs.current_size = 0;   
            }
            return *this;
        }

        ~BinomialQueue() {make_empty();}

        bool is_empty() const
        {return current_size == 0;}

        void insert(const T& x)
        {
            BinomialQueue q{x};
            merge(q);
        }

        void insert(T&& x)
        {
            BinomialQueue q{std::move(x)};
            merge(q);
        }
        
        const T& find_min() const
        {
            if(is_empty()) throw UnderflowException{};
            return Trees[find_min_index()]->val;
        }

        void delete_min()
        {
            T x;
            delete_min(x);
        }

        void delete_min(T& x)
        {
            if(is_empty()) throw UnderflowException{};
            int min_idx = find_min_index();
            x = Trees[min_idx]->val;
            Node* old = Trees[min_idx];
            Node* del_tree = old->left;
            delete old;

            BinomialQueue del_q;
            del_q.Trees.resize(min_idx);
            del_q.current_size = (1 << min_idx) - 1;
            for(int i = min_idx-1; i>=0; ++i)
            {
                del_q.Trees[i]  =  del_tree;
                del_tree = del_tree->right;
                del_q.Trees[i]->right = nullptr;
            }
            Trees[min_idx] = nullptr;
            current_size -= del_q.current_size + 1;
            merge(del_q);
        }

        void merge(BinomialQueue& rhs);

        void make_empty()
        {
            current_size = 0;
            for(auto& root:Trees) make_empty(root);
        }

    private:
        struct Node
        {
            T val,
            Node* left;
            Node* right;

            Node(const T& v):
            val{v}, left{nullptr}, right{nullptr};

            Node(const T& v, Node* lt, Node* rt):
            val{v}, left{lt}, right{rt} {};

            Node(T&& v, Node* lt, Node* rt):
            val{std::move(v)}, left{lt}, right{rt} {};
        }

        const static int DEFAULT_TREE_NUM = 1;

        std::vector<Node*> Trees;
        int current_size;

        int find_min_index()
        {
            int i, min_idx;
            for(i = 0; Trees[i] == nullptr; ++i){}; // find first non empty tree index;
            min_idx = i;
            for(; i < Trees.size(); ++i)
            {   
                if(Trees[i] == nullptr) continue;
                if(Trees[i]->val < Trees[min_idx]->val) min_idx = i;
            }
            return min_idx
        }

        int capacity() const
        {
            return (1 << Trees.size()) - 1;
        }

        Node* merge_trees(Node* t1, Node* t2)
        {
            if(t1->val > t2->val) return merge_trees(t2, t1); // make t1 the smaller
            t2->right = t1->left;
            t1->left = t2;
            return t1;
        }

        void make_empty(Node*& t)
        {
            if(t != nullptr)
            {
                make_empty(t->left);
                make_empty(t->right);
                delete t;
                //t = nullptr;
            }
        }

        Node* clone(Node* t) const
        {
            if(t == nullptr) return nullptr;
            return new Node(t->val, clone(t->left), clone(t->right));
        }
};

#endif