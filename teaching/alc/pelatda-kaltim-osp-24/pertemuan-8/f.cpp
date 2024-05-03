#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
bool vis[100005]; // menandakan apakah sebuah node sudah dikunjungi
void dfs(int nd) {
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
      dfs(i);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  // vector yg berisi 1 node dr masing" connected component
  vector<int> cc;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      dfs(i);
      cc.push_back(i);
    }
  }
  // edge baru yg harus dibuat ada sebanyak cc.size() - 1
  // edge yg dibuat bisa (cc[0], cc[1]), (cc[0], cc[2]), ...
  cout << cc.size() - 1 << endl;
  for(int i = 1; i < cc.size(); ++i) {
    cout << cc[0] << " " << cc[i] << endl;
  }
}