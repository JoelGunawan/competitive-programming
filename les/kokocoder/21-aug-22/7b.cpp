#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int w[k + 1], h[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> w[i] >> h[i];
    int dp[k + 1][n + 1];
    pair<int, int> pr[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(j - w[i] < 0 || dp[i - 1][j] >= dp[i - 1][j - w[i]] + h[i])
                pr[i][j] = {i - 1, j}, dp[i][j] = dp[i - 1][j];
            else
                pr[i][j] = {i - 1, j - w[i]}, dp[i][j] = dp[i - 1][j - w[i]] + h[i];
        }
    }
    int berat_min = n;
    for(int i = n - 1; i >= 0; --i) {
        if(dp[k][i] == dp[k][n])
            berat_min = i;
    }
    pair<int, int> cur = {k, berat_min};
    vector<int> res;
    while(cur != make_pair(0, 0)) {
        if(cur.second != pr[cur.first][cur.second].second)
            res.push_back(cur.first);
        cur = pr[cur.first][cur.second];
    }
    reverse(res.begin(), res.end());
    for(auto i : res)
        cout << i << endl;
}