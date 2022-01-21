#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//Shivang101

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void printGraph(vector<vector<int>> &graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : graph[i])
            cout << "-> " << x;
        cout << endl;
    }
}
int main()
{
    int v = 4;
    vector<vector<int>> adjacenyList(v);

    addEdge(adjacenyList, 0, 1);
    addEdge(adjacenyList, 0, 2);
    addEdge(adjacenyList, 1, 2);
    addEdge(adjacenyList, 2, 3);

    printGraph(adjacenyList, v);
    return 0;
}