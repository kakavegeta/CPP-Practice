#include "DisjSets.hpp"

DisjSets::DisjSets(int n)
    :s(n, 0), count{n}
    {
        for (int i = 0; i < n; i++)
            s[i] = i;
    }

DisjSets::find(int x) const {
    return s[x];
}

DisjSets::unify(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if(rx == ry) return;

    for(int i=0; i<s.size(); ++i) {
        if(s[i] == rx) s[i] = ry;
    }

    count--;
}
