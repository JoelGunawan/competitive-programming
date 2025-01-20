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
int mod = 998244353;
int to_int(char a) {
  if(a >= 'a' && a <= 'z')
    return a - 'a';
  else if(a >= 'A' && a <= 'Z')
    return a - 'A' + 26;
  else
    return a - '0' + 52;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int cnt[11][62][62];
  memset(cnt, 0, sizeof(cnt));
  set<string> sets;
  for(int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if(!sets.count(s)) {
      string t = s;
      reverse(t.begin(), t.end());
      ++cnt[s.size()][to_int(s[0])][to_int(s.back())];
      if(s != t)
        ++cnt[s.size()][to_int(s.back())][to_int(s[0])];
      sets.insert(s);
      sets.insert(t);
    }
  }
  // fix 4 positions, rest choose based on the other 3
  // based on other 3, count all possible ways
  ll precomp[11][62][62][62];
  memset(precomp, 0, sizeof(precomp));
  for(int i = 3; i <= 10; ++i) {
    for(int j = 0; j < 62; ++j) {
      for(int k = 0; k < 62; ++k) {
        for(int l = 0; l < 62; ++l) {
          for(int m = 0; m < 62; ++m) {
            precomp[i][j][k][l] += 1ll * cnt[i][j][m] * cnt[i][k][m] * cnt[i][l][m];
          }
          precomp[i][j][k][l] %= mod;
        }
      }
    }
  }
  ll res = 0;
  // can const opt to reduce unnecessary calculations by considering symmetries (3, 3, 6, 8) and (6, 3, 3, 8) are the same thing
  // total -> idk how many reductions
  for(int i = 3; i <= 10; ++i) {
    for(int j = 0; j < 62; ++j) {
      for(int k = 0; k < 62; ++k) {
        for(int l = 0; l < 62; ++l) {
          if(precomp[i][j][k][l] == 0)
            continue;
          ll tmp = 0;
          for(int m = 0; m < 62; ++m) {
            if(precomp[i][j][k][m] == 0 || precomp[i][j][l][m] == 0 || precomp[i][k][l][m] == 0)
              continue;
            // set to j, k, l, m
            // all possible combinations
            tmp +=  precomp[i][j][k][m] * ((precomp[i][j][l][m] * precomp[i][k][l][m]) % mod) % mod; 
          }
          res += (tmp * precomp[i][j][k][l]) % mod;
        }
      }
    }
  }
  cout << res % mod << endl;
}