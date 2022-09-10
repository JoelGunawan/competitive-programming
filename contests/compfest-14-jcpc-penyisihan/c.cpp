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
int mod = 998244353;
const int lim = 3e5 + 5;
ll fact[lim], inv[lim];
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll combinmod(ll a, ll b) {
    if(a < b)
        return 0;
    else
        return (((fact[a] * inv[b]) % mod) * inv[a - b]) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    int n, m;
    cin >> n >> m;
    int d[n];
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    // harus exact opposite, baru right triangle
    // hitung tanpa opposite berapa
    // baru terakhir hitung opposite
    ll total_dist = 0;
    for(int i = 0; i < n; ++i)
        total_dist += d[i];
    if(total_dist & 1)
        cout << powmod(m, n) << endl, exit(0);
    vector<ll> pr = {0};
    for(int i = 0; i < n - 1; ++i) {
        pr.pb(pr.back() + d[i]);
    }
    total_dist >>= 1;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(binary_search(pr.begin(), pr.end(), pr[i] + total_dist))
            ++cnt;
    }
    ll res = 0;
    for(int i = 0; i <= cnt; ++i) {
        res += (((((((combinmod(cnt, i) * combinmod(m, i)) % mod) * fact[i]) % mod) 
        * powmod(m - i, n - 2 * i - (cnt - i))) % mod) * powmod(m - i - 1, cnt - i)) % mod;
    }
    cout << res % mod << endl;
    return 0;
}