#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 2e5 + 5;
struct fenwick {
    long long a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, long long val) {
        if(idx == 0)
            return;
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
    long long q(int l, int r) {
        return q(r) - q(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    long long s, t;
    cin >> n >> q >> s >> t;
    // make 2 bit
    // one bit to check for difference array stuff
    // other bit to check for sum of degree change
    int input[n + 1];
    cin >> input[0];
    fenwick diff, sum;
    for(int i = 1; i <= n; ++i)
        cin >> input[i], diff.upd(i, input[i] - input[i - 1]);
    for(int i = 1; i <= n; ++i) {
        if(input[i] > input[i - 1]) {
            sum.upd(i, -(input[i] - input[i - 1]) * s);
        }
        else {
            sum.upd(i, -(input[i] - input[i - 1]) * t);
        }
    }
    for(int query = 1; query <= q; ++query) {
        int l, r, x;
        cin >> l >> r >> x;
        diff.upd(l, x);
        diff.upd(r + 1, -x);
        // l nya di update dengan previous
        sum.upd(l, -sum.q(l, l));
        if(diff.q(l) > diff.q(l - 1)) {
            sum.upd(l, -(diff.q(l) - diff.q(l - 1)) * s);
        }
        else {
            sum.upd(l, -(diff.q(l) - diff.q(l - 1)) * t);
        }
        // r nya di update dengan next, ubah ke sumnya
        if(r != n) {
            //cout << diff.q(r + 1) << " " << diff.q(r) << endl;
            sum.upd(r + 1, -sum.q(r + 1, r + 1));
            if(diff.q(r + 1) > diff.q(r)) {
                sum.upd(r + 1, -(diff.q(r + 1) - diff.q(r)) * s);
            }
            else {
                sum.upd(r + 1, -(diff.q(r + 1) - diff.q(r)) * t);
            }
        }
        cout << sum.q(n) << endl;
    }
}