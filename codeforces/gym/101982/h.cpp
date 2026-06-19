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
  int x;
  cin >> x;
  vector<int> primes;
  bool prime[x + 5];
  memset(prime, 1, sizeof(prime));
  for (int i = 2; i <= x; ++i) {
    if (prime[i]) {
      for (ll j = 1ll * i * i; j <= x; j += i) {
        prime[j] = 0;
      }
      primes.push_back(i);
    }
  }
  int res = 0;
  while (x >= 4) {
    for (auto p : primes) {
      if (prime[x - p]) {
        x = (x - 2 * p);
        break;
      }
    }
    ++res;
  }
  cout << res << endl;
  return 0;
}