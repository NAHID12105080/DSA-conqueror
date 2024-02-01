#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;

void bfs(int root, vector<vector<int>> &adj)
{
    queue<pair<int, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int node = q.front().first;
        cout << node << " ";

        int par = q.front().second;

        q.pop();
        for (auto it : adj[node])
        {
            if (it != par)
            {
                q.push({it, node});
            }
        }
    }
}

signed main()
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

    bfs(1, adj);
}
