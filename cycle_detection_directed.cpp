#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &patVis, int V)
{
    vis[node] = 1;
    patVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, patVis, V))
            {
                return true;
            }
        }
        else if (patVis[it])
        {
            return true;
        }
    }
    patVis[node] = 0;
    return false;
}
bool detectCycle(int V, vector<int> adj[])
{
    // Write your code here.
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis, V))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int v, e, x, y;
    cout << "Enter the number of vertices and edges:";
    cin >> v >> e;
    vector<int> adj[100];
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    bool cycle = detectCycle(v, adj);
    if (cycle)
    {
        cout << "Cycle found in the graph";
    }
    else
    {
        cout << "Cycle Not found in graph";
    }
    return 0;
}