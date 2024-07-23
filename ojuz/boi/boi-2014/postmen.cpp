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
vector<vector<int>> ans;
const int lim = 5e5 + 5;
vector<int> edges[lim], st;
priority_queue<int> del[lim];
bool active[lim];
int find_cycle(int nd) {
  active[nd] = 1;
  // cerr << "FIND CYCLE " << nd << endl;
  while (edges[nd].size()) {
    if(del[nd].size() && del[nd].top() == edges[nd].back()) {
      edges[nd].pop_back();
      del[nd].pop();
      continue;
    }
    int cur = edges[nd].back();
    edges[nd].pop_back();
    del[cur].push(nd);
    st.pb(nd);
    if(active[cur]) {
      // cerr << "FOUND CYCLE " << nd << " " << cur << endl;
      // found cycle
      active[nd] = 0;
      return cur;
    }
    else {
      // cerr << "MOVE " << nd << " " << cur << endl;
      int x = find_cycle(cur);
      // cerr << "RESULT " << nd << " " << cur << " " << x << endl;
      if(x != nd) {
        active[nd] = 0;
        return x;
      }
      else {
        ans.pb({});
        do {
          ans.back().pb(st.back());
          st.pop_back();
        } while(ans.back().back() != nd);
      }
    }
  }
  active[nd] = 0;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  for(int i = 1; i <= n; ++i)
    sort(edges[i].begin(), edges[i].end());
  for(int i = 1; i <= n; ++i) {
    if(edges[i].size())
      find_cycle(i);
  }
  for(auto x : ans) {
    for(auto y : x)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}