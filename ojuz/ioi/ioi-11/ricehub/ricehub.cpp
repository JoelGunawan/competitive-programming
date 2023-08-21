#include "ricehub.h"
#include <bits/stdc++.h>
#define ub upper_bound
#define lb lower_bound
using namespace std;
int besthub(int R, int L, int X[], long long B)
{
  // for every median, calculate maximum res di kiri dan di kanan
  // calculate yg exactly maximum res berapa
  // rlog^2r
  int a[R + 1];
  a[0] = 0;
  for(int i = 1; i <= R; ++i)
    a[i] = X[i - 1];
  long long pref[R + 1];
  pref[0] = 0;
  for(int i = 1; i <= R; ++i)
    pref[i] = pref[i - 1] + a[i];
  int ans = 1;
  for(int i = 1; i <= R; ++i) {
    long long l = 1, r = L;
    while(l <= r) {
      int mid = (l + r) / 2;
      // cek klo cost ambil yg < mid brp, yg tepat jarak mid ada berapa
      // cek lower dlu
      int idx1 = ub(a + 1, a + R + 1, a[i] - mid) - a, cntmid = ub(a + 1, a + R + 1, a[i] - mid) - lb(a + 1, a + R + 1, a[i] - mid);
      int idx2 = lb(a + 1, a + R + 1, a[i] + mid) - a - 1;
      cntmid += ub(a + 1, a + R + 1, a[i] + mid) - lb(a + 1, a + R + 1, a[i] + mid);
      // cari prefsum dr idx1 dan idx2
      long long cost = 1ll * (i - idx1 + 1) * a[i] - (pref[i] - (idx1 - 1 >= 0 ? pref[idx1 - 1] : 0));
      //cout << cost << endl;
      cost += (pref[idx2] - pref[i - 1]) - 1ll * a[i] * (idx2 - i + 1);
      //cout << i << "  " << idx1 << " " << idx2 << " " << cost << " " << cntmid << endl;
      if(cost > B) {
        r = mid - 1;
        continue;
      }
      else {
        ans = max((long long)ans, abs(idx2 - idx1) + 1 + min((B - cost) / mid, (long long)cntmid));
        l = mid + 1;
      }
    }
  }
  return ans;
}
