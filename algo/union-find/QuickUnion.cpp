#include "DisjSets.hpp"


DisjSets::DisjSets(int n)
    : s(n, 0), count{n}
{
    for(int i=0; i<n; ++i) s[i] = i;
}

DisjSets::find(int x) const {
    while(x != s[x]) {
        x = x[x];
    }
    return x;
} 

DisjSets::unify(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if(rootX == rootY) return;
    s[x] = y;
    count--;
}
