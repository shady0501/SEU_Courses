#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node(int a, Node* p)
    {
        data = a;
        pointer = p;
    }

    ~Node()
    {
    }

    int getData()
    {
        return data;
    }

    Node* getPointer()
    {
        return pointer;
    }

private:
    int data;
    Node* pointer;
};

class Graph 
{
public:
    Graph(int v) : vertices(v)
    {
        adjacencyList = new Node* [v];
        for (int i = 0; i < v; ++i)
        {
            adjacencyList[i] = nullptr;
        }
    }

    void addEdge(int v1, int v2) 
    {
        Node* newNode1 = new Node(v2, adjacencyList[v1]);
        adjacencyList[v1] = newNode1;

        Node* newNode2 = new Node(v1, adjacencyList[v2]);
        adjacencyList[v2] = newNode2;
    }

    void printAdjacencyList() 
    {
        for (int i = 0; i < vertices; ++i) {
            cout << "点 " << i;
            Node* current = adjacencyList[i];
            while (current != nullptr) {
                cout << " -> " << current->getData();
                current = current->getPointer();
            }
            cout << endl;
        }
    }

private:
    int vertices;
    Node** adjacencyList;
};

int main() {
    int vertices, edges;

    cout << "输入顶点数: ";
    cin >> vertices;
    cout << "输入边数: ";
    cin >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        cout << "输入第 " << i + 1 << "条边:";
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }

    cout << "\n邻接表:\n";
    graph.printAdjacencyList();

    return 0;
}
//运行时间为：O(m+n)