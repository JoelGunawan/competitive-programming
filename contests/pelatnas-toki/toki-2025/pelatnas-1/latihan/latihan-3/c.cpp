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
  int n, q;
  cin >> n >> q;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int cnt[(int)2e6 + 5];
  memset(cnt, 0, sizeof(cnt));
  int shift = 1e6;
  ll res[n + 1][n + 1];
  memset(res, 0, sizeof(res));
  for(int i = 1; i <= n; ++i) {
    for(int j = i + 1; j <= n; ++j) {
      if(abs(a[i] + a[j]) <= shift && cnt[shift - a[i] - a[j]])
        res[i][j] = cnt[shift - a[i] - a[j]];
      ++cnt[a[j] + shift];
      // cout << res[i][j] << " ";
    }
    // cout << endl;
    for(int j = i + 1; j <= n; ++j)
      --cnt[a[j] + shift];
  }
  for(int i = 2; i <= n; ++i) {
    for(int j = 1; i + j <= n; ++j) {
      res[j][i + j] += res[j + 1][i + j] + res[j][i + j - 1] - res[j + 1][i + j - 1];
    }
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << res[l][r] << endl;
  }
  return 0;
}