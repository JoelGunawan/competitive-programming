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
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int zero = 0;
    for(int i = 1; i <= n; ++i) {
      if(a[i] == 0)
        ++zero; 
    }
    if(m < zero) {
      cout << "Impossible" << endl;
      continue;
    }
    ll tot = 0;
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= n; ++i) {
      if(a[i] == 0)
        used[i] = 1;
      else if(zero < m)
        ++zero, used[i] = 1, tot += a[i];
    }
    if(n == m) {
      cout << "Richman" << endl;
    }
    else {
      int mn = 1e9;
      for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
          mn = min(mn, a[i]);
        }
      }
      cout << tot + mn - 1 << endl;
    }
  }
  return 0;
}