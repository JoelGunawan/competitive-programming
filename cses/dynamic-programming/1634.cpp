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
    int n, x;
    cin >> n >> x;
    int c[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    int dp[x + 1];
    fill(dp, dp + x + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    cout << (dp[x] > x ? -1 : dp[x]) << endl;
    return 0;
}