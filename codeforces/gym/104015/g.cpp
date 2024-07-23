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
  int n;
  cin >> n;
  pair<int, int> a[n];
  for(int i = 0; i < n; ++i) 
    cin >> a[i].fi >> a[i].se;
  // find count of invalid: 
  // - two problems have same topic
  // - two problems have same difficulty
  // two problems same topic, two problems same difficulty
  // two problems same topic, three problems same difficulty
  // three problem same topic, two problems same difficulty
  // three problems same topic, three problems same difficulty
  // let's say cur is diff a, topic b
  // for every pair a, b try two/three of same a and two/three of same b
  // at most 1e5 pairs?
  // case 2 topic 2 diff
  // yes, because (a, b), (a, c), (d, b) -> b[p] * (c[p.fi] - b[p]) * (d[p.se] - b[p])
  // or (a, b), (a, b), (c, d) -> b[p] * (b[p] - 1) / 2 * (total - c[p.fi] - d[p.se] + b[p])
  // case 3 topic 2 diff
  // (a, b) (a, b) (a, c) -> b[p] * (b[p] - 1) / 2 * (c[p.fi] - b[p])
  // case 2 topic 3 diff
  // (a, b), (a, b), (c, b) -> b[p] * (b[p] - 1) / 2 * (d[p.se] - b[p])
  // case 3 topic 3 diff
  // (a, b) (a, b) (a, b) -> b[p] * (b[p] - 1) * (b[p] - 2) / 6
  map<pair<int, int>, int> b;
  map<int, int> c, d;
  for(auto x : a) {
    ++b[x];
    ++c[x.fi];
    ++d[x.se];
  }
  ll res = 0;
  for(auto p : a) {
    res += 1ll * b[p] * (c[p.fi] - b[p]) * (d[p.se] - b[p]);
    res += 1ll * b[p] * (b[p] - 1) / 2 * (n - c[p.fi] - d[p.se] + b[p]);
    res += 1ll * b[p] * (b[p] - 1) / 2 * (c[p.fi] - b[p]);
    res += 1ll * b[p] * (b[p] - 1) / 2 * (d[p.se] - b[p]);
    res += 1ll * b[p] * (b[p] - 1) * (b[p] - 2) / 6;
    // cout << "DEBUG: " << res << endl;
  }
  cout << 1ll * n * (n - 1) * (n - 2) / 6 - res << endl;
  return 0;
}