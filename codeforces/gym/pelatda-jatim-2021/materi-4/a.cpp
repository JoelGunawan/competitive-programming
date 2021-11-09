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
bool vis[1001];
vector<int> edges[1001];
int find_size(int nd)
{
    vis[nd] = 1;
    int res = 1;
    for(int i = 0; i < edges[nd].size(); ++i)
        if(!vis[edges[nd][i]])
            res += find_size(edges[nd][i]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int gov_nodes[k];
    for(int i = 0; i < k; ++i)
        cin >> gov_nodes[i];
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    // find the amount of nodes connected to each government, nodes that are not yet connected to any government will be connected to the largest government
    ll gov_size[k];
    for(int i = 0; i < k; ++i)
        gov_size[i] = find_size(gov_nodes[i]);
    int max_size = 0, max_index;
    for(int i = 0; i < k; ++i)
    {
        if(gov_size[i] > max_size)
            max_index = i, max_size = gov_size[i];
    }
    // find nodes that are not visited
    int no_gov_count = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            ++no_gov_count;
    gov_size[max_index] += no_gov_count;
    ll res = 0;
    for(int i = 0; i < k; ++i)
        res += gov_size[i] * (gov_size[i] - 1) / 2;
    cout << res - m << endl;
    return 0;
}