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
const int lim = 1 << 17;
struct segment_tree {
    int a[2 * lim], lazy[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    void prop(int nd, int cl, int cr) {
        if(cl != cr) {
            if(lazy[nd]) {
                lazy[2 * nd] ^= lazy[nd];
                lazy[2 * nd + 1] ^= lazy[nd];
            }
        }
        if(lazy[nd])
            a[nd] = (cr - cl + 1) - a[nd];
        lazy[nd] = 0;
    }
    void upd(int nd, int cl, int cr, int l, int r) {
        prop(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] ^= 1;
            prop(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) / 2;
            upd(2 * nd, cl, mid, l, r);
            upd(2 * nd + 1, mid + 1, cr, l, r);
            a[nd] = a[2 * nd] + a[2 * nd + 1];
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        prop(nd, cl, cr);
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    segment_tree seg[20];
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for(int j = 0; j < 20; ++j) {
            if((1 << j) & x)
                seg[j].upd(1, 0, lim - 1, i, i);
        }
    }
    int m;
    cin >> m;
    while(m--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            cin >> l >> r;
            ll res = 0;
            for(int i = 0; i < 20; ++i) {
                res += 1ll * (1 << i) * seg[i].query(1, 0, lim - 1, l, r);
            }
            cout << res << endl;
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            for(int i = 0; i < 20; ++i) {
                if((1 << i) & x) {
                    seg[i].upd(1, 0, lim - 1, l, r);
                }
            }
        }
    }
    return 0;
}