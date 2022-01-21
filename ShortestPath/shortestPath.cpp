#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <limits.h>

using namespace std;

//Shivang101

template <typename T>
class Graph
{
    map<T, list<T>> adjacencyList;

public:
    void addEdge(int x, int y)
    {
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }
    void BFS(T src)
    {
        map<T, int> dist;
        queue<T> q;

        for (auto x : adjacencyList)
        {
            T node = x.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (q.empty() == false)
        {
            T node = q.front();
            q.pop();
            // cout << node << " ";

            for (auto x : adjacencyList[node])
            {
                if (dist[x] == INT_MAX)
                {
                    q.push(x);
                    dist[x] = dist[node] + 1;
                }
            }
        }

        for (auto x : adjacencyList)
        {
            T node = x.first;
            int d = dist[node];
            cout << "Node " << node << " dist from src " << d << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.BFS(0);

    return 0;
}