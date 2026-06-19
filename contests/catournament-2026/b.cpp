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
  ll n, t;
  cin >> n >> t;
  // either two smallest A OR smallest A + multiple of (A + B)
  pair<ll, ll> a[n];
  for (ll i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    a[i] = {x, y};
  }
  sort(a, a + n);
  if (n == 1) {
    if (t >= a[0].fi) {
      cout << 1 + (t - a[0].fi) / (a[0].fi + a[0].se);
    } else {
      cout << 0 << endl;
    }
  } else {
    ll res = 0;
    if (t >= a[0].fi) {
      // 1 only
      res = max(res, 1 + (t - a[0].fi) / (a[0].fi + a[0].se));
      // 1 and 2
      ll cur = t / (a[0].fi + a[1].fi);
      cur *= 2;
      if ((t % (a[0].fi + a[1].fi)) >= a[0].fi) {
        ++cur;
      }
      res = max(res, cur);
    }
    cout << res << endl;
  }
  return 0;
}