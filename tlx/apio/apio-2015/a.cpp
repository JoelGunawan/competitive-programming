#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    ll y[n + 1];
    memset(y, 0, sizeof(y));
    for(int i = 1; i <= n; ++i)
        cin >> y[i];
    // n <= 20, a = 1, y[i] <= 10
    // find a way how we could add a subgroup in each increase in n, which means O(n^2)
    // total time complexity is O(n^3)
    // basically n^2 dp space n * b
    // dp[i][j] saves the minimum cost of segment 1 to i with j different groups
    // we can add from the previous dp by adding new groups
    // the expected dp is O(n^3) i think? since it's O(n) for each state
    ll dp[n + 1][b + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= b; ++j)
            dp[i][j] = (ll)1e15;
    dp[0][0] = 0;
    for(int j = 1; j <= b; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            ll tmp_sum = 0;
            for(int k = i; k > 0; --k)
            {
                tmp_sum += y[k];
                dp[i][j] = min(dp[i][j], (dp[k - 1][j - 1] | tmp_sum));
            }
        }
    }
    /*
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= b; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    ll res = (ll)1e15;
    for(int i = a; i <= b; ++i)
        res = min(res, dp[n][i]);
    cout << res << endl;
    return 0;
}