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
void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  ll sum = 0;
  ll sum2 = 0;
  ll sum3 = 0;
  // consider all pairs w/ gcd = x
  // then, not very much unique gcd values -> very important (at most nlog unique gcd values)
  // consider all pairs, we actually only need to consider an upper bound
  // then, with the second number, the gcd must necessarily = x
  // then, we have that we only need to check for all factors of k
  // so check all other smaller numbers with the current number, gcd = x for some number
  // then, multiply by numbers larger than cur
  
  // gcd = 24 -> 1 number
  // gcd >= 12 -> 1 number
  // gcd >= 6 -> 1 number
  // gcd >= 3 -> 2 number
  const int lim = 1e5;
  int cnt[lim + 5];
  int factor[lim + 5];
  vector<int> factors[lim + 5];
  memset(factor, 0, sizeof(factor));
  memset(cnt, 0, sizeof(cnt));
  int used[lim + 5];
  memset(used, 0, sizeof(used));
  int rem = n;
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];
  for (int i = 1; i <= lim; ++i) {
    for (int j = 1; 1ll * j * j <= i; ++j) {
      if (i % j == 0) {
        factors[i].pb(j);
        factors[i].pb(i / j);
      }
    }
    sort(factors[i].begin(), factors[i].end());
    factors[i].resize(unique(factors[i].begin(), factors[i].end()) - factors[i].begin());
    reverse(factors[i].begin(), factors[i].end());
    if (cnt[i] == 0) continue;
    rem -= cnt[i];
    

    // all same case
    if (cnt[i] >= 3) sum += 1ll * i * (1ll * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
    // two (smaller) same case
    if (cnt[i] >= 2) sum += 1ll * i * (1ll * cnt[i] * (cnt[i] - 1) / 2) * rem;

    // special case: 
    // - what if two large numbers are the same?
    // - what if two small numbers are the same?
    // - what if all three numbers are the same?
    // largest to smallest factor
    for (auto x : factors[i]) {
      // calculate gcd = x
      int new_use = factor[x] - used[x];
      // add sum, as much as cnt needs
      sum += 1ll * x * cnt[i] * new_use * rem;
      // two larger same case
      // cout << "DEBUG: " << x << " " << factor[x] << " " << used[x] << " " << cnt[i] << endl;
      sum += 1ll * x * new_use * (1ll * cnt[i] * (cnt[i] - 1) / 2);
      for (auto y : factors[x]) {
        // if (new_use)
        // cout << "add: " << y << " " << new_use << endl;
        used[y] += new_use;
      }
    }
    
    for (auto x : factors[i]) {
      used[x] = 0;
      factor[x] += cnt[i];
    }
  }

  // 12 9 9
  // gcd = 3
  // only 1 triplet
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}