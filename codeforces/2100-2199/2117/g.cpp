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
const int inf = 2e9;
struct disjoint_set {
  vector<int> mn, h, sz;
  disjoint_set(int n) {
    sz = vector<int>(n + 5, 1);
    h = vector<int>(n + 5, -1);
    mn = vector<int>(n + 5, inf);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  void merge(int x, int y, int val) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
      mn[x] = min({mn[x], mn[y], val});
    }
  }
};
void tc() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> edges;
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(w, mp(u, v));
  }
  sort(edges.begin(), edges.end());
  disjoint_set dsu(n);
  ll res = 1e18;
  for(auto [cost, p] : edges) {
    auto [u, v] = p;
    dsu.merge(u, v, cost);
    if(dsu.fh(1) == dsu.fh(n))
      res = min(res, 0ll + dsu.mn[dsu.fh(1)] + cost);
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}