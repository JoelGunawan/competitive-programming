#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1000000;
int main()
{
    int n;
    cin >> n;
    ll dp[n + 1];
    if(n < 3)
    {
        cout << 1 << endl;
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1, dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 3]) % mod;
    cout << dp[n] << endl;
    return 0;
}