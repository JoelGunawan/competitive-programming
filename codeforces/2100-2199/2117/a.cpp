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
void tc() {
  int n, x;
  cin >> n >> x;
  char a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int mn = n, mx = 1;
  for(int i = 1; i <= n; ++i) {
    if(a[i] == '1') {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  // cerr << mx << " " << mn << endl;
  cout << ((mx - mn + 1 <= x) ? "YES" : "NO") << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}