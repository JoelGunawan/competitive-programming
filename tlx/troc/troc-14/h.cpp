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
const int lim2 = 1 << 16;
struct segtree_inv {
  int a[lim2 << 1];
  bool lazy[lim2 << 1];
  segtree_inv() {
    memset(a, 0, sizeof(a));
    memset(lazy, 0, sizeof(lazy));
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      lazy[nd << 1] ^= lazy[nd];
      lazy[(nd << 1) | 1] ^= lazy[nd];
    }
    if(lazy[nd])
      a[nd] = (cr - cl + 1) - a[nd];
    lazy[nd] = 0;
  }
  void update(int nd, int cl, int cr, int l, int r) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazy[nd] ^= 1;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l)
      return;
    else {
      int mid = (cl + cr) >> 1;
      update((nd << 1), cl, mid, l, r);
      update((nd << 1) | 1, mid + 1, cr, l, r);
      a[nd] = a[nd << 1] + a[(nd << 1) | 1];
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      // cerr << "QUERY " << cl << " " << cr << " " << a[nd] << endl;
      return a[nd];
    }
    else if(cl > r || cr < l) 
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return query(nd << 1, cl, mid, l, r) + query((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }
} seg_inv;
struct segtree {
  int a[lim2 << 1];
  segtree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim2;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = a[idx << 1] + a[(idx << 1) | 1];
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      // cerr << "GOT " << cl << " " << cr << " " << a[nd] << endl;
      return a[nd];
    }
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return query(nd << 1, cl, mid, l, r) + query((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }
} seg;
const int lim = 5e4 + 5;
int par[lim], root[lim], in[lim], out[lim], subtree[lim], depth[lim], maxd[lim], t;
vector<int> edges[lim], child[lim];
bool vis[lim];
void get_subtree(int nd) {
  vis[nd] = 1;
  maxd[nd] = depth[nd];
  subtree[nd] = 1;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      par[x] = nd;
      depth[x] = depth[nd] + 1;
      get_subtree(x);
      subtree[nd] += subtree[x];
      child[nd].pb(x);
      if(subtree[child[nd][0]] < subtree[child[nd].back()])
        swap(child[nd][0], child[nd].back());
    }
  }
  if(child[nd].size())
    maxd[nd] = max(maxd[nd], maxd[child[nd][0]]);
}
void dfs_hld(int nd) {
  in[nd] = ++t;
  for(auto x : child[nd]) {
    root[x] = x == child[nd][0] ? root[nd] : x;
    dfs_hld(x);
  }
  out[nd] = t;
}
// sum -> number of pairs
ll sum[lim];
// w -> number of white nodes in current component
int w[lim];
void update(int nd) {
  // update to root
  // cerr << "UPDATE " << nd << endl;
  while(nd != 0) {
    // update to root
    // update sum of pairs
    // cerr << "UP " << in[root[nd]] << " " << in[root[nd]] + depth[nd] - depth[root[nd]] << endl;
    seg_inv.update(1, 0, lim2 - 1, in[root[nd]], in[root[nd]] + depth[nd] - depth[root[nd]]);
    // cerr << seg_inv.query(1, 0, lim2 - 1, in[root[nd]], in[root[nd]] + maxd[nd] - depth[root[nd]]) << " " << seg.query(1, 0, lim2 - 1, in[root[nd]], in[root[nd]] + maxd[nd] - depth[root[nd]]) << endl;
    int new_w = seg_inv.query(1, 0, lim2 - 1, in[root[nd]], in[root[nd]] + maxd[nd] - depth[root[nd]]) + seg.query(1, 0, lim2 - 1, in[root[nd]], in[root[nd]] + maxd[nd] - depth[root[nd]]);
    int total = seg.query(1, 0, lim2 - 1, in[par[root[nd]]], in[par[root[nd]]]);
    sum[par[root[nd]]] -= 1ll * w[root[nd]] * (total - w[root[nd]]);
    sum[par[root[nd]]] += 1ll * new_w * (total - w[root[nd]]);
    // cerr << "UPD " << nd << " " << par[root[nd]] << " " << total + new_w - w[root[nd]] << endl;
    seg.update(in[par[root[nd]]], total + new_w - w[root[nd]]);
    // cerr << "DEB " << nd << " " << total << " " << new_w << " " << w[root[nd]] << endl;
    w[root[nd]] = new_w;
    nd = par[root[nd]];
  }
  // for(int i = 0; i <= 6; ++i)
  //   cerr << seg.query(1, 0, lim2 - 1, i, i) << " ";
  // cerr << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  root[1] = 1;
  depth[1] = 1;
  get_subtree(1);
  dfs_hld(1);
  for(int i = 1; i <= n; ++i) {
    if(a[i])
      update(i), update(par[i]);
  }
  while(q--) {
    int t;
    int x;
    cin >> t >> x;
    if(t == 1) {
      update(x);
    }
    else {
      // cerr << seg.query(1, 0, lim2 - 1, in[x] + 1, in[x] + maxd[x] - depth[x]) << " " << seg_inv.query(1, 0, lim2 - 1, in[x], in[x] + maxd[x] - depth[x]) << " " << seg.query(1, 0, lim2 - 1, in[x], in[x]) << " " << sum[x] << endl;
      ll res = 1ll * (seg.query(1, 0, lim2 - 1, in[x] + 1, in[x] + maxd[x] - depth[x]) + seg_inv.query(1, 0, lim2 - 1, in[x], in[x] + maxd[x] - depth[x])) * seg.query(1, 0, lim2 - 1, in[x], in[x]) + sum[x];
      // cerr << res << endl;
      if(seg_inv.query(1, 0, lim2 - 1, in[x], in[x]) == 1) {
        // cerr << "HERE " << in[x] << " " << in[x] + maxd[x] - depth[x] << " " << seg_inv.query(1, 0, lim2 - 1, in[x], in[x] + maxd[x] - depth[x]) << endl;
        res += seg.query(1, 0, lim2 - 1, in[x] + 1, in[x] + maxd[x] - depth[x]) + seg_inv.query(1, 0, lim2 - 1, in[x], in[x] + maxd[x] - depth[x]) - 1;
      }
      cout << res << endl;
    }
  }
  // for(int i = 1; i <= n; ++i)
  //   cerr << root[i] << " ";
  // cerr << endl;
  // for(int i = 1; i <= n; ++i)
  //   cerr << subtree[i] << " ";
  // cerr << endl;
  return 0;
}