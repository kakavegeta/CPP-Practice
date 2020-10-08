/*************************************************************************
	> File Name: huffman.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Oct 2020 07:50:43 PM EDT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <queue>
#include <unordered_map>
#include <functional>

using namespace std;


class HuffmanTree {




private:
    struct Node{
        Node():ch{0}, freq{0}, left{nullptr}, right{nullptr} {}
        Node(char c, int fq):
            ch{c}, freq{fq}, left{nullptr}, right{nullptr} {}
        char ch;
        int freq;
        Node *left, *right;
    };

    struct Code{
        char ch;
        string str;
    };

    
    int sz;
    Node *root;
     

};



