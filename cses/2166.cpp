// header file
#include <bits/stdc++.h>
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
const int lim = 1 << 18;
struct segtree {
    ll a[2 * lim], lazy[2 * lim];
    segtree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    int arr_size = lim;
    void propagate(int nd, int cl, int cr) {
        a[nd] += lazy[nd];
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void update(int l, int r, ll val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, ll val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = max(a[2 * nd], a[2 * nd + 1]);
        }
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) 
            return -1e18;
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    ll vals[n + 1];
    segtree seg;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        vals[i] = x;
        seg.update(i, n, x);
        //cout << seg.query(1, 0, seg.arr_size - 1, i, i) << " ";
    }
    //cout << endl;
    for(int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        if(query == 2) {
            int a, b;
            cin >> a >> b;
            cout << seg.query(1, 0, seg.arr_size - 1, a - 1, b) - seg.query(1, 0, seg.arr_size - 1, a - 1, a - 1) << endl;
        }
        else {
            ll k, x;
            cin >> k >> x;
            seg.update(k, n, x - vals[k]);
            vals[k] = x;
        }
    }
    return 0;
}