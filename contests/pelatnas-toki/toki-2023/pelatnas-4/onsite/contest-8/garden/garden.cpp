#include "garden.h"

#include <bits/stdc++.h>
using namespace std;
// simpan max height yg dibutuhkan
const int lim = 5005;
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
      h[y] = x;
      sz[x] += sz[y];
    }
  }
};
int minimum_cells(int N, int M, int D, std::vector<int> P, std::vector<int> Q,
                  std::vector<int> R, std::vector<int> S) {
  // d^3
  assert(N != 0);
  int pre[D];
  memset(pre, 0, sizeof(pre));
  for(int i = 0; i < N; ++i)
    ++pre[P[i]];
  for(int i = 1; i < D; ++i)
    pre[i] = pre[i - 1] + pre[i];
  // (ini utk tiap height)
  int last_occur[D];
  bool exist[D][D];
  memset(exist, 0, sizeof(exist));
  memset(last_occur, -1, sizeof(last_occur));
  for(int i = 0; i < M; ++i) {
    // di ketinggian x, posisi S[i] bisa
    last_occur[S[i]] = max(last_occur[S[i]], R[i]);
    exist[R[i]][S[i]] = 1;
  }
  for(int i = 0; i < N; ++i)
    last_occur[Q[i]] = -2; // -> ga ada
  // coba expand ke kanan
  int res = D * D;
  for(int i = 0; i < D; ++i) {
    // simpan di horizontal ke-i kita perlu hapus apa dr multiset
    disjoint_set dsu;
    bool allow[D];
    vector<int> change[D];
    memset(allow, 0, sizeof(allow));
    int mx = 0;
    for(int j = 0; j < D; ++j) {
      if(last_occur[j] == -2) {
        // selalu gaboleh
      }
      else if(last_occur[j] == -1) {
        // -> boleh diambil lgsg
        allow[j] = 1;
        if(allow[(j + 1) % D])
          dsu.merge(j, (j + 1) % D);
        if(allow[(j - 1 + D) % D])
          dsu.merge((j - 1 + D) % D, j);
        mx = max(mx, dsu.sz[dsu.fh(j)]);
        //cout << j << " " << dsu.sz[dsu.fh(j)] << endl;
      }
      else {
        change[last_occur[j]].push_back(j);
      }
    }
    for(int j = 0; j < D; ++j) {
      int l = i, r = (i + j) % D;
      // given L, R do merge, find max
      for(auto j : change[r]) {
        allow[j] = 1;
        if(allow[(j + 1) % D])
          dsu.merge(j, (j + 1) % D);
        if(allow[(j - 1 + D) % D])
          dsu.merge((j - 1 + D) % D, j);
        mx = max(mx, dsu.sz[dsu.fh(j)]);
        //cout << j << " " << dsu.sz[dsu.fh(j)] << endl;
      }
      // make sure between l to r itu bisa semua type 1
      bool valid;
      if(l <= r) {
        valid = (pre[r] - (l == 0 ? 0 : pre[l - 1])) == N;
      }
      else {
        valid = (pre[r] + pre[D - 1] - pre[l - 1]) == N;
      }
      //if(valid)
      //  cout << l << " " << r << " " << (j + 1) << " " << (D - mx) << endl;
      if(D - mx == 0) {

      }
      if(valid)
        res = min(res, (j + 1) * (D - mx));
    } 
    for(int j = 0; j < D; ++j) {
      if(exist[i][j] && last_occur[j] != -2)
        last_occur[j] = i;
    }   
  }
  return res;
}
