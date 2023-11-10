#include <bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 5;
struct fenwick {
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void upd(int idx, int val) {
    ++idx;
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int q(int idx) {
    ++idx;
    int ret = 0;
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
  int q(int l, int r) {
    return q(r) - q(l - 1);
  }
};
long long minimum_actions(int N, std::vector<int> A) {
  fenwick bit;
  // coba N <= 3000 dulu
  int l[N + 1], r[N + 1];
  memset(l, -1, sizeof(l));
  for(int i = 0; i < 2 * N; ++i) {
    //cout << A[i] << " " << l[A[i]] << endl;
    if(l[A[i]] == -1)
      l[A[i]] = i;
    else
      r[A[i]] = i;
  }
  long long res = 0;
  for(int i = 1; i <= N; ++i) {
    //cout << "DEB " << l[i] << " " << r[i] << endl;
    res += r[i] - l[i] - 1;
  }
  long long red1 = 0, red2 = 0;
  for(int i = 0; i < 2 * N; ++i) {
    // cek count 1 dan count 2 di tengah ada berapa
    // yg count 1 cmn perlu dihitung sekali
    if(r[A[i]] == i) {
      // cari count 2 berapa
      int cnt2 = bit.q(l[A[i]] + 1, r[A[i]] - 1);
      int cnt1 = r[A[i]] - l[A[i]] - 1 - 2 * cnt2;
      red1 += cnt1;
      red2 += cnt2;
      bit.upd(l[A[i]], 1);
    }
  }
  //cout << res << " " << ret << endl;
  return res - red1 / 2 - 2 * red2 + N;
}