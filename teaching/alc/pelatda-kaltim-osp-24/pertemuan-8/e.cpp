#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
bool vis[100005]; // apakah sebuah node sudah dikunjungi
// return banyak node di connected component yg di dfs
int dfs(int nd) {
  vis[nd] = 1;
  cout << "Mengunjungi node: " << nd << endl;
  int jumlah_node = 1;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      jumlah_node += dfs(x);
    }
  }
  return jumlah_node;
}
int main() {
  int n, m;
  cin >> n >> m;
  // anggap undirected
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  cout << "Banyak node: " << dfs(10) << endl;
}