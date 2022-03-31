// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 2e5 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, ll val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    void update(int l, int r, ll val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    ll query(int idx) {
        ll res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    fenwick bit;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bit.update(i + 1, i + 1, x);
    }
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            bit.update(a, b, u);
        }
        else {
            int x;
            cin >> x;
            cout << bit.query(x) << endl;
        }
    }
    return 0;
}