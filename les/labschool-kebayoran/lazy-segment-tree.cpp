#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int lim = 1 << 18;
struct lazy_segment_tree {
    ll a[2 * lim], lazy[2 * lim], arr_size = lim;
    lazy_segment_tree() {
        memset(lazy, 0, sizeof(lazy));
        memset(a, 0, sizeof(a));
    }
    ll merge(ll a, ll b) {
        return a + b;
    }
    void propagate(int nd, int cl, int cr) {
        a[nd] += (cr - cl + 1) * lazy[nd];
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl > r || cr < l) {
            return;
        }
        else if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = merge(a[2 * nd], a[2 * nd + 1]);
        }
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {

}