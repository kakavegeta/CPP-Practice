#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <queue>

template <typename T>
class Graph{
public:
    int V; //the number of vertices
    int E; //the number of edges

    enum State{WHITE, GRAY, BLACK};
    struct Vertex;

    struct Node{
        Vertex* vertex;
        Node* next;
    }

    struct Vertex{
        State state;
        T data;
        Node* list;
    };

    std::vector<Vertex> vertices;

public:
    Graph() = default;
    Graph(std::vector<T>&);
    void addEdge(T, T);
    void printGraph();
    ~Graph();

}