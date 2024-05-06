#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> edges[105];
int a[105], mod = 1e9, m;
long long dp[105][100005];
bool vis[105];
void dfs(int nd) {
  vis[nd] = 1;
  dp[nd][a[nd]] = 1;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      dfs(x);
      for(int i = 1; i <= m; ++i) {
        // i - a[i] harus >= 0
        dp[nd][i] += dp[x][i];
        if(i - a[nd] >= 0)
          dp[nd][i] += dp[x][i - a[nd]];
        dp[nd][i] %= mod;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1);
  long long sementara = 0;
  for(int i = 1; i <= m; ++i) {
    sementara += dp[1][i];
    sementara %= mod;
    cout << sementara << endl;
  }
}