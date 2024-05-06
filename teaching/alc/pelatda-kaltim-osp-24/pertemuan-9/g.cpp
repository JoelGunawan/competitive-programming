#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool vis[100005];
vector<int> edges[100005];
int dfs(int nd) {
  vis[nd] = 1;
  int ret = a[nd];
  for(auto x : edges[nd]) {
    if(!vis[x])
      ret = min(ret, dfs(x));
  }
  return ret;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int b[m + 1];
  for(int i = 0; i < m; ++i)
    cin >> b[i];
  for(int i = 1; i <= k; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  // utk setiap connected component min a nya berapa
  vector<int> cc;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      cc.push_back(dfs(i));
    }
  }
  sort(cc.begin(), cc.end());
  sort(b, b + m);
  // jika kontraktor tdk cukup utk bangun di setiap connected component
  // diminta utk keluarkan -1
  if(cc.size() > m) {
    cout << -1 << endl;
  }
  else {
    long long res = 0;
    for(int i = 0; i < cc.size(); ++i) {
      res += (long long)cc[i] * b[cc.size() - i - 1];
    }
    cout << res << endl;
  }
}