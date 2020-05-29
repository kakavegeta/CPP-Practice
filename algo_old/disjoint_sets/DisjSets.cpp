#include "DisjSets.hpp"
#include "dsexception.hpp"

DisjSets::DisjSets(int num)
: s(num, -1) {};

int DisjSets::find(int x) const{
    if(s[x]<0) return x;
    else return find(s[x]);
}

// path compression
int DisjSets::find(int x) {
    if(s[x]<0) return x;
    else return s[x] = find(s[x]);
}

void DisjSets::union_sets(int r1, int r2){
    if(s[r1] < s[r2]){
        s[r2] = r1;
    } 
    else if(s[r1] > s[r2]) {
        s[r1] = r2;
    }
    else {
        --s[r1];
        s[r2] = r1;
    }
}