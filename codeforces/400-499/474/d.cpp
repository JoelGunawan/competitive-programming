// header file
#include <bits/stdc++.h>
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
int mod = 1e9 + 7;
ll fact[100001];
ll mulmod(ll a, ll b) {
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = mulmod(tmp, tmp);
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll inv(ll a) {
    return powmod(a, mod - 2);
}
ll combinmod(ll a, ll b) {
    //cout << a << " " << b << endl;
    return mulmod(fact[a], mulmod(inv(fact[b]), inv(fact[a - b])));
}
int main() {
    fact[0] = 1;
    for(int i = 1; i <= 100000; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, k;
    cin >> t >> k;
    ll dp[100001], pref_sum[100001];
    memset(pref_sum, 0, sizeof(pref_sum));
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= 100000; ++i) {
        if(i >= k)
            dp[i] = (dp[i - 1] + dp[i - k]) % mod;
        else
            dp[i] = dp[i - 1];
    }
    for(int i = 1; i <= 100000; ++i) 
        pref_sum[i] = (pref_sum[i - 1] + dp[i]) % mod;
    //for(int i = 1; i <= 5; ++i)
    //    cout << dp[i] << " ";
    //cout << endl;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << ((pref_sum[b] - pref_sum[a - 1]) + mod) % mod << endl;
    }
    return 0;
}