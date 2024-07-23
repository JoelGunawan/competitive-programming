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
  // just dfs/bfs?
  // in each col, there has to be at least 1 occur of 0
  int n;
  cin >> n;
  string s[2];
  cin >> s[0] >> s[1];
  bool valid = 1;
  for(int i = 0; i < n; ++i) {
    if(s[0][i] == '1' & s[1][i] == '1')
      valid = 0;
  }
  cout << (valid ? "YES" : "NO") << endl;
  return 0;
}