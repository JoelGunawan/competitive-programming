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
  int n;
  cin >> n;
  cout << n / 3 * 2 + ((n % 3) > 0) << endl;
  // construct a solution for 3x+2, then extend to n
  int num_prev = (n + 1) / 3;
  // construct num_prev
  vector<pair<int, int>> ans;
  int cnt = 2 * (num_prev - 1) + 1;
  int top = cnt / 2 + 1, bottom = cnt / 2;
  for(int i = 0; i < bottom; ++i) {
    int tmp = num_prev * 3 - 1;
    ans.pb(mp(tmp - i, tmp - bottom + i + 1));
  }
  for(int i = 0; i < top; ++i) {
    ans.pb(mp(top - i, i + 1));
  }
  if(n % 3 == 1) {
    if(n > 1)
      ans.pb(mp(n - 1, n - 1));
    ans.pb(mp(n, n));
  }
  else if (n % 3 == 0) {
    ans.pb(mp(n, n));
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  for(auto x : ans) {
    cout << x.fi << " " << x.se << endl;
  }
  return 0;
}