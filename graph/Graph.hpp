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
        std::vector<int> discvy_t;
        std::vector<int> finish_t;

        explicit Graph(int Vnum)
        : V{Vnum}, E{0}, adjs(Vnum), colors(Vnum), dists(Vnum), pres(Vnum), discvy_t(Vnum), finish_t(Vnum) {}
        
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

void DFS(Graph& g){
    for(int v=0; v<g.V; ++v){
        g.colors[v] = WHITE;
        g.pres[v] = -1;
    }

    int time = 0;
    for(int v=0; v<g.V; ++v){
        if(g.colors[v]==WHITE) DFS_visit(g, time, v);
    }
}

void DFS_visit(Graph& g, int& time, int const u){
    time += 1;
    g.colors[u] = GRAY;
    g.discvy_t[u] = time;
    for(int v=0; v<g.adjs[u].size(); ++v){
        if(g.colors[v] == WHITE){
            g.pres[v] = u;
            DFS_visit(g, time, v);
        }
    }
    g.colors[u] = BLACK;
    time += 1;
    g.finish_t[u] = time;
}

#endif
