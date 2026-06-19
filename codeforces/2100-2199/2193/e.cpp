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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  int r[n + 5];
  fill(r, r + n + 5, 1e9);
  for (auto x : a) {
    r[x] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (auto x : a) {
      auto idx = 1ll * i * x;
      if (idx > n) break;
      r[idx] = min(r[idx], r[i] + 1);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (r[i] > n) cout << -1 << " ";
    else cout << r[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    tc();
  }
  return 0;
}