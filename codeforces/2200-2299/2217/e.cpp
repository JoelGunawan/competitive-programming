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
void tc() {
  int n;
  cin >> n;
  
  int p[n + 5];
  for (int i = 1; i <= n; ++i) cin >> p[i];
  int d[n + 5];
  for (int i = 1; i <= n; ++i) cin >> d[i];

  vector<int> edges[n + 5];

  // cerr << __LINE__ << endl;
  // assume first i is dependent on everything on rhs
  // then remove dependencies slowly, starting from the vertex
  // with the least "in-degree"
  // cerr << __LINE__ << endl;
  for (int i = n; i >= 1; --i) {
    // add edges to everything greater than i
    // but, we need to skip stuff that dominates other stuff
    // cerr << __LINE__ << endl;
    int cur = 0;
    vector<int> nx;
    
    // cerr << __LINE__ << endl;
    
    bool vis[n + 5];
    memset(vis, 0, sizeof(vis));
    int cur_in[n + 5];
    memset(cur_in, 0, sizeof(cur_in));
    for (int j = i + 1; j <= n; ++j) {
      if (p[j] > p[i]) {
        ++cur;
        for (auto y : edges[j]) ++cur_in[y];
      }
    }

    // cerr << __LINE__ << endl;
    
    // cerr << __LINE__ << endl;

    // not enough even if we include all
    if (d[i] > cur) {
      cout << -1 << endl;
      return;
    }
    // cerr << __LINE__ << endl;
    
    // try to remove vertices, starting with those with smallest in
    
    // res contains vertices that will be edges
    set<pair<int, int>> res;
    // start with all "base"
    for (int j = i + 1; j <= n; ++j) {
      if (p[j] > p[i] && cur_in[j] == 0) res.insert({p[j], j});
    }

    // erase right-most that is 0...
    while (cur > d[i]) {
      --cur;
      auto [_, nd] = *--res.end();
      res.erase(--res.end());
      for (auto x : edges[nd]) {
        --cur_in[x];
        if (cur_in[x] == 0) {
          res.insert({p[x], x});
        }
      }
    }

    for (auto [_, x] : res) edges[i].push_back(x);
  }
  // cerr << __LINE__ << endl;

  vector<int> inv[n + 5];
  int out[n + 5];
  memset(out, 0, sizeof(out));
  int left[n + 5];
  for (int i = 1; i <= n; ++i) {
    out[i] = edges[i].size();
    for (auto x : edges[i]) {
      inv[x].push_back(i);
    }

    if (inv[i].empty()) left[i] = i;
    else {
      int mn = 1e9;
      for (auto x : inv[i]) mn = min(mn, left[x]);
      left[i] = mn;
    }
  }

  int ans[n + 5];
  memset(ans, -1, sizeof(ans));
  int cur_number = n;
  for (int i = 1; i <= n; ++i) {
    pair<int, int> cand = mp(5005, 5005);
    for (int j = 1; j <= n; ++j) {
      // cerr << out[j] << " ";
      if (out[j] == 0) {
        // ans[j] = cur_number--;
        // --out[j];
        // for (auto x : inv[j]) --out[x];
        // break;
        cand = min(cand, mp(left[j], j));
      }
    }
    // cerr << endl;

    if (cand.fi <= n) {
      auto j = cand.se;
      ans[j] = cur_number--;
      --out[j];
      for (auto x : inv[j]) --out[x];
    }
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << endl;

  // cerr << "DEBUG OUTPUT" << endl;
  // for (int i = 1; i <= n; ++i) {
  //   for (auto x : edges[i]) cerr << x << " ";
  //   cerr << endl;
  // }
  // cerr << "DEBUG DONE" << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}