#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 18;
struct segment_tree {
    int a[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        idx += lim;
        a[idx] += val;
        while(idx) {
            idx >>= 1;
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    int query(int nd, int cl, int cr, int x) {
        // cari bilangan pertama yg >= x
        //cout << nd << " " << cl << " " << cr << endl;
        if(a[nd] < x) {
            // ga ada yg memenuhi
            return 0;
        }
        if(cl == cr) {
            return cl;
        }
        // coba cek di child kiri ada yg >= x atau bkn
        int mid = (cl + cr) / 2;
        if(a[2 * nd] >= x) {
            return query(2 * nd, cl, mid, x);
        }
        else {
            return query(2 * nd + 1, mid + 1, cr, x);
        }
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    segment_tree seg;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        seg.update(i, x);
    }
    for(int i = 1; i <= m; ++i) {
        int cnt;
        cin >> cnt;
        int idx = seg.query(1, 0, lim - 1, cnt);
        cout << idx << endl;
        if(idx != 0)
            seg.update(idx, -cnt);
    }
}