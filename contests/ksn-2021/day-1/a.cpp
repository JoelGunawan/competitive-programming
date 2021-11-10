#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
ll mod = 1e9 + 7;
ll addmod(ll a, ll b)
{
    return (a + b) % mod;
}
int main()
{
    fast_io();
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    if(m == 1)
    {
        if(n == k)
        {
            ll res = 1;
            for(int i = 0; i < n; ++i)
                if(s[i] == '?')
                    res *= 2;
            cout << res << endl;
        }
        else
            cout << 0 << endl;
        return 0;
    }
    ll dp_a[n + 1][m][k + 1], dp_b[n + 1][m][k + 1];
    memset(dp_a, 0, sizeof(dp_a)), memset(dp_b, 0, sizeof(dp_b));
    dp_a[0][0][0] = 1;
    for(int i = 0; i < n; ++i)
    {
        // error happens when m = 1
        // we are accessing out of bounds
        if(s[i] != 'B')
        {
            // iterate through the B DP
            for(int j = 0; j < m; ++j)
                for(int l = 0; l < k + 1; ++l)
                    dp_a[i + 1][1][l] = addmod(dp_a[i + 1][1][l], dp_b[i][j][l]);
            // iterate through the A DP
            for(int j = 0; j < m; ++j)
                for(int l = 0; l < k + 1; ++l)
                {
                    if(j == m - 1 && l != k)
                        dp_a[i + 1][j][l + 1] = addmod(dp_a[i + 1][j][l + 1], dp_a[i][j][l]);
                    else if(j != m - 1)
                        dp_a[i + 1][j + 1][l] = addmod(dp_a[i + 1][j + 1][l], dp_a[i][j][l]);
                }
        }
        if(s[i] != 'A')
        {
            // iterate through the A DP
            for(int j = 0; j < m; ++j)
                for(int l = 0; l < k + 1; ++l)
                    dp_b[i + 1][1][l] = addmod(dp_b[i + 1][1][l], dp_a[i][j][l]);
            // iterate through the B DP
            for(int j = 0; j < m; ++j)
                for(int l = 0; l < k + 1; ++l)
                {
                    // if j is equal to m, we have a special case
                    // if k is not yet at the limit it is ok
                    // else it is not okay
                    if(j == m - 1 && l != k)
                        dp_b[i + 1][j][l + 1] = addmod(dp_b[i + 1][j][l + 1], dp_b[i][j][l]);
                    else if(j != m - 1)
                        dp_b[i + 1][j + 1][l] = addmod(dp_b[i + 1][j + 1][l], dp_b[i][j][l]);
                }
        }
    }
    /*
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            for(int l = 0; l < k + 1; ++l)
                cout << dp_a[i][j][l] << " ";
            cout << endl;
        }
        cout << endl;
    }
    cout << "SEP" << endl;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            for(int l = 0; l < k + 1; ++l)
                cout << dp_b[i][j][l] << " ";
            cout << endl;
        }
        cout << endl;
    }
    */
    // output all states at state dp[n][x][k]
    //cout << "SEP" << endl;
    ll res = 0;
    for(int i = 0; i < m; ++i)
    {
        //cout << dp_a[n][i][k] << " " << dp_b[n][i][k] << endl;
        res = addmod(res, dp_a[n][i][k]), res = addmod(res, dp_b[n][i][k]);
    }
    cout << (res + mod) % mod << endl;
    return 0;
}