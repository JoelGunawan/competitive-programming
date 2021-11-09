#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define ins insert
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
bool vis[(int)1e5 + 1];
vector<int> edges[(int)1e5 + 1];
int dfs(int nd)
{
    vis[nd] = 1;
    vector<int> num;
    for(int i = 0; i < edges[nd].size(); ++i)
    {
        if(!vis[edges[nd][i]])
            num.pb(dfs(edges[nd][i]));
    }
    if(num.size() == 0)
        return 1;
    else if(num.size() == 1)
        return num[0] + 1;
    else
        return 2 * min(num[0], num[1]) + 1;
}
void test_case()
{
    int n;
    cin >> n;
    // resets edges
    for(int i = 0; i <= n; ++i)
        edges[i] = {};
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v), edges[v].pb(u);
    }
    cout << dfs(0) << endl;
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