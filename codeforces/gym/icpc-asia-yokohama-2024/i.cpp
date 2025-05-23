#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
const int lim = 1 << 17;
struct segment_tree {
  int a[lim << 1];
  segment_tree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = max(a[idx], val);
    while(idx) {
      idx >>= 1;
      a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd];
    }
    else if (cl > r || cr < l) {
      return 0;
    }
    else {
      int mid = (cl + cr) >> 1;
      return max(query((nd << 1), cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
} seg;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int q;
  cin >> q;
  pair<pair<int, int>, int> query[q];
  for(int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    query[i] = mp(mp(r, l), i);
  }
  sort(query, query + q);
  int ans[q];
  memset(ans, -1, sizeof(ans));
  int last[lim];
  memset(last, -1, sizeof(last));
  int idx = 0;
  for(int i = 1; i <= n; ++i) {
    vector<int> v;
    for(int j = 1; 1ll * j * j <= a[i]; ++j) {
      if(a[i] % j == 0) {
        v.pb(a[i] / j);
        v.pb(j);
      }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(auto x : v) {
      if(last[x] != -1) {
        seg.update(last[x], x);
      }
      last[x] = i;
    }
    while(idx < q && query[idx].fi.fi == i) {
      ans[query[idx].se] = seg.query(1, 0, lim - 1, query[idx].fi.se, i);
      ++idx;
    }
  }
  for(int i = 0; i < q; ++i)
    cout << ans[i] << endl;
}