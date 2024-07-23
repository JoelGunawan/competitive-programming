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
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> table;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // if over sqrt(10^9) and not observed already -> must be unique
  for(int i = 1; i <= sqrt(1e9); ++i) {
    if(table.find(i) == table.end()) {
      table[i] = i;
      if(i != 1) {
        for(ll j = 1ll * i * i; j <= 1e9; j *= i) {
          table[j] = i;
        }
      }
    }
  }
  gp_hash_table<int, ll, chash> cnt;
  for(int i = 1; i <= n; ++i) {
    if(table.find(a[i]) == table.end())
      cnt[a[i]] += a[i];
    else
      cnt[table[a[i]]] += a[i];
  }
  ll res = 0;
  for(auto x : cnt) {
    // cout << x.fi << " " << x.se << endl;
    res = max(res, x.se);
  }
  cout << res << endl;
  return 0;
}