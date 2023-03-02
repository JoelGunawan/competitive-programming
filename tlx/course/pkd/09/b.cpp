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
vector<int> edges[50005];
bool vis[50005], imp[50005];
int dfs(int nd) {
    vis[nd] = 1;
    int res = 0;
    if(imp[nd])
        ++res;
    for(auto i : edges[nd]) {
        if(!vis[i])
            res += dfs(i);
    }
    return res;
}
void tc() {
    memset(vis, 0, sizeof(vis));
    memset(imp, 0, sizeof(imp));
    for(int i = 0; i < 50005; ++i)
        edges[i].clear();
    int n, e, q, r;
    cin >> n >> e >> q >> r;
    pair<int, int> init_edges[e];
    for(int i = 0; i < e; ++i) {
        cin >> init_edges[i].fi >> init_edges[i].se;
    }
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        imp[x] = 1;
    }
    set<int> dis;
    for(int i = 0; i < r; ++i) {
        int x;
        cin >> x;
        dis.ins(x - 1);
    }
    pair<int, int> edge_list[e - r];
    int idx = 0;
    for(int i = 0; i < e; ++i) {
        if(dis.find(i) == dis.end())
            edge_list[idx++] = init_edges[i];
    }
    for(int i = 0; i < e - r; ++i) {
        edges[edge_list[i].fi].pb(edge_list[i].se);
        edges[edge_list[i].se].pb(edge_list[i].fi);
    }
    ll res = 1ll * q * (q - 1) / 2;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            int cnt = dfs(i);
            res -= 1ll * cnt * (cnt - 1) / 2;
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}