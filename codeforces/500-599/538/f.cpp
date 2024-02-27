// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
const int lim = 2e5 + 5;
struct fenwick {
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void upd(int idx, int val) {
    assert(idx != 0);
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    int ret = 0;
    assert(idx >= 0);
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    // 1...n - 1
    // fi -> p<val, ary>
    // se -> p<l, r>
    vector<pair<pair<int, int>, pair<int, int>>> check;
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j < n; ++j) {
        if(j * (i - 1) + 2 <= n) {
          check.pb(mp(mp(a[i], j), mp(j * (i - 1) + 2, min(j * i + 1, n))));
        }
        else
          break;
      }
    }
    pair<int, int> b[n];
    for(int i = 1; i <= n; ++i)
      b[i - 1] = mp(a[i], i);
    sort(b, b + n);
    sort(check.begin(), check.end());
    fenwick bit;
    int cur = 0;
    int ans[n];
    memset(ans, 0, sizeof(ans));
    for(auto p : check) {
      int val = p.fi.fi, ary = p.fi.se, l = p.se.fi, r = p.se.se;
      while(cur < n && b[cur].fi < val) {
        bit.upd(b[cur++].se, 1);
      }
      ans[ary] += bit.query(l, r);
    }
    for(int i = 1; i < n; ++i)
      cout << ans[i] << " ";
    cout << endl;
    return 0;
}