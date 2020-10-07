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
int root = 0;
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
        sum(lc(ind)) += tag(ind) * cnt(lc(ind));
        sum(rc(ind)) += tag(ind) * cnt(rc(ind));
        tag(ind) = 0;
    }
    return ;
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

int query(int ind, int ll, int rr, int l, int r) {
    if (ll <= l && rr >= r) {
        return sum(ind);
    }
    down(ind);
    int mid = (l+r)>>1;
    int ans = 0;
    if (ll <= mid) ans += query(lc(ind), ll, rr, l, mid); 
    if (rr > mid) ans += query(rc(ind), ll, rr, mid+1, r);
    return ans;
}

void modify(int ind, int ll, int rr, int v, int l, int r) {
    if (ll <= l && rr >= r) {
        tag(ind) += v;
        sum(ind) += v * cnt(ind);
        return;
    }
    down(ind);
    int mid = (l+r)>>1;
    if (ll <= mid) modify(lc(ind), ll, rr, v, l ,mid);
    if (rr > mid) modify(rc(ind), ll, rr, v, mid+1, r);
    up(ind);
    return;
}

int main() {
    int m, n;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> arr[i];
    }
    build(root, 1, n);

    for (int i=0; i<m; ++i) {
        int ll, rr, v;
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'Q':
                cin >> ll >> rr;
                cout << query(root, ll, rr, 1, n) << endl;
                break;
            case 'C':
                cin >> ll >> rr >> v;
                modify(root, ll, rr, v, 1, n);
                break;
        }
    }
    return 0;
}

