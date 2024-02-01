#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5;

int N, p[maxN + 1], sz[maxN + 1];
vector<int> Adj[maxN + 1];

void dfs(int node)
{
    sz[node] = 1;
    for (int it : Adj[node])
    {
        dfs(it);
        sz[node] += sz[it];
    }
}

int main()
{
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        cin >> p[i];
        Adj[p[i]].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= N; i++)
        cout << sz[i] - 1 << ((i == N) ? '\n' : ' ');

    return 0;
}
