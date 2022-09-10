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
// fungsi pangkat
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll fact[400005], invfact[400005];
ll combinmod(ll a, ll b) {
    return (((fact[a] * invfact[b]) % mod) * invfact[a - b]) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // C(1000, 500)
    fact[0] = 1, invfact[0] = 1;
    for(int i = 1; i <= 400000; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = powmod(fact[i], mod - 2);
    }
    int n, m, k;
    cin >> n >> m >> k;
    ll res = 0;
    for(int i = 0; i <= k; ++i) {
        res += (m * powmod(m - 1, n - i - 1)) % mod * combinmod(n - 1, i);
        res %= mod;
    }
    cout << res << endl;
}