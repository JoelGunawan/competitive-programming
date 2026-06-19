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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  n = 1 << (n + 1);
  --n;
  int a[n + 5];
  for (int i = 2; i <= n; ++i) cin >> a[i];
  // always balance bottom, then balance top
  ll res = 0;
  for (int i = n / 2; i >= 1; --i) {
    int lhs = a[2 * i], rhs = a[2 * i + 1];
    res += abs(rhs - lhs);
    a[i] += max(lhs, rhs);
  }
  cout << res << endl;
  return 0;
}