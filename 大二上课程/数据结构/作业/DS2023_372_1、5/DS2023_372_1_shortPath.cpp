
struct Edge {
    int to;
    int weight;
};

struct Node {
    vector<Edge> edges;
};

int dfs(const vector<Node>& tree, int node, vector<int>& subtree_height, int& total_cost)
{
    int height = 0;

    for (const Edge& edge : tree[node].edges) 
    {
        int child = edge.to;
        int edge_weight = edge.weight;

        int child_height = dfs(tree, child, subtree_height, total_cost) + 1;

        total_cost += edge_weight * child_height;

        height = max(height, child_height);
    }

    subtree_height[node] = height;

    return height;
}

int shortestPath(const vector<Node>& tree, int v) 
{
    int n = tree.size();

    vector<int> subtree_height(n, 0);
    int total_cost = 0;

    dfs(tree, v, subtree_height, total_cost);

    return total_cost;
}
