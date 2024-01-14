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
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 1e9;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        // case 1
        int pr = i;
        while(a[i] <= a[pr - 1] && pr >= 1) {
            dp[i] += dp[pr - 1];
            dp[i] %= mod;
            --pr;
        }
        // case 2
        int mn = a[i];
        for(int j = i - 1; j >= 1; --j) {
            mn = min(mn, a[j]);
            if(mn == a[j]) {
                dp[i] += dp[j];
                dp[i] %= mod;
            }
        }
        // cout << dp[i] << " ";
    }
    // cout << endl;
    int mn = a[n];
    ll res = 0;
    for(int i = n; i >= 1; --i) {
        mn = min(mn, a[i]);
        if(mn == a[i]) 
            res = (res + dp[i]) % mod;
    }
    cout << res << endl;
}