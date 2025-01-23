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
ll mod = 998244353;
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
ll combinmod(ll a, ll b) {
  ll ret = 1;
  for(int i = a; i > a - b; --i)
    ret = mul(ret, i);
  for(int i = b; i >= 1; --i)
    ret = mul(ret, powmod(i, mod - 2));
  // cerr << "COMBINMOD " << a << " " << b << " " << ret << endl;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  const int lim = 1e5 + 5;
  int cnt[lim][17];
  memset(cnt, 0, sizeof(cnt));
  // get count of all, order matters
  for(int i = 1; i < lim; ++i) {
    cnt[i][1] = 1; // the number itself, always true
    for(int j = 2; j <= sqrt(i); ++j) {
      if(1ll * j * j == i) {
        // do once
        for(int k = 1; k < 16; ++k) {
          cnt[i][k + 1] += cnt[j][k];
        }
      }
      else {
        if(i % j == 0) {
          for(int k = 1; k < 16; ++k) {
            cnt[i][k + 1] += cnt[j][k];
            cnt[i][k + 1] += cnt[i / j][k];
          }
        }
      }
    }
  }
  while(t--) {
    int k, n;
    cin >> k >> n;
    int cur[17];
    memset(cur, 0, sizeof(cur));
    for(int i = 2; i <= k; ++i) {
      for(int j = 0; j < 17; ++j)
        cur[j] += cnt[i][j];
    }
    // for 1, special case, we know it's always 1
    cout << n << " ";
    ll pre[17];
    for(int i = 1; i < 17; ++i) 
      pre[i] = combinmod(n + 1, i + 1);
    for(int i = 2; i <= k; ++i) {
      ll cur = 0;
      for(int j = 1; j < 17; ++j) {
        // cerr << i << " " << j << " " << cnt[i][j] << " " << pre[j] << endl;
        cur += mul(cnt[i][j], pre[j]);
      }
      cout << cur % mod << " ";
    }
    // cerr << endl;
    cout << endl;
  }
  return 0;
}