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
int a[4001][4001];
ll prefsum[4001][4001];
ll dp[801][4001];
ll get_cost(int l, int r) {
    return (prefsum[r][r] - prefsum[l - 1][r] - prefsum[r][l - 1] + prefsum[l - 1][l - 1]) / 2;
}
void calc(int depth, int l, int r, int optl, int optr) {
    if(l > r)
        return;
    if(l == r) {
        // calc dp value only
        for(int i = optl; i <= optr && i < l; ++i) {
            dp[depth][l] = min(dp[depth][l], dp[depth - 1][i] + get_cost(i + 1, l));
        }
        return;
    }
    ll tmp = 0;
    // calc opt and dp val
    int m = (l + r) / 2;
    for(int i = optl; i < m && i <= optr; ++i) {
        if(get_cost(i + 1, m) + dp[depth - 1][i] < dp[depth][m]) {
            tmp = i;
            dp[depth][m] = dp[depth - 1][i] + get_cost(i + 1, m);
        }
    }
    calc(depth, l, m - 1, optl, tmp);
    calc(depth, m + 1, r, tmp, optr);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            prefsum[i][j] = prefsum[i][j - 1] + prefsum[i - 1][j] - prefsum[i - 1][j - 1] + a[i][j];
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = 1e10;
    dp[0][0] = 0;
    for(int i = 1; i <= k; ++i)
        calc(i, 1, n, 0, n);
    cout << dp[k][n] << endl;
    return 0;
}