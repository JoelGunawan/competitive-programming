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
const int lim = 1 << 18;
struct segment_tree {
    int mx[2 * lim], mn[2 * lim], lazysum[2 * lim], lazymin[2 * lim], lazymax[2 * lim];
    segment_tree() {
        fill(mx, mx + 2 * lim, -2e9);
        fill(mn, mn + 2 * lim, 2e9);
        memset(lazysum, 0, sizeof(lazysum));
        fill(lazymin, lazymin + 2 * lim, 2e9);
        fill(lazymax, lazymax + 2 * lim, -2e9);
    }
    void propagate(int nd, int cl, int cr) {
        mn[nd] += lazysum[nd];
        mx[nd] += lazysum[nd];
        mn[nd] = min(mn[nd], lazymin[nd]);
        mx[nd] = min(mx[nd], lazymin[nd]);
        mn[nd] = max(mn[nd], lazymax[nd]);
        mx[nd] = max(mx[nd], lazymax[nd]);
        //cout << cl << " " << cr << " " << mn[nd] << " " << mx[nd] << " " << lazysum[nd] << " " << lazymin[nd] << endl;
        if(cl != cr) {
            lazysum[2 * nd] += lazysum[nd];
            lazysum[2 * nd + 1] += lazysum[nd];
            lazymin[2 * nd] = min(max(lazymax[nd], lazymin[2 * nd] + lazysum[nd]), lazymin[nd]);
            lazymin[2 * nd + 1] = min(max(lazymax[nd], lazymin[2 * nd + 1] + lazysum[nd]), lazymin[nd]);
            lazymax[2 * nd] = max(min(lazymax[2 * nd] + lazysum[nd], lazymin[nd]), lazymax[nd]);
            lazymax[2 * nd + 1] = max(min(lazymin[nd], lazymax[2 * nd + 1] + lazysum[nd]), lazymax[nd]);
        }
        lazysum[nd] = 0;
        lazymin[nd] = 2e9;
        lazymax[nd] = -2e9;
    }
    void update(int nd, int cl, int cr, int idx, int val) {
        propagate(nd, cl, cr);
        if(cl == cr) {
            mn[nd] = val, mx[nd] = val;
            //cout << "SET " << nd << " " << cl << " " << val << endl;
        }
        else {
            int mid = (cl + cr) / 2;
            if(idx <= mid)
                update(2 * nd, cl, mid, idx, val);
            else
                update(2 * nd + 1, mid + 1, cr, idx, val);
            mn[nd] = min(mn[2 * nd], mn[2 * nd + 1]);
            mx[nd] = max(mx[2 * nd], mx[2 * nd + 1]);
        }
    }
    void update_sum(int nd, int cl, int cr, int l, int r, int val) {
        //cout << "BEFORE SUM UPDATE " << nd << " " << cl << " " << cr << " " << mx[nd] << " " << mn[nd] << endl;
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazysum[nd] += val;
            lazymin[nd] += val;
            lazymax[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) / 2;
            update_sum(2 * nd, cl, mid, l, r, val);
            update_sum(2 * nd + 1, mid + 1, cr, l, r, val);
            mn[nd] = min(mn[2 * nd], mn[2 * nd + 1]);
            mx[nd] = max(mx[2 * nd], mx[2 * nd + 1]);
        }
        //cout << "SUM UPDATE " << nd << " " << cl << " " << cr << " " << mx[nd] << " " << mn[nd] << endl;
    }
    void update_min(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazymin[nd] = min(lazymin[nd], val);
            lazymax[nd] = min(lazymax[nd], val);
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) / 2;
            update_min(2 * nd, cl, mid, l, r, val);
            update_min(2 * nd + 1, mid + 1, cr, l, r, val);
            mn[nd] = min(mn[2 * nd], mn[2 * nd + 1]);
            mx[nd] = max(mx[2 * nd], mx[2 * nd + 1]);
        }
    }
    void update_max(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazymin[nd] = max(lazymin[nd], val);
            lazymax[nd] = max(lazymax[nd], val);
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l)
            return;
        else {
            int mid = (cl + cr) / 2;
            update_max(2 * nd, cl, mid, l, r, val);
            update_max(2 * nd + 1, mid + 1, cr, l, r, val);
            mn[nd] = min(mn[2 * nd], mn[2 * nd + 1]);
            mx[nd] = max(mx[2 * nd], mx[2 * nd + 1]);
        }
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r)
            return mp(mn[nd], mx[nd]);
        else if(cl > r || cr < l)
            return mp(2e9, -2e9);
        else {
            int mid = (cl + cr) / 2;
            pair<int, int> res = mp(2e9, -2e9);
            pair<int, int> tmp = query(2 * nd, cl, mid, l, r);
            res.fi = min(res.fi, tmp.fi), res.se = max(res.se, tmp.se);
            tmp = query(2 * nd + 1, mid + 1, cr, l, r);
            res.fi = min(res.fi, tmp.fi), res.se = max(res.se, tmp.se);
            return res;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    segment_tree seg;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        seg.update(1, 0, lim - 1, i, x);
    }
    for(int query = 0; query < q; ++query) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            //cout << "UPDATE SUM" << endl;
            seg.update_sum(1, 0, lim - 1, l, r, k);
        }
        else if(type == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            //cout << "UPDATE MIN" << endl;
            seg.update_min(1, 0, lim - 1, l, r, k);
        }
        else if(type == 3) {
            int l, r, k;
            cin >> l >> r >> k;
            seg.update_max(1, 0, lim - 1, l, r, k);
        }
        else {
            int l, r;
            cin >> l >> r;
            //cout << "OUTPUT" << endl;
            pair<int, int> tmp = seg.query(1, 0, lim - 1, l, r);
            cout << tmp.fi << " " << tmp.se << endl;
        }
    }
}