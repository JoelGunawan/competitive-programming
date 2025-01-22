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
const int lim2 = 1 << 17;
struct segment_tree {
  // maintains count of 1
  int a[lim2 << 1];
  bool lazy[lim2 << 1];
  segment_tree() {
    memset(a, 0, sizeof(a));
    memset(lazy, 0, sizeof(lazy));
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      lazy[nd << 1] ^= lazy[nd];
      lazy[(nd << 1) | 1] ^= lazy[nd];
    }
    if(lazy[nd] & 1)
      a[nd] = (cr - cl + 1) - a[nd];
    lazy[nd] = 0;
  }
  void update(int nd, int cl, int cr, int l, int r) {
    // flip entire range
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazy[nd] ^= 1;
      prop(nd, cl, cr);
      // cerr << "UPDATE " << cl << " " << cr << " " << a[nd] << endl;
    }
    else if(cl > r || cr < l)
      return;
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r);
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
} seg;
const int lim = 1e5 + 5;
bool vis[lim];
vector<int> edges[lim], child[lim];
int depth[lim], subtree[lim], root[lim], par[lim], in[lim], out[lim], t;
void get_subtree(int nd) {
  vis[nd] = 1;
  subtree[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      par[i] = nd;
      depth[i] = depth[nd] + 1;
      get_subtree(i);
      child[nd].pb(i);
      subtree[nd] += subtree[i];
      if(subtree[child[nd].back()] > subtree[child[nd][0]])
        swap(child[nd].back(), child[nd][0]);
    }
  }
}
void dfs_hld(int nd) {
  in[nd] = ++t;
  for(auto i : child[nd]) {
    root[i] = child[nd][0] == i ? root[nd] : i;
    dfs_hld(i);
  }
  out[nd] = t;
}
void update(int u) {
  // update to root, change parity of everything
  while(u != 0) {
    // DON'T UPDATE ROOT
    seg.update(1, 0, lim2 - 1, max(2, in[root[u]]), in[root[u]] + depth[u] - depth[root[u]]);
    u = par[root[u]];
  }
}
int dfs(int nd, bool first = 0) {
  int sum_c = 0;
  for(auto x : child[nd]) {
    sum_c += dfs(x, 0);
  }
  // cerr << nd << " " << sum_c << endl;
  // for leaf, set to 1
  sum_c = max(sum_c, 1);
  // if even, to par get +1 extra
  if(!first && (sum_c & 1) == 0)
    seg.update(1, 0, lim2 - 1, in[nd], in[nd]);
  return sum_c;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  int deg[n + 5];
  memset(deg, 0, sizeof(deg));
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
    ++deg[u], ++deg[v];
  }
  int leaf = 0;
  int r = 1;
  for(int i = 1; i <= n; ++i) {
    if(deg[i] == 1)
      ++leaf;
    else {
      if(deg[i] > deg[r])
        r = i;
    }
  }
  // cerr << "DEB " << r << " " << deg[r] << endl;
  get_subtree(r);
  root[r] = r;
  dfs_hld(r);
  dfs(r, 1);
  // even -> +1
  // odd -> 0
  // star case WA
  // perfect binary tree AC
  // all off by 1? (too much)
  // small degree correct, large degree incorrect, what is the issue?
  // degree 1/2 correct
  // star incorrect
  while(q--) {
    int d;
    cin >> d;
    vector<int> v(d);
    for(int i = 0; i < d; ++i)
      cin >> v[i];
    for(auto x : v) {
      if(deg[x] == 1)
        --leaf;
      else
        update(x);
      ++deg[x];
    }
    // cerr << leaf << " " << d << endl;
    // n + d - 1 -> number of edges
    // seg.query -> number of double crossed edges
    if((leaf + d) & 1)
      cout << -1 << endl;
    else
      cout << seg.query(1, 0, lim2 - 1, 0, lim2 - 1) + n - 1 + d << endl;
    for(auto x : v) {
      --deg[x];
      if(deg[x] == 1)
        ++leaf;
      else
        update(x);
    }
    // cerr << "SEP" << endl;
  }
  return 0;
}