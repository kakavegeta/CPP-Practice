/*************************************************************************
	> File Name: quick_union.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Oct 2020 03:59:37 AM EDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


class Union {
public:
    vector<int> parent;
    Union(int n) {
        for (int i=0; i<n; ++i) parent[i] = i;

    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unify(int x, int y) {
        int rx = parent[x], ry = parent[y];
        if (rx == ry) return false;
        parent[rx] = ry;
        return true;
    }
};


