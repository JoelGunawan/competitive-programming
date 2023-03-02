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
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
const int lim = 3e5 + 5;
ll fact[lim], inv[lim];
ll combinmod(ll a, ll b) {
    return mul(fact[a], mul(inv[a - b], inv[b]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int w[n + 1];
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    for(int i = 1; i <= n; ++i)
        cin >> w[i];
    ll res = combinmod(n / 3, n / 6);
    for(int i = 1; i <= n; i += 3) {
        vector<int> tmp;
        for(int j = i; j < i + 3; ++j)
            tmp.pb(w[j]);
        sort(tmp.begin(), tmp.end());
        if(tmp[0] == tmp[2])
            res = (res * 3) % mod;
        else if(tmp[0] == tmp[1])
            res = (res * 2) % mod;
    }
    cout << res << endl;
    return 0;
}