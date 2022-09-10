#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
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
      idx /= 2;
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
    if(l > r)
        return 0;
    return query(1, 0, size - 1, l, r);
  }
};
segment_tree segtree;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q, x;
        cin >> n >> q;
        for(int i = 0; i < n; ++i)
            cin >> x, segtree.update(i + 1, x);
        for(int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            cout << gcd(segtree.query(0, l - 1), segtree.query(r + 1, n)) << endl;
        }
        for(int i = 0; i < n; ++i)
            segtree.update(i, 0);
    }
}