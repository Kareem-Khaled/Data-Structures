#ifndef GRAPH_H
#define GRAPH_H
#include "Linked_list.h"

template<class T>
class Vertex;

template<class T>
class Edge{
    public:
        T Weight;
        Vertex<T> *Adjacent;
        Edge(Vertex<T>* vertex, T weight){
            Adjacent = vertex;
            Weight = weight;
        }
};

template<class T>
class Vertex{
    public:
        T Key;
        bool isVisted = 0;
        Linked_list<Edge<T> > Edges;
        Vertex(T key){
            Key = key;
        }
        void AddEdge(Vertex<T>* vertex, T weight){
            Edge<T>* newEdge = new Edge<T>(vertex, weight);
            Edges.Add(newEdge);
        }
};

template<class T>
class Graph
{
    private:
        Linked_list<Vertex<T> > Vertices;
    public:
        Vertex<T>* AddVertex(T key){
            Vertex<T>* newVertex = new Vertex<T>(key);
            Vertices.Add(newVertex);
            return newVertex;
        }
        void AssignEdge(Vertex<T>* src, Vertex<T>* des, T weight){
            src->AddEdge(des, weight);
            des->AddEdge(src, weight);
        }
        void Dfs(Vertex<T>* src, Vertex<T>* par){
            if(src->isVisted)
                return;
            cout << src->Key << ' ' << par->Key << endl;
            Edge<T> *edge = src->Edges.Begin();
            src->isVisted = 1;
            while(edge){
                Dfs(edge->Adjacent, src);
                edge = src->Edges.GetNext();
            }
            src->isVisted = 0;
        }
};

#endif // GRAPH_H
