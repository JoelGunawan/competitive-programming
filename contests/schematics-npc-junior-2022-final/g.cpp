#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O2")
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    ll res = 1, tmp2 = a;
    while(b) {
        if(b & 1)
            res *= tmp2, res %= mod;
        tmp2 = (tmp2 * tmp2) % mod;
        b >>= 1;
    }
    return res;
}
int main() {
    // (C(h + w, w) - 1) * val
    // observasi: nilai C g mgkn berubah banyak
    // buat untuk tiap baris aja
    ll m, n;
    scanf("%lld%lld", &m, &n);
    n %= mod;
    ll tmp = n + 1, tmp2 = 1, h, w, in, res = 0, diff;
    int memo[(int)1e6 + 2];
    for(int i = 0; i <= 1e6 + 1; ++i)
        memo[i] = powmod(i, mod - 2);
    for(int i = 0; i < m; ++i) {
        h = i + 1, w = n - i;
        if(w < 0)
            w += mod;
        scanf("%lld", &in);
        in %= mod;
        //cout << tmp << " " << tmp2 << endl;
        res += ((tmp - tmp2) * in) % mod;
        if(res > mod)
            res -= mod;
        else if(res < 0)
            res += mod;
        tmp = (((tmp * w) % mod) * memo[h + 1]) % mod;
        tmp2 = (((tmp2 * memo[h]) % mod) * w) % mod;
    }
    printf("%lld\n", res);
}