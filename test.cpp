#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <climits>
// kbx2157
using namespace std;
template <class T>
class Graph
{
    map<T, list<pair<T, int>>> adjList;

public:
    void addEdge(T x, T y, int dist, bool isBidirectional = true)
    {
        adjList[x].push_back(make_pair(y, dist));

        if (isBidirectional)
        {
            adjList[y].push_back(make_pair(x, dist));
        }
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
    void shortestDistance(T src)
    {
        map<T, int> distance;
        for (auto i : adjList)
        {
            distance[i.first] = INT_MAX;
        }
        set<pair<int, T>> s; // Set is used so we get minimum element. Priority // queue can also be used.
        distance[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty())
        {

            auto p = *(s.begin());
            T node = p.second;
            s.erase(p);
            for (auto neighbourPair : adjList[node])
            {
                T neighbourNode = neighbourPair.first;
                int neighbourDistFromNode = neighbourPair.second;

                if ((distance[node] + neighbourDistFromNode) <
                    distance[neighbourNode])
                {
                    // If set contains the node remove it
                    auto f = s.find(make_pair(distance[neighbourNode], neighbourNode));
                    if (f != s.end())
                        s.erase(f);
                    distance[neighbourNode] =
                        distance[node] + neighbourDistFromNode;
                    s.insert(make_pair(distance[neighbourNode], neighbourNode));
                }
            }
        }
        for (auto p : distance)
        {
            cout << p.first << "->" << p.second << endl;
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
    // g.dijkstra(0);
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 4);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 2);
    // g.addEdge(1, 4, 7);

    // g.printAdjList();
    cout << endl;
    g.shortestDistance(0);
    return 0;
}