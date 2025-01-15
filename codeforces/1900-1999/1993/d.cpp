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
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if(k == 1) {
    int mx = 0;
    for(int i = 1; i <= n; ++i)
      mx = max(mx, a[i]);
    cout << mx << endl;
    return;
  }
  else if(n <= k) {
    sort(a + 1, a + n + 1);
    cout << a[(n + 1) / 2] << endl;
    return;
  }
  int l = 1, r = n, ans = -1;
  int b[n + 1];
  for(int i = 1; i <= n; ++i)
    b[i] = a[i];
  sort(b + 1, b + n + 1);
  while(l <= r) {
    int m = (l + r) >> 1;
    int mid = b[m];
    int mx[k];
    fill(mx, mx + k, -1e9);
    int mod = 0;
    for(int i = 1; i <= n; ++i) {
      ++mod;
      if(mod == k)
        mod = 0;
      if(mod == 1) 
        mx[mod] = max(mx[mod], (a[i] >= mid ? 1 : -1));
      else
        mx[mod] = max(mx[mod], mx[mod == 0 ? k - 1 : mod - 1] + (a[i] >= mid ? 1 : -1));
    }     
    // cerr << mid << " " << mx[n % k] << endl;
    if(mx[n % k] > 0)
      ans = mid, l = m + 1;
    else
      r = m - 1;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}