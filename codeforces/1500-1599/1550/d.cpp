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
const int lim = 2e5 + 5;
ll fact[lim], inv[lim];
int mod = 1e9 + 7;
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
  if(a < b || a < 0 || b < 0)
    return 0;
  return mul(fact[a], mul(inv[a - b], inv[b]));
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
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = powmod(fact[i], mod - 2);
  }
  while(t--) {
    int n, l, r;
    cin >> n >> l >> r;
    int px[n + 1], nx[n + 1];
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
      px[i] = r - i;
      nx[i] = i - l;
    }
    if(px[n] > 0 && nx[1] > 0) {
      ll x = combinmod(n, n / 2);
      if(n & 1) {
        x = mul(2, x);
      }
      res += mul(min(px[n], nx[1]) - 1, x);
    }
    if(l - n > 1 - r) {
      // do neg first
      int pos = n;
      for(int i = 1; i <= n; ++i) {
        if(px[pos - 1] == nx[i]) 
          --pos;
        if(nx[i] == 0)
          continue;
        int le = n - i + 1, re = pos, both = pos - i + 1;
        if(both < 0)
          break;
        if(n & 1) {
          if(le < n / 2 || re < n / 2 || (le == n / 2 && re == n / 2))
            break;
          le -= both, re -= both;
          int rl = n / 2 - le, rr = n / 2 - re;
          res += combinmod(rl + rr + 1, rl);
          res += combinmod(rl + rr + 1, rr);
        }
        else {
          // calculate only n / 2
          if(le < n / 2 || re < n / 2) {
            break;
          }
          le -= both, re -= both;
          int rl = n / 2 - le, rr = n / 2  - re;
          res += combinmod(rl + rr, rl);
        }
      }
    }
    else {
      // do pos first
      int neg = 1;
      for(int i = n; i >= 1; --i) {
        if(nx[neg + 1] == px[i])
          ++neg;
        if(px[i] == 0)
          continue;
        int le = i, re = n - neg + 1, both = i - neg + 1;
        if(both < 0) {
          break;
        }
        if(n & 1) {
          // calculate both possibilities
          if(le < n / 2 || re < n / 2 || (le == n / 2 && re == n / 2))
            break;
          le -= both, re -= both;
          int rl = n / 2 - le, rr = n / 2 - re;
          //cout << le << " " << re << " " << rl << " " << rr << endl;
          res += combinmod(rl + rr + 1, rl);
          res += combinmod(rl + rr + 1, rr);
        }
        else {
          // calculate only n / 2
          if(le < n / 2 || re < n / 2) {
            break;
          }
          le -= both, re -= both;
          int rl = n / 2 - le, rr = n / 2  - re;
          res += combinmod(rl + rr, rl);
        }
      }
    }
    cout << res % mod << endl;
  }
  return 0;
}