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
// Joel's solution
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n; ll m;
  cin >> n >> m;
  ll a[n];
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if(n <= 5) {
    int res = 0;
    for(int i = 0; i < 1 << n; ++i) {
      ll sum = 0;
      for(int j = 0; j < n; ++j) {
        if((1 << j) & i)
          sum += a[j];
      }
      if(sum <= m) {
        ++res;
      }
    }
    cout << res << endl;
  }
  else {
    vector<ll> v1, v2;
    for(int i = 0; i < 1 << n / 2; ++i) {
      ll sum = 0;
      for(int j = 0; j < n / 2; ++j) {
        if((1 << j) & i)
          sum += a[j];
      }
      if(sum <= m)
        v1.pb(sum);
    }
    for(int i = 0; i < 1 << (n - n / 2); ++i) {
      ll sum = 0;
      for(int j = 0; j < n - n / 2; ++j) {
        if((1 << j) & i)
          sum += a[j + n / 2];
      }
      if(sum <= m)
        v2.pb(sum);
    }
    ll res = 0;
    sort(v2.begin(), v2.end());
    for(auto x : v1) {
      res += ub(v2.begin(), v2.end(), m - x) - v2.begin();
    }
    cout << res << endl;
  }
  return 0;
}