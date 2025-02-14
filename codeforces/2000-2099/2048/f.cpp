#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1 << 18;
ll inf = 2e18;
struct segtree {
  pair<ll, int> a[lim << 1];
  segtree() {
    for(int i = 0; i < lim << 1; ++i)
      a[i] = mp(inf, -1);
  }
  void upd(int idx, ll val) {
    int tmp = idx;
    idx += lim;
    a[idx] = mp(val, tmp);
    while(idx) {
      idx >>= 1;
      a[idx] = min(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  pair<ll, int> query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)  
      return a[nd];
    else if(cl > r || cr < l) 
      return mp(inf, -1);
    else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
} seg;
ll a[lim];
ll b[lim];
vector<ll> solve(int l, int r) {
  if(l > r) 
    return vector<ll>(61, 0);
  pair<ll, int> mn = seg.query(1, 0, lim - 1, l, r);
  vector<ll> lv = solve(l, mn.se - 1), rv = solve(mn.se + 1, r);
  vector<ll> ret(61, 2e18);
  int idx = 0;
  for(int i = 0; i < lv.size(); ++i) {
    while(idx + 1 < rv.size() && lv[i] < rv[idx] && i + idx + 1 < ret.size()) {
      ++idx;
    }
    if(i + idx < ret.size())
      ret[i + idx] = min(ret[i + idx], max(lv[i], rv[idx]));
  }
  idx = 0;
  for(int i = 0; i < rv.size(); ++i) {
    while(idx + 1 < lv.size() && rv[i] < lv[idx] && i + idx + 1 < ret.size()) {
      ++idx;
    }
    if(i + idx < ret.size())
      ret[i + idx] = min(ret[i + idx], max(rv[i], lv[idx]));
  }
  // consider a[mn.se]
  for(int i = 0; i < 61; ++i)
    ret[i] = max(ret[i], a[mn.se]);
  for(int i = 1; i < 61; ++i) {
    ret[i] = min(ret[i], ret[i - 1] / mn.fi + (bool)(ret[i - 1] % mn.fi > 0));
  }
  // cerr << "SOLUTION " << l << " " << r << endl;
  // for(int i = 0; i < 10; ++i)
  //   cerr << ret[i] << " ";
  // cerr << endl;
  return ret;
}
void tc() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  for(int i = 1; i <= n; ++i)
    seg.upd(i, b[i]);
  vector<ll> v = solve(1, n);
  for(int i = 0; i < v.size(); ++i) {
    if(v[i] == 1) {
      cout << i << endl;
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}