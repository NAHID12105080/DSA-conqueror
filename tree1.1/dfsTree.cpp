#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, int par)
{
    cout << node << " ";
    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, adj, node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, -1);

    return 0;
}

/* Input :
5 4
1 2
2 3
1 4
3 5
output :
1 2 3 5 4*/
