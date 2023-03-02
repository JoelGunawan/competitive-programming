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
const int lim = 2e5 + 5;
vector<int> edges[lim], inv[lim];
bool vis1[lim], vis2[lim];
void dfs1(int nd) {
    vis1[nd] = 1;
    for(auto i : edges[nd])
        if(!vis1[i])
            dfs1(i);
}
void dfs2(int nd) {
    vis2[nd] = 1;
    for(auto i : inv[nd])
        if(!vis2[i])
            dfs2(i);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0)
            exit(0);
        for(int i = 1; i <= n; ++i)
            edges[i].clear(), inv[i].clear(), vis1[i] = 0, vis2[i] = 0;
        for(int i = 1; i <= m; ++i) {
            int u, v, t;
            cin >> u >> v >> t;
            edges[u].pb(v);
            inv[v].pb(u);
            if(t == 2)
                edges[v].pb(u), inv[u].pb(v);
        }
        dfs1(1), dfs2(1);
        /*
        for(int i = 1; i <= n; ++i)
            cout << disc[i] << " ";
        cout << endl;
        for(int i = 1; i <= n; ++i)
            cout << low[i] << " ";
        cout << endl;
        */
        bool ans = 1;
        for(int i = 1; i <= n; ++i) {
            if(!vis1[i] || !vis2[i])
                ans = 0;
        }
        cout << (int)ans << endl;
    }
    return 0;
}