#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 18;
struct segment_tree {
    int a[2 * lim], arr_size = lim;
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        idx += arr_size;
        a[idx] += val;
        idx >>= 1;
        while(idx != 0)
            a[idx] = max(a[2 * idx], a[2 * idx + 1]), idx >>= 1;
    }
    int query(int nd, int cl, int cr, int k) {
        if(cl == cr)
            return cl;
        if(a[nd] < k)
            return 0;
        else if(a[2 * nd] >= k)
            return query(2 * nd, cl, (cl + cr) / 2, k);
        else
            return query(2 * nd + 1, (cl + cr) / 2 + 1, cr, k);
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    segment_tree segtree;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        segtree.update(i, x);
    }
    for(int i = 1; i <= m; ++i) {
        int r;
        cin >> r;
        int idx = segtree.query(1, 0, segtree.arr_size - 1, r);
        cout << idx << endl;
        if(idx != 0)
            segtree.update(idx, -r);
    }
}