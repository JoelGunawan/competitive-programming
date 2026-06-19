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
    int n, k;
    cin >> n >> k;
    int a[n + 5];
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    set<int> s;
    for (int i = 1; i <= n; ++i)
      s.insert(a[i]);
      
    if (n == s.size()) {
      // case there is 0 unused: P[1], P[2], ... P[N], P[1], P[2], ..., P[N]
      for (int i = 1; i <= k; ++i) {
        cout << a[i] << " ";
      }
      cout << endl;
    } else if (n - 1 == s.size()) {
      // case there is 1 unused
      int spec = -1;
      for (int i = 1; i <= n; ++i) {
        if (s.count(i) == 0) {
          spec = i;
          --k;
          break;
        }
      }

      bool used[n + 1];
      memset(used, 0, sizeof(used));
      used[spec] = 1;
      cout << spec << " ";
      for (int i = 1; i <= n; ++i) {
        if (k > 0 && i != spec && i != a[n]) {
          used[i] = 1;
          cout << i << " ";
          --k;
          break;
        }
      }

      for (int i = 1; i <= n; ++i) {
        if (!used[i] && k > 0) {
          cout << i << " ";
          used[i] = 1;
          --k;
        }
      }

      cout << endl;
    } else {
      // case there are 2 unused: .... A B 1 2 3 ... X
      set<int> unused;
      for (int i = 1; i <= n; ++i) {
        if (s.count(i) == 0)
          unused.insert(i);
      }

      while (k--) {
        if (unused.size()) {
          cout << *unused.begin() << " ";
          unused.erase(unused.begin());
        } else {
          cout << *s.begin() << " ";
          s.erase(s.begin());
        }
      }
      cout << endl;
    }
  }
  return 0;
}