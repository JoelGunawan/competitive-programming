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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t-- ) {
    int n;
    cin >> n;
    ll a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    // sum of all multiplications divided by all pairs
    ll cur_sum = 0, cur = 0;
    for(int i = 1; i <= n; ++i) {
      cur_sum += a[i] * cur;
      cur += a[i];
      cur_sum %= mod;
      cur %= mod;
    }
    ll tmp = powmod((1ll * n * (n - 1) / 2) % mod, mod - 2);
    tmp *= cur_sum;
    tmp %= mod;
    cout << tmp << endl;
  }
  return 0;
}