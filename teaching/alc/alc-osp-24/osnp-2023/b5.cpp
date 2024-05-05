#include <bits/stdc++.h>
using namespace std;
int m, a[105];
vector<int> edges[105];
long long dp[105][100005];
bool vis[105];
int mod = 1e9;
void dfs(int nd) {
    vis[nd] = 1;
    dp[nd][a[nd]] = 1;
    for(auto x : edges[nd]) {
        if(!vis[x]) {
            dfs(x);
            for(int i = 1; i <= m; ++i) {
                if(i - a[nd] >= 0) {
                    dp[nd][i] += dp[x][i] + dp[x][i - a[nd]];
                }
                else {
                    dp[nd][i] += dp[x][i];
                }
                dp[nd][i] %= mod;
            }
        }
    }
}
int main() {
    int n;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    long long cur = 0;
    for(int i = 1; i <= m; ++i) {
        cur += dp[1][i];
        cur %= mod;
        cout << cur << endl;
    }
}