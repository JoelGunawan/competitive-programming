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
struct segment_tree {
    vector<ll> a, lazy;
    int sz;
    segment_tree(int init) {
        // find closest power of 2 larger than init
        int tmp = 1;
        while(tmp < init)
            tmp *= 2;
        sz = tmp;
        lazy = a = vector<ll>(2 * sz, 0);
    }
    void propagate(int nd, int cl, int cr) {
        a[nd] += lazy[nd] * (cr - cl + 1);
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) >> 1;
            propagate(nd, cl, cr);
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = a[2 * nd] + a[2 * nd + 1];
        }
        //cout << "UPD " << cl << " " << cr << " " << a[nd] << endl;
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) >> 1;
            return query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r);
        }
    }
};
void tc() {
    int n, c;
    cin >> n >> c;
    segment_tree seg = segment_tree(n + 1);
    while(c--) {
        int t;
        cin >> t;
        if(t == 0) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.update(1, 0, seg.sz - 1, l, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 0, seg.sz - 1, l, r) << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}