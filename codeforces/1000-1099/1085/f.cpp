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
const int lim = 2e5 + 5;
struct fenwick {
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    int ret = 0;
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
  return mp(max(a.fi, b.fi), min(a.se, b.se));
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  int a[n + 1];
  for(int i = 1; i < s.size(); ++i) {
    if(s[i] == 'R')
      a[i] = 0;
    else if(s[i] == 'S') 
      a[i] = 1;
    else
      a[i] = 2;
  }
  // special cases: 
  // - only two elements (only element that wins can win)
  // - only one element (everyone can win)
  set<int> occur[3];
  fenwick bit[3];
  for(int i = 1; i <= n; ++i) {
    occur[a[i]].ins(i), bit[a[i]].update(i, 1);
  }
  int cnt_unique = !occur[0].empty() + !occur[1].empty() + !occur[2].empty();
  if(cnt_unique == 1) {
    cout << n << endl;
  }
  else if(cnt_unique == 2) {
    for(int i = 0; i < 3; ++i) {
      if(occur[i].size() && occur[(i + 1) % 3].size()) {
        cout << occur[i].size() << endl;
      }
    }
  }
  else {
    // count validL and validR for each
    // validL -> all equal or there is something that cur wins against
    // Form for R: RRRRR....S.....
    // Form for S: SSSSS....P.....
    // Form for P: PPPPP....R.....
    int res = 0;
    for(int i = 0; i < 3; ++i) {
      // find prefix such that only i occurs
      int l = 0, r = n, ans = 0;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(bit[i].query(mid) == mid) {
          ans = mid, l = mid + 1;
        }
        else {
          r = mid - 1;
        }
      }
      vector<pair<int, int>> valid_l = {mp(1, ans)};
      // find first occur of i + 1
      valid_l.pb(mp(*occur[(i + 1) % 3].begin(), n));
      // find suffix such that only i occurs
      l = 1, r = n + 1, ans = n + 1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(bit[i].query(mid, n) == n - mid + 1) {
          ans = mid, r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      vector<pair<int, int>> valid_r = {mp(ans, n)};
      // find last occur of i + 1
      valid_r.pb(mp(1, *--occur[(i + 1) % 3].end()));
      for(auto p1 : valid_l) {
        for(auto p2 : valid_r) {
          if(p1.fi <= p1.se && p2.fi <= p2.se) {
            res += max(0, bit[i].query(intersect(p1, p2).fi, intersect(p1, p2).se));
          }
        }
      }
    }
    cout << res << endl;
  }
  while(q--) {
    int idx; char c;
    cin >> idx >> c;
    int val;
    if(c == 'R')
      val = 0;
    else if(c == 'S')
      val = 1;
    else
      val = 2;
    occur[a[idx]].erase(idx);
    bit[a[idx]].update(idx, -1);
    a[idx] = val;
    occur[a[idx]].ins(idx);
    bit[a[idx]].update(idx, 1);
    int cnt_unique = !occur[0].empty() + !occur[1].empty() + !occur[2].empty();
    if(cnt_unique == 1) {
      cout << n << endl;
    }
    else if(cnt_unique == 2) {
      for(int i = 0; i < 3; ++i) {
        if(occur[i].size() && occur[(i + 1) % 3].size()) {
          cout << occur[i].size() << endl;
        }
      }
    }
    else {
      // count validL and validR for each
      // validL -> all equal or there is something that cur wins against
      // Form for R: RRRRR....S.....
      // Form for S: SSSSS....P.....
      // Form for P: PPPPP....R.....
      int res = 0;
      for(int i = 0; i < 3; ++i) {
        // find prefix such that only i occurs
        int l = 0, r = n, ans = 0;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(bit[i].query(mid) == mid) {
            ans = mid, l = mid + 1;
          }
          else {
            r = mid - 1;
          }
        }
        vector<pair<int, int>> valid_l = {mp(1, ans)};
        // find first occur of i + 1
        valid_l.pb(mp(*occur[(i + 1) % 3].begin(), n));
        // find suffix such that only i occurs
        l = 1, r = n + 1, ans = n + 1;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(bit[i].query(mid, n) == n - mid + 1) {
            ans = mid, r = mid - 1;
          }
          else {
            l = mid + 1;
          }
        }
        vector<pair<int, int>> valid_r = {mp(ans, n)};
        // find last occur of i + 1
        valid_r.pb(mp(1, *--occur[(i + 1) % 3].end()));
        for(auto p1 : valid_l) {
          for(auto p2 : valid_r) {
            if(p1.fi <= p1.se && p2.fi <= p2.se) {
              res += max(0, bit[i].query(intersect(p1, p2).fi, intersect(p1, p2).se));
            }
          }
        }
      }
      cout << res << endl;
    }
  }
  return 0;
}