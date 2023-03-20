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
const int lim = 1 << 19;
struct segment_tree {
    int lazy[2 * lim + 5], a[2 * lim + 5];
    segment_tree() {
        // find lazy max update
        // query min
        memset(lazy, -1, sizeof(lazy));
        memset(a, -1, sizeof(a));
    }
    void propagate(int nd, int cl, int cr) {
        if(cl != cr) {
            // prop to child
            lazy[2 * nd] = max(lazy[2 * nd], lazy[nd]);
            lazy[2 * nd + 1] = max(lazy[2 * nd + 1], lazy[nd]);
        }
        a[nd] = max(lazy[nd], a[nd]);
        lazy[nd] = -1;
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] = val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = min(a[2 * nd], a[2 * nd + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l) 
            return 1e9;
        else {
            int mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> x[n + 5];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        x[v].pb(mp(u, -1));
    }
    for(int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        x[v].pb(mp(u, i));
    }
    segment_tree seg;
    bool ans[q];
    for(int i = 1; i <= n; ++i) {
        for(auto j : x[i]) {
            if(j.se == -1) {
                seg.update(1, 0, lim - 1, j.fi, i, j.fi);
            }
            else {
                ans[j.se] = seg.query(1, 0, lim - 1, j.fi, i) == j.fi; 
            }
        }
    }
    for(auto i : ans) {
        if(i)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}