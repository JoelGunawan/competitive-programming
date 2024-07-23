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
  int m, k, c;
  cin >> m >> k >> c;
  string s;
  getline(cin, s);
  int pr = 0;
  int cur = 0;
  int curnum = 0;
  array <int, 100> ans;
  for (int i = 0; i < 100; i++) {
    ans[i] = -1;
  }
  vector<int> a;

  function<void(int, int, int)> brute = [&](int i, int cnt, int cur) {
    if (i == m) {
      if (cnt == k) {
        a.push_back(cur);
      }
      return;
    }

    for (int v = 1; v >= 0; v--) {
      int newcur = cur | (v << i);
      if (v + cnt <= k) {
        brute(i + 1, cnt + v, newcur);
      } 
    }
  };
  brute(0, 0, 0);
  // for(auto x : a)
  //   cerr << x << " ";
  // cerr << endl;

  // for(int i = 0; i < 1 << m; ++i) {
  //   if(__builtin_popcount(i) == k) {
  //     vector<int> cur;
  //     for(int j = 0; j < m; ++j) {
  //       if((1 << j) & i)
  //         cur.pb(j);
  //     }
  //     a.pb(mp(cur, i));
  //   }
  // }
  // sort(a.begin(), a.end());
  while(getline(cin, s)) {
    ++curnum;
    s.erase(s.begin());
    s.erase(--s.end());
    stringstream ss(s);
    vector<int> v;
    int tmp;
    while(ss >> tmp)
      v.pb(tmp);
    for(auto x : v)
      cur |= 1 << x;
    int num = __builtin_popcount(cur);
    // cout << "DEB1 " << num << " " << cur << endl;
    if(num > k) {
      // invalid -> skip
      cur = 0;
      pr = curnum - 1;
      for(auto x : v)
        cur |= 1 << x;
    }
    num = __builtin_popcount(cur);
    // cout << "DEB2 " << num << " " << cur << endl;
    if(num == k) {
      // set from previous to cur as now
      int now = -1;
      for(int i = 0; i < a.size(); ++i) {
        if(a[i] == cur)
          now = i;
      }
      for(int i = pr + 1; i <= curnum; ++i)
        ans[i] = now;
      pr = curnum;
    }
    else if(num > k) {
      pr = curnum;
      cur = 0;
    }
  }

  assert(curnum <= 50);
  for(int i = 1; i <= curnum; ++i) {
    if(ans[i] == -1)
      cout << "?" << endl;
    else
      cout << ans[i] << endl;
  }
  return 0;
}