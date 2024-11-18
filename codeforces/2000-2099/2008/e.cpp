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
  // for even -> check every pair and check the count of letters need to change
  // for odd -> check every pair and every deletion point (use prefix/suffix) and check the count of letters need to change
  int t;
  cin >> t;
  char a[26];
  for(int i = 0; i < 26; ++i)
    a[i] = 'a' + i;
  while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n & 1) {
      if(s.size() == 1) {
        cout << 1 << endl;
        continue;
      }
      int res = 1e9;
      int pref[n + 1];
      for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
          pref[0] = 0;
          for(int k = 0; k < s.size(); ++k) {
            if(k != 0)
              pref[k] = pref[k - 1];
            if((k & 1))
              pref[k] += s[k] != a[i];
            else
              pref[k] += s[k] != a[j];
          }
          int cur = 0;
          res = min(res, pref[s.size() - 2]);
          for(int k = s.size() - 1; k >= 1; --k) {
            if(!(k & 1))
              cur += s[k] != a[i];
            else
              cur += s[k] != a[j];
            res = min(res, (k == 1 ? 0 : pref[k - 2]) + cur);
          }
        }
      }
      cout << res + 1 << endl;
    }
    else {
      int res = 1e9;
      for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
          int cur = 0;
          for(int k = 0; k < s.size(); ++k) {
            if((k & 1))
              cur += s[k] != a[i];
            else
              cur += s[k] != a[j];
          }
          res = min(res, cur);
        }
      }
      cout << res << endl;
    }
  }
  return 0;
}