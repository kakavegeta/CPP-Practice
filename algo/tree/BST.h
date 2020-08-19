#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>

namespace algo 
{

template<typename T>
class BST {

public:
BST(): root{nullptr} {};

BST(T v): root{new Node(v)};

BST(const BST& rhs): root{nullptr} {
    root = clone(rhs.root);
}


private:

struct Node {
    T val;
    Node* left;
    Node* right;
    Node(T v): val{v}, left{nullptr}, right{nullptr} {}

    Node(const T& v, Node* l, Node* r): 
    val{v},left{l}, right{r} {}

    Node(T&& v, Node* l, Node* r):
    val{std::move(v)}, left{l}, right{r} {}
}

Node* root;

Node* clone(Node* node) const{
    if (node == nullptr) return nullptr;
    return new Node(node->val, clone(node->left), clone(node->right));
}

}





}


#endif