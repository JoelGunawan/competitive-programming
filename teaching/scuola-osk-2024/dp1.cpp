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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n = 10;
    // array memoisasi
    int dp[n + 1];
    // set nilai array ke 0
    memset(dp, 0, sizeof(dp));
    // bottom up, initialisasi base case
    dp[0] = 1;
    // mulai transisi dari base case ke akhir
    for(int i = 1; i <= n; ++i) {
        dp[i] += dp[i - 1];
        // dp[-...] = 0
        if(i >= 2)
            dp[i] += dp[i - 2];
        if(i >= 4) 
            dp[i] += dp[i - 4];
    }
    cout << dp[10] << endl;
    return 0;
}