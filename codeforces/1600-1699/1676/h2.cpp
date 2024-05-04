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
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    int ret = 0;
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
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  fenwick bit;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
      bit.upd(i, -bit.query(i));
    }
    int a[n + 1];
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
      res += bit.query(a[i], n);
      bit.upd(a[i], 1);
    }
    cout << res << endl;
  }
  return 0;
}