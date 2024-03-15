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
        while(idx > 1) {
            idx >>= 1;
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    int query(int nd, int cl, int cr, int room) {
        if(cl == cr) {
            if(a[nd] >= room)
                return cl;
            else
                return 0;
        }
        else {
            // kiri
            int mid = (cl + cr) >> 1;
            if(a[2 * nd] >= room) {
                return query(2 * nd, cl, mid, room);
            }
            // kanan
            else if(a[2 * nd + 1] >= room) {
                return query(2 * nd + 1, mid + 1, cr, room);
            }
            else {
                return 0;
            }
        }
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    int h[n + 1];
    segment_tree segtree;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        segtree.update(i, h[i]);
    }
    for(int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        cout << segtree.query(1, 0, segtree.arr_size - 1, x) << endl;
        if(segtree.query(1, 0, segtree.arr_size - 1, x)) {
            segtree.update(segtree.query(1, 0, segtree.arr_size - 1, x), -x);
        }
    }
}