#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

//Shivang101

template <typename T>
class graph
{
    map<T, list<T>> adjacencyList;

public:
    void addEdge(T x, T y)
    {
        adjacencyList[x].push_back(y);
    }
    void DfsHelper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;

        for (auto x : adjacencyList[src])
        {
            if (visited[x] == false)
            {
                DfsHelper(x, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void DFS()
    {
        map<T, bool> visited;
        list<T> ordering;

        for (auto x : adjacencyList)
        {
            T node = x.first;
            visited[node] = false;
        }

        for (auto x : visited)
        {
            cout << x.first << "  " << x.second << endl;
        }
        for (auto x : adjacencyList)
        {
            T node = x.first;
            if (!visited[node])
            {
                cout << "going in for " << node << endl;
                DfsHelper(node, visited, ordering);
            }
        }

        for (auto node : ordering)
        {
            cout << node << " ";
        }
    }
    void display()
    {
        for (auto x : adjacencyList)
        {
            list<T> lol = x.second;
            cout << x.first << " ";
            for (auto node : lol)
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph<string> g;

    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("DataSet", "FaceRecogn");
    g.display();
    g.DFS();
    return 0;
}