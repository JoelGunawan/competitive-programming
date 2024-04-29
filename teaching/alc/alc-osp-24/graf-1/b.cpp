#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj[105];
void dfs(int nd) {
  vis[nd] = 1;
  cout << "KUNJUNGI NODE " << nd << endl;
  for(int i = 0; i < adj[nd].size(); ++i) {
    if(!vis[adj[nd][i]]) {
      dfs(adj[nd][i]);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
}