#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

template <typename T>

class Graph
{
    // map<T, pair<T, T>> adjacencyList;

    map<pair<T, T>, T> adjacencyList;

public:
    void addEdge(int u, int v, int w)
    {
        adjacencyList[make_pair(u, v)] = w;
    }
    void display()
    {
        for (auto &pr : adjacencyList)
        {
            auto &edge = pr.first;
            auto &edgeWeight = pr.second;
            cout << "Start Vertex " << edge.first << " End Vertex " << edge.second << " Weight = " << edgeWeight << endl;
        }
    }
};

void addEdge(vector<pair<int, int>> adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation ot graph
void printGraph(vector<pair<int, int>> adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    Graph<int> g;
    g.addEdge(1, 2, 3);
    g.addEdge(2, 2, 3);
    g.addEdge(3, 2, 3);
    g.addEdge(4, 2, 3);

    int V = 5;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    // printGraph(adj, V);
    g.display();
    return 0;
}