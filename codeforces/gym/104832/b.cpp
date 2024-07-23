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
bool comp(pair<int, int> a, pair<int, int> b) {
  return 1ll * a.fi * b.se <= 1ll * a.se * b.fi;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, c, p, q;
  string s;
  cin >> n >> c >> p >> q >> s;
  s = " " + s;
  int pr = 0, res = 0;
  for(int i = 1; i <= n; ++i) {
    if(i - pr < c)
      continue;
    int x = 0, cnt = 0;
    for(int j = i; j > i - c; --j) {
      if(s[j] == 'Y')
        ++x;
      ++cnt;
    }
    bool can = 0;
    for(int j = i - c; j >= i - 2 * c; --j) {
      if(comp(mp(p, q), mp(x, cnt))) {
        can = 1;
        break;
      }
      if(j == pr)
        break;
      if(s[j] == 'Y')
        ++x;
      ++cnt;
    }
    if(can)
      ++res, pr = i;
  }
  cout << res << endl;
  return 0;
}