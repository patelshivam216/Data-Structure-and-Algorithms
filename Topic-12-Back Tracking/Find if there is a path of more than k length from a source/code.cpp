#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<pair<int, int>> graph[], vector<bool> &vis, int target)
{

    if (target <= 0)
        return true;

    for (auto pair : graph[v])
    {
        int child = pair.first;
        int weight = pair.second;
        if (vis[child] == true)
            continue;

        if (weight >= target)
            return true;

        vis[child] = true;
        if (dfs(child, graph, vis, target - weight))
        {
            return true;
        }
        vis[child] = false;
    }

    return false;
}

int main()
{

    int n;
    cin >> n;
    vector<pair<int, int>> graph[n + 1];

    for (int i = 0; i < n; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    int target = 30;
    int source = 1;

    vector<bool> vis(n + 1, false);
    cout << dfs(source, graph, vis, target) << endl;

    return 0;
}