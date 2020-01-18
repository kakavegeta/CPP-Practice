#include <vector>
#include <string>
#include <iostream>

#include "Graph.hpp"

int main(){
    Graph g = Graph(7);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(0, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_edge(1, 5);

   
    
    BFS(g, 0);
    /*
    for(int i=0; i<7; ++i){
        std::cout << g.dists[i] << std::endl;
    }*/


}