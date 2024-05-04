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
const int lim = 2e5 + 5;
vector<int> edges[lim], child[lim];
pair<int, int> dp[lim][2];
bool vis[lim];
// current is good:
// dp[nd][1] = sum(dp[child][0])
// dp[nd][0] = sum(dp[child][0] or dp[child][1])
// if use dp[nd][0] -> set val to 1
// else -> set val to degree
void dfs(int nd) {
  vis[nd] = 1;
  dp[nd][0] = mp(0, -1);
  dp[nd][1] = mp(1, -(int)edges[nd].size());
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
      child[nd].pb(i);
      dp[nd][1].fi += dp[i][0].fi;
      dp[nd][1].se += dp[i][0].se;
      if(dp[i][1] > dp[i][0]) {
        dp[nd][0].fi += dp[i][1].fi;
        dp[nd][0].se += dp[i][1].se;
      }
      else {
        dp[nd][0].fi += dp[i][0].fi;
        dp[nd][0].se += dp[i][0].se;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  if(n == 2) {
    cout << 2 << " " << 2 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  } 
  // do dp
  // no 2 adjacent nodes can be good
  // dp[nd][good]
  // + need backtrack
  dfs(1);
  cout << max(dp[1][0], dp[1][1]).fi << " " << -max(dp[1][0], dp[1][1]).se << endl;
  queue<pair<int, bool>> q;
  if(dp[1][0] > dp[1][1])
    q.push(mp(1, 0));
  else
    q.push(mp(1, 1));
  int val[n + 5];
  while(q.size()) {
    int nd = q.front().fi, state = q.front().se;
    q.pop();
    if(state == 0)
      val[nd] = 1;
    else
      val[nd] = edges[nd].size();
    for(auto i : child[nd]) {
      if(state == 1)
        q.push(mp(i, 0));
      else {
        if(dp[i][0] > dp[i][1])
          q.push(mp(i, 0));
        else
          q.push(mp(i, 1));
      }
    }
  }
  for(int i = 1; i <= n; ++i)
    cout << val[i] << " ";
  cout << endl;
  return 0;
}