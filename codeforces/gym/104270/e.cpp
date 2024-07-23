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
    int n; ll m;
    cin >> n >> m;
    ll a[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    ll l = 0, r = 1e18, ans = 0;
    while(l <= r) {
      ll mid = (l + r) / 2, cnt[n + 5];
      memset(cnt, 0, sizeof(cnt));
      for(int i = 1; i <= n; ++i) {
        cnt[i] = mid % a[i] ? mid / a[i] + 1 : mid / a[i];
      }
      ll step = 0;
      for(int i = 1; i <= n; ++i) {
        if(i == n && cnt[i] <= 0)
          break;
        --cnt[i], ++step;
        if(cnt[i] > 0) {
          // go east west
          // last step, not neccessarily have to go west???
          // actually have to because then
          step += 2 * cnt[i], cnt[i + 1] -= cnt[i], cnt[i] = 0;
        }
        if(step > m)
          break;
        // cerr << "DEB " << i << " " << step << endl;
      }
      // cerr << mid << " " << step << endl;
      if(step <= m)
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    cout << ans << endl;  
  }
  return 0;
}