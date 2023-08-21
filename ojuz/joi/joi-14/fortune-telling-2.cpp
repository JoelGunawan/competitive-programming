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
const int lim = 1e9 + 5;
struct node {
    int l = -1, r = -1, val = -1;
};
struct segment_tree {
    vector<node> a = {node()};
    void update(int nd, int cl, int cr, int idx, int val) {
        //cout << "UPDATE " << nd << " " << cl << " " << cr << " " << idx << " " << val << endl;
        a[nd].val = max(a[nd].val, val);
        if(cl == cr) {
            return;
        }
        int mid = (cl + cr) / 2;
        if(idx <= mid) {
            if(a[nd].l == -1)
                a[nd].l = a.size(), a.pb(node());
            update(a[nd].l, cl, mid, idx, val);
        }
        else {
            if(a[nd].r == -1)
                a[nd].r = a.size(), a.pb(node());
            update(a[nd].r, mid + 1, cr, idx, val);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        //cout << "QUERY " << nd << " " << cl << " " << cr << " " << a[nd].l << " " << a[nd].r << " " << a[nd].val << endl;
        if(cl >= l && cr <= r) {
            return a[nd].val;
        }
        else if(cr < l || cl > r)
            return -1;
        else {
            int mid = (cl + cr) / 2;
            int ret = -1;
            if(a[nd].l != -1)
                ret = max(ret, query(a[nd].l, cl, mid, l, r));
            if(a[nd].r != -1)
                ret = max(ret, query(a[nd].r, mid + 1, cr, l, r));
            return ret;
        }
    }
};
struct fenwick {
    map<int, int> a;
    void update(int idx, int val) {
        ++idx;
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int query(int idx) {
        ++idx;
        int ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    // max only -> min
    // all -> only after last max only
    int b[k];
    segment_tree seg;
    for(int i = 0; i < k; ++i)
        cin >> b[i], seg.update(0, 0, lim - 1, b[i], i);
    ll res = 0;
    // isi -> kartu ke brp
    vector<int> v[k];
    vector<int> sisa;
    for(int i = 0; i < n; ++i) {
        // last occurence yg antara all dan mx
        int last_occur = seg.query(0, 0, lim - 1, min(a[i].fi, a[i].se), max(a[i].fi, a[i].se) - 1);
        //cout << l << " " << r << " " << last_occur << endl;
        // consider cnt all mulai dari max
        // consider cnt all di kanan posisi skrg
        // di kanan last occur
        //cout << last_occur << " ";
        if(last_occur != -1) {
            v[last_occur].pb(i);
        }
        else {
            sisa.pb(i);
        }
    }
    //cout << endl;
    fenwick bit;    
    for(int i = k - 1; i >= 0; --i) {
        bit.update(b[i], 1);
        for(auto j : v[i]) {
            int cntall = bit.query(max(a[j].fi, a[j].se), 1e9);
            //cout << j << " " << cntall << endl;
            if(cntall & 1)
                res += min(a[j].fi, a[j].se);
            else
                res += max(a[j].fi, a[j].se);
            //cout << res << " ";
            //cout << res << endl;
        }
    }
    for(auto j : sisa) {
        int cntall = bit.query(max(a[j].fi, a[j].se), 1e9);
        if(cntall & 1)
            res += a[j].se;
        else
            res += a[j].fi;
        //cout << res << " ";
    }
    cout << res << endl;
    return 0;
}