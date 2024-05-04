#include <bits/stdc++.h>
using namespace std;
// node maksimal angka berapa?
const int lim = 1e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  // initialize
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  // cari representative node
  int find_rep(int nd) {
    return h[nd] == -1 ? nd : h[nd] = find_rep(h[nd]);
  }
  bool merge(int x, int y) {
    x = find_rep(x), y = find_rep(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
    }
    return x != y;
  }
};
int main() {
  // cara cari representative node
  // find_rep(node)
  // mau cari size of cc sebuah node
  // sz[find_rep(node)]
  // cek 2 node terhubung, tinggal cari apa find_rep sama atau tidak
  // find_rep(node1) == find_rep(node2)
  // merge 2 node
  // merge(node1, node2)
  int mx = 0;
  int n, m;
  cin >> n >> m;
  disjoint_set dsu;
  int cc = n;
  for(int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    if(dsu.merge(x, y))
      --cc;
    mx = max(mx, dsu.sz[dsu.find_rep(x)]);
    cout << cc << " " << mx << endl;
  }
}