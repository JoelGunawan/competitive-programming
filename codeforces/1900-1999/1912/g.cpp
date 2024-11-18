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
struct sum_seg {
  ll lazy[2 * lim], a[2 * lim];
  sum_seg() {
    memset(lazy, 0, sizeof(lazy));
    memset(a, 0, sizeof(a));
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      lazy[2 * nd] += lazy[nd];
      lazy[2 * nd + 1] += lazy[nd];
    }
    a[nd] += (cr - cl + 1) * lazy[nd];
    lazy[nd] = 0;
  }
  void update(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazy[nd] += val;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      udpate((nd << 1) | 1, mid + 1, cr, l, r, val);
      a[nd] = a[2 * nd] + a[2 * nd + 1];
    }
  }
  void update(int l, int r, int val) {
    update(1, 0, lim - 1, l, r, val);
  }
  ll query(int nd, int cl, int cr, int l, int r) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return query(nd << 1, cl, mid, l, r) + query((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }
  ll query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
};
struct max_seg {
  ll lazy[2 * lim];
  pair<ll, ll> a[2 * lim];
  max_seg() {
    memset(lazy, 0, sizeof(lazy));
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      lazy[2 * nd] += lazy[nd];
      lazy[2 * nd + 1] += lazy[nd];
    }
    a[nd].fi += lazy[nd];
    lazy[nd] = 0;
  }
  void update(int nd, int cl, int cr, int l, int r, int val) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazy[nd] += val;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      udpate((nd << 1) | 1, mid + 1, cr, l, r, val);
      a[nd] = max(a[2 * nd], a[2 * nd + 1]);
    }
  }
  void update(int l, int r, int val) {
    update(1, 0, lim - 1, l, r, val);
  }
  ll query(int nd, int cl, int cr, int l, int r) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
  ll query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  ll a[n + 2];
  sum_seg segs;
  max_seg segm;
  for(int i = 0; i <= n + 1; ++i)
    segm.a[i + lim].se = i;
  for(int i = 1; i <= n; ++i)
    cin >> a[i], segs.update(i, i, a[i]), segm.update(i, i, a[i]);
  set<int> pref, suff;
  a[0] = a[n + 1] = 0;
  pref.ins(0), suff.ins(n + 1);
  for(int i = 1; i <= n; ++i) {
    if(a[i] > a[*--pref.end()])
      pref.ins(i);
  }
  for(int i = n; i >= 1; --i) {
    if(a[i] > a[*suff.begin()])
      suff.ins(i);
  }
  // calculate the answer
  ll ans = 0;
  vector<int> v;
  for(auto x : pref) 
    v.pb(x);
  for(int i = 0; i < v.size() - 1; ++i) {
    // left is i, right is i + 1
    ans += (v[i + 1] - v[i] - 1) * a[v[i]] - query(v[i] + 1, v[i + 1] - 1);
  }
  v.clear();
  for(auto x : suff)
    v.pb(x);
  reverse(v.begin(), v.end());
  for(int i = 0; i < v.size() - 1; ++i) {
    // left is i, right is i + 1
    ans += (v[i + 1] - v[i] - 1) * a[v[i]] - query(v[i] + 1, v[i + 1] - 1);
  }
  if(*--pref.end() != *suff.begin()) {
    int l = *--pref.end(), r = *suff.begin();
    ans += (r - l - 1) * a[l] - query(l + 1, r - 1);
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    if(pref.lower_bound(x))
  }
  return 0;
}