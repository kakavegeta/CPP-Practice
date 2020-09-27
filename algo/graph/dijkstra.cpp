/*************************************************************************
	> File Name: dijkstra.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Sep 2020 04:06:39 PM EDT
 ************************************************************************/

#include<iostream>
#include<queue>
#include<unordered_map>
#include<utility>
#include<climits>
using namespace std;

typedef int graph_weight_t;
typedef char graph_vertex_id_t;

struct graph_t {
    int nv;
    int ne;
    unordered_map<graph_vertex_id_t, unordered_map<graph_vertex_id_t, graph_weight_t>> matrix;
};


void dijkstra(const graph_t &g, graph_vertex_id_t start, 
unordered_map<graph_vertex_id_t, graph_weight_t> &distance, 
unordered_map<graph_vertex_id_t, graph_vertex_id_t> &father) {

    typedef pair<graph_weight_t, graph_vertex_id_t> to_dist_t;
    priority_queue<to_dist_t, vector<to_dist_t>, greater<to_dist_t>> q;
    q.push(to_dist_t{0, start});

    while (!q.empty()) {
        const to_dist_t u = q.top(); q.pop();
        if (!g.matrix.count(u.second)) continue;

        for (unordered_map<graph_vertex_id_t, graph_weight_t>::const_iterator iter = g.matrix.at(u.second).begin(); 
             iter != g.matrix.at(u.second).end(); iter++) {
                 const graph_vertex_id_t v = iter->first;
                 const graph_weight_t w = iter->second;
                 if (!distance.count(v) || w + distance[u.second] < distance[v]) {
                     distance[v] = w + distance[u.second];

                 }
             } 

    }
}
