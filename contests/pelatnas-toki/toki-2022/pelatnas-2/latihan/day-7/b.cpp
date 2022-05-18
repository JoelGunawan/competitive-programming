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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll r, n, m;
    cin >> r >> n >> m;
    ll dp[n + 5];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1, dp[1] = 1;
    dp[0] %= m;
    dp[1] %= m;
    for(int i = 2; i <= n - 1; ++i) {
        for(int j = 0; j < i; ++j) 
            dp[i] += (dp[j] * dp[i - j - 1]) % m;
        dp[i] %= m;
    }
    cout << dp[n - 1] % m << endl;
    return 0;
}