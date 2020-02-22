#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <queue>

template <typename T>
class Graph{
public:
    int V; //the number of vertices
    int E; //the number of edges

    Graph(std::vector<T>& values)
    : V{values.size()}, vertices(V)
    {
        for(int i=0; i<V; ++i){
            vertices[i].data = values[i];
            vertices[i].state = WHITE;
            vertices[i].list = nullptr;
        }
    }

    void set_edge(T x, T y){
        for(int i=0; i<V; ++i){
            if(vertices[i].data == x){
                for (int j=0; j<V && j!=i; ++j){
                    if(vertices[j]==y){
                        insert_at_end(vertices[i].list, vertices[j]);
                        break;
                    }
                }
            }
            break;
        }
    }

    void print() const{
        Node* node;
        for(int i=0; i<V; ++i){
            std::cout << "Vertex: " << vertices[i].data << " "
            std::cout << "Connections: ";
            node = vertices[i].list;
            while(node != nullptr){
                std::cout << node->vertex_prt->data << " ";
                node = node->next;
            }
            std::cout << std::endl;
        }
    }

    void bfs(T x);


private:
    
    struct Vertex;
    enum State{WHITE, GRAY, BLACK};

    struct Node{
        Vertex* vertex_ptr;
        Node* next;
    }

    struct Vertex{
        State state;
        T data;
        Node* list;
    };

    std::vector<Vertex> vertices;

    Node* get_node(Vertex* v){
        Node* node = new Node;
        node->vertex_prt = v;
        node->next = nullptr;
        return node;
    }

    void insert_at_end(Node*& node, Vertex* v){
        Node* new_node = get_node(v);
        if(node==nullptr){
            node = new_node;
        }else {
            Node* curr = node;
            while(curr != nullptr){
                curr = curr->next;
            }
            curr->next  new_node;
        }
    }

    void delete_all_after(Node*& node){
        Node* curr = node;
        Node* next_node;
        while(curr != nullptr){
            next_node = curr->next;
            delete(curr);
            curr = next_node;
        }
    }


}