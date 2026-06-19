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
struct fenwick {
  vector<int> a;
  int lim;
  fenwick(int n) {
    a = vector<int>(n + 5, 0);
    lim = n + 1;
  }
  
  void upd(int idx, int val) {
    while (idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }

  int q(int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
  
    // same parity only can swap
    // try to do greedily
    // assume that greedy will always work
    // always guaranteed optimal except for last 3
    fenwick fen[2] = {fenwick(n), fenwick(n)};

    vector<int> arr[2];
    ll inv[2] = {0, 0};
    for (int i = 1; i <= n; ++i) {
      int par = i & 1;
      // cerr << i << " " << a[i] << " " << fen[par].q(n) << " " << fen[par].q(a[i]) << endl;
      inv[par] += fen[par].q(n) - fen[par].q(a[i]);
      fen[par].upd(a[i], 1);
      arr[par].push_back(a[i]);
    }

    for (int i = 0; i < 2; ++i)
      sort(arr[i].begin(), arr[i].end());

    if ((inv[0] & 1) != (inv[1] & 1)) {
      swap(arr[n & 1].back(), arr[n & 1][arr[n & 1].size() - 2]);
    }

    int res[n + 5];
    memset(res, -1, sizeof(res));
    for (int i = 0; i < arr[0].size(); ++i) {
      res[2 * i + 2] = arr[0][i];
    }    

    for (int i = 0; i < arr[1].size(); ++i) {
      res[2 * i + 1] = arr[1][i];
    }    

    for (int i = 1; i <= n; ++i)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}