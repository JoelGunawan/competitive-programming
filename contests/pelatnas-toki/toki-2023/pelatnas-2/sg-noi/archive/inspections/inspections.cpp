#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define endl "\n"
using namespace std;
const int lim = 1 << 18;
const ll lim2 = 1e12 + 5;
struct fenwick {
    map<ll, ll> a;
    void update(ll idx, int val) {
        while(idx < lim2) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    ll query(ll idx) {
        ll res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
};
fenwick bit;
struct segment_tree {
    pair<ll, pair<int, int>> a[lim];
    ll sum[lim];
    // sum -> maintains sum of all previous
    void calc_res(pair<ll, pair<int, int>> a, pair<ll, pair<int, int>> b, int cl, int cr) {
        if(a.se == mp(0, 0) || b.se == mp(0, 0))
            return;
        //cout << a.se.fi << " " << a.se.se << " " << b.se.fi << " " << b.se.se << " " << cl << " " << cr << endl;
        ll ls = a.fi + cl - a.se.fi, rs = b.fi + cl - b.se.fi;
        rs -= ls;
        bit.update(rs, cr - cl + 1);
        // calculate results
    }
    void update(int nd, int cl, int cr, pair<ll, pair<int, int>> val) {
        if(cl >= val.se.fi && cr <= val.se.se) {
            // merge_lazy di node sekarang dengan existing
            calc_res(a[nd], val, cl, cr);
            if(a[nd].se == mp(0, 0) && cl != cr) {
                // kita harus pergi ke child untuk calculate hasil
                int mid = (cl + cr) / 2;
                update(2 * nd, cl, mid, val);
                update(2 * nd + 1, mid + 1, cr, val);
            }
            a[nd] = val;
            //cout << nd << " " << a[nd].se.fi << " " << a[nd].se.se << endl;
        }
        else if(cl > val.se.se || cr < val.se.fi) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            if(a[nd].se != mp(0, 0))
                a[2 * nd] = a[2 * nd + 1] = a[nd];
            a[nd] = mp(0, mp(0, 0));   
            update(2 * nd, cl, mid, val);
            update(2 * nd + 1, mid + 1, cr, val);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // buat segment tree
    // awalnya semuanya isinya -1
    // problem: length of segment from pr visit jg pengaruh
    // pr visit: di length berapa aja?
    // cur visit: di length berapa aja?
    // for a propagation just save the segment
    // segment tree a prop isinya segment aja
    // nanti buat merging segment kita lakukan ini O(1) time aja, 
    int n, m, q;
    cin >> n >> m >> q;
    segment_tree seg;
    ll ti = 0;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        seg.update(1, 0, lim - 1, mp(ti, mp(l, r)));
        ti += r - l + 1;
    }
    for(int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        cout << bit.query(lim2 - 1) - bit.query(x) << " ";
    }
    cout << endl;
}