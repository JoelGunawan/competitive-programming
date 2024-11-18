#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
  if(b == 0) {
    return 1;
  }
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  ll a[2 * n + 5];
  ll fact[2 * n + 5];
  fact[0] = 1;
  for(int i = 1; i < 2 * n + 5; ++i)
    fact[i] = mul(fact[i - 1], i);
  for(int i = 1; i <= 2 * n; ++i)
    cin >> a[i];
  // first n cards -> playing area
  // rest -> one by one
  // check contribution, card x in position i
  // total ways: N^{2N}
  ll suff[n + 5];
  memset(suff, 0, sizeof(suff));
  ll cur = 0;
  for(int i = n; i >= 1; --i) {
    cur += mul(powmod(n, i - 1), mul(powmod(n - 1, n - i), fact[n]));
    cur %= mod;
    suff[i] = suff[i + 1] + cur + mul(powmod(n, i - 1), mul(powmod(n - 1, n - i), mul(fact[n], n)));
    // cout << suff[i] << " ";
    suff[i] %= mod;
  }
  // cout << endl;
  // calculate choose in first part
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    ll tmp = res;
    res += mul(suff[1], a[i]);
    // cout << i << " " << res - tmp << endl;
    tmp = res;
    res += mul(a[i], mul(powmod(n - 1, n), mul(fact[n - 1], mul(n, mul(n + 1, powmod(2, mod - 2))))));
    // cout << i << " " << res - tmp << endl;
  } 
  for(int i = n + 1; i <= 2 * n; ++i) {
    res += mul(suff[i - n + 1], a[i]);
    res += mul(a[i], mul(powmod(n, i - n), mul(powmod(n - 1, n - (i - n)), mul(fact[n - 1], mul(n, mul(n + 1, powmod(2, mod - 2)))))));
  }
  cout << res % mod << endl;
  return 0;
}