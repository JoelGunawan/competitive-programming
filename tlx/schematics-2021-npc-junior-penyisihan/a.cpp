#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int dp[1001][1001];
int mod = 1e9 + 7;
void filldp()
{
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 1001; ++i)
        dp[0][i] = 1;
    for(int i = 1; i < 1001; ++i)
    {
        for(int j = 1; j < 1001; ++j)
        { 
            dp[i][j] = dp[i][j - 1];
            if(i >= j)
                dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
        }
    }
}
void solve()
{
    int m, n;
    cin >> m >> n;
    cout << dp[m][n] << endl;
}
int main()
{
    filldp();
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}