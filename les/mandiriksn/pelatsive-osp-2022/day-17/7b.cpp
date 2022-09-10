#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int h[k + 1], w[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> w[i] >> h[i];
    int dp[k + 1][n + 1];
    pair<int, int> pr[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(j >= w[i] && dp[i - 1][j - w[i]] + h[i] > dp[i - 1][j])
                dp[i][j] = dp[i - 1][j - w[i]] + h[i], pr[i][j] = {i - 1, j - w[i]};
            else
                dp[i][j] = dp[i - 1][j], pr[i][j] = {i - 1, j};
        }
    }
    // harga jual total maksimum, berat minimum
    // first -> pos, second -> berat
    pair<int, int> x = {k, 0};
    for(int i = 1; i <= n; ++i) {
        if(dp[k][x.second] < dp[k][i])
            x.second = i;
    }
    vector<int> dibeli;
    while(x.first != 0) {
        // previousnya x itu berkurang atau tidak
        if(x.second != pr[x.first][x.second].second)
            dibeli.push_back(x.first);
        x = pr[x.first][x.second];
    }
    reverse(dibeli.begin(), dibeli.end());
    for(auto i : dibeli)
        cout << i << endl;
}