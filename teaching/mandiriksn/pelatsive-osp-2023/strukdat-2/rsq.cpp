#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1 << 18;
struct segment_tree {
    long long a[2 * lim], zero = 0;
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    long long merge(long long a, long long b) {
        return a + b;
    }
    void update(int idx, long long val) {
        int nd = idx + lim;
        a[nd] = val;
        while(nd > 1) {
            nd = nd / 2;
            a[nd] = merge(a[2 * nd], a[2 * nd + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        // cl, cr -> segment sekarang
        // l, r -> yg di query
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) {
            return zero;
        }
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
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
        seg.update(i, x);
    }
    for(int i = 1; i <= q; ++i) {
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
            cout << seg.query(1, 0, lim - 1, a, b) << endl;
        }
    }
}