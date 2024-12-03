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
  string s, t;
  cin >> s >> t;
  int sd[26], td[26];
  const int inf = 1e9;
  fill(sd, sd + 26, inf);
  fill(td, td + 26, -inf);
  for(int i = 1; i < s.size(); ++i)
    sd[s[i] - 'a'] = min(sd[s[i] - 'a'], i);
  for(int i = 0; i < (int)t.size() - 1; ++i)
    td[t[i] - 'a'] = max(td[t[i] - 'a'], i);
  int res = -1;
  string out = "";
  for(int i = 0; i < 26; ++i) {
    if(sd[i] != inf && td[i] != -inf) {
      // cerr << i << " " << sd[i] << " " << td[i] << endl;
      string cur = "";
      for(int j = 0; j < sd[i]; ++j)
        cur += s[j];
      for(int j = td[i]; j < t.size(); ++j)
        cur += t[j];
      if(res == -1 || cur.size() < res)
        res = cur.size(), out = cur;
      // cerr << i << " " << cur << endl;
    }
  }
  if(res == -1)
    cout << -1 << endl;
  else
    cout << out << endl;
  return 0;
}