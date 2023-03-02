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
const int lim = 1 << 17;
int k;
struct segment_tree {
    ll occur_drop[2 * lim][32], a[2 * lim];
    int occur_prop[2 * lim];

    segment_tree() {
        memset(a, 0, sizeof(a));
        memset(occur_drop, 0, sizeof(occur_drop));
        memset(occur_prop, 0, sizeof(occur_prop));
    }
    void propagate(int nd, int cl, int cr) {
        if(cl != cr) {
            occur_prop[2 * nd] += occur_prop[nd];
            occur_prop[2 * nd + 1] += occur_prop[nd];
        }
        //cout << occur_prop[nd] << " " << a[nd] << endl;
        if(occur_prop[nd]) {
            for(int i = 0; i < min(32, occur_prop[nd]); ++i) {
                //cout << occur_drop[nd][i];
                a[nd] -= occur_drop[nd][i];
                occur_drop[nd][i] = 0;
            }
            //cout << cl << " " << cr << " " << a[nd] << endl;
            for(int i = occur_prop[nd]; i < 32; ++i) {
                occur_drop[nd][i - occur_prop[nd]] = occur_drop[nd][i], occur_drop[nd][i] = 0;
            }
            occur_prop[nd] = 0;
        }
    }
    void upd(int nd, int cl, int cr, int idx, int val) {
        propagate(nd, cl, cr);
        // tambahkan occur_drop
        int tmp = val, cur = 0;
        a[nd] += val;
        while(tmp && k != 1) {
            int tmp2 = tmp / k;
            occur_drop[nd][cur++] += tmp - tmp2;
            tmp = tmp2;
        }
        //cout << cl << " " << cr << " " << a[nd] << endl;
        if(cl != cr) {
            int mid = (cl + cr) >> 1;
            if(idx <= mid)
                upd(2 * nd, cl, mid, idx, val);
            else
                upd(2 * nd + 1, mid + 1, cr, idx, val);
        }
    }
    void erase(int nd, int cl, int cr, int idx, int val) {
        propagate(nd, cl, cr);
        // tambahkan occur_drop
        int tmp = val, cur = 0;
        a[nd] -= val;
        while(tmp && k != 1) {
            int tmp2 = tmp / k;
            occur_drop[nd][cur++] -= tmp - tmp2;
            tmp = tmp2;
        }
        //cout << cl << " " << cr << " " << a[nd] << endl;
        if(cl != cr) {
            int mid = (cl + cr) >> 1;
            if(idx <= mid)
                erase(2 * nd, cl, mid, idx, val);
            else
                erase(2 * nd + 1, mid + 1, cr, idx, val);
        }
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        //cout << cl << " " << cr << " " << a[nd] << endl;
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) >> 1;
            return query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r);
        }
    }
    void spray(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            ++occur_prop[nd];
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) >> 1;
            spray(2 * nd, cl, mid, l, r);
            spray(2 * nd + 1, mid + 1, cr, l, r);
            for(int i = 0; i < 32; ++i)
                occur_drop[nd][i] = occur_drop[2 * nd][i] + occur_drop[2 * nd + 1][i];
            a[nd] = a[2 * nd] + a[2 * nd + 1];
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // each node maintains array of occur
    // at most 30/31
    int n, q;
    cin >> n >> q >> k;
    segment_tree seg;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        seg.upd(1, 0, lim - 1, i, x);
    }
    for(;q--;) {
        int s, t, u;
        cin >> s >> t >> u;
        if(s == 1) {
            seg.erase(1, 0, lim - 1, t, seg.query(1, 0, lim - 1, t, t));
            seg.upd(1, 0, lim - 1, t, u);
        }
        else if(s == 2) {
            //cout << "SPRAY" << endl;
            seg.spray(1, 0, lim - 1, t, u);
            //cout << "SPRAYEND" << endl;
        }
        else {
            cout << seg.query(1, 0, lim - 1, t, u) << endl;
        }
    }
    return 0;
}