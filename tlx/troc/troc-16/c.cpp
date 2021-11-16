#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp *= tmp; tmp %= mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    ll dp[n][m];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < m; ++i)
        dp[0][i] = 1;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            for(int k = 0; k < m - 1; ++k)
                dp[i][j] += dp[i - 1][k];
            if(j != m - 1)
                dp[i][j] += dp[i - 1][m - 1];
            dp[i][j] %= mod;
        }
    }
    ll res = 0;
    for(int i = 0; i < m; ++i)
        res += dp[n - 1][i], res %= mod;
    cout << (res - powmod(m - 1, n) + mod) % mod << endl;
    return 0;
}