#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edge_list;
  // pair<int, int> x;
  // akses pertama -> x.first
  // akses kedua -> x.second
  vector<int> adj[n + 1];
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    pair<int, int> x;
    x.first = u;
    x.second = v;
    edge_list.push_back(x);
    // atau edge_list.push_back(make_pair(u, v))
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  /*
  for(int i = 0; i < m; ++i) {
    cout << edge_list[i].first << " " << edge_list[i].second << endl;
  }
  for(int i = 1; i <= n; ++i) {
    cout << "Node yang adjacent dengan node " << i << " adalah:" << endl;
    for(int j = 0; j < adj[i].size(); ++j) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
  */
 // bfs dari node 1
 queue<int> bfs;
 bfs.push(1);
 bool vis[n + 5];
 memset(vis, 0, sizeof(vis));
 while(bfs.size()) {
  int nd = bfs.front();
  bfs.pop();
  if(vis[nd]) {
    continue;
  }
  vis[nd] = 1;
  cout << nd << endl;
  for(int i = 0; i < adj[nd].size(); ++i) {
    if(!vis[adj[nd][i]])
      bfs.push(adj[nd][i]);
  }
 }
}