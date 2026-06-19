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
bool vis[lim];
int subtree[lim], pr[lim], n, k;
void cnt_subtree(int nd) {
  subtree[nd] = 1;
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
      cnt_subtree(i), subtree[nd] += subtree[i];
  }
}

ll glob_res;

void dfs(int nd, map<int, int> &cnt, int &res) {
  glob_res += res;
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      ++cnt[n - subtree[i]];
      --cnt[subtree[i]];
      if (n - subtree[i] >= k) ++res;
      if (subtree[i] >= k) --res;
      dfs(i, cnt, res);
      ++cnt[subtree[i]];
      --cnt[n - subtree[i]];
      if (n - subtree[i] >= k) --res;
      if (subtree[i] >= k) ++res;
    }
  }
}

void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; ++i) {
    vis[i] = 0;
    subtree[i] = 0;
    edges[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  cnt_subtree(1);
  for(int i = 1; i <= n; ++i)
    vis[i] = 0;
  map<int, int> cnt;
  for(int i = 1; i <= n; ++i)
    ++cnt[subtree[i]];
  glob_res = 0;
  int cur_res = 0;
  for(int i = 1; i <= n; ++i)
    if (subtree[i] >= k) ++cur_res;
  dfs(1, cnt, cur_res);
  cout << glob_res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}