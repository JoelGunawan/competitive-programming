#include "experiment.h"
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define ins insert
using namespace std;
const int lim = 600001;
//const int lim2 = 501;
/*
struct prefix_sum {
  int arr[lim2][lim2];
  prefix_sum() {
    memset(arr, 0, sizeof(arr));
  }
  void build() {
    for(int i = 1; i < lim2; ++i)
      for(int j = 1; j < lim2; ++j)
        arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
  }
  int query(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) {
      return 0;
    }
    return arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
  }
};
*/
struct BIT {
  int arr[lim];
  BIT() {
    memset(arr, 0, sizeof(arr));
  }
  int query(int left, int right) {
    return query(right) - query(left - 1);
  }
  int query(int idx) {
    int res = 0;
    while(idx > 0) {
      res += arr[idx];
      idx -= (idx&-idx);
    }
    return res;
  }
  void update(int idx, int value) {
    while(idx < lim) {
      arr[idx] += value;
      idx += (idx&-idx);
    }
  }
};
std::vector<long long> get_experiment_results(int N, int M,
                                              std::vector<int> P, std::vector<int> Q,
                                              std::vector<int> L, std::vector<int> R,
                                              std::vector<int> D, std::vector<int> U) {
  std::vector<long long> ans(M, -1);
  for(int i = 0; i < M; ++i)
    ++L[i], ++R[i], ++D[i], ++U[i];
  for(int i = 0; i < N; ++i)
    ++P[i], ++Q[i];
  // ada 3 tipe kuadran
  // pertama -> full overlap
  // kedua -> x overlap or y overlap
  // ketiga -> no overlap
  // pertama -> bisa sama 8 kuadran lain
  // kedua -> bisa sama 6 kuadran opposite
  // ketiga -> bisa sama 4 kuadran lain
  // pakai sweep line yang pindah"
  // pindah horizontal dulu terus pindah vertikal -> repeat sampai selesai
  // do a prefix sum for sub 1-3
  /*
  prefix_sum prefsum;
  for(int i = 0; i < N; ++i) {
    ++prefsum.arr[P[i]][Q[i]];
  }
  prefsum.build();
  for(int i = 0; i < M; ++i) {
    // query prefsum
    // use the quadrants approach
    long long arr[9];
    memset(arr, -1, sizeof(arr));
    arr[0] = prefsum.query(1, U[i] + 1, L[i] - 1, N);
    arr[1] = prefsum.query(L[i], U[i] + 1, R[i], N);
    arr[2] = prefsum.query(R[i] + 1, U[i] + 1, N, N);
    arr[3] = prefsum.query(1, D[i], L[i] - 1, U[i]);
    arr[4] = prefsum.query(L[i], D[i], R[i], U[i]);
    arr[5] = prefsum.query(R[i] + 1, D[i], N, U[i]);
    arr[6] = prefsum.query(1, 1, L[i] - 1, D[i] - 1);
    arr[7] = prefsum.query(L[i], 1, R[i], D[i] - 1);
    arr[8] = prefsum.query(R[i] + 1, 1, N, D[i] - 1);
    for(int j = 0; j < 9; ++j)
      cout << arr[j] << " ";
    cout << endl;
    ans[i] = arr[4] * (arr[0] + arr[1] + arr[2] + arr[3] + arr[5] + arr[6] + arr[7] + arr[8]);
    ans[i] += arr[4] * (arr[4] - 1) / 2;
    ans[i] += arr[5] * (arr[0] + arr[1] + arr[3] + arr[6] + arr[7]);
    ans[i] += arr[1] * (arr[3] + arr[6] + arr[7] + arr[8]);
    ans[i] += arr[3] * (arr[2] + arr[7] + arr[8]);
    ans[i] += arr[7] * (arr[0] + arr[2]);
    ans[i] += arr[0] * arr[8] + arr[6] * arr[2];
  }
  */
  // use the fact -> only one index per line
  // transisi vertikal -> total O(N)
  // transisi horizontal -> lebih tricky, tapi bisa dibuat lah :D
  // implement BIT
  BIT cur;
  int add[N + 1];
  for(int i = 0; i < N; ++i)
    add[Q[i]] = P[i];
  // sweep line of y, query_number, left, right, type
  // the "type" meaning whether it is a up or a down
  pair<pair<int, int>, pair<pair<int, int>, bool>> sweep[2 * M];
  for(int i = 0; i < M; ++i) {
    // query between L to R in index D and index U
    sweep[2 * i] = mp(mp(D[i] - 1, i), mp(mp(L[i], R[i]), 0));
    sweep[2 * i + 1] = mp(mp(U[i], i), mp(mp(L[i], R[i]), 1));
  }
  sort(sweep, sweep + 2 * M);
  int l_d[M], m_d[M], r_d[M], l_m[M], m_m[M], r_m[M];
  int bit_pos = 0;
  for(int i = 0; i < 2 * M; ++i) {
    int y = sweep[i].fi.fi, idx = sweep[i].fi.se;
    int left = sweep[i].se.fi.fi, right = sweep[i].se.fi.se;
    bool type = sweep[i].se.se;
    while(bit_pos < y) {
      cur.update(add[++bit_pos], 1);
    }
    // !type is d
    if(!type) {
        l_d[idx] = cur.query(left - 1);
        m_d[idx] = cur.query(left, right);
        r_d[idx] = cur.query(right + 1, N);
    }
    // type is m
    else {
      l_m[idx] = cur.query(left - 1);
      m_m[idx] = cur.query(left, right);
      r_m[idx] = cur.query(right + 1, N);
    }
  }
  while(bit_pos < N) {
    cur.update(add[++bit_pos], 1);
  }
  for(int i = 0; i < M; ++i) {
    long long arr[9];
    arr[0] = cur.query(L[i] - 1) - l_m[i];
    arr[1] = cur.query(L[i], R[i]) - m_m[i];
    arr[2] = cur.query(R[i] + 1, N) - r_m[i];
    l_m[i] -= l_d[i];
    m_m[i] -= m_d[i];
    r_m[i] -= r_d[i];
    arr[3] = l_m[i], arr[4] = m_m[i], arr[5] = r_m[i];
    arr[6] = l_d[i], arr[7] = m_d[i], arr[8] = r_d[i];
    ans[i] = arr[4] * (arr[0] + arr[1] + arr[2] + arr[3] + arr[5] + arr[6] + arr[7] + arr[8]);
    ans[i] += arr[4] * (arr[4] - 1) / 2;
    ans[i] += arr[5] * (arr[0] + arr[1] + arr[3] + arr[6] + arr[7]);
    ans[i] += arr[1] * (arr[3] + arr[6] + arr[7] + arr[8]);
    ans[i] += arr[3] * (arr[2] + arr[7] + arr[8]);
    ans[i] += arr[7] * (arr[0] + arr[2]);
    ans[i] += arr[0] * arr[8] + arr[6] * arr[2];
  }
  return ans;
}
