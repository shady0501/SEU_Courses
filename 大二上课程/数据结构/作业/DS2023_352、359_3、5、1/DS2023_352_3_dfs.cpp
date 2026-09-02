#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <stack>

using namespace std;

class Graph 
{
public:
    int vertices;
    vector<list<int>> adjacencyList;

    Graph(int vertices) : vertices(vertices), adjacencyList(vertices) 
    {
    }

    void addEdge(int u, int v) 
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);  
    }

    void DFS(int startVertex) 
    {
        vector<bool> visited(vertices, false);
        stack<int> stack;

        stack.push(startVertex);

        while (!stack.empty()) 
        {
            int vertex = stack.top();
            stack.pop();

            if (!visited[vertex]) 
            {
                cout << vertex << " ";
                visited[vertex] = true;

                // 将未访问的邻接顶点入栈
                for (int neighbor : adjacencyList[vertex]) 
                {
                    if (!visited[neighbor])
                        stack.push(neighbor);
                }
            }
        }
    }

    void printGraph() 
    {
        for (int i = 0; i < vertices; ++i) 
        {
            cout << "顶点 " << i << " 的邻接表: ";

            for (int neighbor : adjacencyList[i]) 
                cout << neighbor << " ";

            cout << endl;
        }
    }

    bool isValidGraph() 
    {
        for (int i = 0; i < vertices; ++i) 
        {
            for (int neighbor : adjacencyList[i]) 
                if (neighbor < 0 || neighbor >= vertices) 
                    return false;
        }
        return true;
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);

    cout << "图的邻接表：" << endl;
    graph.printGraph();

    if (graph.isValidGraph()) {
        cout << "图是有效的。" << endl;
        cout << "深度优先搜索结果：" << endl;
        graph.DFS(0);
        cout << endl;
    }
    else {
        cout << "图是无效的。" << endl;
    }

    return 0;
}
