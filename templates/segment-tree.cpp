#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 18;
struct segment_tree {
    // replace zero with LLONG_MIN for max query
    // replace zero with LLONG_MAX for min query
    long long a[2 * lim], arr_size = lim, zero = 0;
    segment_tree() {
        fill(a, a + 2 * lim, zero);
    }
    long long merge(long long a, long long b) {
        return a + b;
    }
    void update(int idx, long long val) {
        idx += arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx >>= 1;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(int l, int r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
int main() {
    // checked using cses 1648
    int n, q;
    cin >> n >> q;
    segment_tree seg;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        seg.update(i + 1, x);
    }
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int k, u;
            cin >> k >> u;
            seg.update(k, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << seg.query(a, b) << '\n';
        }
    }
}