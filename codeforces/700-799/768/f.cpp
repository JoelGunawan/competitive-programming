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
int mod = 1e9 + 7;
const int lim = 2e5 + 5;
ll fact[lim], inv[lim];
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
  if(a < b)
    return 0;
  return mul(fact[a], mul(inv[a - b], inv[b]));
}
// x: number of groups, y: number of objects
// at least one in all
ll star_bar(ll x, ll y) {
  if(y < x || y < 0 || x < 0)
    return 0;
  return combinmod(y - 1, y - x);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i) {
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  }
  int f, w, h;
  cin >> f >> w >> h;
  if(f == 0 || w == 0) {
    if(w == 0 || w > h)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  ll ways = 0;
  // count all ways, how many first
  // fwfw...
  for(int i = 2; i <= f + w; ++i) {
    int wg = (i + 1) / 2, fg = i / 2;
    // cerr << wg << " " << fg << " " << star_bar(wg, w) << " " << star_bar(fg, f) << endl;
    if(wg > w || fg > f)
      break;
    ways += mul(star_bar(wg, w), star_bar(fg, f));
  }
  // cerr << ways << endl;
  // wfwf...
  for(int i = 2; i <= f + w; ++i) {
    int wg = i / 2, fg = (i + 1) / 2;
    if(wg > w || fg > f)
      break;
    ways += mul(star_bar(wg, w), star_bar(fg, f));
  }
  // count valid ways
  // fwfw...
  ll valid = 0;
  for(int i = 2; i <= f + w; ++i) {
    int wg = (i + 1) / 2, fg = i / 2;
    if(w < 1ll * wg * (h + 1) || fg > f)
      break;
    valid += mul(star_bar(wg, w - wg * h), star_bar(fg, f));
  }
  // wfwf...
  for(int i = 2; i <= f + w; ++i) {
    int wg = i / 2, fg = (i + 1) / 2;
    if(w < 1ll * wg * (h + 1) || fg > f)
      break;
    valid += mul(star_bar(wg, w - wg * h), star_bar(fg, f));
  }
  ways %= mod, valid %= mod;
  cout << mul(valid, powmod(ways, mod - 2)) << endl;
  return 0;
}