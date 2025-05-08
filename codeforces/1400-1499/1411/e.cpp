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
  ll t;
  cin >> n >> t;
  string s;
  cin >> s;
  s = " " + s;
  ll base = 0;
  base += 1 << (s[n] - 'a');
  base -= 1 << (s[n - 1] - 'a');
  n = n - 2;
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  t -= base;
  t = abs(t);
  for(int i = 25; i >= 0; --i) {
    // just find smallest assignment of multiples
    // t -> our target
    ll mn = 1e18;
    for(int j = 0; j <= cnt[i]; ++j) {
      mn = min(mn, abs(t - 1ll * (1 << i) * j + 1ll * (1 << i) * (cnt[i] - j)));
    }
    t = mn;
  }
  cout << (t == 0 ? "Yes" : "No") << endl;
  return 0;
}