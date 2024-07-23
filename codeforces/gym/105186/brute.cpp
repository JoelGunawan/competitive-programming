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
  string s;
  cin >> s;
  int mx = 0;
  for(int i = 0; i < 1 << s.size(); ++i) {
    string fin = "";
    for(int j = 0; j < s.size(); ++j) {
      if((1 << j) & i) {
        fin += s[j];
      }
    }
    int res = 0;
    for(int j = 0; j < fin.size(); ++j) {
      if(j >= 2 && fin[j] == 'W' && fin[j - 1] == 'W' && fin[j - 2] == 'W')
        res += 3;
      else if(fin[j] == 'W')
        res += 2;
      else if(fin[j] == 'D')
        res += 1;
    }
    // cout << fin << " " << res << endl;
    mx = max(mx, res);
  }
  cout << mx << endl;
  return 0;
}