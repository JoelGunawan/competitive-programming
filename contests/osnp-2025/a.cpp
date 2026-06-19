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
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  int suff[n + 5];
  int pref[3][n + 5];
  memset(pref, 0, sizeof(pref));
  memset(suff, 0, sizeof(suff));
  char c[] = {'O', 'S', 'N'};

  for(int i = 0; i < 3; ++i) {
    for(int j = 1; j <= n; ++j) {
      pref[i][j] = pref[i][j - 1] + (s[j] == c[i]);
    }
  }

  for(int i = n; i >= 1; --i) {
    suff[i] = suff[i + 1] + (s[i] == 'P');
  }

  int res = -1;
  for(int i = 1; i <= n; ++i) {
    if(pref[0][i] && pref[1][i] && pref[2][i] && suff[i + 1]) {
      res = max(res, pref[0][i] + pref[1][i] + pref[2][i] + suff[i + 1]);
    }
  }
  
  cout << res << endl;

  return 0;
}