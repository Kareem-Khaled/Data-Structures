#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    /*Linked_list<int>lst;
    int x= 133;
    lst.Add(&x);
    cout << lst;*/
    Graph<char>graph;
    Vertex<char>*A = graph.AddVertex('A');
    Vertex<char>*B = graph.AddVertex('B');
    Vertex<char>*C = graph.AddVertex('C');
    Vertex<char>*D = graph.AddVertex('D');
    Vertex<char>*E = graph.AddVertex('E');
    graph.AssignEdge(A, B, 3);
    graph.AssignEdge(A, C, 2);
    graph.Dfs(A, A);
    cout << endl;
    graph.Dfs(B, A);
    cout << endl;
    graph.Dfs(C, A);
}
