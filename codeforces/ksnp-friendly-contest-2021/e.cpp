#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
vector<int> parent, k;
vector<vector<int>> edges;
int dp(int node, int time)
{
    //cout << node << " " << time << endl;
    if(time < 1)
        return 0;
    if(k[node] != -1)
    {
        int res = (int)(bool)k[node];
        k[node] = max(k[node] - 1, 0);
        return res;
    }
    int res = 0;
    for(int i = 0; i < edges[node].size(); ++i)
    {
        if(edges[node][i] == parent[node])
            continue;
        parent[edges[node][i]] = node;
        res = max(res, dp(edges[node][i], time - 1));
    }
    return res;
}
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    // we need to use a pair of timespans to get this correct
    // at each non indegree 0 point, we need to combine the timespans
    parent = vector<int>(n + 1);
    parent[1] = -1;
    edges = vector<vector<int>>(n + 1, vector<int>());
    for(int i = 0; i < n - 1; ++i)
    {  
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    k = vector<int>(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> k[i];
    int res = 0;
    for(int i = 1; i < 2 * 1e5; ++i)
        res += dp(1, i);
    cout << res << endl;
    return 0;
}