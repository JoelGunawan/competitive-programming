#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int lim = 1 << 17;
struct segment_tree {
    pair<int, int> a[2 * lim];
    void update(int idx, int val) {
        idx += lim;
        a[idx] = {val, idx - lim};
        while(idx) {
            idx >>= 1;
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l) {
            return {0, 0};
        }
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
struct fenwick {
    long long a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    long long q(int idx) {
        long long res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    // segment tree with priority_queue inside
    // property modulo?
    // masalahnya di segment tree: simpan state terakhir visitednya dmn???
    // pakai set?
    segment_tree seg;
    fenwick bit;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        seg.update(i, x);
        bit.upd(i, x);
    }
    for(int query = 0; query < m; ++query) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            cout << bit.q(r) - bit.q(l - 1) << endl;
        }
        else if(op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            while(seg.query(1, 0, lim - 1, l, r).first >= x) {
                pair<int, int> tmp = seg.query(1, 0, lim - 1, l, r);
                //cout << "RED " << tmp.se << " " << (tmp.fi % x) - tmp.fi << endl;
                bit.upd(tmp.se, (tmp.fi % x) - tmp.fi);
                seg.update(tmp.se, tmp.fi % x);
            }
        }
        else {
            int k, x;
            cin >> k >> x;
            bit.upd(k, - bit.q(k) + bit.q(k - 1));
            bit.upd(k, x);
            seg.update(k, x);
        }
    }
}