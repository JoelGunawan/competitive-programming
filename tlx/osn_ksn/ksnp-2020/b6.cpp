#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll dp[n + 1];
    // dp[i] = max dp without having segment of size k
    ll pref[n + 1];
    memset(pref, 0, sizeof(pref));
    memset(dp, 0, sizeof(dp));
    pref[0] = dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        dp[i] = mul(pref[i - 1] - (i - k < 0 ? pref[0] : pref[i - k]), m - 1);
        if(i - k + 1 <= 0) {
            dp[i] = (dp[i] + m) % mod;
        }
        pref[i] = (pref[i - 1] + dp[i]) % mod;
        //cout << dp[i] << " ";
    }
    //cout << endl;
    // create segment of size k, which can be of any color
    // rest can be anything
    ll res = 0;
    for(int i = 0; i <= n; ++i) {
        if(i + k <= n) {
            if(i != 0)
                res = (res + mul(dp[i], mul(m - 1, powmod(m, n - (i + k))))) % mod;
            else
                res = (res + mul(m, powmod(m, n - (i + k)))) % mod;
        }
    }
    res %= mod;
    if(res < 0)
        res += mod;
    cout << res % mod << endl;
    return 0;
}