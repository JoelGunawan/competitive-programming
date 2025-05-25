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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // find all prime factors
  // obs: lowest prime factor and everything but the lowest prime factor from that number
  // if everything but lowest prime factor = 1, then -1
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int ans1[n + 1], ans2[n + 1];
  memset(ans1, -1, sizeof(ans1));
  memset(ans2, -1, sizeof(ans2));
  vector<int> primes;
  const int lim = 1e7 + 5;
  bool isp[lim];
  memset(isp, 1, sizeof(isp));
  for(int i = 2; i < lim; ++i) { 
    if(isp[i]) {
      for(ll j = 1ll * i * i; j < lim; j += i) {
        isp[j] = 0;
      }
      primes.pb(i);
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(binary_search(primes.begin(), primes.end(), a[i]))
      continue;
    int p = -1;
    for(auto x : primes) {
      if(a[i] % x == 0) {
        p = x;
        break;
      }
    }
    int tmp = a[i];
    while(a[i] % p == 0)
      a[i] /= p;
    if(a[i] == 1 || a[i] == tmp)
      continue;
    ans1[i] = a[i];
    ans2[i] = tmp / a[i];
  }
  for(int i = 1; i <= n; ++i)
    cout << ans1[i] << " ";
  cout << endl;
  for(int i = 1; i <= n; ++i)
    cout << ans2[i] << " ";
  cout << endl;
  return 0;
}