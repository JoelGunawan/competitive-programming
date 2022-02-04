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
const int lim = 200001;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int value) {
        while(idx < lim) {
            a[idx] += value;
            idx += (idx&-idx);
        }
    }
    ll query(int l, int r) {
        return private_query(r) - private_query(l - 1);
    }
    ll private_query(int idx) {
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
    fenwick bit;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bit.update(i + 1, x);
    }
    for(int i = 0; i < q; ++i) {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1) {
            bit.update(a, b - bit.query(a, a));
        }
        else {
            cout << bit.query(a, b) << endl;
        }
    }
    return 0;
}