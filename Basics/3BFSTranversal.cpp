#include <iostream>
#include <stack>
#include <queue>
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

void BFS(vector<vector<int>> graph, int v, int s)
{
    vector<bool> aux(v + 1, false);

    queue<int> q;
    q.push(s);
    aux[s] = true;

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : graph[u]) // checking in the row "U" for all other connections
        {
            if (aux[v] == false)
            {
                aux[v] = true;
                q.push(v);
            }
        }
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
    int v = 4;
    vector<vector<int>> graph(v);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    cout << "Adjacencty List" << endl;
    printList(graph, v);

    cout << "BFS " << endl;
    BFS(graph, 4, 2);

    cout << "BFS " << endl;
    BFS(graph, 4, 2);

    return 0;
}