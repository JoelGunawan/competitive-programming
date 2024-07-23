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
  string t = "";
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] != 'L')
      t += s[i];
  }
  //cout << t << endl;
  string u = "";
  for(int i = 0; i < t.size(); ++i) {
    if(t[i] == 'D') {
      if(i == 0 || i == t.size() - 1 || (i > 0 && t[i - 1] == 'D') || (i + 1 < t.size() && t[i + 1] == 'D') || !((u.size() >= 2 && u.back() == 'W' && u[u.size() - 2] == 'W') || (i + 2 < t.size() && t[i + 1] == 'W' && t[i + 2] == 'W')))
        u += t[i];
    }
    else
      u += t[i];
  }
  int res = 0;
  string fin = "";
  for(int i = u.size() - 1; i >= 0; --i) {
    if(u[i] == 'D') {
      if(i == 0 || i == t.size() - 1 || (i > 0 && u[i - 1] == 'D') || (i + 1 < u.size() && u[i + 1] == 'D') || !((fin.size() >= 2 && fin.back() == 'W' && fin[fin.size() - 2] == 'W') || (i + 2 < u.size() && u[i + 1] == 'W' && u[i + 2] == 'W')))
        fin += u[i];
    }
    else
      fin += u[i];
  }
  //cout << u << endl;
  reverse(fin.begin(), fin.end());
  for(int i = 0; i < fin.size(); ++i) {
    if(fin[i] == 'W' && i >= 2 && fin[i - 1] == fin[i - 2] && fin[i - 1] == 'W')
      res += 3;
    else if(fin[i] == 'W')
      res += 2;
    else if(fin[i] == 'D')
      res += 1;
  }
  // cerr << fin << endl;
  cout << res << endl;
  return 0;
}