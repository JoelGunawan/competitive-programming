#include "factories.h"
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int lim = 1e6 + 5, lim2 = 20;
struct sparse_table {
  ll a[lim2][lim];
  int logz[lim];
  sparse_table() {
    logz[1] = 0;
    for(int i = 2; i < lim; ++i)
      logz[i] = logz[i / 2] + 1;
  }
  void build() {
    for(int i = 1; i < lim2; ++i) {
      for(int j = 0; j + (1 << (i - 1)) < lim; ++j) {
        a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  ll query(int l, int r) {
    int lg = logz[r - l + 1];
    //cout << l << " " << r << " " << lg << " " << a[lg][l] << " " << a[lg][r - (1 << lg) + 1] << endl;
    return min(a[lg][l], a[lg][r - (1 << lg) + 1]);
  }
};
// sp -> dist from root at ett index i (se is nd)
sparse_table sp;
// ett -> ett number i itu node brp
// inv -> node i itu ett number paling kecilnya berapa
// depth -> dist from root
int ett[lim], inv[lim], t = 0;
ll depth[lim];
vector<pair<int, int>> edges[lim];
bool vis[lim];
void dfs(int nd) {
  vis[nd] = 1;
  ett[t] = nd;
  inv[nd] = t;
  ++t;
  for(auto i : edges[nd]) {
    if(!vis[i.fi]) {
      depth[i.fi] = depth[nd] + i.se;
      dfs(i.fi);
      ett[t++] = nd;
    }
  }
}

void Init(int N, int A[], int B[], int D[]) {
  for(int i = 0; i < N - 1; ++i) {
    edges[A[i]].push_back(make_pair(B[i], D[i]));
    edges[B[i]].push_back(make_pair(A[i], D[i]));
  }
  dfs(0);
  for(int i = 0; i < t; ++i)
    sp.a[0][i] = depth[ett[i]];
  sp.build();
  for(int i = 0; i < t; ++i)
    sp.query(i, i);
}

ll ans;
struct disjoint_set {
  vector<int> head, sz;
  vector<ll> minx, miny;
  disjoint_set(int a) {
    head = vector<int>(a, -1);
    sz = vector<int>(a, 1);
    minx = miny = vector<ll>(a, 1e18);
  }
  int fh(int nd) {
    while(head[nd] != -1) {
      nd = head[nd];
    }
    return nd;
  }
  bool merge(int x, int y, ll h) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
        sz[x] += sz[y];
        head[y] = x;
        minx[x] = min(minx[x], minx[y]);
        miny[x] = min(miny[x], miny[y]);
        ans = min(ans, minx[x] + miny[x] - 2 * h);
    }
    return x != y;
  }
};

long long Query(int S, int X[], int T, int Y[]) {
  // sort by ett
  // fi -> ett
  // se -> type
  pair<int, bool> a[S + T];
  for(int i = 0; i < S; ++i)
    a[i] = make_pair(inv[X[i]], 0);
  for(int i = 0; i < T; ++i)
    a[i + S] = make_pair(inv[Y[i]], 1);
  sort(a, a + S + T);
  disjoint_set dsu(S + T);
  for(int i = 0; i < S + T; ++i) {
    if(a[i].se)
      dsu.miny[i] = sp.query(a[i].fi, a[i].fi);
    else
      dsu.minx[i] = sp.query(a[i].fi, a[i].fi);
  }
  // fi -> lca depth
  // se -> pair of nodes
  pair<ll, pair<int, int>> b[S + T - 1];
  for(int i = 0; i < S + T - 1; ++i) {
    b[i] = make_pair(sp.query(a[i].fi, a[i + 1].fi), make_pair(i, i + 1));
  }
  sort(b, b + S + T - 1, greater<pair<ll, pair<int, int>>>());
  ans = 1e18;
  for(int i = 0; i < S + T - 1; ++i) {
    dsu.merge(b[i].se.fi, b[i].se.se, b[i].fi);
  }
  return ans;
}
