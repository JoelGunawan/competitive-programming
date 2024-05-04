#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> edges[n + 1];
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  // seringkali, buat bfs harus pake pair<int, int> yg pertama -> node, kedua -> jarak dari awal
  queue<pair<int, int>> bfs;
  bfs.push(make_pair(1, 0));
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  while(bfs.size() > 0) {
    int nd = bfs.front().first;
    int jarak = bfs.front().second;
    bfs.pop();
    if(vis[nd]) {
      continue;
      // langsung kembali ke awal while loop (cek bfs.size() > 0)
    }
    vis[nd] = 1;
    cout << "node " << nd << " memiliki jarak " << jarak << endl;
    for(auto x : edges[nd]) {
      if(!vis[x]) {
        bfs.push(make_pair(x, jarak + 1));
      }
    }
  }
}