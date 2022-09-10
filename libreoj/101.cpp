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
ll adj[101][101];
bool vis[101];
bool dfs(int a, int b, int bound) {
    if(a == b)
        return 1;
    vis[a] = 1;
    for(int i = 1; i <= 100; ++i) {
        if(adj[a][i] >= bound && !vis[i]) {
            bool tmp = dfs(i, b, bound);
            if(tmp) {
                adj[a][i] -= bound;
                adj[i][a] += bound;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // max flow algo
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u][v] += c;
    }
    ll res = 0;
    for(int i = 30; i >= 0; --i) {
        while(dfs(s, t, 1 << i)) {
            res += 1 << i;
            memset(vis, 0, sizeof(vis));
        }
        memset(vis, 0, sizeof(vis));
    }
    cout << res << endl;
    return 0;
}