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
int memo[1001], pref_memo[1001];
void tc() {
    int n, k;
    cin >> n >> k;
    int b[n + 1], c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    // convert b[i] to amount of operations necessary
    int sum = 0;
    for(int i = 1; i <= n; ++i)
        b[i] = memo[b[i]], sum += b[i];
    // pair of price, weight
    // O(n^2) algo
    // consider dp[n][n]
    // either include or not include
    //for(int i = 1; i <= n; ++i)
    //    cout << b[i] << " ";
    //cout << endl;
    int dp[n + 1][min(sum, k) + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= min(sum, k); ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j >= b[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - b[i]] + c[i]);
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][min(sum, k)] << endl;
}
bool f(int a, int b) {
    // find a way from b such that a = b + b / x
    int l = 1, r = b;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(b + b / mid == a)
            return 1;
        else if(b + b / mid < a) 
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memo[1] = 0;
    int res = 0, sum = 0;
    for(int i = 2; i <= 1000; ++i) {
        memo[i] = INT_MAX;
        for(int j = i / 2; j < i; ++j) {
            // find x such that floor(j / x) = (i - j)
            // if it exists then go
            if(f(i, j))
                memo[i] = min(memo[i], memo[j] + 1);
        }
    }
    for(int i = 1; i <= 1000; ++i)
        pref_memo[i] = pref_memo[i - 1] + memo[i];
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}