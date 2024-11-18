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
int nxt[lim];
bool vis[lim];
bool white[lim];
int dp[lim];
vector<int> v;
void dfs(int nd, int cur = 0) {
  vis[nd] = 1;
  v.pb(nd);
  // cout << "PRE " << nd << " " << white[nd] << " " << dp[nd] << endl;
  if(vis[nxt[nd]]) {
    // we found a cycle
    // set all dp in that cycle to that number
    dp[nd] = cur;
    vector<int> cur;
    do {
      cur.pb(v.back()), v.pop_back();
    } while(cur.back() != nxt[nd]);
    int res = 0;
    for(auto x : cur) {
      if(!white[x])
        ++res;
    }
    for(auto x : cur)
      dp[x] = res;
    for(auto x : cur) {
      v.pb(x);
    }
  }
  else {
    dfs(nxt[nd]);
    if(dp[nd] == -1)
      dp[nd] = dp[nxt[nd]] + !white[nd];
  }
  // cout << "POST " << nd << " " << white[nd] << " " << dp[nd] << endl;
  v.pop_back();
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int p[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> p[i], nxt[i] = p[i];
    // find all cycles in a permutation
    for(int i = 1; i <= n; ++i)
      vis[i] = 0, dp[i] = -1;
    string s;
    cin >> s;
    for(int i = 1; i <= n; ++i)
      white[i] = s[i - 1] == '1';
    for(int i = 1; i <= n; ++i) {
      if(!vis[i])
        dfs(i);
    }
    for(int i = 1; i <= n; ++i) {
      cout << dp[i] << " ";
    }
    cout << endl;
  }
  return 0;
}