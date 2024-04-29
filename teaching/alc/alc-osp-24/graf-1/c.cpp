#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
bool vis[100005];
void dfs(int nd) {
  vis[nd] = 1;
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
  int cc = 0;
  vector<int> v;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      v.push_back(i);
      dfs(i);
      ++cc;
    }
  }
  cout << cc - 1 << endl;
  for(int i = 1; i < v.size(); ++i) {
    cout << v[0] << " " << v[i] << endl;
  }
}