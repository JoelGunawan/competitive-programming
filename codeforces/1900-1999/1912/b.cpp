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
const int lim = 2e5 + 5;
int mod = 998244353;
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
  if(b > a)
    return 0;
  return mul(fact[a], mul(inv[b], inv[a - b]));
}
ll sum(ll n) {
  ll half = n / 2;
  if(n & 1) {
    return half * (half - 1) + half;
  }
  else {
    return half * (half - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i)
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    ll fixed = n / (2 * k), rem = n % (2 * k);
    // edge case for fixed = 0, all must have at least 1
    if(fixed == 0) {
      // cout << "TEMP" << endl;
      // everything must have 1, then rem can be distributed wherever
      rem -= k + 1;
      // first/last can not be added
      // only mid points
      cout << 0 << " " << combinmod(k - 1, rem) << endl;
      continue;
    }
    ll mn = rem * fixed + sum(fixed * 2) * k;
    ll ways = 0;
    // cerr << "CUR " << n << " " << k << endl;
    for(int i = 0; i <= k; ++i) {
      // consider i groups are 1
      // consider when first/last combo are 1 or not
      int rest = rem - i;
      if(rest < 0 || (rest & 1))
        continue;
      else {
        int two = rest / 2;
        // cerr << i << " " << combinmod(k - 1, i) << " " << combinmod(k - i, two) << endl;
        if(i == 0)
          ways += combinmod(k - i, two);
        else {
          // from remaining, consider when first/last not 1
          ways += combinmod(k - 1, i) * combinmod(k - i, two);
          // from remaining, consider when first/last is 1
          ways += combinmod(k - 1, i - 1) * combinmod(k - i, two) * 2;
        }
        ways %= mod;
      }
    }
    cout << mn << " " << ways << endl;
  }
  return 0;
}