#include <bits/stdc++.h>
using namespace std;
const int lim = 3e5 + 5;
bool on[lim], vis[lim];
vector<int> edges[lim];
long long dp[lim][2][2];
void dfs(int nd) {
    vis[nd] = 1;
    if(on[nd])
        dp[nd][1][0] = 1, dp[nd][0][1] = 0;
    else
        dp[nd][0][0] = 0, dp[nd][1][1] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            // case now not pressed
            // awalannya 0
            int x = dp[nd][0][0], y = dp[nd][0][1];
            dp[nd][0][0] = min(dp[i][0][0] + x, dp[i][1][0] + y);
            dp[nd][0][1] = min(dp[i][0][0] + y, dp[i][1][0] + x);
            // case now pressed
            // awalannya 1
            x = dp[nd][1][0], y = dp[nd][1][1];
            dp[nd][1][0] = min(dp[i][0][1] + x, dp[i][1][1] + y);
            dp[nd][1][1] = min(dp[i][0][1] + y, dp[i][1][1] + x);
        } 
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        cin >> on[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 2; ++j)
            dp[i][j][0] = dp[i][j][1] = 1e6;
    }
    // dp on tree
    // cari dr child
    // pake dp[i][1], nandain dp di subtree ini dengan root 1 atau root 0
    // problem -> child bisa effect root
    // nanti ans itu dp[1][0]
    // nanti 4 kemungkinan
    // root 0, root changed
    // root 0, root not changed
    // root 1, root changed
    // root 1, root not changed
    // transisi dp?
    dfs(1);
    if(min(dp[1][1][0], dp[1][0][0]) > n) {
        cout << "impossible" << endl;
    }
    else
        cout << min(dp[1][1][0], dp[1][0][0]) << endl;
}