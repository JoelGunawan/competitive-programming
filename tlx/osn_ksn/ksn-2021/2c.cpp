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
int mod = 1e9 + 7;
const int lim = 1 << 18;
struct segment_tree {
    int a[2 * lim];
    segment_tree() {
        fill(a, a + 2 * lim, -1e9);
    }
    void update(int idx, int val) {
        idx += lim;
        a[idx] = val;
        while(idx) {
            idx >>= 1;
            a[idx] = max(a[idx << 1], a[(idx << 1) + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return -1e9;
        else {
            int mid = (cl + cr) / 2;
            return max(query(nd << 1, cl, mid, l, r), query((nd << 1) + 1, mid + 1, cr, l, r));
        }
    }
    int query(int l, int r) {
        return query(1, 0, lim - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int h[n + 5];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    segment_tree mx, mxpre, mxsuf;
    for(int i = 1; i <= n; ++i) {
        mx.update(i, h[i]);
        mxpre.update(i, h[i] - i);
        mxsuf.update(i, h[i] + i);
    }
    int q;
    cin >> q;
    for(;q--;) {
        int a, b;
        cin >> a >> b;
        ll l = min(a, b), r = max(a, b);
        ll tgth = mx.query(l, r), pre = mxpre.query(l, r), suf = mxsuf.query(l, r);
        if(a < b) {
            pre = pre - h[a] + a;
            suf = suf - h[b] - b;
        }
        else {
            pre = pre - h[b] + b;
            suf = suf - h[a] - a;
        }
        cout << 4 * (tgth - h[a]) + (tgth - h[b]) + 2 * max(0ll, (r - l - (2 * tgth - h[a] - h[b] - pre - suf))) << endl;
    }
}