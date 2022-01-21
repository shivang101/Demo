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

    return;
}
void printList(vector<vector<int>> graph, int v)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int x : graph[i])
            cout << "-> " << x;
        cout << endl;
    }
    return;
}
void BFS(vector<vector<int>> graph, vector<bool> &aux, int s)
{
    queue<int> q;
    q.push(s);
    aux[s] = true;

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : graph[u])
        {
            if (aux[x] == false)
            {
                aux[x] = true;
                q.push(x);
            }
        }
    }
}
void BFSDisconnected(vector<vector<int>> &graph, int v)
{
    vector<bool> aux(v + 1, false);
    int cnt = 0;
    for (int i = 0; i < aux.size() - 1; i++)
    {
        if (aux[i] == false)
        {
            BFS(graph, aux, i);
            cnt++;
            cout << "Graph Completed" << endl;
        }
    }
    cout << "Total Number of Islands/Components are " << cnt << endl;
}

int main()
{
    int v = 7;
    vector<vector<int>> graph(v + 1);

    addEdge(graph, 0, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 5, 5);
    printList(graph, 6);
    cout << endl;

    BFSDisconnected(graph, 6);
    return 0;
}