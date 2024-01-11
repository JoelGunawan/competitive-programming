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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e5 + 5, lim2 = 1e2 + 5;
// path rooted at index nd, with v breadcrumbs used
vector<int> edges[lim];
bool vis[lim];
int par[lim];
ll res, dp[lim][lim2], v, a[lim];
void dfs(int nd) {
  vis[nd] = 1;
  // take
  vector<int> child;
  ll sum = 0;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      par[i] = nd;
      dfs(i);
      sum += a[i];
      child.pb(i);
    }
  }
  ll prmx[v + 1], prmx2[v + 1];
  memset(prmx, 0, sizeof(prmx));
  memset(prmx2, 0, sizeof(prmx2));
  for(auto i : child) {
      // transition
      for(int j = 0; j <= v; ++j) {
        // case current is root and combine 2 paths (with root not taken)
        res = max(res, dp[i][j] + prmx[v - j]);
        // case current is root and combine 2 paths (with root taken)
        if(v - j - 1 >= 0)
          res = max(res, dp[i][j] + sum + a[par[nd]] + prmx2[v - j - 1] - a[i]);
        // case current is root and only single path (not combin of 2 paths), not taken
        res = max(res, dp[i][j]);
        // case current is root, only single path, and taken
        if(j != 0)
          res = max(res, dp[i][j - 1] + sum + a[par[nd]] - a[i]);
        // "base transition" for simplicity sake
        if(j != 0)
          dp[nd][j] = max(dp[nd][j], dp[nd][j - 1]);
        // not take
        dp[nd][j] = max(dp[nd][j], dp[i][j]);
        // take
        if(j != 0)
          dp[nd][j] = max(dp[nd][j], dp[i][j - 1] + sum - a[i]);
      }
      for(int j = 1; j <= v; ++j) {
        prmx[j] = max(prmx[j], dp[i][j]);
        prmx2[j] = max(prmx2[j], dp[i][j] - a[i]);
      }
  }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n >> v;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    for(int i = 1; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      edges[a].pb(b);
      edges[b].pb(a);
    }
    dfs(1);
    cout << res << endl;
    return 0;
}