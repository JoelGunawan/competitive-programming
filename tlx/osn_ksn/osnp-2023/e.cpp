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
int mod = 1e9;
ll dp[105][100005], val[105];
bool vis[105];
vector<int> edges[105];
void dfs(int nd) {
  vis[nd] = 1;
  dp[nd][val[nd]] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
      for(int j = 0; j <= 1e5; ++j) {
        dp[nd][j] += dp[i][j];
        if(j >= val[nd])
          dp[nd][j] += dp[i][j - val[nd]];
        dp[nd][j] %= mod;
      }
    }
  }
  //cout << "DEBUG " << nd << endl;
  //for(int i = 1; i <= 4; ++i) 
  //  cout << dp[nd][i] << " ";
  //cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> val[i];
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  dfs(1);
  ll cur = 0;
  for(int i = 1; i <= m; ++i)
    cur += dp[1][i], cout << cur % mod << endl;
  return 0;
}