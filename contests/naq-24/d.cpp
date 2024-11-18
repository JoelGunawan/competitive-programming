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
int cnt[lim], c[lim];
struct disjoint_set {
  int h[lim], sz[lim];
  map<int, int> a[lim];
  ll res[lim];
  disjoint_set() {
    memset(res, 0, sizeof(res));
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
      // cerr << "OLD RES " << x << " " << y << " " << res[x] << " " << res[y] << endl;
      for(auto p : a[y]) {
        if(a[x][p.fi] == 0) {
          a[x][p.fi] = p.se;
          res[x] += 1ll * p.se * (cnt[p.fi] - p.se);
        }
        else {
          int &ref = a[x][p.fi];
          res[x] -= 1ll * ref * (cnt[p.fi] - ref);
          ref += p.se;
          res[x] += 1ll * ref * (cnt[p.fi] - ref);
        }
      }
      // cerr << "NEW RES " << res[x] << endl;
    }
  }
} dsu;
vector<int> edges[lim];
bool vis[lim];
int depth[lim];
ll res[lim];
void dfs(int nd) {
  vis[nd] = 1;
  dsu.a[nd][c[nd]]++;
  dsu.res[nd] = cnt[c[nd]] - 1;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      depth[x] = depth[nd] + 1;
      dfs(x);
      dsu.merge(nd, x);
    }
  }
  res[nd] = dsu.res[dsu.fh(nd)];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> c[i];
    ++cnt[c[i]];
  }
  vector<pair<int, int>> adj;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj.pb(mp(u, v));
    edges[u].pb(v);
    edges[v].pb(u);
  }
  dfs(1);
  for(auto p : adj) {
    if(depth[p.fi] > depth[p.se])
      swap(p.fi, p.se);
    cout << res[p.se] << endl;
  }
  return 0;
}