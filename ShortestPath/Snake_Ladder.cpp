#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <limits.h>
#include <algorithm>
using namespace std;

//Shivang101
template <typename T>
class Graph
{
    map<T, list<T>> adjacentList;

public:
    void addEdge(int x, int y)
    {
        adjacentList[x].push_back(y);
    }
    int BFS(int src, T dest)
    {
        map<T, int> dist;
        map<T, T> parent;
        for (auto x : adjacentList)
        {
            T node = x.first;
            dist[node] = INT_MAX;
        }

        queue<int> q;
        q.push(src);

        dist[src] = 0;
        parent[src] = src;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (auto x : adjacentList[node])
            {
                if (dist[x] == INT_MAX)
                {
                    q.push(x);
                    dist[x] = dist[node] + 1;
                    parent[x] = node;
                }
            }
        }
        //print distance from all nodes !
        // for (auto x : adjacentList)
        // {
        //     T node = x.first;
        //     int d = dist[node];
        //     cout << "Node " << node << " dist from src " << d << endl;
        // }
        T temp = dest;
        while (temp != src)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src << endl;
        return dist[dest];
    }
};

int main()
{

    int board[50] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;
    for (int i = 0; i < 37; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }

    g.addEdge(36, 36);

    cout << g.BFS(0, 36);
    return 0;
}