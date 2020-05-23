#ifndef DISJSET_H
#define DISJSET_H

#include <vector>
#include <algorithm>

#include "dsexception.hpp"

class DisjSets{
    public:
        explicit DisjSets(int num);
        int find(int x) const;
        int find(int x);
        void union_sets(int r1, int r2);
    private:
        std::vector<int> s;
};

#endif

