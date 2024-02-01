#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, int par, vector<int> &level, int l = 0)
{
    level[node] = l;
    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, adj, node, level, l + 1);
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

    vector<int> level(n + 1, 0);

    dfs(1, adj, -1, level);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, level[i] + 1);
    }
    cout << ans << endl;

    return 0;
}

/* Input :
5 4
1 2
2 3
1 4
3 5
output :
4
*/
