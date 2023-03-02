// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 5e3 + 5;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int q(int l, int r) {
        return q(r) - q(l - 1);
    }
    int q(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
};
void tc() {
    fenwick bit;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // brute force pb and pc
    // find right of pc less than pb
    // find left of pb less than pc
    int l[n][n], r[n][n];
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            l[i][j] = bit.q(a[j] - 1);
        }
        bit.upd(a[i], 1);
    }
    fenwick bit2;
    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < n; ++j) {
            r[j][i] = bit2.q(a[j] - 1);
        }
        bit2.upd(a[i], 1);
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            res += 1ll * l[i][j] * r[i][j];
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}