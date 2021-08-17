#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[--u].push_back(--v);
        edges[v].push_back(u);
    }
    for(int i = 0; i < n; ++i)
        edges[i].push_back(i);
    vector<vector<ll>> dp(2, vector<ll>(n, 0));
    dp[1][0] = 1;
    for(int i = 0; i < k; ++i)
    {
        ll base = 0;
        for(int j = 0; j < n; ++j)
            base += dp[(i + 1) % 2][j], base %= mod;
        for(int j = 0; j < n; ++j)
        {
            dp[i % 2][j] = base;
            for(int k = 0; k < edges[j].size(); ++k)
                dp[i % 2][j] -= dp[(i + 1) % 2][edges[j][k]], dp[i % 2][j] %= mod;
            dp[i % 2][j] += mod, dp[i % 2][j] %= mod;
        }
    }
    cout << dp[(k - 1) % 2][0] << endl;
    return 0;
}