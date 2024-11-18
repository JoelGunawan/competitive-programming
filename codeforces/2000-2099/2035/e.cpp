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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll cur = 0, cur_cost = 0;
    ll res = 1e18;
    for(int i = 1; i <= 2 * sqrt(z); ++i) {
      if(i % k == 0)
        cur += i, cur_cost += y;
      cur_cost += x;
      // cout << cur << " " << cur_cost << endl;
      if(cur >= z)
        res = min(res, cur_cost);
      else
        res = min(res, (ll)ceil((z - cur) / (double)(i)) * y + cur_cost);
    }
    // try to check 1 to sqrt(z) of doing 2nd operations (not mandatory)
    for(int i = 0; i <= sqrt(z); ++i) {
      // try binary search
      int l = 1, r = z, ans = 1;
      // cout << "DEBUG " << i << endl;
      while(l <= r) {
        int mid = (l + r) / 2;
        // cout << ((mid / k) * (mid / k + 1) / 2) * k << " " << mid << " " << ceil((z - ((mid / k) * (mid / k + 1) / 2) * k) / (double)mid) << endl;
        if(ceil((z - ((mid / k) * (mid / k + 1) / 2) * k) / (double)mid) <= i)
          r = mid - 1, ans = mid;
        else
          l = mid + 1;
      }
      // set at ans, what is cost?
      res = min(res, (ll)ceil(max(0ll, z - ((ans / k) * (ans / k + 1) / 2) * k) / (double)ans) * y + ans / k * y + ans * x);
    }
    cout << res << endl;
  }
  return 0;
}