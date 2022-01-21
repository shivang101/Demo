#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

//Shivang101

template <typename T>
class Graph
{
    map<T, list<T>> adjanencyList;

public:
    void addEdge(int x, int y)
    {
        adjanencyList[x].push_back(y);
        adjanencyList[y].push_back(x);
    }

    void DFSHelper(T src, map<T, bool> &aux)
    {
        aux[src] = true;
        cout << src << " ";

        for (T x : adjanencyList[src])
        {
            if (aux[x] == false)
            {
                DFSHelper(x, aux);
            }
        }
    }
    void DFS(T src)
    {
        map<T, bool> aux;

        for (auto x : adjanencyList)
        {
            T node = x.first;
            aux[node] = false;
        }
        int cnt = 0;
        for (auto x : adjanencyList)
        {
            T node = x.first;
            if (aux[node] == false)
            {
                cout << ++cnt << ")Component ";
                DFSHelper(node, aux);
                cout << endl;
            }
        }
        cout << "Total Number of graphs are " << cnt << endl;
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
    cout << "Traversal By DFS " << endl;
    g.DFS(5);
    return 0;
}