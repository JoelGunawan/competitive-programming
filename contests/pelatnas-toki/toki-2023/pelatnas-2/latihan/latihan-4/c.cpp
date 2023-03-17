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
int mod = 998244353;
/*
const int lim = 1 << 18;
struct lazy_segment_tree {
    long long a[2 * lim], lazy[2 * lim], inf = 1e18;
    lazy_segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    int arr_size = lim;
    void propagate(int nd, int cl, int cr) {
        a[nd] += lazy[nd] * (cr - cl + 1);
        a[nd] %= mod;
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd] %= mod;
            lazy[2 * nd + 1] += lazy[nd];
            lazy[2 * nd + 1] %= mod;
        }
        lazy[nd] = 0;
    }
    void update(int l, int r, long long val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, long long val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] += val;
            lazy[nd] %= mod;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = (a[2 * nd] + a[2 * nd + 1]) % mod;
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) 
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return (query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r)) % mod;
        }
    }
};
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // use stack algo + prefsum + lazysegtree
    // lazy segtree -> buat perkalian, maintain perkaliannya perlu berapa
    // kalo ketemu minimum baru, berarti nanti semuanya dikali sama minimum lama gtu kan ya
    // tiap elemen yang di stack minimum tapi posisi sebelum cur, nanti di update jadi new value
    int n;
    cin >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll pref[n + 2];
    pref[0] = 1;
    // mx maintains the maximum so far
    stack<int> mx, mn;
    ll res = 0;
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        ll mini = a[i], maxi = a[i];
        bool first = 1;
        while(mx.size() && a[i] >= a[mx.top()]) {
            // update semua elemen antara cur dan tempat dia ke pop dengan jumlah dpnya yg bs didapet di prefsum
            // pasti awalnya itu i - 1 kan posisinya
            // berarti tiap elemen antara i - 1 ke sebelumnya di update
            int cur = mx.top();
            mx.pop();
            int x = 0;
            if(mx.size()) {
                x = mx.top();
            }
            // antara x ke cur itu ganti max
            //cout << a[i] << " " << a[cur] << " " << pref[cur - 1] << " " << pref[x - 1] << endl;
            if(x == 0)
                res += (a[i] - a[cur]) * (pref[cur - 1]);
            else
                res += (a[i] - a[cur]) * (pref[cur - 1] - pref[x - 1]);
            first = 0;
            res %= mod;
        }
        first = 1;
        while(mn.size() && a[i] <= a[mn.top()]) {
            int cur = mn.top();
            mn.pop();
            int x = 0;
            if(mn.size()) {
                x = mn.top();
            }
            // antara x ke cur itu ganti max
            //cout << a[i] << " " << a[cur] << " " << pref[cur - 1] << " " << pref[x - 1] << endl;
            if(x == 0)
                res += (a[cur] - a[i]) * (pref[cur - 1]);
            else
                res += (a[cur] - a[i]) * (pref[cur - 1] - pref[x - 1]);
            res %= mod;
            first = 0;
        }
        //cout << res << " " << dp[i] << endl;
        mx.push(i); mn.push(i);
        pref[i] = pref[i - 1] + res;
        pref[i] %= mod;
    }
    cout << (res + mod) % mod << endl;
    return 0;
}