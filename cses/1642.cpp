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
  int n, x;
  cin >> n >> x;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  unordered_map<int, int> suf;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j)
      ++suf[a[i] + a[j]];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (suf[x - a[i] - a[j]] > 0) {
        // FOUND
        for (int k = i + 1; k <= n; ++k) {
          for (int l = k + 1; l <= n; ++l) {
            if (a[i] + a[j] + a[k] + a[l] == x) {
              cout << i << " " << j << " " << k << " " << l << endl;
              return 0;
            }
          }
        }
      } 
    }

    for (int j = i + 1; j <= n; ++j) {
      --suf[a[i] + a[j]];
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}