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
  string s = "";
  vector<string> a;
  while(cin >> s) {
    if(s == "0") {
      break;
    }
    a.push_back(s);
  }
  if(s == "") {
    return 0;
  }

  set<int> tmp;
  vector<int> cnta(26), cntb(26);
  vector<vector<int>> edges(26);
  bool keya = 0, keyb = 0;
  for(auto s : a) {
    char x = s[0], y = s[1];
    if(x > y)
      swap(x, y);
    if(x <= 'Z') {
      if(x <= 'M')
        ++cnta[y - 'a'], keya = 1;
      else
        ++cntb[y - 'a'], keyb = 1;
      tmp.insert(y - 'a');
    }
    else {
      int u = x - 'a', v = y - 'a';
      edges[u].push_back(v);
      edges[v].push_back(u);
      tmp.insert(u);
      tmp.insert(v);
    }
  }

  cout << "Case " << ++case_num << ": ";
  if(tmp.size() == 1 && keya && keyb) {
    cout << "impossible" << endl;
    goto START;
  }
  else if(!keya && !keyb) {
    cout << 0 << " " << 0 << endl;
    goto START;
  }

  vector<int> type(26);
  int r1 = 0;
  int numa = 0, numb = 0;
  for(int i = 0; i < 26; ++i) {
    if(cnta[i] || cntb[i]) {
      if(cnta[i] == cntb[i])
        type[i] = 2;
      else if(cnta[i] < cntb[i])
        type[i] = 1, ++numb;
      else
        type[i] = 0, ++numa;
      r1 += min(cnta[i], cntb[i]);
    }
    else {
      type[i] = 3;
    }
  }

  vector<vector<int>> dp(26, vector<int>(3, 1e9));
  vector<bool> vis(26, 0);

  function<void(int)> dfs;

  bool allow = 0;
  int cc = 0;

  dfs = [&] (int nd) -> void {
    vis[nd] = 1;
    vector<int> child;
    for(auto adj : edges[nd]) {
      if(!vis[adj]) {
        dfs(adj);
        child.push_back(adj);
      }
    }

    if(type[nd] != 3)
      allow = 1;

    if(child.empty()) {
      if(type[nd] == 3)
        dp[nd][2] = 0;
      else if(type[nd] == 2)
        dp[nd][0] = dp[nd][1] = 0, dp[nd][2] = 1;
      else 
        dp[nd][type[nd]] = 0, dp[nd][2] = 1;
    }
    // none
    else if(type[nd] == 3) {
      int c0 = 0, c1 = 0, c2 = 0;
      for(auto c : child) {
        c0 += min(dp[c][0], dp[c][2]);
        c1 += min(dp[c][1], dp[c][2]);
        c2 += dp[c][2];
      }
      dp[nd][0] = c0;
      dp[nd][1] = c1;
      dp[nd][2] = min({c2, c0 + 1, c1 + 1});
    }
    // can be both
    else if(type[nd] == 2) {
      int c0 = 0, c1 = 0;
      for(auto c : child) {
        c0 += min(dp[c][0], dp[c][2]);
        c1 += min(dp[c][1], dp[c][2]);
      }
      dp[nd][0] = c0;
      dp[nd][1] = c1;
      dp[nd][2] = min({c0, c1}) + 1;
    }
    // b
    else if(type[nd] == 1) {
      int c1 = 0;
      for(auto c : child) {
        c1 += min(dp[c][1], dp[c][2]);
      }
      dp[nd][1] = c1;
      dp[nd][2] = c1 + 1;
    }
    // a
    else {
      int c0 = 0;
      for(auto c : child) {
        c0 += min(dp[c][0], dp[c][2]);
      }
      dp[nd][0] = c0;
      dp[nd][2] = c0 + 1;
    }
  };

  int res = 0;
  for(int i = 0; i < 26; ++i) {
    if(!vis[i]) {
      allow = 0;
      dfs(i);
      if(allow) {
        ++cc;
        res += min({dp[i][0], dp[i][1], dp[i][2]});
      }
    }
  }

  if(keya ^ keyb) {
    cout << 0 << " " << cc - 1 << endl;
    goto START;
  }

  int total_cc = cc + res;
  // cerr << "DEBUG " << total_cc << endl;
  if(total_cc - 2 < 0) {
    cout << 2 * r1 << " " << res << endl;
    goto START;
  }
  cout << 2 * r1 << " " << res + total_cc - 2 << endl;

  goto START;
  return 0;
}