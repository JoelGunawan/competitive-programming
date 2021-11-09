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
int region[(int)1e5 + 1];
vector<pii> edges[(int)1e5 + 1];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    // maintain an array of regions containing amount of nodes and total length of roads
    // 
    for(int i = 0; i < m; ++i)
    {
        int l, u, v;
        cin >> l >> u >> v;
        edges[u].pb({l, v});
        edges[v].pb({l, u});
    }
    for(int i = 0; i < n; ++i)
    {
        // cari regionnya
    }
    return 0;
}