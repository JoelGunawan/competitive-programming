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
  int n, m, k;
  cin >> n >> m >> k;
  ll a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  ll tmp = (m / (k + 1) * k + m % (k + 1));
  // cerr << a[n - 1] << " " << a[n] << endl;
  // cerr << a[n] * tmp << " " << a[n - 1] * (m - tmp) << endl;
  cout << a[n] * tmp + a[n - 1] * (m - tmp) << endl;
  return 0;
}