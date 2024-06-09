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
int cnt[30];
ll fact[100005], inv[100005], mn, mx, tot;
int mod = 1e9 + 7;
ll mul(ll a, ll b) {
  return ((a % mod) * (b % mod)) % mod;
}
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = mul(tmp, tmp);
    return b & 1 ? mul(tmp, a) : tmp;
  }
}
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[b], inv[a - b])); 
}
vector<pair<ll, int>> arr1, arr2;
// 2.6e10 states
// important -> for given x, y, cnt find 
void bf1(int x = 1, ll y = 0, ll z = 1) {
  if(x == 19) {
    // cerr << x << " " << y << " " << z << endl;
    arr1.pb(mp(y, z));
    return;
  }
  for(int i = 0; i <= 25; ++i) {
    if(y + 1ll * i * (tot / x) <= mx && i <= cnt[x]) {
      bf1(x + 1, y + 1ll * i * (tot / x), mul(z, combinmod(cnt[x], i)));
    }
  }
}
void bf2(int x = 19, ll y = 0, ll z = 1) {
  if(x == 26) {
    // cout << x << " " << y << " " << z << " " << cnt << endl;
    arr2.pb(mp(y, z));
    return;
  }
  for(int i = 0; i <= 25; ++i) {
    if(y + 1ll * i * (tot / x) <= mx && i <= cnt[x]) {
      bf2(x + 1, y + 1ll * i * (tot / x), mul(z, combinmod(cnt[x], i)));
    }
  }
}
ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}
int main() {
  fact[0] = inv[0] = 1;
  for(int i = 1; i <= 100000; ++i)
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  int mini = 1e9, maxi = 0;
  for(int i = 1; i <= n; ++i)
    cin >> a[i], ++cnt[a[i]], mini = min(mini, a[i]), maxi = max(maxi, a[i]);
  // do brute force
  // observe: you cannot extend a valid way
  // and there are not that many numbers that are possible
  // just do recursion brute force
  tot = 1;
  for(int i = 1; i <= 25; ++i)
    tot = lcm(tot, i);
  // cout << tot << endl;
  mn = tot / 100 * 99;
  mx = tot / 100 * 101;
  bf1();
  bf2();
  // cout << arr1.size() << " " << arr2.size() << endl;
  // arr1 is bigger
  sort(arr2.begin(), arr2.end());
  ll res = 0;
  ll pref[arr2.size()];
  memset(pref, 0, sizeof(pref));
  for(int i = 0; i < arr2.size(); ++i) {
    pref[i] = (i == 0 ? 0 : pref[i - 1]) + arr2[i].se;
    pref[i] %= mod;
  }
  for(auto p : arr1) {
    // p.fi -> y count
    // p.se -> count of ways
    // p.fi must be between mn and mx
    ll low = mn - p.fi, high = mx - p.fi;
    // between low to high
    // cerr << "DEB " << (double)low / tot << " " << (double)high / tot << " " << p.se << " " << (high <= arr2.front().fi ? 0 : pref[--ub(arr2.begin(), arr2.end(), mp(high, mod + 5)) - arr2.begin()]) - (low <= arr2.front().fi ? 0 : pref[--ub(arr2.begin(), arr2.end(), mp(low, mod + 5)) - arr2.begin()]) << endl;
    res += mul(p.se, (high < arr2.front().fi ? 0 : pref[--ub(arr2.begin(), arr2.end(), mp(high, mod + 5)) - arr2.begin()]) - (low <= arr2.front().fi ? 0 : pref[--ub(arr2.begin(), arr2.end(), mp(low, 0)) - arr2.begin()]));
    res %= mod;
  }
  /*
  for(auto p : arr1) {
    for(auto q : arr2) {
      if(p.fi + q.fi <= mx && p.fi + q.fi >= mn) {
        cerr << "OUT " << (p.fi + q.fi) / (double) tot << " " << p.se << " " << q.se << endl;
      }
    }
  }
  */
  res %= mod;
  if(res < 0)
    res += mod;
  cout << res % mod << endl;
  return 0;
}