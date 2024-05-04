#include <bits/stdc++.h>
using namespace std;
vector<int> edges[200005];
bool vis[200005];
int subtree[200005];
void dfs(int nd) {
  vis[nd] = 1;
  subtree[nd] = 1; // (node ini sendiri)
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      dfs(x);
      subtree[nd] += subtree[x];
    }
  }
}
int main() {
  int n;
  cin >> n;
  // n - 1 edge
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1);
  for(int i = 1; i <= n; ++i) {
    cout << subtree[i] << " ";
  }
  cout << endl;
}