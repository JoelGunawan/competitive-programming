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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct node {
    ll l = -1, r = -1;
    ll lazy = 0;
};
struct persistent_dynamic_lazy_segment_tree {
    vector<node> a = {node()};
    vector<ll> head_idx = {0};
    void upd(ll oldnd, ll newnd, ll cl, ll cr, ll l, ll r, ll val) {
        if(oldnd == -1) {
            if(cl >= l && cr <= r) {
                a[newnd].lazy += val;
            }
            else if(cl > r || cr < l) {

            }
            else {
                a[newnd].l = a.size();
                a.pb(node());
                a[newnd].r = a.size();
                a.pb(node());
                ll mid = (cl + cr) >> 1;
                upd(-1, a[newnd].l, cl, mid, l, r, val);
                upd(-1, a[newnd].r, mid + 1, cr, l, r, val);
            }
        }
        else {
            // copy data from old node
            a[newnd].lazy = a[oldnd].lazy;
            if(cl >= l && cr <= r) {
                a[newnd].l = a[oldnd].l;
                a[newnd].r = a[oldnd].r;
                a[newnd].lazy += val;
            }
            else if(cl > r || cr < l)  {
                a[newnd].l = a[oldnd].l;
                a[newnd].r = a[oldnd].r;
            }
            else {
                ll mid = (cl + cr) >> 1;
                a[newnd].l = a.size();
                a.pb(node());
                a[newnd].r = a.size();
                a.pb(node());
                upd(a[oldnd].l, a[newnd].l, cl, mid, l, r, val);
                upd(a[oldnd].r, a[newnd].r, mid + 1, cr, l, r, val);
            }
        }
        //cout << newnd << " " << cl << " " << cr << " " << a[newnd].lazy << " " << a[newnd].l << " " << a[newnd].r << endl;
    }
    ll query(ll nd, ll cl, ll cr, ll idx, ll cur_lazy) {
        cur_lazy += a[nd].lazy;
        if(cl == idx && cr == idx) {
            return cur_lazy;
        }
        else {
            ll mid = (cl + cr) >> 1;
            if(idx <= mid) {
                if(a[nd].l == -1)
                    return cur_lazy;
                else 
                    return query(a[nd].l, cl, mid, idx, cur_lazy);
            }
            else {
                if(a[nd].r == -1)
                    return cur_lazy;
                else
                    return query(a[nd].r, mid + 1, cr, idx, cur_lazy);
            }
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll r, c, q;
    cin >> r >> c >> q;
    ll last_upd[400005], val[400005];
    memset(last_upd, 0, sizeof(last_upd));
    memset(val, 0, sizeof(val));
    persistent_dynamic_lazy_segment_tree seg;
    for(ll i = 1; i <= q; ++i) {
        ll ops;
        cin >> ops;
        if(ops == 1) {
            ll le, re, v;
            cin >> le >> re >> v;
            seg.head_idx.pb(seg.a.size());
            seg.a.pb(node());
            seg.upd(seg.head_idx[seg.head_idx.size() - 2], seg.head_idx.back(), 1, 4e5, le, re, v);
        }
        else if(ops == 2) {
            ll re, v;
            cin >> re >> v;
            last_upd[re] = seg.head_idx.back(), val[re] = v;
        }
        else {
            ll re, ce;
            cin >> re >> ce;
            cout << val[re] + seg.query(seg.head_idx.back(), 1, 4e5, ce, 0) - seg.query(last_upd[re], 1, 4e5, ce, 0) << endl;
        }
    }
    return 0;
}