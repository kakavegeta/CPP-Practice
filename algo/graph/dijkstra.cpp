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
                 if (!distance.count(v) || w + u.first < distance[v]) {
                     distance[v] = w + u.first;
                     father[v] = u.second;
                     q.push(to_dist_t{distance[v], v});
                 }
             } 
        
    }
}


void print_path(const unordered_map<graph_vertex_id_t, graph_vertex_id_t> &father, graph_vertex_id_t end) {  
    if (!father.count(end)) {cout << end; return;}
    print_path(father, father.at(end));
    cout << "->" << end;
}

void read_graph(graph_t &g) {
    cin >> g.ne;
    for (int i=0; i<g.ne; ++i) {
        graph_vertex_id_t from, to;
        graph_weight_t weight;
        cin >> from >> to >> weight;
        g.matrix[from][to] = weight;
    }

}

int main() {
    graph_t graph;
    unordered_map<graph_vertex_id_t, graph_weight_t> distance;
    unordered_map<graph_vertex_id_t, graph_vertex_id_t> father;

    read_graph(graph);
    dijkstra(graph,'A', distance, father);
    
    for (unordered_map<graph_vertex_id_t, graph_vertex_id_t>::const_iterator iter = father.begin(); iter!=father.end(); ++iter) {
        if (iter->first != 'A') {
            print_path(father, iter->first);
            cout << endl;
        }
    }

    return 0;
}
