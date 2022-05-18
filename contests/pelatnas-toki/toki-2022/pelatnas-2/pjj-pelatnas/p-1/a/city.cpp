#include <bits/stdc++.h>
#include "city.h"
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
const int lim = 100000;
struct disjoint_set {
  int head[lim], size[lim];
  disjoint_set() {
    memset(head, -1, sizeof(head));
    fill(size, size + lim, 1);
  }
  int find_head(int node) {
    while(head[node] != -1)
      node = head[node];
    return node;
  }
  bool merge(int a, int b) {
    int x = find_head(a), y = find_head(b);
    if(x != y) {
      if(size[x] < size[y])
        head[x] = y, size[y] += size[x];
      else
        head[y] = x, size[x] += size[y];
    }
    return x != y;
  }
};
struct sparse_table {
  pair<ll, int> a[21][lim];
  void build(vector<pair<ll, int>> arr) {
    for(int i = 0; i < arr.size(); ++i) {
      a[0][i] = arr[i];
    }
    for(int i = 1; i < 21; ++i) {
      for(int j = 0; j + (1 << i) <= lim; ++j) {
        a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  pair<ll, int> query(int l, int r) {
    if(r < l)
      return mp((ll)1e18, (int)1e9);
    int dist = r - l + 1;
    pair<ll, int> res = mp(LLONG_MAX, INT_MAX);
    for(int i = 20; i >= 0; --i) {
      if(dist >= (1 << i)) {
        res = min(res, a[i][l]);
        l += 1 << i;
        dist -= 1 << i;
      }
    }
    return res;
  }
};
struct special_sparse_table {
  int a[21][lim];
  void build(vector<int> arr) {
    for(int i = 0; i < arr.size(); ++i) {
      a[0][i] = arr[i];
    }
    for(int i = 1; i < 21; ++i) {
      for(int j = 0; j + (1 << i) <= lim; ++j) {
        a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  int query(int l, int r) {
    if(r < l)
      return 1e9;
    int dist = r - l + 1, res = 1e9;
    for(int i = 20; i >= 0; --i) {
      if(dist >= (1 << i)) {
        res = min(res, a[i][l]);
        l += 1 << i;
        dist -= 1 << i;
      }
    }
    return res;
  }
};
std::pair<int, int> getBestXY(int N, int M, int S, int T, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  // make a random mst
  // it is fine :D
  // *insert this is fine meme*
  disjoint_set mst;
  vector<pair<int, pair<int, int>>> edges(M);
  for(int i = 0; i < M; ++i) {
    edges[i] = mp(C[i], mp(A[i], B[i]));
  }
  sort(edges.begin(), edges.end());
  vector<pair<int, pair<int, int>>> mst_edges;
  int edge_max = 0;
  for(int i = 0; i < M; ++i) {
    if(mst.merge(edges[i].se.fi, edges[i].se.se))
      edge_max = edges[i].fi, mst_edges.pb(edges[i]);
  }
  edges.clear();
  // fi is nd, se is dist
  vector<pair<int, int>> adj[N];
  vector<pair<int, int>> full_edge[N];
  for(int i = 0; i < M; ++i) {
    full_edge[A[i]].pb(mp(B[i], C[i]));
    full_edge[B[i]].pb(mp(A[i], C[i]));
  }
  for(auto i : mst_edges) {
    adj[i.se.fi].pb(mp(i.se.se, i.fi));
    adj[i.se.se].pb(mp(i.se.fi, i.fi));
  }
  A.clear(), B.clear(), C.clear();
  // use to find dist from s to t
  priority_queue<pair<ll, int>> pq;
  pq.push(mp(0, S));
  ll s_dist[N], t_dist[N];
  bool vis[N];
  memset(vis, 0, sizeof(vis));
  while(pq.size() > 0) {
    ll cur_dist = -pq.top().fi, nd = pq.top().se;
    pq.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    s_dist[nd] = cur_dist;
    for(auto i : full_edge[nd]) {
      if(!vis[i.fi]) {
        pq.push(mp(-(cur_dist + i.se), i.fi));
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  pq.push(mp(0, T));
  while(pq.size() > 0) {
    ll cur_dist = -pq.top().fi, nd = pq.top().se;
    pq.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    t_dist[nd] = cur_dist;
    for(auto i : full_edge[nd]) {
      if(!vis[i.fi]) {
        pq.push(mp(-(cur_dist + i.se), i.fi));
      }
    }
  }
  //for(int i = 0; i < N; ++i)
  //  cout << s_dist[i] << " " << t_dist[i] << endl;
  // set 0 as root
  // and do euler tour
  memset(vis, 0, sizeof(vis));
  int et_index[N], subtree[N];
  // return size of subtree
  int cur = 0;
  function<int(int)> et = [&] (int nd) -> int {
    vis[nd] = 1;
    subtree[nd] = 1;
    et_index[nd] = cur;
    ++cur;
    for(auto i : adj[nd]) {
      if(!vis[i.fi]) {
        subtree[nd] += et(i.fi);
      }
    }
    return subtree[nd];
  };
  et(0);
  vector<pair<ll, int>> build_s(N), build_t(N);
  vector<int> special_sp_build(N);
  for(int i = 0; i < N; ++i) {
    build_s[et_index[i]] = mp(s_dist[i], i);
    build_t[et_index[i]] = mp(t_dist[i], i);
    special_sp_build[et_index[i]] = i;
  }
  sparse_table s;
  s.build(build_s);
  build_s.clear();
  sparse_table t;
  t.build(build_t);
  build_t.clear();
  special_sparse_table sp;
  sp.build(special_sp_build);
  special_sp_build.clear();
  pair<int, int> res = mp(1e9, 1e9); ll min_res = s_dist[T];
  for(auto i : mst_edges) {
    if(i.fi == edge_max) {
      int x = i.se.fi, y = i.se.se;
      if(subtree[x] < subtree[y])
        swap(x, y);
      ll cur_res = 0;
      pair<ll, int> a = s.query(et_index[y], et_index[y] + subtree[y] - 1), b = t.query(et_index[y], et_index[y] + subtree[y] - 1);
      pair<ll, int> c = min(s.query(0, et_index[y] - 1), s.query(et_index[y] + subtree[y], N - 1)),
      d = min(t.query(0, et_index[y] - 1), t.query(et_index[y] + subtree[y], N - 1));
      // case s di 1 t di 2
      // a and d
      pair<int, int> p;
      p = mp(min(a.se, d.se), max(a.se, d.se));
      if(a.fi + d.fi < min_res) {
        min_res = a.fi + d.fi;
        res = p;
      }
      else if(a.fi + d.fi == min_res && p < res) {
        res = p;
      }
      // case s di 2 t di 1
      // b and c
      p = mp(min(b.se, c.se), max(b.se, c.se));
      if(b.fi + c.fi < min_res) {
        min_res = b.fi + c.fi;
        res = p;
      }
      else if(b.fi + c.fi == min_res && p < res)
        res = p;
      // case min dist == s_dist[T]
      if(min_res == s_dist[T]) {
        int e = 1e9, f = 1e9;
        e = sp.query(et_index[y], et_index[y] + subtree[y] - 1);
        f = min(sp.query(0, et_index[y] - 1), sp.query(et_index[y] + subtree[y], N - 1));
        p = mp(min(e, f), max(e, f));
        res = min(res, p);
      }
    }
  }
  return res;
}