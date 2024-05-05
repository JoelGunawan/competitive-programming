#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    int s[m + 1], e[m + 1], p[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> s[i] >> e[i] >> p[i];
    }
    long long dp[15005];
    // base case -> 0 (karena ga kerja)
    memset(dp, 0, sizeof(dp));
    // utk tiap posisi e, dia itu bisa startnya mana aja?
    // first -> start
    // second -> honor
    vector<pair<int, int>> v[15005];
    for(int i = 1; i <= m; ++i) {
        v[e[i]].push_back(make_pair(s[i], p[i]));
    }
    for(int i = 1; i <= 15000; ++i) {
        dp[i] = dp[i - 1];
        for(auto p : v[i]) {
            dp[i] = max(dp[i], dp[p.first - 1] + p.second);
        }
    }
    cout << dp[15000] << endl;
}