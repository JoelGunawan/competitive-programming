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
    int n;
    cin >> n;
    int a[n + 1];
    map<int, int> cnt;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
      ++cnt[a[i]];
    }
    sort(a + 1, a + n + 1);
    // > 1 occur -> both lis and lds
    // 1 occur -> only lis/lds except for one elem
    int one = 0, two = 0;
    for(auto p : cnt) {
      if(p.se == 1) {
        ++one;
      }
      else {
        ++two;
      }
    }
    if(one) {
      cout << two + (one + 1) / 2 << endl;
    }
    else {
      cout << two << endl;
    }
  }
  return 0;
}