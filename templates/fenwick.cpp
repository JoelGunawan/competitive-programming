#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
struct fenwick {
    long long a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    long long query(int idx) {
        long long res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    // checked using cses 1648
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    fenwick bit;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bit.update(i + 1, x);
    }
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int k, u;
            cin >> k >> u;
            bit.update(k, u - bit.query(k, k));
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << bit.query(a, b) << '\n';
        }
    }
}