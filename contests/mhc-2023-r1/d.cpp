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
struct node {
    pair<int, int> mnp = mp(0, 0), mxp = mp(0, 0), mnn = mp(0 ,0), mxn = mp(0 ,0);
    int lazy = 0;
};
const int lim = 1 << 19;
int mod = 1e9 + 7;
struct segment_tree {
    node a[2 * lim];
    void propagate(int nd, int cl, int cr) {
        if(cl != cr) {
            a[2 * nd].lazy += a[nd].lazy;
            a[2 * nd + 1].lazy += a[nd].lazy;
        }
        if(a[nd].lazy & 1) {
            swap(a[nd].mnp, a[nd].mnn);
            swap(a[nd].mxp, a[nd].mxn);
        }
        a[nd].lazy = 0;
    }
    void change_val(int nd, int cl, int cr, int idx, int val) {
        a[nd].mxp = max(a[nd].mxp, mp(val, -idx));
        //cout << nd << " " << a[nd].mxp.fi << " " << a[nd].mxp.se << " " << a[nd].mnp.fi << " " << a[nd].mnp.se << endl;
        if(a[nd].mnp.fi == 0)
            a[nd].mnp = mp(val, idx);
        else
            a[nd].mnp = min(a[nd].mnp, mp(val, idx));
        if(cl == cr) {
            return;
        }
        int mid = (cl + cr) / 2;
        if(idx <= mid) {
            change_val(2 * nd, cl, mid, idx, val);
        }
        else {
            change_val(2 * nd + 1, mid + 1, cr, idx, val);
        }
    }
    void update(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            ++a[nd].lazy;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r);
            update(2 * nd + 1, mid + 1, cr, l, r);
            a[nd].mxp = max(a[2 * nd].mxp, a[2 * nd + 1].mxp);
            a[nd].mxn = max(a[2 * nd].mxn, a[2 * nd + 1].mxn);
            a[nd].mnp = mp(mod, mod), a[nd].mnn = mp(mod, mod);
            if(a[2 * nd].mnp.fi)
                a[nd].mnp = min(a[nd].mnp, a[2 * nd].mnp);
            if(a[2 * nd + 1].mnp.fi)
                a[nd].mnp = min(a[nd].mnp, a[2 * nd + 1].mnp);
            if(a[2 * nd].mnn.fi)
                a[nd].mnn = min(a[nd].mnn, a[2 * nd].mnn);
            if(a[2 * nd + 1].mnn.fi)
                a[nd].mnn = min(a[nd].mnn, a[2 * nd + 1].mnn);
            if(a[nd].mnp.fi == mod)
                a[nd].mnp = mp(0, 0);
            if(a[nd].mnn.fi == mod)
                a[nd].mnn = mp(0, 0);
        }
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            pair<int, int> ret = a[nd].mxp;
            //cout << "QUERY " << endl;
            //cout << nd << " " << cl << " " << cr << endl;
            //cout << a[nd].mxp.fi << " " << a[nd].mxp.se << endl;
            //cout << a[nd].mnp.fi << " " << a[nd].mnp.se << endl;
            //cout << a[nd].mxn.fi << " " << a[nd].mxn.se << endl;
            //cout << a[nd].mnn.fi << " " << a[nd].mnn.se << endl;
            if(a[nd].mnn.fi)
                ret = max(ret, mp(mod - a[nd].mnn.fi, -a[nd].mnn.se));
            return ret;
        }
        else if(cl > r || cr < l) {
            return mp(0, 0);
        }
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dikali -1 mod 1e9 + 7
    // tiap node punya 2 state, cari maksimum aja
    // nanti tinggal pakai semacam lazy segment tree, tiap node punya base case
    // ada 2 cara: activate/deactivate
    // tiap node: current value, actual value
    // simpan yg bentuk negatif, cari yg paling besar
    // yg bentuk biasa, cari yg paling besar jg
    // nanti tinggal activate/deactivate according to l, r yg dikasih
    // sama aja nge flip semua by negative 1
    // observe: simpan semua dengan nilai sebenarnya
    // nanti tiap node simpan maks dan min positif, maks dan min negatif
    // klo flip, nanti tuker semua state itu
    int t;
    cin >> t;
    int c = 0;
    while(t--) {
        ++c;
        segment_tree seg;
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; ++i) {
            seg.change_val(1, 0, lim - 1, i, a[i]);
        }
        int q;
        cin >> q;
        int res = 0;
        for(int i = 1; i <= q; ++i) {
            int l, r;
            cin >> l >> r;
            seg.update(1, 0, lim - 1, l, r);
            //cout << seg.query(1, 0, lim - 1, 1, n).fi << " " << seg.query(1, 0, lim - 1, 1, n).se << endl;
            res += abs(seg.query(1, 0, lim - 1, 1, n).se);
        }
        cout << "Case #" << c << ": " << res << endl;
    } 
    return 0;
}