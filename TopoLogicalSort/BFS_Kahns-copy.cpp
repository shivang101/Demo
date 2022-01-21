#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> adjacencyList;

public:
    void addEdge(T x, T y)
    {
        adjacencyList[x].push_back(y);
    }
    void topological_sort()
    {
        map<T, int> indegree;

        for (auto x : adjacencyList)
        {
            T node = x.first;
            indegree[node] = 0;
        }

        for (auto x : adjacencyList)
        {
            T node = x.first;
            for (auto y : adjacencyList[node])
            {
                indegree[y]++;
            }
        }

        queue<int> q;

        for (auto x : adjacencyList)
        {
            if (indegree[x.first] == 0)
            {
                q.push(x.first);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto nbr : adjacencyList[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
    void display()
    {
        for (auto x : adjacencyList)
        {
            for (auto y : adjacencyList[x.first])
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
};

//Shivang101

int main()
{
    Graph<int> g;
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 5);
    g.display();
    g.topological_sort();

    return 0;
}