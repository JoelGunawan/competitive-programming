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
ll fact[lim], inv[lim];
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
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[b], inv[a - b]));
}
void tc() {
  ll l, n;
  cin >> l >> n;
  ll res = combinmod(l, 2 * n);
  for(int i = 0; i <= l; i += 2) {
    int even_cnt = i / 2;
    int rest_cnt = l - i - 2 * n;
    if(rest_cnt < 0)
      break;
    res -= mul(combinmod(even_cnt + n - 1, n - 1), combinmod(rest_cnt + n, n));
  }
  res *= 2;
  res %= mod;
  if(res < 0)
    res += mod;
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = powmod(fact[i], mod - 2);
  }
  while(t--) 
    tc();
  
  return 0;
}