#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int lim = 1e3 + 5;
bool vis[lim];
vector<int> edges[lim];
void dfs(int nd) {
  vis[nd] = 1;
  cout << nd << endl;
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
    edges[u].pb(v);
    edges[v].pb(u);
  }
  int x;
  cin >> x;
  dfs(x);
}