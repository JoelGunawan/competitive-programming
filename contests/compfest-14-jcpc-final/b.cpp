// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 1e5 + 5;
int mod = 998244353;
int depth[lim];
bool vis[lim];
vector<int> edges[lim];
int odd = 0;
void dfs(int nd, int d) {
    vis[nd] = 1;
    depth[nd] = d;
    if(d & 1)
        ++odd;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i, d + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // subtask 2, 3 -> even cnt * odd cnt
    // subtask 4 -> dfs from each root
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int q;
    cin >> q;
    int l, r;
    cin >> l >> r;
    dfs(1, 0);
    cout << (1ll * odd * (n - odd)) % mod << endl;
    return 0;
}