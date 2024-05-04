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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, x;
    cin >> n >> x;
    int a[n + 1];
    // bigger than max -> one group
    // smaller than min -> one group
    // between -> don't count
    int mn = 1e9, mx = 0;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
    ll base_res = 0;
    for(int i = 2; i <= n; ++i) {
      base_res += abs(a[i] - a[i - 1]);
    }
    if(mn != 1) {
      // do mn group
      // consider at first, last or minimum
      base_res += min(min(a[1], a[n]) - 1, 2 * (mn - 1));
    }
    if(mx < x) {
      // do mx group
      base_res += min(x - max(a[1], a[n]), 2 * (x - mx));
    }
    cout << base_res << endl;
  }
  return 0;
}