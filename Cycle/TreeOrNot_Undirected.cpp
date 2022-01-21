#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//Shivang101

template <typename T>

class graph
{
    map<T, list<T>> adjacentList;

public:
    void addEdge(T x, T y)
    {
        adjacentList[x].push_back(y);
        adjacentList[y].push_back(x);
    }
    void displayGraph()
    {
        for (auto x : adjacentList)
        {
            cout << x.first << "---- ";
            for (auto y : adjacentList[x.first])
                cout << y << " -> ";

            cout << endl;
        }
        cout << adjacentList.size();
    }
    // void displayGraph()
    // {
    //     for (auto edge : adjacentList)
    //     {
    //         auto nbr = edge.second;
    //         cout << edge.first << "---- ";
    //         for (auto x : nbr)
    //         {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    bool is_Tree_Helper(T src, map<T, bool> &visited, map<T, T> &parent)
    {
        queue<T> q;

        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (T nbr : adjacentList[node])
            {
                if (visited[nbr] == true && parent[node] != nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = node;
                }
            }
        }
        return true;
    }
    void is_Tree()
    {
        map<T, bool> visited;
        map<T, T> parent;

        for (auto x : adjacentList)
        {
            visited[x.first] = false;
            parent[x.first] = x.first;
        }
        int cnt = 0;
        for (auto x : adjacentList)
        {
            T node = x.first;
            if (visited[node] == false)
            {
                cout << ++cnt << ")Component ";
                if (is_Tree_Helper(node, visited, parent))
                {
                    cout << "NO it is Not cyclic grpah" << endl;
                }
                else
                {
                    cout << "YES it is a CYCLIC graph" << endl;
                }
            }
        }
    }
};

int main()
{
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.displayGraph();
    cout << endl;
    // cout << endl;
    g.is_Tree();
    return 0;
}