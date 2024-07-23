#include "temple.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
const int lim2 = 1e5 + 5;
struct disjoint_set {
  int sz[lim2], h[lim2], l[lim2], r[lim2];
  vector<int> v[lim2];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim2, 1);
    for(int i = 0; i < lim2; ++i)
      v[i] = {i}, l[i] = i, r[i] = i;
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
      l[x] = min(l[x], l[y]);
      r[x] = max(r[x], r[y]);
      for(auto p : v[y])
        v[x].pb(p);
    }
    return x != y;
  }
};
const int lim = 1 << 17;
struct lazy_segment_tree {
    long long a[2 * lim], lazy[2 * lim], inf = 1e18;
    lazy_segment_tree() {
      fill(lazy, lazy + 2 * lim, inf);
      fill(a, a + 2 * lim, inf);
    }
    int arr_size = lim;
    void propagate(int nd, int cl, int cr) {
        a[nd] = min(a[nd], lazy[nd]);
        if(cl != cr) {
            lazy[2 * nd] = min(lazy[2 * nd], lazy[nd]);
            lazy[2 * nd + 1] = min(lazy[2 * nd + 1], lazy[nd]);
        }
        lazy[nd] = inf;
    }
    void update(int l, int r, long long val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, long long val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] = min(lazy[nd], val);
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = min(a[2 * nd], a[2 * nd + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) 
            return inf;
        else {
            int mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(int l, int r) {
      return query(1, 0, lim - 1, l, r);
    }
};
long long min_weight(int N, int M, int K,
                     std::vector<int> U, std::vector<int> V, std::vector<int> W,
                     std::vector<int> P) {
  // multisource prim
  // sources: exits, insert the edges then find min cost
  // do dijkstra sol first
  // find closest path to n as proc by edges
  vector<int> edges[N];
  vector<pair<int, pair<int, int>>> adj(M);
  for(int i = 0; i < M; ++i)
    adj[i] = mp(W[i], mp(U[i], V[i]));
  sort(adj.begin(), adj.end());
  ll cost[N];
  fill(cost, cost + N, 1e18);
  ll res = 1e18;
  int idx = -1;
  // cout << "before rename" << endl;
  cout.flush();
  disjoint_set renumber;
  disjoint_set dsu;
  for(auto p : adj) {
    renumber.merge(p.se.fi, p.se.se);
  }
  map<int, int> r;
  for(int i = 0; i < renumber.v[renumber.fh(0)].size(); ++i)
    r[renumber.v[renumber.fh(0)][i]] = i;
  for(auto &p : adj) {
    p.se.fi = r[p.se.fi];
    p.se.se = r[p.se.se];
  }
  // cout << "after rename" << endl;
  lazy_segment_tree seg;
  for(auto x : P) 
    seg.update(r[x], r[x], 0);
  // for(auto x : r) {
  //   cout << x.fi << " " << x.se << endl;
  // }
  for(auto p : adj) {
    // use dsu to find out whether it is connected to 1 and update min cost of all adjacent nodes
    int u = p.se.fi, v = p.se.se, w = p.fi;
    ll min_cost = min(seg.query(u, u) + w, seg.query(v, v) + w);
    // ll min_cost = 0;
    // cout << "DEBUG " << min_cost << " " << u << " " << v << endl;
    while(idx + 1 < adj.size() && adj[idx + 1].fi == w) {
      ++idx;
      int u = adj[idx].se.fi, v = adj[idx].se.se;
      dsu.merge(u, v);
      edges[u].pb(v);
      edges[v].pb(u);
    }
    // this is the only part causing O(N^2)
    // if we can ensure the dsu is always merging adjacent, we can make lazy seg rmq
    // renumber elements (should not be that hard)
    seg.update(dsu.l[dsu.fh(u)], dsu.r[dsu.fh(u)], min_cost);
    // cout << "insert cost " << dsu.fh(u) << " " << dsu.fh(r[0]) << " " << min_cost << endl;
    if(dsu.fh(u) == dsu.fh(r[0]))
      res = min(res, min_cost);
  }
  return res;
}
