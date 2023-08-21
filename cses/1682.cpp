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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e5 + 5;
bool vis[lim];
vector<int> edges[lim], inv[lim];
int dfs(int nd) {
    int ret = 1;
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            ret += dfs(i);
    }
    return ret;
}
int dfs2(int nd) {
    int ret = 1;
    vis[nd] = 1;
    for(auto i : inv[nd]) {
        if(!vis[i])
            ret += dfs2(i);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        inv[v].pb(u);
    }
    int s = dfs(1);
    if(s != n) {
        cout << "NO" << endl;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                cout << "1 " << i << endl;
                return 0;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    int t = dfs2(1);
    if(s == n && t == n)
        cout << "YES" << endl;
    else {
        cout << "NO" << endl;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                cout << i << " 1" << endl;
                return 0;
            }
        }
    }
    return 0;
}