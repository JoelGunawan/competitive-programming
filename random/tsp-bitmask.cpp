#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main() {
    // vektor di indeks ke-i berisi edge yg berasal dari node i
    // fi -> node tujuan, se -> cost
    /*
    4 6
    0 1 10
    0 2 15
    0 3 20
    1 2 35
    1 3 25
    2 3 30
    */
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges[n];
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    int dp[n][1 << n];
    // initialize dp to max
    for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j)
            dp[j][i] = 2e9;
    }
    for(int i = 1; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            if((1 << j) == i) {
                // base case
                dp[j][i] = 0;
            }
            // transisi dp
            for(auto p : edges[j])
                dp[p.fi][i | (1 << p.fi)] = min(dp[p.fi][i | (1 << p.fi)], dp[j][i] + p.se);
        }
    }
    int mn = 2e9;
    for(int j = 0; j < n; ++j) {
        mn = min(mn, dp[j][(1 << n) - 1]);
    }
    cout << mn << endl;
}