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
const int lim = 1e5 + 5;
bool vis[lim], active[lim];
vector<int> edges[lim];
bool dfs(int nd) {
  vis[nd] = 1;
  active[nd] = 1;
  bool ret = 0;
  for(auto i : edges[nd]) {
    if(active[i]) {
      active[nd] = 0;
      return true;
    }
    else if(!vis[i]) {
      ret |= dfs(i);
      if(ret)
        break;
    }
  }
  active[nd] = 0;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // freopen("milkorder.in", "r", stdin);
  // freopen("milkorder.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<int> v[m + 1];
  for(int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    for(int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      v[i].pb(y);
    }
  }
  int in[n + 1];
  vector<int> sol;
  int l = 0, r = m;
  while(l <= r) {
    int mid = (l + r) >> 1;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i)
      edges[i].clear();
    for(int i = 1; i <= mid; ++i) {
      for(int j = 1; j < v[i].size(); ++j)
        edges[v[i][j - 1]].pb(v[i][j]);
    }
    // check if there is a cycle
    bool ret = 0;
    for(int i = 1; i <= n; ++i)
      if(!vis[i]) {
        ret |= dfs(i);
        if(ret)
          break;
      }
    // invalid
    if(ret) {
      r = mid - 1;
      continue;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    l = mid + 1;
    vector<int> v;
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= n; ++i) {
      for(auto j : edges[i])
        ++in[j];
    }
    for(int i = 1; i <= n; ++i)
      if(in[i] == 0)
        pq.push(i);
    while(pq.size()) {
      int cur = pq.top();
      pq.pop();
      for(auto x : edges[cur]) {
        --in[x];
        if(in[x] == 0)
          pq.push(x);
      }
      v.pb(cur);
    }
    sol = v;
  }
  for(auto x : sol)
    cout << x << (x == sol.back() ? "" : " "); 
  cout << endl;
  return 0;
}