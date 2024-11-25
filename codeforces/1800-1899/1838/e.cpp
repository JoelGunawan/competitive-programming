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
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    // a doesn't matter -> sum of C(m, 0) * powmod(k - 1, m - 0) + C(m, 1) * powmod(k - 1, m - 1) + C(m, 2) * powmod(k - 1, m - 2) * ... *
    // ... * C(m, n - 1) * powmod(k - 1, m - (n - 1))
    // get values of C(m, n):
    // C(m, i) = C(m, i - 1) * (m - (i - 1)) / i 
    ll init = 1, res = 0;
    for(int i = 0; i < n; ++i) {
      res += mul(init, powmod(k - 1, m - i));
      init = mul(init, mul(m - i, powmod(i + 1, mod - 2)));
    }
    res = powmod(k, m) - res;
    res %= mod;
    if(res < 0)
      res += mod;
    res %= mod;
    cout << res << endl;
  }
  return 0;
}