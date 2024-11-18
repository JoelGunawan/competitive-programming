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
  ll n, m;
  cin >> n >> m;
  int a[n + 5];
  ll sum = 0;
  for(int i = 1; i <= n; ++i)
    cin >> a[i], sum += a[i];
  if(sum < m) {
    cout << -1 << endl;
    return 0;
  }
  int l = 0, r = 1e6, ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    ll cur = 0;
    for(int i = 1; i <= n; ++i) {
      cur += max(0, a[i] - mid);
    }
    if(cur >= m) {
      ans = mid, l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}