#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <list>
using namespace std;

//Shivang101
template <typename T>
class Graph
{
    map<T, list<pair<T, int>>> adjList;

public:
    void addEdge(T x, T y, int dist)
    {
        adjList[x].push_back(make_pair(y, dist));
        adjList[y].push_back(make_pair(x, dist));
    }
    void printAdjList()
    {
        for (auto it : adjList)
        {
            cout << it.first << "->";
            for (auto item : it.second)
            {
                cout << "(" << item.first << "," << item.second << ")"
                     << " ";
            }
            cout << endl;
        }
    }
    int selectMinVertex(map<T, int> &value, map<T, bool> &processed)
    {
        int minimum = INT_MAX;
        int vertex;

        for (auto x : adjList)
        {
            T node = x.first;
            if (processed[node] == false && value[node] < minimum)
            {
                vertex = node;
                minimum = value[node];
            }
        }
        return vertex;
    }
    void dijkstra(T src)
    {
        map<T, T> parent;
        for (auto x : adjList)
        {
            parent[x.first] = -1;
        }
        map<T, bool> processed;
        for (auto x : adjList)
        {
            processed[x.first] = false;
        }
        map<T, int> value;
        for (auto x : adjList)
        {
            value[x.first] = INT_MAX;
        }
        parent[src] = -1;
        value[src] = 0;

        for (auto v : adjList)
        {
            int u = selectMinVertex(value, processed);
            cout << "proccesed " << u << endl;
            processed[u] = true;
            for (auto it : v.second)
            {
                cout << v.first << endl;
                cout << "it.first " << it.first << " it.second " << it.second << endl;
                if (it.second != 0 && processed[it.first] == false && value[u] != INT_MAX && value[u] + it.second < value[it.first])
                {
                    value[it.first] = value[u] + it.second;
                    parent[it.first] = u;
                }
            }
        }
        cout << "Solution " << endl;
        for (auto x : value)
        {
            cout << x.first << "  " << x.second << " " << endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(7, 1, 11);
    g.addEdge(2, 3, 7);
    g.printAdjList();
    g.dijkstra(0);
    cout << endl;

    return 0;
}