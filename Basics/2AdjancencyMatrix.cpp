#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//Shivang101

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void printGraph(vector<vector<int>> graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int v = 4;
    /*
    We create a 2D vector containing "n"
    elements each having the value "vector<int> (m, 0)".
    "vector<int> (m, 0)" means a vector having "m"
    elements each of value "0".
    Here these elements are vectors.
    */
    vector<vector<int>> adjacenyList(v, vector<int>(v, 0));

    addEdge(adjacenyList, 0, 1);
    addEdge(adjacenyList, 0, 2);
    addEdge(adjacenyList, 1, 2);
    addEdge(adjacenyList, 2, 3);

    printGraph(adjacenyList, v);
    return 0;
}