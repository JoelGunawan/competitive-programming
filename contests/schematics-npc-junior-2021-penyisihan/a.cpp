#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int dp[1001][1001];
void filldp()
{
    for(int i = 0; i < 1001; ++i)
        dp[i][0] = 1, dp[0][i] = 1;
    for(int i = 1; i < 1001; ++i)
    {
        for(int j = 1; j < 1001; ++j)
        { 
            
        }
    }
}
void solve()
{
    int m, n;
    cin >> m >> n;


}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}