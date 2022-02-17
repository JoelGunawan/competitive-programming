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
void tc() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int x;
    cin >> x;
    // observations:
    // not always optimal to choose a[i] >= x
    // answer is always at least ceil(n / 2)
    // we need to "merge" sequences so that we can select more
    // if the average of 2 adjacent sequences are okay, then we can merge them
    // merge requirements: 
    // subsegment must not have adjacent elements that are < x
    // fi is pos, se is mask of prev elements
    ll dp[n][4];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][2], dp[i - 1][0]);
        if(i > 1)
            dp[i][0] = max(dp[i][0], max(dp[i - 2][1], dp[i - 2][3]));
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        if(i > 1)
            dp[i][1] = max(dp[i][1], dp[i - 2][3] + 1);
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]);
        if(a[i] + a[i - 1] >= 2 * x)
            dp[i][3] = dp[i - 1][1] + 1;
        if(i >= 2 && a[i] + a[i - 1] >= 2 * x && a[i] + a[i - 1] + a[i - 2] >= 3 * x)
            dp[i][3] = max(dp[i][3], dp[i - 1][3] + 1);
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]))) << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}