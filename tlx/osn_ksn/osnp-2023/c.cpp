#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int lim = 1e5 + 5;
int val[lim];
bool vis[lim];
vector<int> edges[lim];
int dfs(int nd) {
  vis[nd] = 1;
  int ret = val[nd];
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      ret = min(ret, dfs(i));
    }
  }
  return ret;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> b(m);
  for(int i = 1; i <= n; ++i)
    cin >> val[i];
  for(int i = 0; i < m; ++i)
    cin >> b[i];
  for(int i = 1; i <= k; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  vector<int> cc;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      cc.push_back(dfs(i));
    }
  }
  sort(cc.begin(), cc.end());
  sort(b.begin(), b.end());
  if(b.size() < cc.size()) {
    cout << -1 << endl;
  }
  else {
    while(b.size() > cc.size())
      b.pop_back();
    ll res = 0;
    for(int i = 0; i < cc.size(); ++i) {
      res += 1ll * cc[i] * b[b.size() - i - 1];
    }
    cout << res << endl;
  }
}