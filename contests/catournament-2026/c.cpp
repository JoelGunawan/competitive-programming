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
vector<pair<int, int>> edges[lim];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
  }

  if (edges[1].size() != n - 1) {
    cout << -1 << endl;
  } else {
    // go based on distance
    int deleted_edges = 0;
    int cheapest_cost[n + 5];
    for (auto [v, w] : edges[1]) {
      cheapest_cost[v] = w;
    }
    for (int i = 2; i <= n; ++i) {
      for (auto [v, w] : edges[i]) {
        if (v != 1 && w < max(cheapest_cost[v], cheapest_cost[i])) {
          ++deleted_edges;
        }
      }
    }
    assert(deleted_edges % 2 == 0);
    cout << deleted_edges / 2 << endl;
  }
  
  return 0;
}