#ifndef DISJSETS_H
#define DISJSETS_H

#include <vector>
#include <algorithm>

class DisjSets {
    public:
    explicit DisjSets(int num);
    int find(int x) const;
    int find(int x);
    void unify(int x, int y);
    int count;

    private:
    std::vector<int> s;

}




#endif