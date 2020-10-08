/*************************************************************************
	> File Name: huffman_tree.c
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Oct 2020 03:59:11 PM EDT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N  1000

#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b, b = temp;\
}

typedef struct Node{
    char ch;
    double p;
    struct Node *next[2];
} Node;


int compare(const void *a, const void *b) {
    return ((*(Node **)b)->p - (*(Node **)a)->p);
}

typedef struct Code{
    char ch;
    char *str;
} Code;

typedef struct HuffmanTree {
    Node *root;
    Code *codes;
    int n;
} HuffmanTree;

typedef struct Data {
    char ch;
    double p;
} Data;

Data arr[MAX_N+5];

Node *getNewNode(Data *d) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->ch = (d ? d->ch: 0);
    node->p = (d ? d->p: 0);
    node->next[0] = node->next[1] = NULL;
    return node;
}

HuffmanTree *getNewTree(int n) {
    HuffmanTree *tree = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->root = NULL;
    tree->n = n;
    return tree;
}

void insert(Node **pnodes, int n) {
    for (int i=n; i>=1; --i) {
        if (pnodes[i]->p > pnodes[i-1]->p) {
           swap(pnodes[i], pnodes[i-1]);
        }
        else break; 
    }
    return ;
}

int encode(Node *root, Code *codes, int k ,int depth, char *buff) {
    buff[depth] = 0;
    if (!root->next[0] && !root->next[1]) {
        codes[k].ch = root->ch;
        codes[k].str = strdup(buff);
        return 1;
    }
    int d = 0;
    buff[depth] = '0';
    d += encode(root->next[0], codes, k+d, depth+1, buff);
    buff[depth] = '1';
    d += encode(root->next[1], codes, k+d, depth+1, buff);
    return d;
}

HuffmanTree *build(Data arr[], int n) {
    Node **pnodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i=0; i<n; ++i) {
        pnodes[i] = getNewNode(arr+i);
    }
    qsort(pnodes, n, sizeof(Node *), compare);
    /*
    for (int i=1; i<n; ++i) {
        insert(pnodes, i);
    }
    */
    for (int i=0; i<n; ++i) {
        printf("%c: %lf\n", pnodes[i]->ch, pnodes[i]->p);
    }

    for (int i=n-1; i>=1; --i) {
        Node *pnode = getNewNode(NULL);
        pnode->next[0] = pnodes[i];
        pnode->next[1] = pnodes[i-1];
        pnode->p = pnodes[i]->p + pnodes[i-1]->p;
        pnodes[i-1] = pnode;
        insert(pnodes, i-1);
    }
    
    char *buff = (char *)malloc(sizeof(char) * n);
    HuffmanTree *tree = getNewTree(n);
    tree->root = pnodes[0];
    encode(tree->root, tree->codes, 0, 0, buff);
    free(tree);
    free(buff);
    return tree;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[10];
    for (int i=0; i<n; ++i) {
        scanf("%s%lf", s, &arr[i].p);
        arr[i].ch = s[0];
    }

    HuffmanTree *tree = build(arr, n);

    for (int i=0; i<tree->n; ++i) {
        printf("%c: %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}

