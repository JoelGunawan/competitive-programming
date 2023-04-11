#include "race.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int l;
int res = 1e9;
const int lim = 2e5 + 5;
int depth[lim];
bool vis[lim];
vector<pair<int, int>> edges[lim];
struct disjoint_set {
  int h[lim], sz[lim], d[lim];
  ll shift[lim];
  // fi -> distance
  // se -> depth
  // cari depth terkecil
  set<pair<int, int>> a[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    //memset(sz, 0, sizeof(sz));
    fill(sz, sz + lim, 1);
    memset(shift, 0, sizeof(shift));
    memset(d, -1, sizeof(d));
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
      if(a[x].size() < a[y].size()) {
        swap(a[x], a[y]);
        swap(shift[x], shift[y]);
      }
      //cout << d[x] << " " << d[y] << endl;
      //cout << x << " " << y << endl;
      d[x] = min(d[x], d[y]);
      for(auto i : a[y]) {
        // coba cari di a[x] yg panjangnya pas
        int target = l - i.first - shift[x] - shift[y];
        // cari target di a[x];
        if(a[x].lower_bound(make_pair(target, 0)) != a[x].end() && (*a[x].lower_bound(make_pair(target, 0))).first == target) {
          //cout << d[x] << endl;
          //cout << i.first + shift[y] << " " << (*a[x].lower_bound(make_pair(target, 0))).first + shift[x] << endl;
          //cout << i.second << " " << (*a[x].lower_bound(make_pair(target, 0))).second << endl;
          res = min(res, (*a[x].lower_bound(make_pair(target, 0))).second + i.second - 2 * d[x]);
        }
      }
      for(auto i : a[y]) {
        auto tmp = i;
        tmp.first += shift[y] - shift[x];
        //cout << x << " " << shift[x] << " " << tmp.first << " " << tmp.second << endl;
        a[x].insert(tmp);
      }
      //for(auto i : a[x]) {
        //cout << "CUR " << x << " " << shift[x] << " " << i.first << " " << i.second << endl;
      //}
    }
    return x != y;
  }
};

disjoint_set dsu;
void dfs(int nd = 0) {
  //cout << "NODE " << nd << " " << depth[nd] << endl;
  vis[nd] = 1;
  dsu.a[nd].insert(make_pair(0, depth[nd]));
  dsu.d[nd] = depth[nd];
  for(auto i : edges[nd]) {
    if(!vis[i.first]) {
      depth[i.first] = depth[nd] + 1;
      dfs(i.first);
      dsu.shift[dsu.fh(i.first)] += i.second;
      //cout << "MERGE " << nd << endl;
      dsu.merge(i.first, nd);
    }
  }
}

int best_path(int N, int K, int H[][2], int L[])
{
  l = K;
  for(int i = 0; i < N - 1; ++i) {
    edges[H[i][0]].push_back(make_pair(H[i][1], L[i]));
    edges[H[i][1]].push_back(make_pair(H[i][0], L[i]));
  }
  dfs();
  if(res == 1e9)
    return -1;
  else
    return res;
}

