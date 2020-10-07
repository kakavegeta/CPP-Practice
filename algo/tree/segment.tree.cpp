/*************************************************************************
	> File Name: segment.tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Oct 2020 09:41:38 PM EDT
 ************************************************************************/

#include <iostream>
#include <algorithm>

#define MAX_N 10000

#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define tag(ind) (tree[ind].tag)
#define sum(ind) (tree[ind].sum)
#define cnt(ind) (tree[ind].cnt)

using namespace std;

int cnt = 0;
int arr[MAX_N+5];

struct Node{
    int sum, tag, cnt;
    int lind, rind;
} tree[(MAX_N<<1)+5];

int getNode(){return ++cnt;}

void up(int ind) {
    tree[ind].sum = tree[lc(ind)].sum + tree[rc(ind)].sum;
}

void down(int ind) {
    if (tag(ind)) {
        tag(lc(ind)) += tag(ind);
        tag(rc(ind)) += tag(ind);
        
   }
}

void build(int ind, int l, int r) {
    tree[ind].cnt = r-l+1;
    if (l==r) {
        tree[ind].sum = arr[l];
        return;
    }

    int mid = (l+r)>>1;
    tree[ind].lind = getNode();
    tree[ind].rind = getNode();
    build(lc(ind), l, mid);
    build(rc(ind), mid+1, r);
    up(ind);
    return ;
}

