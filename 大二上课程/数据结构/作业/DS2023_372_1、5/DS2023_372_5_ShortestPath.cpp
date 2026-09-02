
const int MAXN = 100;

void shortestPath(const int n, const int length[MAXN][MAXN])
{
    bool s[MAXN]; 
    int dist[MAXN]; 

    for (int i = 0; i < n; ++i) 
    {
        s[i] = false;
        dist[i] = 9999999999; 
    }

    int v = 0;
    s[v] = true;
    dist[v] = 0;

    for (int i = 0; i < n - 2; i++) 
    {
        int u = -1; 
        int minDist = 9999999999;

        for (int j = 0; j < n; j++) 
            if (!s[j] && dist[j] < minDist) 
            {
                u = j;
                minDist = dist[j];
            }

        if (u == -1) 
        {
            cout << "Graph is not connected!";
            return;
        }

        s[u] = true;

        for (int w = 0; w < n; w++) 
            if (!s[w] && length[u][w] < dist[w]) 
                dist[w] = length[u][w];
    }

    cout << "Minimum Spanning Tree Distances:" << endl;

    for (int i = 0; i < n; ++i) 
        cout << "To Vertex " << i << ": " << dist[i] << endl;
}
