/*************************************************************************
	> File Name: topo_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 28 Sep 2020 11:04:00 PM EDT
 ************************************************************************/

#include <iostream>
#include <climits>
#include <stack>
using namespace std;


const int MAX_NV = 100;
typedef int graph_weight_t;

const graph_weight_t GRAPH_INF = INT_MAX;

struct graph_t {
    int nv;
    int ne;
    int matrix[MAX_NV][MAX_NV];
};

graph_t g;

int topo[MAX_NV];

bool topo_sort(const graph_t &g, int topo[]) {
    const int n = g.nv;
    int *in_degree = new int[n]();
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (g.matrix[i][j]<GRAPH_INF) in_degree[j]++;
        }
    }
    
    stack<int> s;
    for (int i=0; i<n; ++i) {
        if(in_degree[i]==0) s.push(i);
    }

    int count = 0; 
    while (!s.empty()) {
        const int u = s.top(); s.pop();
        topo[count++] = u;
        for (int i=0; i<n; ++i) {
            if (g.matrix[u][i]<GRAPH_INF){
                if (--in_degree[i]==0) s.push(i);
            }
        }
    }

    delete[] in_degree;
    if (count != n) return false;
    return true;
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
    topo_sort(g, topo);
    
    for (int i=0; i<g.nv; ++i) {
        cout << (char)('A'+topo[i]) << " ";
    }

    return 0;
}



