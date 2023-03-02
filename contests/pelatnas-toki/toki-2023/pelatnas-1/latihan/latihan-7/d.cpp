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
const int lim = 1e4 + 5;
struct disjoint_set {
    int sz[lim], h[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        while(h[nd] != -1)
            nd = h[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    disjoint_set dsu;
    int n, m, k;
    cin >> n >> m >> k;
    int pembangkit[k];
    for(int i = 0; i < k; ++i) {
        cin >> pembangkit[i];
    }
    for(int i = 1; i < k; ++i)
        dsu.merge(pembangkit[i], pembangkit[0]);
    pair<int, pair<int, int>> adj[m];
    ll ans = 0;
    for(int i = 0; i < m; ++i) {
        cin >> adj[i].se.fi >> adj[i].se.se >> adj[i].fi;
    }
    sort(adj, adj + m);
    for(int i = 0; i < m; ++i) {
        if(dsu.merge(adj[i].se.fi, adj[i].se.se)) {
            ans += adj[i].fi;
        }
    }
    if(dsu.sz[dsu.fh(1)] == n)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}