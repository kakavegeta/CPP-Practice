#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <deque>
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
        : V{Vnum}, E{0}, adjs(Vnum), colors(Vnum), dists(Vnum), pres(Vnum) {}
        
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

void BFS(Graph& g, int const s){
    for(int v=0; v<g.V && v!=s; ++v){
        g.colors[v] = WHITE;
        g.dists[v] = INT8_MAX;
        g.pres[v] = -1;
    }

    g.colors[s] = GRAY;
    g.dists[s] = 0;
    g.pres[s] = -1;
    std::deque<int> q;
    q.push_back(s);

    std::cout << "begin to search..." << std::endl; 
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(int v:g.adjs[u]){
            if(g.color(v)==WHITE){
                g.colors[v] = GRAY;
                g.dists[v] = g.dist(u) + 1;
                g.pres[v] = u;
                q.push_back(v);
            }
        }
        g.colors[u] = BLACK; 
    }
} 


#endif
