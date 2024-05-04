// header file
#include <bits/stdc++.h>
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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1], b[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  ll c[n + 1];
  for(int i = 1; i <= n; ++i) {
    c[i] = mul(b[i], powmod(a[i], b[i]));
  }
  ll res = 1;
  for(int i = 1; i <= n; ++i) {
    res = mul(res, c[i] + 1);
  }
  --res;
  if(res < 0)
    res += mod;
  cout << res << endl;
  return 0;
}