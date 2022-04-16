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
int mod = 998244353;
ll fact[5005];
ll invfact[5005];
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mulmod(ll a, ll b) {
    return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
    if(a < 0 || b < 0)
        return 0;
    return mulmod(fact[a], mulmod(invfact[b], invfact[a - b]));
}
void tc() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    reverse(a, a + n);
    int cnt = 0;
    vector<int> b;
    for(int i = 0; i < n; ++i) {
        if(i != 0 && a[i] != a[i - 1])  
            b.pb(cnt), cnt = 0;
        ++cnt;
    }
    b.pb(cnt);
    // for each number
    ll dp[2][n / 2 + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    int sum = 0;
    for(int i = 0; i < b.size(); ++i) {
        // transisi 2 tipe
        // tambah atau ga tambah
        for(int j = 0; j <= n / 2; ++j) {
            int unoccupied = j - (sum - j) - 1;
            if(j == n / 2)
                ++unoccupied;
            dp[i % 2][j] = dp[(i + 1) % 2][j] * combinmod(unoccupied, b[i]);
            if(j > 0) {
                if(j - 1 == 0)
                    unoccupied = (j - 1) - (sum - (j - 1));
                else
                    unoccupied = (j - 1) - (sum - (j - 1)) - 1;
                dp[i % 2][j] += dp[(i + 1) % 2][j - 1] * combinmod(unoccupied, b[i] - 1);
            }
            //cout << unoccupied << " ";
            dp[i % 2][j] %= mod;
        }
        //cout << endl;
        for(int j = 0; j <= n / 2; ++j)
            dp[(i + 1) % 2][j] = 0;
        //cout << endl;
        sum += b[i];
    }
    cout << dp[(b.size() + 1) % 2][n / 2] << endl;
}

int main() {
    fact[0] = 1, invfact[0] = powmod(fact[0], mod - 2);
    for(int i = 1; i < 5005; ++i)
        fact[i] = (fact[i - 1] * i) % mod, invfact[i] = powmod(fact[i], mod - 2);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}