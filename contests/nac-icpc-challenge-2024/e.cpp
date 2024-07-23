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
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> a(n, vector <int> (m, 0));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  vector <int> flag(5000);

  auto sub1 = [&]() {
    vector <int> dp(bit(n * m));

    vector <int> trans(bit(n * m));
    for (int mask = 0; mask < bit(n * m); mask++) {
      vector <int> num;
      for (int i = 0, cur = 0; i < n; i++, cur += m) {
        num.push_back((mask >> cur) & (bit(m) - 1));
      }
      sort(num.begin(), num.end());
      for (int i = 0, cur = 0; i < n; i++, cur += m) {
        trans[mask] |= (num[i] << cur);
      }
    }

    vector <int> ord;
    for (int i = 0; i < bit(n * m); i++) {
      if (trans[i] == i) {
        ord.push_back(i);
      }
    }

    // cerr << "processed\n";

    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return __builtin_popcount(i) < __builtin_popcount(j);
    });

    for (int mask : ord) {
      vector <int> nim;
      for (int i = 0; i < n; i++) {
        vector <int> pos;
        for (int j = 0; j < m; j++) if (getbit(mask, i * m + j)) {
          pos.push_back(i * m + j);
        }

        for (int msk = 1; msk < bit(pos.size()); msk++) {
          int newmask = mask;
          for (int k = 0; k < (int) pos.size(); k++) {
            if (getbit(msk, k)) {
              newmask ^= bit(pos[k]);
            }
          }
          nim.push_back(dp[trans[newmask]]);
        }
      }

      for (int j = 0; j < m; j++) {
        vector <int> pos;
        for (int i = 0; i < n; i++) if (getbit(mask, i * m + j)) {
          pos.push_back(i * m + j);
        }

        for (int msk = 1; msk < bit(pos.size()); msk++) {
          int newmask = mask;
          for (int k = 0; k < (int) pos.size(); k++) {
            if (getbit(msk, k)) {
              newmask ^= bit(pos[k]);
            }
          }
          nim.push_back(dp[trans[newmask]]);
        }
      }

      for (int x : nim) {
        flag[x] = true;
      }

      while (flag[dp[mask]]) {
        dp[mask]++;
      }

      for (int x : nim) {
        flag[x] = false;
      }
    }
    // cerr << '.';
    int ans = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      ans |= a[i][j] << (i * m + j);
    }

    // for (int x : dp) {
    //   cout << x << " ";
    // }

    if (dp[trans[ans]] > 0) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  };  

  auto sub2 = [&]() {
    vector <pair <int, int>> points;
    vector <int> cntr(n), cntc(m), rows, cols;
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        points.push_back({i, j});
        cntr[i]++;
        cntc[j]++;
        rows.push_back(i);
        cols.push_back(j);
      }
    }
    
    sort(ALL(rows));
    sort(ALL(cols));
    rows.resize(unique(ALL(rows)) - rows.begin());
    cols.resize(unique(ALL(cols)) - cols.begin());

    int k = points.size();
    vector <int> dp(bit(k));

    for (int mask = 0; mask < bit(k); mask++) {
      vector <int> nim;
      for (int i : rows) {
        vector <int> lone, mul;
        for (int j = 0; j < k; j++) if (getbit(mask, j)) {
          auto [x, y] = points[j];
          if (x == i) {
            if (cntc[y] == 1) {
              lone.push_back(j);
            } else {
              mul.push_back(j);
            }
          }
        }

        for (int ind = 0; ind <= (int) lone.size(); ind++)
        for (int msk = 0; msk < bit(mul.size()); msk++) {
          int newmask = mask;
          for (int it = 0; it < ind; it++) {
            newmask ^= bit(lone[it]);
          }

          for (int it = 0; it < (int) mul.size(); it++) if (getbit(msk, it)) {
            newmask ^= bit(mul[it]);
          }

          if (ind + msk > 0) {
            nim.push_back(dp[newmask]);
          }
        }
      }

      for (int i : cols) {
        vector <int> lone, mul;
        for (int j = 0; j < k; j++) if (getbit(mask, j)) {
          auto [x, y] = points[j];
          if (y == i) {
            if (cntr[x] == 1) {
              lone.push_back(j);
            } else {
              mul.push_back(j);
            }
          }
        }

        for (int num = 0; num <= (int) lone.size(); num++)
        for (int msk = 0; msk < bit(mul.size()); msk++) {
          int newmask = mask;
          for (int it = 0; it < num; it++) {
            newmask ^= bit(lone[it]);
          }

          for (int it = 0; it < (int) mul.size(); it++) if (getbit(msk, it)) {
            newmask ^= bit(mul[it]);
          }

          if (num + msk > 0) {
            // cerr << mask << " " << newmask << " " << dp[newmask] << "\n";
            nim.push_back(dp[newmask]);
          }
        }
      }

      for (int x : nim) {
        flag[x] = true;
      }

      while (flag[dp[mask]]) {
        dp[mask]++;
      }

      for (int x : nim) {
        flag[x] = false;
      }
    }

    // for (int x : dp) {
    //   cout << x << " ";
    // }

    if (dp[bit(k) - 1] > 0) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  };

  if (max(n, m) <= 5) {
    sub1();
  } else {
    sub2();
  }
  

  return 0;
}