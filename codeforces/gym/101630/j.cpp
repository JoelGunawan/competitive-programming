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
const int lim = 3005;
struct disjoint_set {
  int h[lim], sz[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  void merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
    }
  }
} dsu;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> edges[n + 5];
  vector<int> vals = {0};
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].pb(mp(v, w));
    edges[v].pb(mp(u, w));
    vals.pb(w);
  }
  sort(vals.begin(), vals.end());
  reverse(vals.begin(), vals.end());
  priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
  ll res = 1e18;
  while(vals.size()) {
    // find length shortest path <= k
    for(int i = 1; i <= n; ++i) {
      for(auto &p : edges[i])
        swap(p.fi, p.se);
      sort(edges[i].begin(), edges[i].end());
      reverse(edges[i].begin(), edges[i].end());
      for(auto &p : edges[i])
        swap(p.fi, p.se);
    }
    for(int i = 1; i <= n; ++i) {
      while(edges[i].size() && edges[i].back().se <= vals.back())
        dsu.merge(i, edges[i].back().fi), edges[i].pop_back();
    }
    for(int i = 1; i <= n; ++i) {
      if(dsu.fh(i) != i) {
        while(edges[i].size())
          edges[dsu.fh(i)].pb(edges[i].back()), edges[i].pop_back();
      }
    }
    // fi -> dist
    // se.fi -> -len
    // se.se -> nd
    pq.push(mp(0, mp(0, dsu.fh(1))));
    ll dist[n + 1];
    int res_len = 0;
    fill(dist, dist + n + 1, 1e18);
    while(pq.size()) {
      ll d = pq.top().fi; int len = pq.top().se.fi, nd = pq.top().se.se;
      pq.pop();
      if(d >= dist[nd])
        continue;
      if(dsu.fh(nd) == dsu.fh(n))
        res_len = -len;
      dist[nd] = d;
      for(auto i : edges[nd]) {
        if(d + i.se < dist[dsu.fh(i.fi)])
          pq.push(mp(d + i.se - vals.back(), mp(len - 1, dsu.fh(i.fi))));
      }
    }
    res = min(res, 1ll * k * vals.back() + dist[dsu.fh(n)]);
    vals.pop_back();
  }
  cout << res << endl;
  return 0;
}