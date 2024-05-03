#include <bits/stdc++.h>
using namespace std;
// a ditaruh di variabel global agar mudah di dfs
int a[100005];
bool vis[100005];
vector<int> edges[100005];
// dfs yang mengembalikan nilai minimum a di connected component
int dfs(int nd) {
  vis[nd] = 1;
  int mn = a[nd];
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      mn = min(mn, dfs(i));
    }
  }
  return mn;
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
  // cari untuk setiap connected component, nilai a minimalnya
  // simpan nilai a minimal di dalam vector
  vector<int> min_a;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      int mn = dfs(i);
      min_a.push_back(mn);
    }
  }
  if(min_a.size() > m) {
    cout << -1 << endl;
    return 0;
  }
  long long res = 0;
  int c = min_a.size();
  sort(min_a.begin(), min_a.end());
  sort(b, b + m);
  for(int i = 0; i < c; ++i) {
    res += (long long)min_a[i] * b[c - i - 1];
  }
  cout << res << endl;
}
