#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 18;
struct lazy_segment_tree {
    long long a[2 * lim], lazy[2 * lim], inf = 1e18;
    lazy_segment_tree() {
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
    void update(int l, int r, long long val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, long long val) {
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
    long long query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) 
            return -inf;
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};