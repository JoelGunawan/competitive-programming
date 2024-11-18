// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim];
vector<int> cur;
void dfs(int nd) {
  vis[nd] = 1;
  cur.pb(nd);
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int b[n + 1], g[m + 1];
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  for(int i = 1; i <= m; ++i)
    cin >> g[i];
  for(int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  sort(g + 1, g + m + 1);
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      cur.clear();
      dfs(i);
      for(auto &x : cur) 
        x = b[x];
      sort(cur.begin(), cur.end());
      // find closest smaller and closest larger
      int l, r;
      if(cur.size() == 0)
        continue;
      if(cur.size() & 1)
        l = r = cur[cur.size() / 2];
      else 
        l = cur[cur.size() / 2 - 1], r = cur[cur.size() / 2];
      // find closest to L and closest to R
      ll ref1, ref2;
      if(lb(g + 1, g + m + 1, l) != g + m + 1)
        ref1 = *lb(g + 1, g + m + 1, l);
      else
        ref1 = g[m];
      if(lb(g + 1, g + m + 1, l) != g + 1)
        ref2 = g[lb(g + 1, g + m + 1, l) - g - 1];
      else
        ref2 = g[1];
      // cerr << "CUR " << ref << endl;
      ll res1 = 0, res2 = 0;
      for(auto x : cur) {
        // cerr << x << " ";
        res1 += abs(x - ref1);
        res2 += abs(x - ref2);
      }
      res += min(res1, res2);
      // cerr << endl;
    }
  }
  cout << res << endl;
  return 0;
}