#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
using namespace std;
const int lim = 1 << 19;
struct max_segtree {
  int a[2 * lim];
  max_segtree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = max(a[idx << 1], a[(idx << 1) + 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd]; 
    }
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r), query((nd << 1) + 1, mid + 1, cr, l, r));
    }
  }
  int query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
};
struct min_segtree {
  int a[2 * lim];
  min_segtree() {
    fill(a, a + 2 * lim, 1e9);
  }
  void update(int idx, int val) {
    // assert(val);
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = min(a[idx << 1], a[(idx << 1) + 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    // cout << cl << " " << cr << " " << a[nd] << endl;
    if(cl >= l && cr <= r) {
      return a[nd]; 
    }
    else if(cl > r || cr < l)
      return 1e9;
    else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) + 1, mid + 1, cr, l, r));
    }
  }
  int query(int l, int r) {
    // cout << "GET " << l << " " << r << endl;
    return query(1, 0, lim - 1, l, r);
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  // update 2 -> ignore?
  // update 1 -> swap
  // query -> query rectangle
  // observe that we need to find the smallest element not in the rectangle
  // update 2 is simply a shift
  // update 1 is kind of hard?
  // in other words we need to find the mex in a random rectangle with swaps and shifts
  // O(NQ) works
  // O(NMQ) doesn't
  // precompute a structure for each row that will maintain contiguous segments?
  // let's say there are no shifts and swaps
  // therefore for any rectangle we need to be able to compute mex in O(N) or O(M)
  // find smallest index such that something is outside
  pair<int, int> a[n * m + 5];
  int arr[n + 5][m + 5];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      arr[i][j] = x;
      a[x] = mp(i, j);
    }
  }
  min_segtree mnr, mnc;
  max_segtree mxr, mxc;
  for(int i = 0; i < n * m; ++i) {
    mnr.update(i, a[i].fi);
    mnc.update(i, a[i].se);
    mxr.update(i, a[i].fi);
    mxc.update(i, a[i].se);
    mnr.update(i + n * m, a[i].fi);
    mnc.update(i + n * m, a[i].se);
    mxr.update(i + n * m, a[i].fi);
    mxc.update(i + n * m, a[i].se);
  }
  int q;
  cin >> q;
  int shift = 0;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      // swap
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      swap(arr[r1][c1], arr[r2][c2]);
      int x = arr[r1][c1], y = arr[r2][c2];
      // di array a swap posisi x, y
      swap(a[x], a[y]);
      mnr.update(x, a[x].fi);
      mnc.update(x, a[x].se);
      mxr.update(x, a[x].fi);
      mxc.update(x, a[x].se);
      mnr.update(x + n * m, a[x].fi);
      mnc.update(x + n * m, a[x].se);
      mxr.update(x + n * m, a[x].fi);
      mxc.update(x + n * m, a[x].se);
      mnr.update(y, a[y].fi);
      mnc.update(y, a[y].se);
      mxr.update(y, a[y].fi);
      mxc.update(y, a[y].se);
      mnr.update(y + n * m, a[y].fi);
      mnc.update(y + n * m, a[y].se);
      mxr.update(y + n * m, a[y].fi);
      mxc.update(y + n * m, a[y].se);
    }
    else if(t == 2) {
      int x;
      cin >> x;
      shift -= x;
      if(shift < 0)
        shift += n * m;
    }
    else {
      // bsta
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      int l = 0, r = (r2 - r1 + 1) * (c2 - c1 + 1), ans = -1;
      // cout << "Query " << shift << endl;
      while(l <= r) {
        int mid = (l + r) / 2;
        // shift menentukan posisi awal, ez
        // cout << "DEBUG " << mid << endl;
        // cout << mnr.query(shift, shift + mid - 1) << " " << mxr.query(shift, shift + mid - 1) << " " << mnc.query(shift, shift + mid - 1) << " " << mxc.query(shift, shift + mid - 1) << endl;
        if(mnr.query(shift, shift + mid - 1) < r1 || mxr.query(shift, shift + mid - 1) > r2 || mnc.query(shift, shift + mid - 1) < c1 || mxc.query(shift, shift + mid - 1) > c2)
          r = mid - 1;
        else
          l = mid + 1, ans = mid;
      }
      if(ans == n * m)
        cout << -1 << endl;
      else
        cout << ans << endl;
    }
  }
}