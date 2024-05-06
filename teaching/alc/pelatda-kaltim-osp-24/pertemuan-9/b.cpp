#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges[n + 1];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
  }
  // seringkali, buat bfs harus pake pair<int, int> yg pertama -> node, kedua -> jarak dari awal
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, 1));
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  while(pq.size() > 0) {
    int jarak = pq.top().first;
    int nd = pq.top().second;
    pq.pop();
    if(vis[nd]) {
      continue;
      // langsung kembali ke awal while loop (cek bfs.size() > 0)
    }
    vis[nd] = 1;
    cout << "node " << nd << " memiliki jarak " << jarak << endl;
    for(auto x : edges[nd]) {
      if(!vis[x.first]) {
        // first -> jarak
        // second -> node
        pq.push(make_pair(jarak + x.second, x.first));
      }
    }
  }
}