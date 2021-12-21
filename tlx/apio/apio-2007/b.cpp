#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int dp[3][k + 1];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j <= k; ++j)
            dp[i][j] = 2e9;
    dp[0][0] = 0;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j <= min(i / 2 + 1, k); ++j)
        {
            if(j == 0)
                dp[i % 3][j] = dp[(i + 2) % 3][j];
            else if(i == 1)
            {
                if(j == 1)
                    dp[i][j] = min(dp[(i + 2) % 3][j], a[i] - a[i - 1]);
                else
                    dp[i][j] = 2e9;
            }
            else
                dp[i % 3][j] = min(dp[(i + 2) % 3][j], dp[(i + 1) % 3][j - 1] + a[i] - a[i - 1]);
        }
    cout << dp[(n - 1) % 3][k] << endl;
    return 0;
}