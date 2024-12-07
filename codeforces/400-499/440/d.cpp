#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
// dp[nd][i] -> min cc to make subtree of nd have i nodes
const int lim = 405;
vector<int> edges[lim];
int dp[lim][lim];
vector<pair<int, int>> pr[lim][lim];
bool vis[lim];
void dfs(int nd) {
  vis[nd] = 1;
  dp[nd][1] = 0;
  for(auto c : edges[nd]) {
    if(vis[c])
      continue;
    dfs(c);
    int nx[lim];
    vector<pair<int, int>> nxpr[lim];
    fill(nx, nx + lim, lim);
    for(int i = 0; i < lim; ++i) {
      for(int j = 0; j <= i; ++j) {
        // combine both cases
        if(dp[c][j] + dp[nd][i - j] < nx[i])
          nxpr[i] = pr[nd][i - j], nxpr[i].pb(mp(c, j));
        nx[i] = min(nx[i], dp[c][j] + dp[nd][i - j]);
      }
      // cut off
      if(nx[i] > dp[nd][i] + 1)
        nxpr[i] = pr[nd][i];
      nx[i] = min(nx[i], dp[nd][i] + 1);
    }
    for(int i = 0; i < lim; ++i)
      dp[nd][i] = nx[i], pr[nd][i] = nxpr[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> adj;
  for(int i = 0; i < lim; ++i)
    fill(dp[i], dp[i] + lim, lim);
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj.pb(mp(u, v));
    edges[u].pb(v);
    edges[v].pb(u);
  }
  dfs(1);
  pair<int, int> mn = mp(lim, lim);
  for(int i = 1; i <= n; ++i)
    mn = min(mn, mp(dp[i][k] + (i != 1), i));
  // backtrack
  // how the fuck do you backtrack :pensive:
  queue<pair<int, int>> q;
  q.push(mp(mn.se, k));
  vector<int> v;
  while(q.size()) {
    int curx = q.front().fi, cury = q.front().se;
    q.pop();
    v.pb(curx);
    for(auto x : pr[curx][cury])
      q.push(x);
  }
  sort(v.begin(), v.end());
  vector<int> ans;
  // cerr << mn.fi << " " << mn.se << endl;
  // for(auto x : v)
  //   cerr << x << " ";
  // cerr << endl;
  for(int i = 0; i < adj.size(); ++i) {
    if(binary_search(v.begin(), v.end(), adj[i].fi) != binary_search(v.begin(), v.end(), adj[i].se))
      ans.pb(i + 1);
  }
  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}