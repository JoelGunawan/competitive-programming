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
  int n;
  cin >> n;
  string a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  auto convert = [&] (string s) -> int {
    if(s[0] == '0')
      return 52;
    else {
      return s[0] - 'A' + (s[1] == '+' ? 26 : 0);
    }
  };

  vector<int> sides[n + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 4; ++j) {
      sides[i].push_back(convert(a[i].substr(j * 2, 2)));
    }
  }
  
  vector<vector<int>> allowed(52);
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 4; ++j) {
      for(int k = 0; k < 4; ++k) {
        if(j != k && sides[i][j] < 52 && sides[i][k] < 52)
          allowed[sides[i][j] < 26 ? sides[i][j] + 26 : sides[i][j] - 26].push_back(sides[i][k]);
      }
    }
  }

  for(int i = 0; i < 52; ++i) {
    sort(allowed[i].begin(), allowed[i].end());
    allowed[i].resize(unique(allowed[i].begin(), allowed[i].end()) - allowed[i].begin());
  }

  vector<bool> vis(52, 0);
  vector<bool> active(52, 0);

  function<bool(int)> dfs;
  
  dfs = [&vis, &allowed, &dfs, &active] (int nd) -> bool {
    vis[nd] = 1;
    active[nd] = 1;
    
    for(auto x : allowed[nd]) {
      if(active[x]) {
        active[nd] = 0;
        return true;
      }
      if(!vis[x]) {
        bool ret = dfs(x);
        if(ret) {
          active[ret] = 0;
          return true;
        }
      }
    }
    active[nd] = 0;
    return false;
  };

  bool ans = 0;
  for(int i = 1; i <= n; ++i) {
    for(auto x : sides[i]) {
      if(x < 52 && !vis[x]) {
        ans |= dfs(x);
        if(ans)
          break;
      }
    }
    if(ans)
      break;
  }
  cout << (ans ? "unbounded" : "bounded") << endl;
  return 0;
}