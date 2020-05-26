#include <vector>
#include <string>
#include <iostream>

#include "Graph.hpp"

int main(){
    Graph g = Graph(8);
    g.add_edge(0, 1);
    g.add_edge(1, 5);
    g.add_edge(0, 4);
    g.add_edge(5, 2);
    g.add_edge(5, 6);
    g.add_edge(2, 3);
    g.add_edge(2, 6);
    g.add_edge(6, 3);
    g.add_edge(6, 7);
    g.add_edge(3, 7);

   
    
    BFS(g, 1);
    
    for(int i=0; i<g.V; ++i){
        std::cout << g.dists[i] << std::endl;
    }

    Graph g1 = Graph(6);
    g1.add_edge(0, 1);
    g1.add_edge(0, 3);
    g1.add_edge(0, 3);

    return 0;
}