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
  while(t--) {
    int n, m, q;
    cin >> n >> m >> q;
    int b[m];
    for(int i = 0; i < m; ++i)
      cin >> b[i];
    sort(b, b + m);
    while(q--) {
      // check closest left and closest right
      int x;
      cin >> x;
      if(lb(b, b + m, x) == b) {
        // go furthest left
        cout << *lb(b, b + m, x) - 1 << endl;
      }
      else if(lb(b, b + m, x) == b + m) {
        cout << n - b[lb(b, b + m, x) - b - 1] << endl;
      }
      else {
        cout << (*lb(b, b + m, x) - b[lb(b, b + m, x) - b - 1]) / 2 << endl;
      }
    }
  }
  return 0;
}