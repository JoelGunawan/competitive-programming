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
const int inf = 5e8;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k, v;
  cin >> n >> k >> v;
  int a[n + 1];
  int sum = 0;
  for(int i = 1; i <= n; ++i)
    cin >> a[i], sum += a[i];
  if(sum < v) {
    cout << "NO" << endl;
    return 0;
  }
  bool dp[n + 1][k];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i) {
    int mod = a[i] % k;
    for(int j = 0; j < k; ++j) {
      dp[i][j] = dp[i - 1][j] | dp[i - 1][j - mod < 0 ? j - mod + k : j - mod];
    }
  }
  if(!dp[n][v % k]) {
    cout << "NO" << endl;
    return 0;
  }
  // cerr << "HERE" << endl;
  vector<int> used;
  int tmp1 = n, tmp2 = v % k;
  while(tmp1 > 0) {
    if(dp[tmp1 - 1][tmp2]) {
      // cerr << "IN C1" << endl;
      --tmp1;
    }
    else {
      tmp2 -= a[tmp1] % k;
      if(tmp2 < 0)
        tmp2 += k;
      used.push_back(tmp1);
      --tmp1;
    }
  }
  vector<pair<int, pair<int, int>>> ops;
  if(used.empty()) {
    used.push_back(1);
    a[2] += a[1];
    a[1] = 0;
    ops.push_back(mp(inf, mp(1, 2)));
  }
  sort(used.begin(), used.end());
  // WLOG, move all to first used
  for(int i = 1; i < used.size(); ++i) {
    ops.push_back(mp(inf, mp(used[i], used[0])));
    a[used[0]] += a[used[i]];
    a[used[i]] = 0;
  }
  int dump;
  for(int i = 1; i <= n; ++i) {
    if(i != used[0]) {
      dump = i;
      break;
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(!binary_search(used.begin(), used.end(), i)) {
      // move to dump
      if(a[i] > 0 && i != dump) {
        ops.push_back({inf, mp(i, dump)});
        a[dump] += a[i];
        a[i] = 0;
      }
    }
  }
  if(a[used[0]] != v) {
    // move...
    int num_move = (a[used[0]] - v) / k;
    if(num_move > 0) {
      ops.push_back(mp(num_move, mp(used[0], dump)));
    }
    else {
      ops.push_back(mp(-num_move, mp(dump, used[0])));
    }
  }
  cout << "YES" << endl;
  for(auto [cnt, p] : ops) {
    cout << cnt << " " << p.fi << " " << p.se << endl;
  }
  return 0;
}