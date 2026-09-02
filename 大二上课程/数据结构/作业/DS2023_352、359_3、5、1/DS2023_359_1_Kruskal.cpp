#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 边的结构体，包含起点、终点和权值
struct Edge {
    int start, end, weight;
};

// 并查集类
class Sets {
public:
    Sets(int);
    ~Sets();
    void WeightedUnion(int, int);
    int CollapsingFind(int);

private:
    int* parent;
    int n;
};

Sets::Sets(int numberOfElements) {
    if (numberOfElements < 2)
        throw "Must have at least 2 elements.";
    n = numberOfElements;
    parent = new int[n];
    fill(parent, parent + n, -1);
}

Sets::~Sets() {
    delete[] parent;
}

void Sets::WeightedUnion(int i, int j) {
    int temp = parent[i] + parent[j];

    if (parent[i] > parent[j]) {
        parent[i] = j;
        parent[j] = temp;
    }
    else {
        parent[j] = i;
        parent[i] = temp;
    }
}

int Sets::CollapsingFind(int i) {
    int r = i;
    for (; parent[r] >= 0; r = parent[r]);
    while (i != r) {
        int s = parent[i];
        parent[i] = r;
        i = s;
    }

    return r;
}

// 手动实现最小堆
void heapify(vector<Edge>& edges, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && edges[left].weight < edges[smallest].weight)
        smallest = left;

    if (right < n && edges[right].weight < edges[smallest].weight)
        smallest = right;

    if (smallest != i) {
        swap(edges[i], edges[smallest]);
        heapify(edges, n, smallest);
    }
}

void buildHeap(vector<Edge>& edges) {
    int n = edges.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(edges, n, i);
    }
}

// 最小生成树的Kruskal算法
void KruskalMST(vector<Edge>& edges, int numVertices) {
    // 初始化并查集
    Sets sets(numVertices);

    // 构建最小堆
    buildHeap(edges);
    int weightSum = 0;

    cout << "最小生成树边：" << endl;

    // 选取最小权值的边，并检查是否形成环
    while (!edges.empty()) {
        Edge currentEdge = edges[0];
        swap(edges[0], edges[edges.size() - 1]);
        edges.pop_back();

        heapify(edges, edges.size(), 0);

        int rootStart = sets.CollapsingFind(currentEdge.start);
        int rootEnd = sets.CollapsingFind(currentEdge.end);

        if (rootStart != rootEnd) {
            // 边不形成环，加入最小生成树
            cout << "(" << currentEdge.start << ", " << currentEdge.end << ") - " << currentEdge.weight << endl;
            weightSum += currentEdge.weight;
            sets.WeightedUnion(rootStart, rootEnd);
        }
    }

    cout << "最小生成树的总权值为：" << weightSum << endl;
}

int main() {
    // 例子：图的边集合
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {2, 5, 4},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };

    // 顶点数
    int numVertices = 9;

    // 执行Kruskal算法
    KruskalMST(edges, numVertices);

    return 0;
}
