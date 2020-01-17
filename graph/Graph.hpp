#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <string>

enum COLOR {WHITE, GRAY, BLACK};

class Graph{
    public:
        int V;
        int E;
        std::vector<std::vector<int>> adjs;
        std::vector<COLOR> colors;
        std::vector<int> dists;
        std::vector<int> pres;

        explicit Graph(int Vnum)
        : V{Vnum}, E{0}, adjs(Vnum), colors(Vnum), dists(Vnum) {}
        
        void add_edge(int u, int v){
            adjs[u].push_back(v);
            adjs[v].push_back(u);
            ++E;
        }

        std::vector<int> adj(int v) const{
            return adjs[v];
        }

        COLOR color(int v) const{
            return colors[v];
        }

        int dist(int v) const{
            return dists[v];
        }

        int pre(int v) const{
            return pres[v];
        }
};

void BFS(Graph& g, int s){
    for(int v=0; v<g.V; ++v){
        g.colors[v] = WHITE;
        g.dists[v] = INT8_MAX;
        g.pres[v] = -1;
    }

    g.colors[s] = GRAY;
    g.dists[s] = 0;
    g.pres[s] = -1;

    std::queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:g.adjs[u]){
            if(g.color(v)==WHITE){
                g.color(v) = GRAY;
                g.dist(v) = g.dist(u) + 1;
                g.pre(v) = u;
            }
            q.push(v);
        }
        g.color(u) = BLACK; 
    }
} 


#endif
