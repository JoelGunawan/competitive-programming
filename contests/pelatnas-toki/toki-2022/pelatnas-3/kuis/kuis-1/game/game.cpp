#include "game.h"
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
using namespace std;
const int lim = 1 << 17;
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
struct segment_tree {
  int a[2 * lim], size = lim;
  segment_tree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += size;
    a[idx] = val;
    while(idx > 1) {
        idx >>= 1;
        a[idx] = gcd(a[2 * idx], a[2 * idx + 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    int mid = (cl + cr) / 2;
    if(cl > r || cr < l)
      return 0;
    else if(cl >= l && cr <= r)
      return a[nd];
    else
      return gcd(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
  }
  int query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }
};
segment_tree segtree;
int N;
void init(std::vector<int> B) {
  N = B.size();
  for(int i = 0; i < N; ++i)
    segtree.update(i + 1, B[i]);
  return;
}

long long modify(int i, int x) {
  ++i;
  segtree.update(i, x);
  //cout << "PREF SUFF Q" << endl;
  //for(int i = 1; i <= N; ++i)
  //  cout << segtree.pref_query(i, i) << " " << segtree.suff_query(i, i) << " " << segtree.query(i, i) << endl;
  int le = 1, re = N - 1, ans = -1;
  while(le <= re) {
    int mid = (le + re) / 2;
    if(segtree.query(mid + 1, N) <= segtree.query(0, mid))
      ans = mid, le = mid + 1;
    else
      re = mid - 1;
  }
  if(ans == -1) {
    // buat semuanya prefix
    ll cur = 1, res = 0;
    while(cur <= N) {
      int l = cur, r = N, furthest = -1;
      while(l <= r) {
        int mid = (l + r) / 2;
        if(segtree.query(0, mid) == segtree.query(0, cur))
          furthest = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      res += (furthest - cur + 1) * segtree.query(0, cur);
      cur = furthest + 1;
    }
    return res;
  }
  ll res = 0, cur = 2;
  while(cur <= ans + 1) {
    int l = cur, r = ans + 1, furthest = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(segtree.query(cur, N) == segtree.query(mid, N))
        furthest = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    res += 1ll * (furthest - cur + 1) * segtree.query(cur, N);
    cur = furthest + 1;
  }
  cur = ans + 1;
  while(cur <= N) {
    int l = cur, r = N, furthest = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(segtree.query(0, mid) == segtree.query(0, cur))
        furthest = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    res += (furthest - cur + 1) * segtree.query(0, cur);
    cur = furthest + 1;
  }
  return res;
}