#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define ll long long
using namespace std;
vector<int> edges[(int)1e5 + 1];
void test_case()
{
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for(int i = 1; i <= n; ++i)
        edges[i].clear();
    // db >= 2 * da + 1
    // and diameter >= db
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    // do 2 dfs to determine diameter
    stack<pair<int, int>> dfs;
    int depth[n + 1]; memset(depth, 0, sizeof(depth));
    bool vis[n + 1]; memset(vis, 0, sizeof(vis));
    dfs.push({1, 0});
    while(dfs.size() > 0)
    {
        pair<int, int> cur = dfs.top();
        dfs.pop();
        vis[cur.fi] = 1;
        depth[cur.fi] = cur.se;
        for(int i = 0; i < edges[cur.fi].size(); ++i)
            if(!vis[edges[cur.fi][i]])
                dfs.push({edges[cur.fi][i], cur.se + 1});
    }
    int next, val = 0;
    for(int i = 1; i <= n; ++i)
        if(depth[i] > val)
            next = i, val = depth[i];
    memset(depth, 0, sizeof(depth));
    memset(vis, 0, sizeof(vis));
    dfs.push({next, 0});
    while(dfs.size() > 0)
    {
        pair<int, int> cur = dfs.top();
        dfs.pop();
        vis[cur.fi] = 1;
        depth[cur.fi] = cur.se;
        for(int i = 0; i < edges[cur.fi].size(); ++i)
            if(!vis[edges[cur.fi][i]])
                dfs.push({edges[cur.fi][i], cur.se + 1});
    }
    int diameter = 0;
    for(int i = 1; i <= n; ++i)
        diameter = max(diameter, depth[i]);
    memset(depth, 0, sizeof(depth));
    memset(vis, 0, sizeof(vis));
    dfs.push({a, 0});
    while(dfs.size() > 0)
    {
        pair<int, int> cur = dfs.top();
        dfs.pop();
        vis[cur.fi] = 1;
        depth[cur.fi] = cur.se;
        for(int i = 0; i < edges[cur.fi].size(); ++i)
            if(!vis[edges[cur.fi][i]])
                dfs.push({edges[cur.fi][i], cur.se + 1});
    }
    if(db >= 2 * da + 1 && diameter >= 2 * da + 1 && depth[b] > da)
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}