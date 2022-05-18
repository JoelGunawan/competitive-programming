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
const int lim = 1e6 + 25;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
bool prime[lim];
vector<int> prime_factors[lim];
// prime factors cnt is for f0
void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i < lim; ++i) {
        if(prime[i]) {
            prime_factors[i].pb(i);
            for(int j = 2 * i; j < lim; j += i)
                prime[j] = 0, prime_factors[j].pb(i);
        }
    }
}
ll fact[lim], inv[lim];
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll c(ll a, ll b) {
    return mul(fact[a], mul(inv[a - b], inv[b]));
}
ll sub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    int q;
    cin >> q;
    sieve();
    while(q--) {
        ll d, n;
        cin >> d >> n;
        ll res = 1;
        for(auto i : prime_factors[n]) {
            ll tmp = n, cnt = 0;
            while(tmp % i == 0)
                tmp /= i, ++cnt;
            res = mul(res, sub(mul(2, c(d + cnt, cnt)), c(d + cnt - 1, cnt)));
            res %= mod;
            res += mod;
            res %= mod;
        }
        cout << res << endl;
    }
    return 0;
}