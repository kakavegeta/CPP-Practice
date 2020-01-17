#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>



class Graph{
    public:
        explicit Graph(int Vnum);
        int V;
        int E;
        std::vector<int> Adjs;
        
        void add_edge(int v, int w);


        
};


#endif
