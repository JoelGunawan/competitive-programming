// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
  int allow[n][5];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 5; ++j)
      cin >> allow[i][j];
  }
  for(int i = 0; i < 5; ++i) {
    for(int j = i + 1; j < 5; ++j) {
      // find cnti, cntj, cntboth, cntnone
      int cnti = 0, cntj = 0, cntboth = 0, cntnone = 0;
      for(int k = 0; k < n; ++k) {
        if(allow[k][i] && allow[k][j])
          ++cntboth;
        else if(allow[k][i])
          ++cnti;
        else if(allow[k][j])
          ++cntj;
        else
          ++cntnone;
      }
      if(cntnone == 0 && cnti <= n / 2 && cntj <= n / 2) {
        // cout << cnti << " " << cntj << " " << cntboth << " " << cntnone << endl;
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}