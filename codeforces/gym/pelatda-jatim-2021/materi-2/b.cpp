#include <bits/stdc++.h>
#define ll long long
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    ll dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ll prefix[k + 1];
    for(int i = 1; i <= n; ++i)
    {
        // fill prefix
        for(int j = 0; j < k + 1; ++j)
        {
            prefix[j] = dp[i - 1][j];
            if(j != 0)
                prefix[j] += prefix[j - 1];
            prefix[j] %= mod;
        }    
        // add by sum between cur and max(b[i] - cur, 0)
        for(int j = 0; j <= k; ++j)
        {
            if(j - b[i] <= 0)
                dp[i][j] = prefix[j];
            else
                dp[i][j] = prefix[j] - prefix[(j - b[i] - 1)];
            dp[i][j] %= mod;
        }
    }
    cout << (dp[n][k] + mod) % mod << endl;
    return 0;
}