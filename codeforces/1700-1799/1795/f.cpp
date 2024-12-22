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
const int lim = 2e5 + 5;
vector<int> edges[lim];
int val[lim], dp[lim];
bool vis[lim];
bool dfs(int nd) {
  // cerr << "DFS " << nd << endl;
  vis[nd] = 1;
  int def = 0;
  if(val[nd] <= 0)
    ++def;
  bool cur = 1;
  int maxc = 0;
  int need = 0;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      cur &= dfs(i);
      if(dp[i] < 0)
        ++def, need = dp[i];
      if(!cur)
        return false;
      if(def > 1)
        return false;
      maxc = max(maxc, dp[i]);
    }
  }
  if(val[nd] > 0) {
    if(def)
      dp[nd] = (maxc + 1 + need >= 0 ? 0 : need + 1); // try to satisfy child needs using subtree if unable, just use cur and let par handle
    else
      dp[nd] = maxc + 1; // extend longest path
  }
  else
    dp[nd] = (maxc + val[nd] >= 0 ? 0 : val[nd]); // check maxc, if it satisfies
  // cerr << nd << " " << val[nd] << " " << dp[nd] << endl;
  return cur;
}
void tc() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    edges[i].clear();
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  int k;
  cin >> k;
  int a[k];
  set<int> non_spec;
  for(int i = 1; i <= n; ++i)
    non_spec.ins(i);
  for(int i = 0; i < k; ++i) {
    cin >> a[i];
    non_spec.erase(a[i]);
  }
  vector<int> v;
  for(auto x : non_spec)
    v.pb(x);
  int cl = 1, cr = n, ans = 0;
  while(cl <= cr) {
    int mid = (cl + cr) >> 1;
    for(int i = 1; i <= n; ++i)
      val[i] = 0, vis[i] = 0;
    for(int i = 0; i < mid; ++i)
      --val[a[i % k]];
    for(auto x : v)
      ++val[x];
    bool valid = dfs(1);
    // cerr << endl;
    // cerr << "DEB " << mid << " " << dp[1] << endl;
    if(valid && dp[1] >= 0)
      cl = mid + 1, ans = mid;
    else
      cr = mid - 1;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}