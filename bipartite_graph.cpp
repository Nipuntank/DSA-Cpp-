#include <iostream>
using namespace std;
bool dfs(int node, int col, vector<int> adj[], vector<int> &color)
{
    color[node] = 1;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, !col, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}
bool bipartite(vector<int> adj[], int v)
{
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int v, e, x, y;
    cout << "Enter the number of vertices and edges in the graph:";
    cin >> v >> e;
    vector<int> adj[100];
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    bool ans = bipartite(adj, v);
    if (ans)
    {
        cout << "Graph is bipartite";
    }
    else
    {
        cout << "Graph is not bipartite";
    }
    return 0;
}