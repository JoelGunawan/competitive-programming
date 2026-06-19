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
vector<int> sieve(int n) {
  bool isp[n + 5];
  memset(isp, 1, sizeof(isp));
  vector<int> res;
  for(int i = 2; i <= n; ++i) {
    if(isp[i]) {
      for(ll j = 1ll * i * i; j <= n; j += i)
        isp[j] = 0;
      res.emplace_back(i);
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  vector<int> primes = sieve(1000);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    int res = -1;
    for(auto p : primes) {
      for(int i = 1; i <= n; ++i) {
        if(__gcd(a[i], (ll)p) == 1) {
          res = p;
          break;
        }
      }
      if(res != -1)
        break;
    }
    cout << res << endl;
  }
  return 0;
}