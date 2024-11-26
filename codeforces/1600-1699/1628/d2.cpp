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
const int lim = 1e6 + 5;
ll fact[lim], inv[lim], pow2[lim];
int mod = 1e9 + 7;
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
  else
    return mul(fact[a], mul(inv[a - b], inv[b]));
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  fact[0] = inv[0] = 1, pow2[0] = 1;
  for(int i = 1; i < lim; ++i)
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  pow2[1] = powmod(2, mod - 2);
  for(int i = 2; i < lim; ++i)
    pow2[i] = mul(pow2[i - 1], pow2[1]);
  int t;
  cin >> t;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    ll res = 0;
    int na = n - m;
    if(na == 0) {
      cout << mul(n, k) << endl;
      continue;
    }
    for(int i = 1; i <= n; ++i) {
      if(n - i - 1 >= na - 1)
        res += mul(combinmod(n - i - 1, na - 1), mul(pow2[n - i], mul(i, k)));
    }
    cout << res % mod << endl;
  }
  return 0;
}