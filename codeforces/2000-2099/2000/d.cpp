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
  // greedy pair front and back
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    string s;
    cin >> s;
    s = " " + s;
    ll pref[n + 1], ans;
    pref[0] = ans = 0;
    for(int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + a[i];
    }
    int l = 1, r = n;
    vector<pair<int, int>> v;
    while(l <= r) {
      while(l <= n && s[l] != 'L')
        ++l;
      while(r >= 1 && s[r] != 'R')
        --r;
      if(l <= r) {
        v.pb(mp(l, r));
        ++l, --r;
      }
    }
    for(auto p : v) {
      ans += pref[p.se] - pref[p.fi - 1];
    }
    cout << ans << endl;
  }
  return 0;
}