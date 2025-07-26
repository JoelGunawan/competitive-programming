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
  ll a, m, p, q, r, s;
  int tc_num = 1;
  while(true) {
    cin >> a >> m >> p >> q >> r >> s;
    if(a == 0 && m == 0 && p == 0 && q == 0 && r == 0 && s == 0) {
      break;
    }
    if(p >= r && q <= s) {
      cout << "Case " << tc_num++ << ": ";
      cout << "empty" << endl;
      continue;
    }
    int cnt_mul = 0;
    vector<pair<int, vector<pair<char, int>>>> sols;
    while(q - p <= s - r && p <= s) {
      int min_add = (r - p) / a;
      if((r - p) % a)
        ++min_add;
      min_add = max(min_add, 0);
      int max_add = (s - q) / a;
      // cerr << cnt_mul << " " << min_add << " " << max_add << endl;
      for(int i = cnt_mul; i >= 0; --i) {
        // try multiple of m^i then choose minimum
        ll tmp = 1;
        for(int j = 0; j < i; ++j) {
          tmp *= m;
          if(tmp > s)
            break;
        }
        if(tmp > s)
          continue;
        ll nx = min_add;
        nx /= tmp;
        nx *= tmp;
        if(nx < min_add)
          nx += tmp;
        for(int j = i; j < cnt_mul; ++j) {
          tmp *= m;
          if(tmp > s)
            break;
        } 
        if(tmp > s)
          continue;
        if(nx <= max_add) {
          // generate sols
          vector<pair<char, int>> ans;
          int cnt = 0;
          while(tmp) {
            if(nx / tmp) 
              ans.emplace_back('A', nx / tmp), cnt += nx / tmp;
            if(tmp > 1) {
              if(ans.size() && ans.back().fi == 'M')
                ++ans.back().se;
              else
                ans.emplace_back('M', 1);
              ++cnt;
            }
            nx %= tmp;
            if(m == 1)
              break;
            tmp /= m;
          }
          sols.emplace_back(cnt, ans);
        }
      }
      if(m == 1)
        break;
      ++cnt_mul;
      p *= m;
      q *= m;
      // cerr << p << " " << q << " " << r << " " << s << endl;
    }
    if(sols.empty()) {
      cout << "Case " << tc_num++ << ": ";
      cout << "impossible" << endl;
    } else {
      // cerr << "HERE" << endl;
      auto tmp = sols;
      tmp.clear();
      int mn = 1e9;
      for(auto &[cnt, p] : sols) {
        // cerr << "GET " << cnt << endl;
        mn = min(mn, cnt);
      }
      for(auto &[cnt, p] : sols) {
        if(cnt == mn) {
          tmp.emplace_back(cnt, p);
        }
      }
      sols = tmp;
      // cerr << sols.size() << endl;
      auto ans = sols[0];
      for(int i = 1; i < sols.size(); ++i) {
        ans = min(ans, sols[i], [] (const auto &a, const auto &b) -> bool { 
          for(int i = 0; i < a.se.size(); ++i) {
            // cerr << "DEB " << i << " " << a.se.size() << " " << b.se.size() << endl;
            // cerr << a.se[i].fi << " " << a.se[i].se << " " << b.se[i].fi << " " << b.se[i].se << endl;
            if(a.se[i].fi != b.se[i].fi) {
              return a.se[i].fi < b.se[i].fi;
            } else if(a.se[i].se != b.se[i].se) {
              if(a.se[i].fi == 'A') {
                // cerr << "FIRST SMALLER" << endl;
                return a.se[i].se > b.se[i].se;
              }
              else {
                // cerr << "SECOND SMALLER" << endl;
                return a.se[i].se < b.se[i].se;
              }
            }
          }
          return true;
        });
      }
      cout << "Case " << tc_num++ << ": ";
      for(auto [c, num] : ans.se) {
        cout << num << c << " ";
      }
      cout << endl;
    }
  }
  return 0;
}