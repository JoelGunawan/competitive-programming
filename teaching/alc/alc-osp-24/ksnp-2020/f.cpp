#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// a^b modulo mod
long long powmod(long long a, long long b) {
    if(b == 0) {
        return 1;
    }
    else {
        long long tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    long long dp[n + 1], pref[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i) {
        if(i - k < 0)
            dp[i] = pref[i - 1] * (m - 1);
        else
            dp[i] = (pref[i - 1] - pref[i - k]) * (m - 1); 
        // khusus untuk awalan
        if(i < k)
            dp[i] += m;
        dp[i] %= mod;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
    }
    long long res = powmod(m, n) - dp[n];
    res += 2 * mod;
    res %= mod;
    cout << res << endl;
}