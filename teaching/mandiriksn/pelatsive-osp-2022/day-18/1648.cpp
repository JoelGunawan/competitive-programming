#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1 << 18;
struct rsq {
    long long a[2 * lim], arr_size = lim;
    rsq() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        idx += arr_size;
        a[idx] = val;
        idx >>= 1;
        while(idx != 0) {
            a[idx] = a[2 * idx] + a[2 * idx + 1];
            idx >>= 1;
        }
    }
    long long query(int nd, int cl, int cr, int ql, int qr) {
        if(cl >= ql && cr <= qr) {
            return a[nd]; 
        }
        else if(cl > qr || cr < ql)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return query(2 * nd, cl, mid, ql, qr) + query(2 * nd + 1, mid + 1, cr, ql, qr);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    rsq segtree;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        segtree.update(i, x);
    }
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1)
            segtree.update(a, b);
        else
            cout << segtree.query(1, 0, segtree.arr_size - 1, a, b) << endl;
    }
}