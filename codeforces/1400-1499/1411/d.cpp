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
  // observe: optimum always put all 0, then all 1 (or vice versa)
  // the main idea is that the amount of pairs is always the same
  // we just have to choose to have 01 or 10
  // manual calc: can do, do init all 0, then change to 1, then change back to 0
  // why is prefix always optimal?
  // or is it?
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int pref[s.size() + 5][2], suff[s.size() + 5][2];
  memset(pref, 0, sizeof(pref));
  memset(suff, 0, sizeof(suff));
  int n = s.size();
  s = " " + s;
  for(int i = 1; i <= n; ++i) {
    pref[i][0] = pref[i - 1][0];
    pref[i][1] = pref[i - 1][1];
    if(s[i] == '0')
      ++pref[i][0];
    else if(s[i] == '1')
      ++pref[i][1];
  }
  for(int i = n; i >= 1; --i) {
    suff[i][0] = suff[i + 1][0];
    suff[i][1] = suff[i + 1][1];
    if(s[i] == '0')
      ++suff[i][0];
    else if(s[i] == '1')
      ++suff[i][1];
  }
  ll base = 0;
  for(int i = 1; i <= n; ++i) {
    if(s[i] == '0') {
      base += 1ll * x * suff[i + 1][1];
    }
    else if(s[i] == '1') {
      base += 1ll * y * suff[i + 1][0];
    }
  }
  int cnt0 = 0, cnt1 = 0;
  ll res = 1e18;
  if(x < y) {
    // 0 first then 1
    // try init all 1, then change the 0 from the front
    ll cur = 0;
    for(int i = 1; i <= n; ++i) {
      // set to 1
      if(s[i] == '?') {
        cur += 1ll * y * suff[i + 1][0] + 1ll * x * pref[i - 1][0];
        ++cnt1;
      }
    }
    res = min(res, base + cur);
    // set to 0
    for(int i = 1; i <= n; ++i) {
      if(s[i] == '?') {
        // change 1 to 0
        cur -= 1ll * y * suff[i + 1][0] + 1ll * x * pref[i - 1][0];
        cur += 1ll * x * suff[i + 1][1] + 1ll * y * pref[i - 1][1];
        ++cnt0, --cnt1;
        res = min(res, base + cur + 1ll * cnt0 * cnt1 * x);
      }
    }
  }
  else {
    // 1 first then 0
    // try init all 0, then change the 1 from the back
    ll cur = 0;
    for(int i = 1; i <= n; ++i) {
      // set to 0
      if(s[i] == '?') {
        cur += 1ll * x * suff[i + 1][1] + 1ll * y * pref[i - 1][1];
        ++cnt0;
      }
    }
    res = min(res, base + cur);
    // set to 1
    for(int i = 1; i <= n; ++i) {
      if(s[i] == '?') {
        // change 0 to 1
        cur -= 1ll * x * suff[i + 1][1] + 1ll * y * pref[i - 1][1];
        cur += 1ll * y * suff[i + 1][0] + 1ll * x * pref[i - 1][0];
        --cnt0, ++cnt1;
        res = min(res, base + cur + 1ll * cnt1 * cnt0 * y);
      }
    }
  }
  cout << res << endl;
  return 0;
}