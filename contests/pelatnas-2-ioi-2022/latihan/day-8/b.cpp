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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // do a dp of size (r - l + 2), k + 1
    // memo count of taken elements and cost already used
    // transisi dp[s][cost] = min(dp[s][cost], dp[s - 1][cost - (position difference)] + A[i]);
    int dp[2][r - l + 2][k + 1];
    memset(dp, -1, sizeof(dp));
    for(int tmp = 0; tmp < 2; ++tmp)
        for(int i = 0; i <= r - l + 1; ++i)
            for(int j = 0; j <= k; ++j)
                dp[tmp][i][j] = 1e9;
    dp[0][0][0] = 0;
    for(int cur = 1; cur <= n; ++cur) {
        for(int i = 0; i <= r - l + 1; ++i)
            for(int j = 0; j <= k; ++j) {
                int dist = abs(cur - (l + i - 1));
                dp[cur % 2][i][j] = dp[(cur + 1) % 2][i][j];
                if(i > 0 && j >= dist)  
                    dp[cur % 2][i][j] = min(dp[cur % 2][i][j], dp[(cur + 1) % 2][i - 1][j - dist] + a[cur]);
            }
    }
    int res = INT_MAX;
    for(int i = 0; i <= k; ++i)
        res = min(res, dp[n % 2][r - l + 1][i]);
    cout << res << endl;
    return 0;
}