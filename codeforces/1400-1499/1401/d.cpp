#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int mod = 1e9 + 7;
vector<int> edges[(int)1e5 + 1];
int depth[(int)1e5 + 1];
ll subtree[(int)1e5 + 1];
bool vis[(int)1e5 + 1];
ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}
ll add(ll a, ll b)
{
    return (a + b) % mod;
}
int dfs(int a = 1, int d = 0)
{
    vis[a] = 1;
    depth[a] = d;
    subtree[a] = 1;
    for(int i = 0; i < edges[a].size(); ++i)
        if(!vis[edges[a][i]])
            subtree[a] += dfs(edges[a][i], d + 1);
    return subtree[a];
}
void test_case()
{
    memset(depth, 0, sizeof(depth));
    memset(subtree, 0, sizeof(subtree));
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        edges[i].clear();
    // make it a rooted tree and have a sum of how many nodes a subtree contains
    pair<int, int> x[n - 1];
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
        x[i] = {u, v};
    }
    int m;
    cin >> m;
    int p[m];
    for(int i = 0; i < m; ++i)
        cin >> p[i];
    dfs();
    ll sizes[n - 1];
    for(int i = 0; i < n - 1; ++i)
    {
        if(depth[x[i].fi] < depth[x[i].se])
            sizes[i] = (subtree[1] - subtree[x[i].se]) * subtree[x[i].se];
        else
            sizes[i] = (subtree[1] - subtree[x[i].fi]) *  subtree[x[i].fi];
    }
    sort(p, p + m);
    sort(sizes, sizes + n - 1);
    ll res = 0;
    if(m < n)
    {
        reverse(p, p + m);
        reverse(sizes, sizes + n - 1);
        for(int i = 0; i < n - 1; ++i)
        {
            if(i < m)
                res = add(res, mul(sizes[i], p[i]));
            else
                res = add(res, sizes[i]);
        }
    }
    else
    {
        for(int i = 0; i < n - 2; ++i)
            res = add(res, mul(sizes[i], p[i]));
        ll tmp = 1;
        for(int i = n - 2; i < m; ++i)
            tmp = mul(tmp, p[i]);
        res = add(res, mul(tmp, sizes[n - 2]));
    }
    cout << res << endl;
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