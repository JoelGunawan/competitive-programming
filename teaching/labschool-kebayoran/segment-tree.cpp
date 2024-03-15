#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int lim = 1 << 18;
struct segment_tree {
    ll a[2 * lim], arr_size = lim;
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    ll merge(ll x, ll y) {
        return x + y;
    }
    void update(int idx, int val) {
        idx = idx + arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx /= 2;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        if(cl > r || cr < l) {
            return 0;
        }
        else if(cl >= l && cr <= r) {
            return a[nd];
        }
        else {
            int mid = (cl + cr) / 2;
            return query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r);
        }
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    int x[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    segment_tree segtree;
    for(int i = 0; i < n; ++i)
        segtree.update(i, x[i]);
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1)
            segtree.update(x - 1, y);
        else
            cout << segtree.query(1, 0, segtree.arr_size - 1, x - 1, y - 1) << endl;
    }
}