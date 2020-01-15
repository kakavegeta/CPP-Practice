#include <vector>
#include <string>

#include "Graph.hpp"



Graph::Graph(std::vector<std::vector<int>> M)
: vertices(M.size()){
    for(int i=0; i<M.size(); ++i){
        vertices[i] = Vertex{i};
        for(int j=0; j<M[0].size(); ++j){
            if(M[i][j]==1){
                Vertex v = vertices[i];
                vertices[i].adjs.push_back(Vertex{j});
            } 
        }
    }
}

Graph::