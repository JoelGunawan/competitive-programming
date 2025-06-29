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
  int case_num = 0;
  START:
  int n;
  if(!(cin >> n)) {
    return 0;
  }
  ++case_num;
  cout << "Case " << case_num << ": ";
  vector<int> v[n];
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for(int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      if (v[i].size() && v[i].back() == y) 
        continue;
      v[i].emplace_back(y);
    }
  }

  vector<int> m;
  for(int i = 0; i < n; ++i) {
    for(auto x : v[i])
      m.push_back(x);
  }

  sort(m.begin(), m.end());
  m.resize(unique(m.begin(), m.end()) - m.begin());

  for(int i = 0; i < n; ++i) {
    for (auto &x : v[i]) {
      x = lb(m.begin(), m.end(), x) - m.begin() + 1;
    }
  }

  int dp[m.size() + 1][n];
  memset(dp, 0, sizeof(dp));

  bool cnt[m.size() + 1][n];
  int num[m.size() + 1];
  memset(cnt, 0, sizeof(cnt));
  memset(num, 0, sizeof(num));
  int total = 0;
  for(int i = 0; i < n; ++i) {
    // split
    total += v[i].size() - 1;
    // join
    total += v[i].size() - 1;
    for(auto x : v[i])
      cnt[x][i] = 1, num[x]++;
  }
  
  total += n;
  
  for(int j = 0; j < n; ++j) {
    if(cnt[1][j])
      dp[1][j] = 1;
  }

  for(int i = 2; i <= m.size(); ++i) {
    for(int j = 0; j < n; ++j) {
      if(cnt[i][j] && cnt[i - 1][j]) {
        for(int k = 0; k < n; ++k)
          if(cnt[i][k] && j != k)
            dp[i][k] = max(dp[i][k], dp[i - 1][j] + 2);
        if(num[i] == 1)
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + 2);
      }
      else if(cnt[i - 1][j]) {
        for(int k = 0; k < n; ++k)
          dp[i][k] = max(dp[i][k], dp[i - 1][j]);
      }
    }
  }

  int mx = 0;
  for(int i = 0; i < n; ++i)
    mx = max(mx, dp[m.size()][i]);
  
  cout << total - mx << endl;

  goto START;
  return 0;
}