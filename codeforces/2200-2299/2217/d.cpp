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
  int n, k;
  cin >> n >> k;
  bool a[n + 5];
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i] = x;
  }
  vector<int> b(k);
  for (int i = 0; i < k; ++i) cin >> b[i];
  bool tgt = a[b[0]];
  // find count of inversions between specs)
  bool spec[n + 5];
  memset(spec, 0, sizeof(spec));
  for (auto x : b) {
    spec[x] = 1;
  }

  int cnt_inv = 0;
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    if (i > 1 && a[i] != a[i - 1]) ++cnt_inv;
    if (spec[i]) {
      v.push_back(cnt_inv);
      cnt_inv = 0;
    }   
  }
  v.push_back(cnt_inv);

  int sum = 0;
  for (auto &x : v) {
    if (x & 1) ++x;
    sum += x;
  }

  // violate if:
  // - there is majority
  int mx = -1;
  for (auto x : v) {
    // cerr << "deb " << x << " " << sum / 2 << endl;
    if (x > sum / 2) {
      // cerr << "DEBUG" << endl;
      mx = x;
      // cerr << "value of mx: " << mx << endl;
    }
  }

  if (mx != -1) {
    // cerr << "not done" << endl;
    int rest = sum - mx;
    int out = rest;
    out += mx - rest;
    cout << out << endl;
  } else {
    // cerr << "DEB: " << n << " " << sum << endl;
    // if (out & 1) ++out;
    cout << sum / 2 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}