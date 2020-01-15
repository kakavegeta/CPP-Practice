#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph{
    public:
        explicit Graph(std::vector<std::vector<int>> M);
        void topsort();

    private:
        struct Vertex{
            int key;
            int indegree;
            int topnum;
            std::vector<Vertex> adjs;

            explicit Vertex(int num)
            : key{num}, indegree{0}, topnum{0}{};

            Vertex(const Vertex& x)
            : key{x.key}, indegree{x.indegree}, topnum{x.topnum}{};

            Vertex(const Vertex&& x)
            : key{std::move(x.key)}, indegree{std::move(x.indegree)}, topnum{std::move(x.topnum)}
            {};
            
        };

        std::vector<Vertex> vertices;

        
};


#endif
