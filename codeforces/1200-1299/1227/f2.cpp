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
int mod = 998244353;
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
const int lim = 2e5 + 5;
ll fact[lim], inv[lim];
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[a - b], inv[b]));
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = powmod(fact[i], mod - 2);
  }
  int n, k;
  cin >> n >> k;
  int h[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> h[i];
  int cnt_dup = 0;
  for(int i = 1; i <= n; ++i) {
    if(h[i] == h[(i % n) + 1])
      ++cnt_dup;
  }
  // can be any
  ll res = powmod(k, cnt_dup);
  n -= cnt_dup;
  ll res2 = 0;
  for(int i = 1; i <= n; ++i) {
    // i change
    if(i & 1) {
      res2 += mul(combinmod(n, i), mul(powmod(max(0, k - 2), n - i), powmod(2, i - 1)));
    }
    else {
      res2 += mul(combinmod(n, i), mul(powmod(max(0, k - 2), n - i), powmod(2, i - 1) - combinmod(i - 1, i / 2)));
    }
  }
  res2 %= mod;
  if(res2 < 0)
    res2 += mod;
  cout << mul(res, res2) << endl;
  return 0;
}