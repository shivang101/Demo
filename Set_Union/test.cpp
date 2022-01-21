#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;
//Shivang101
class Graph
{
    map<int, list<int>> adjacencyList;

public:
    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
    }

    void display()
    {
        for (auto edge : adjacencyList)
        {
            auto nbr = edge.second;
            cout << edge.first << "---- ";
            for (auto x : nbr)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    // Find
    int findSet(int i, map<int, int> &parent)
    {
        //base case
        if (parent[i] == -1)
            return i;

        return findSet(parent[i], parent);
    }

    //Union
    void union_set(int x, int y, map<int, int> &parent)
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        cout << "S1 " << s1 << " S2 " << s2 << " in union" << endl;

        if (s1 != s2)
        {
            parent[s1] = s2;
        }
        cout << parent[s1] << " union cross check" << endl;
    }
    bool contains_cycle()
    {
        map<int, int> parent;

        for (auto x : adjacencyList)
        {
            parent[x.first] = -1;

            auto nbr = x.second;
            for (auto y : nbr)
            {
                parent[y] = -1;
            }
        }
        for (auto x : parent)
        {
            cout << x.first << " " << parent[x.first] << endl;
        }
        cout << "Hello" << endl;
        for (auto edge : adjacencyList)
        {
            int i = edge.first;
            for (auto x : edge.second)
            {
                int j = x;
                cout << "val of i " << i << " val of j " << j << endl;
                int s1 = findSet(i, parent);
                int s2 = findSet(j, parent);
                cout << "S1 " << s1 << " S2 " << s2 << endl;

                if (s1 != s2)
                {
                    union_set(s1, s2, parent);
                    for (auto x : parent)
                    {
                        cout << x.first << " " << parent[x.first] << endl;
                    }
                }
                else
                {
                    cout << "Same Parents " << s1 << " and " << s2 << endl;
                    return true;
                }
                // cout << "Same Parents " << s1 << " and " << s2 << endl;
                // cout << "Hello22" << endl;
            }
        }
        return false;
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.display();
    cout << g.contains_cycle();
    return 0;
}