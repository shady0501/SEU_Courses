#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph 
{
private:
    int vertices;  
    vector<list<int>> adjacencyList;  

public:
    Graph(int vertices) : vertices(vertices) 
    {
        adjacencyList.resize(vertices);
    }

    
    void addEdge(int u, int v) 
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);  
    }

   
    void BFS(int startVertex) 
    {
        vector<bool> visited(vertices, false);
        queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) 
        {
            int currentVertex = queue.front();
            queue.pop();

            cout << currentVertex << " ";

            // 遍历邻接顶点
            for (int neighbor : adjacencyList[currentVertex]) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
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
            for (int neighbor : adjacencyList[i]) 
                if (neighbor < 0 || neighbor >= vertices)
                    return false;
        
        return true;
    }
};

int main() {
    // 创建图
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

        cout << "广度优先搜索结果：" << endl;
        graph.BFS(0);
        cout << endl;
    }
    else {
        cout << "图是无效的。" << endl;
    }

    return 0;
}
