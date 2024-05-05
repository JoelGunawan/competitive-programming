#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int lim = 1 << 20;
struct lazy_segment_tree {
    int a[2 * lim], lazy[2 * lim];
    lazy_segment_tree() {
        fill(a, a + 2 * lim, 0);
    }
    void propagate(int nd, int cl, int cr) {
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        a[nd] += lazy[nd];
        lazy[nd] = 0;
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
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
            a[nd] = min(a[2 * nd], a[2 * nd + 1]);
        }
    }
    void update(int l, int r, int val) {
        update(1, 0, lim - 1, l, r, val);
    }
    int query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) {
            return 1e9;
        }
        else {
            int mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    int query(int l, int r) {
        return query(1, 0, lim - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    // observe: jika setiap titik dilewati setidaknya sekali, maka pasti bisa? -> tidak
    // update dari l ke r - 1, lalu nanti jika semua nilainya non zero, maka pasti bisa
    // sort by w, lalu two pointers
    pair<int, pair<int, int>> a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].se.fi >> a[i].se.se >> a[i].fi;
    }
    sort(a, a + n);
    lazy_segment_tree seg;
    int r = 0, ans = 2e9;
    for(int i = 0; i < n; ++i) {
        while(r < n && seg.query(1, m - 1) == 0) {
            //cout << "UPDATE " << a[r].se.fi << " " << a[r].se.se - 1 << endl;
            seg.update(a[r].se.fi, a[r].se.se - 1, 1);
            ++r;
        }
        if(seg.query(1, m - 1) != 0)
            ans = min(ans, a[r - 1].fi - a[i].fi);
        seg.update(a[i].se.fi, a[i].se.se - 1, -1);
    }
    cout << ans << endl;
}