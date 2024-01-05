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
    int n = 11;
    int dp[n + 1];
    // initialisasi array memoisasi
    // utk minimum, initialisasi ke maks
    fill(dp, dp + n + 1, 1e9);
    // isi base case
    dp[0] = 0;
    // isi nilai dp dengna 1e9
    for(int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if(i >= 3) {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
        if(i >= 5) {
            dp[i] = min(dp[i], dp[i - 5] + 1);
        }
    }
    cout << dp[11] << endl;
    return 0;
}