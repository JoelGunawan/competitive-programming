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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll mod = 998244353;
const int lim = 1 << 18;
struct segment_tree {
    // replace zero with LLONG_MIN for max query
    // replace zero with LLONG_MAX for min query
    long long a[2 * lim], arr_size = lim, zero = 0;
    segment_tree() {
        fill(a, a + 2 * lim, zero);
    }
    long long merge(long long a, long long b) {
        return ((a % mod) * (b % mod)) % mod;
    }
    void update(int idx, long long val) {
        idx += arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx >>= 1;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            //cout << "SEG " << cl << " " << cr << " " << a[nd] << endl;
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 1;
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(int l, int r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> p;
    ll minh = 0;
    for(ll i = 1, j, x, y; i <= n; ++i) {
        cin >> j;
        y = 1e9;
        for(;j--;) {
            cin >> x;
            y = min(y, x);
            p.pb(mp(x, i));
        }
        //cout << y << " ";
        minh = max(y, minh);
    }
    //cout << endl;
    sort(p.begin(), p.end());
    pair<ll, ll> queries[q];
    for(ll i = 0; i < q; ++i)
        cin >> queries[i].fi, queries[i].se = i;
    sort(queries, queries + q);
    ll ans[q];
    memset(ans, -1, sizeof(ans));
    ll j = 0;
    segment_tree segtree;
    //cout << minh << endl;
    for(ll i = 0; i < p.size() && j < q; ++i) {
        for(;j < q && queries[j].fi < p[i].fi;)
            ans[queries[j].se] = segtree.query(1, n), ++j;
        segtree.update(p[i].se, segtree.query(p[i].se, p[i].se) + 1);
        //cout << segtree.query(p[i].se, p[i].se) << " ";
        //cout << a[p[i].se] << " ";
    }
    //cout << endl;
    //cout << endl;
    for(;j < q; ++j)
        ans[queries[j].se] = segtree.query(1, n);
    for(auto i : ans)
        cout << i << endl;
    return 0;
}