// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
ll query(ll a) {
  cout << "query " << a << endl;
  ll x;
  cin >> x;
  return x;
}
int main() {
  // interactive
  // for each digit -> 4 queries
  // actually can probably do in 2 queries (no, because edge case)
  // do from largest digit instead?
  // possible, choose a number such that the final result is not linear with the addition
  ll pr = query(0), prnum = 0;
  ll pow[18];
  pow[0] = 1;
  for(int i = 1; i < 18; ++i)
    pow[i] = pow[i - 1] * 10;
  ll res = 0;
  for(int i = 17; i >= 0; --i) {
    int l = 1, r = 9, ans = -1;
    ll q[10];
    while(l <= r) {
      int mid = (l + r) / 2;
      ll tmp = query(prnum + pow[i] * mid);
      if(tmp != mid + pr) {
        r = mid - 1;
        ans = mid;
        q[mid] = tmp;
      }
      else {
        l = mid + 1;
      }
    }
    // if answer is -1, cur is 0
    if(ans != -1) {
      pr = q[ans], prnum += ans * pow[i];
      res += (10 - ans) * pow[i];
    }
  }
  cout << "answer " << res << endl;
  return 0;
}