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
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if(a[0] % 2 == a[1] % 2 && a[0] % 2 == a[2] % 2) {
    if(a[0] == a[2]) {
      cout << 0 << endl;
      return 0;
    }
    if(a[1] == 0) {
      cout << -1 << endl;
      return 0;
    }
    // biggest will be decreased to second
    // then equal to second, then close in to a midpoint
    int ops = a[2] - a[1] + (a[1] - a[0]) / 2;
    cout << ops << endl;
  }
  else {
    cout << -1 << endl;
  }
  return 0;
}