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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e5 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    ll query(int idx) {
        ll ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // memo kiri jatuh dan kanan jatuh
    int n, q;
    cin >> n >> q;
    int a[n + 2];
    a[0] = -1;
    a[n + 1 ] = -1;
    fenwick bit;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i], bit.upd(i, max(a[i], 0));
    }
    int pre[n + 1];
    memset(pre, 0, sizeof(pre));
    for(int i = 1; i <= n; ++i) {
        if(a[i] == -1)
            pre[i] = 0;
        else
            pre[i] = pre[i - 1] + 1;
    }
    int suff[n + 2];
    memset(suff, 0, sizeof(suff));
    for(int i = n; i >= 1; --i) {
        if(a[i] == -1)
            suff[i] = 0;
        else
            suff[i] = suff[i + 1] + 1;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int mxr = l + suff[l], mxl = r - pre[r];
        mxl = max(mxl, l);
        mxr = min(mxr, r);
        if(mxr >= mxl)
            cout << bit.query(l, r) << endl;
        else
            cout << bit.query(l, mxr) + bit.query(mxl, r) << endl;
    }
    return 0;
}