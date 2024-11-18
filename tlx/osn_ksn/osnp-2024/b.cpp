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
  ll b, c, d;
  cin >> b >> c >> d;
  if(c == d) {
    cout << max(b - c, 0ll) << endl;
    return 0;
  }
  vector<ll> v;
  for(int i = 1; i <= sqrt(c - d); ++i)
    if((c - d) % i == 0)
      v.pb(i), v.pb((c - d) / i);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  int res = 0;
  for(auto x : v) {
    if(x > d && x <= b) {
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}