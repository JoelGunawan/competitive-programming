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
const int lim = 1 << 19;
struct segtree_mx {
  int a[lim << 1];
  segtree_mx() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd];
    }
    else if(cl > r || cr < l) {
      return 0;
    }
    else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
};
struct segtree_mn {
  int a[lim << 1];
  segtree_mn() {
    fill(a, a + (lim << 1), 1e9);
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = min(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd];
    }
    else if(cl > r || cr < l) {
      return 1e9;
    }
    else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
};
segtree_mx mx;
segtree_mn mn;
void solve() {
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  ll diff[n + 5];
  memset(diff, 0, sizeof(diff));
  int l[n + 5], l2[n + 5], r[n + 5], r2[n + 5];
  a[0] = a[n + 1] = 0;
  vector<int> st = {0, 0};
  for(int i = 1; i <= n; ++i) {
    while(a[st.back()] > a[i])
      st.pop_back();
    l[i] = st.back();
    st.pb(i);
  }
  st = {n + 1, n + 1};
  for(int i = n; i >= 1; --i) {
    while(a[st.back()] > a[i])
      st.pop_back();
    r[i] = st.back();
    st.pb(i);
  }
  // calculate previous maximal index that is <= some number
  // can do monotonic set trick (can't work for second minimum)
  // for each number, precompute where we should check l, r
  ll res = 0;
  for(int i = 1; i <= n; ++i)
    mx.update(i, 0), mn.update(i, n + 1);
  for(int i = 1; i <= n; ++i) {
    // we know index of l[i]
    // we need to find, left of l[i], what is less than a[i] (guaranteed none between l[i] and i)
    l2[i] = max(mx.query(1, 0, lim - 1, 0, a[l[i]] - 1), mx.query(1, 0, lim - 1, a[l[i]] + 1, a[i]));
    mx.update(a[i], i);
  }
  for(int i = n; i >= 1; --i) {
    r2[i] = min(mn.query(1, 0, lim - 1, 0, a[r[i]] - 1), mn.query(1, 0, lim - 1, a[r[i]] + 1, a[i]));
    mn.update(a[i], i);
  }
  // for(int i = 1; i <= n; ++i) {
  //   cerr << l2[i] << " " << r2[i] << endl;
  // }
  for(int i = 1; i <= n; ++i) {
    ll cur_res = 1ll * a[i] * (i - l[i]) * (r[i] - i);
    ll left_sub = 1ll * (r[i] - i) * a[i];
    ll right_sub = 1ll * (i - l[i]) * a[i];
    // - 1 added because l[i], r[i] is gone
    ll left_add = 1ll *  (r[i] - i) * (l[i] - l2[i] - 1) * a[i];
    ll right_add = 1ll * (i - l[i]) * (r2[i] - r[i] - 1) * a[i];
    res += cur_res;
    diff[i] -= cur_res; // if eliminated, remove every segment containing this as minimum
    diff[i + 1] += cur_res;
    diff[l[i] + 1] -= left_sub;
    diff[i] += left_sub;
    diff[i + 1] -= right_sub;
    diff[r[i]] += right_sub;
    diff[l[i]] += left_add;
    diff[l[i] + 1] -= left_add;
    diff[r[i]] += right_add;
    diff[r[i] + 1] -= right_add;
  }
  // cout << res << endl;
  res += diff[0];
  for(int i = 1; i <= n; ++i) {
    res += diff[i];
    cout << res << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    solve();
}