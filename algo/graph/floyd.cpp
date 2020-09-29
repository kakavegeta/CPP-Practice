/*************************************************************************
	> File Name: floyd.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Sep 2020 09:59:38 PM EDT
 ************************************************************************/

#include <iostream>
#include <climits>

using namespace std;

const int MAX_NV = 100;

typedef int graph_weight_t;

const int GRAPH_INF = INT_MAX/2;

struct graph_t {
    int nv;
    int ne;
    graph_weight_t matrix[MAX_NV][MAX_NV];
};

graph_t g;
graph_weight_t dist[MAX_NV][MAX_NV];

int path[MAX_NV][MAX_NV];

void floyd(const graph_t &g, graph_weight_t dist[][MAX_NV], int path[][MAX_NV]) {
    int i, j, k;
    const int n = g.nv;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i-j) {
                dist[i][j] = g.matrix[i][j];
                path[i][j] = i;
            } else {
                dist[i][j] = 0;
                path[i][j] = -1;
            }
        }
    }

    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void _print_path(int u, int v, const int path[][MAX_NV]) {
    if (path[u][v]==-1) cout << (char)('A'+u);
    else {
        _print_path(u, path[u][v], path);
        cout << "->" << (char)('A'+v);
    }
}

void print_path(const graph_t &g, const int path[][MAX_NV]) {
    for (int i=0; i<g.nv; ++i) {
        for (int j=0; j<g.nv; ++j) {
            if (i-j) {
                _print_path(i, j, path);
                cout << endl;
            }
        }
        cout << endl;
    }
}

void read_graph(graph_t &g) {
    cin >> g.nv >> g.ne;
    for (int i=0; i<g.nv; ++i) {
        for (int j=0; j<g.nv; ++j) {
            g.matrix[i][j] = GRAPH_INF;
        }
    }

    for (int k=0; k<g.ne; ++k) {
        char chx, chy;
        graph_weight_t w;
        cin >> chx >> chy >> w;
        g.matrix[chx-'A'][chy-'A'] = w;
    }
}

int main() {
    read_graph(g);
    floyd(g, dist, path);
    print_path(g, path);
    return 0;
}
