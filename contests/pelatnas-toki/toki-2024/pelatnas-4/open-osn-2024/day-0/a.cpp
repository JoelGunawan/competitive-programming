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
  int n;
  cin >> n;
  int a[n + 5];
  int mn = 1e9, mx = 0;
  double avg = 0;
  cout << fixed << setprecision(5);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i], ++mn, ++mx, mn = min(mn, a[i]), mx = max(mx, a[i]), ++avg, avg += (a[i] - avg) / (double)(i);
    cout << mn << " " << mx << " " << avg << endl;
  }
  return 0;
}