#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template <typename T>
class Graph{
    public:
        explicit Graph();
        void topsort();
    private:
        struct Vertex{
            int key;
            T val;
            std::vector<int> adjs;
            int degree;
        }
};


#endif
