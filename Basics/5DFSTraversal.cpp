#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//Shivang101

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void printList(vector<vector<int>> graph, int v)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int x : graph[i])
            cout << "-> " << x;
        cout << endl;
    }
}
void DFSRecursive(vector<vector<int>> graph, vector<bool> &aux, int s)
{
    aux[s] = true;
    cout << s << " ";

    for (int x : graph[s])
    {
        if (aux[x] == false)
            DFSRecursive(graph, aux, x);
    }
}
void DFS(vector<vector<int>> graph, int v)
{
    vector<bool> aux(v + 1, false);
    DFSRecursive(graph, aux, 0);
}

int main()
{
    int v = 5;
    vector<vector<int>> graph(v + 1);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 4);

    printList(graph, v);
    cout << endl;

    DFS(graph, 5);
    return 0;
}