#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int m;
    cin >> m;
    vector<pair<int, int>> end[15002];
    for(int i = 0; i < m; ++i)
    {
        int s, e, p;
        cin >> s >> e >> p;
        end[e + 1].push_back({s, p});
    }
    ll dp[15002];
    dp[0] = 0;
    for(int i = 1; i <= 15001; ++i)
    {
        dp[i] = dp[i - 1];
        for(int j = 0; j < end[i].size(); ++j)
            dp[i] = max(dp[i], dp[end[i][j].first] + end[i][j].second);
    }
    cout << dp[15001] << endl;
    return 0;
}