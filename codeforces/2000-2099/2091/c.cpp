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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto norm = [n] (int x) -> int {
      if (x > n) x -= n;
      if (x < 1) x += n;
      return x;
    };
    if (n & 1) {
      for (int i = 0; i < n / 2; ++i) {
        cout << norm(n / 2 + 2 + 2 * i) << " ";
      }
      for (int i = n / 2; i < n; ++i) {
        cout << norm(2 * i + 1 - n / 2) << " ";
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}