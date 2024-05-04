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
  if(b == 0) {
    return 1;
  }
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
    int n, m;
    cin >> n >> m;
    bool exist[31];
    memset(exist, 0, sizeof(exist));
    ll res = 0;
    while(m--) {
      int l, r, x;
      cin >> l >> r >> x;
      for(int j = 0; j < 31; ++j) {
        // cek bit ke-j nyala
        if((1 << j) & x)
          exist[j] = 1;
      }
    }
    for(int i = 0; i < 31; ++i) {
      if(exist[i])
        res += ((1ll << i) * powmod(2, n - 1)) % mod;
    }
    cout << res % mod << endl;
  }
  return 0;
}