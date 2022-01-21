#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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

    void BFSHelper(T src, map<T, bool> &aux)
    {
        queue<T> q;

        q.push(src);
        aux[src] = true;

        while (q.empty() == false)
        {
            T u = q.front();
            cout << u << " ";
            q.pop();

            for (T x : adjacencyList[u])
            {
                if (aux[x] == false) // {x ,0} when we accessed it it declared this like it only
                {
                    aux[x] = true;
                    q.push(x);
                }
            }
        }
    }
    void BFS(T src)
    {
        map<T, bool> aux;

        // mark all the nodes as not visited in the map making sure our map does not miss other comoponents on function calls
        for (auto x : adjacencyList)
        {
            T node = x.first;
            aux[node] = false;
        }
        int cnt = 0;
        for (auto x : adjacencyList)
        {
            T node = x.first;
            if (aux[node] == false)
            {
                cout << ++cnt << ")Component ";
                BFSHelper(node, aux);
                cout << endl;
            }
        }

        cout << "Total Number of graphs are " << cnt << endl;
    }
    void printGraph(T src)
    {
        for (auto x : adjacencyList)
        {
            T node = x.first;
            cout << node << " -> ";
            for (auto y : adjacencyList[node])
            {
                cout << y << " ->";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.printGraph(0);
    cout << "BFS" << endl;
    g.BFS(0);

    return 0;
}