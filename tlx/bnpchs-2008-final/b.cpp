#include <bits/stdc++.h>
//#define endl "\n"
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int mod = 1e6 + 7;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    scanf("%d", &t);
    int a = 200, b = 200 * 199 / 2, dp[a + 1][b + 1], prefix;
    dp[1][0] = 1;
    for(int i = 2; i <= a; ++i)
    {
        prefix = 0;
        for(int j = 0; j <= i * (i - 1) / 4; ++j)
        {
            prefix += dp[i - 1][min((i - 2) * (i - 1) / 2 - j, j)];
            if(j >= i)
                prefix -= dp[i - 1][min((i - 2) * (i - 1) / 2 - (j - i), j - i)];
            prefix = (prefix + mod) % mod;
            dp[i][j] = prefix;
        }
    }
    int n, k;
    while(t--)
    {
        scanf("%d%d", &n, &k);
        printf("%d\n", dp[n][min(n * (n - 1) / 2 - k, k)]);
    }
    return 0;
}