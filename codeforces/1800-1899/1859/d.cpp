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
struct portal {
  int l, r, a, b;
  friend bool operator<(const portal& lhs, const portal& rhs) {
    return lhs.l < rhs.l;
  }
};
void tc() {
  int n;
  cin >> n;
  portal a[n + 1];
  // observe always go right
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r >> a[i].a >> a[i].b;
  }
  int q;
  cin >> q;
  pair<int, int> x[q + 1];
  for(int i = 1; i <= q; ++i) {
    cin >> x[i].fi;
    x[i].se = i;
  }
  sort(a + 1, a + n + 1);
  sort(x + 1, x + q + 1);
  int idx = 1;
  int ans[q + 1];
  int mxr = 0;
  for(int i = 1; i <= q; ++i) {
    mxr = max(mxr, x[i].fi);
    while(idx <= n & a[idx].l <= mxr) {
      mxr = max(mxr, a[idx].b);
      ++idx;
    }
    ans[x[i].se] = mxr;
  }
  for(int i = 1; i <= q; ++i)
    cout << ans[i] << " ";
  cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
      tc();
    return 0;
}