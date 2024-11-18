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
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int myrandom(int i) {
  return rng() % i;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n = 10000;
  vector<int> v;
  for(int i = 1; i <= n; ++i)
    v.pb(i);
  int cnt = 1000;
  ll pref[n + 1];
  int res = 0;
  memset(pref, 0, sizeof(pref));
  while(cnt--) {
    random_shuffle(v.begin(), v.end(), myrandom);
    for(int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + v[i - 1];
    int x = 0;
    for(int i = 100; i <= n / 2 - 100; ++i) {
      for(int j = 1; j + i - 1 <= n; ++j) {
        if(pref[i + j - 1] - pref[j - 1] == 1ll * i * i) {
          ++x;
        }
      }
    }
    if(x)
      ++res;
  }
  cout << n << " " << cnt << " " << res << endl;
  return 0;
}