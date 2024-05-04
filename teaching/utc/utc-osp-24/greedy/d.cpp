#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
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
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  // compare weight
  return a.second < b.second;
}
int main() {
  disjoint_set dsu;
  int n, m;
  cin >> n >> m;
  vector<pair<pair<int, int>, int>> v;
  for(int i = 1; i <= m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(make_pair(make_pair(a, b), c));
  }
  sort(v.begin(), v.end(), compare);
  long long sum = 0;
  int cnt = 0;
  for(auto x : v) {
    // kalo berhasil gabungin 2 node
    if(dsu.merge(x.first.first, x.first.second)) {
      // bagian dari mst
      sum += x.second;
      ++cnt;
    }
  }
  // connected semua
  if(cnt == n - 1)
    cout << sum << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}