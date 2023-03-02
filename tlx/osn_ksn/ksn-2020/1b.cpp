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
ll k = 0;
const int lim = 1 << 18;
struct segment_tree {
    pair<int, int> a[2 * lim + 1];
    void update(pair<int, int> val, int idx) {
        idx += lim;
        a[idx] = val;
        idx >>= 1;
        while(idx) {
            a[idx] = min(a[2 * idx], a[2 * idx + 1]);
            idx >>= 1;
        }
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return {1e9 + 5, 1e9 + 5};
        else {
            int mid = (cl + cr) >> 1;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
segment_tree segtree;
pair<ll, int> q[lim];
int last_q = 0;
ll ans[lim];
void solve(int l, int r, int used) {
    if(l > r)
        return;
    //cout << l << " " << r << " " << used << " " << k << " ";
    pair<int, int> query = segtree.query(1, 0, lim - 1, l, r);
    ll new_k = k + 1ll * (r - l + 1) * (query.fi - used) + (query.se - l);
    while(q[last_q].se != 0 && q[last_q].fi <= new_k) {
        // process query
        ans[q[last_q].se] = (q[last_q].fi - 1 - k) % (r - l + 1) + l;
        //cout << q[last_q].fi - 1 << " " << (r - l + 1) << " ";
        ++last_q;
    }
    k = new_k;
    //cout << k << " " << last_q << endl;
    solve(l, query.se - 1, query.fi + 1);
    solve(query.se + 1, r, query.fi);
}   
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i], segtree.update({h[i], i}, i);
    // find first minimum
    // break at first minimum
    // advance current k by such amount
    int x;
    cin >> x;
    for(int i = 0; i < x; ++i)
        cin >> q[i].fi, q[i].se = i + 1;
    sort(q, q + x);
    solve(1, n, 0);
    for(int i = 1; i <= x; ++i)
        cout << ans[i] << endl;
    return 0;
}