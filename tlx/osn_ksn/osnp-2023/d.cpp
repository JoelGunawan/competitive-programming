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
  int n, k, x;
  cin >> n >> k >> x;
  ll pref[n + 1]; 
  int a[n + 1], b[n + 1];
  pref[0] = 0;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= n; ++i)
    cin >> b[i], pref[i] = pref[i - 1] + b[i];
  int l = 1;
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    if(abs(a[i] - x) > k)
      continue;
    while(abs(a[l] - a[i]) + min(abs(a[l] - x), abs(a[i] - x)) > k)
      ++l;
    res = max(res, pref[i] - pref[l - 1]);
  }
  cout << res << endl;
  return 0;
}