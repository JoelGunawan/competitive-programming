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
const int lim = 1 << 20;
struct segment_tree {
    int a[2 * lim], lazy[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    void propagate(int nd, int cl, int cr) {
        a[nd] += lazy[nd];
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void update(int l, int r, int val) {
        update(1, 0, lim - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl > r || cr < l)
            return;
        else if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = max(a[2 * nd], a[2 * nd + 1]);
        }
    }
    int query() {
        return query(1, 0, lim - 1);
    }
    int query(int nd, int cl, int cr) {
        propagate(nd, cl, cr);
        if(cl == cr)
            return cl;
        int mid = (cl + cr) / 2;
        propagate(2 * nd, cl, mid);
        propagate(2 * nd + 1, mid + 1, cr);
        if(max(a[2 * nd], a[2 * nd + 1]) <= 0) {
            return -1;
        }
        else {
            if(a[2 * nd + 1] > 0)
                return query(2 * nd + 1, mid + 1, cr);
            else
                return query(2 * nd, cl, mid);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    segment_tree segtree;
    for(int i = 0; i < n; ++i)
        cin >> a[i], segtree.update(1, a[i], 1);
    for(int i = 0; i < m; ++i)
        cin >> b[i], segtree.update(1, b[i], -1);
    int q;
    cin >> q;
    // if for all ranges it is 0, then output 0
    for(int i = 0; i < q; ++i) {
        int t, x, w;
        cin >> t >> x >> w;
        --x;
        if(t == 1) {
            segtree.update(1, a[x], -1);
            a[x] = w;
            segtree.update(1, a[x], 1);
        }
        else {
            segtree.update(1, b[x], 1);
            b[x] = w;
            segtree.update(1, b[x], -1);
        }
        cout << segtree.query() << endl;
    }
    return 0;
}