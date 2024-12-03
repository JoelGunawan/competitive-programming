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
// fi.fi -> x, fi.se -> y, se -> le/ri
vector<pair<pair<int, int>, int>> edges[205][205][2];
bool vis[205][205][2];
void dfs(int x, int y, int s, vector<pair<pair<int, int>, int>> &v) {
  vis[x][y][s] = 1;
  v.pb(mp(mp(x, y), s));
  for(auto p : edges[x][y][s]) {
    if(!vis[p.fi.fi][p.fi.se][p.se])
      dfs(p.fi.fi, p.fi.se, p.se, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int r, c;
  cin >> r >> c;
  char a[r + 2][c + 2];
  memset(a, 0, sizeof(a));
  for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j)
      cin >> a[i][j];
  int cnt_mirror = 0;
  bool lw[r + 1][c + 1], rw[r + 1][c + 1], uw[r + 1][c + 1], dw[r + 1][c + 1];
  memset(lw, 0, sizeof(lw));
  memset(rw, 0, sizeof(rw));
  memset(uw, 0, sizeof(uw));
  memset(dw, 0, sizeof(dw));
  int limx = r, limy = c;
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(a[i][j] != '.')
        ++cnt_mirror;
      if(a[i][j] == '/') {
        // left/up and right/down
        bool l = 0, u = 0, r = 0, d = 0;
        // left
        for(int k = j - 1; k >= 1; --k) {
          if(a[i][k] != '.') {
            edges[i][j][0].pb(mp(mp(i, k), 1));
            edges[i][k][1].pb(mp(mp(i, j), 0));
            l = 1;
            break;
          }
        }
        // right
        for(int k = j + 1; k <= c; ++k) {
          if(a[i][k] != '.') {
            edges[i][j][1].pb(mp(mp(i, k), 0));
            edges[i][k][0].pb(mp(mp(i, j), 1));
            r = 1;
            break;
          }
        }
        // down
        for(int k = i + 1; k <= limx; ++k) {
          if(a[k][j] != '.') {
            pair<pair<int, int>, int> cur = mp(mp(k, j), 1);
            if(a[k][j] == '/') {
              cur = mp(mp(k, j), 0);
            }
            edges[i][j][1].pb(cur);
            edges[cur.fi.fi][cur.fi.se][cur.se].pb(mp(mp(i, j), 1));
            d = 1;
            break;
          }
        }
        // up
        for(int k = i - 1; k >= 1; --k) {
          if(a[k][j] != '.') {
            pair<pair<int, int>, int> cur = mp(mp(k, j), 0);
            if(a[k][j] == '/') {
              cur = mp(mp(k, j), 1);
            }
            edges[i][j][0].pb(cur);
            edges[cur.fi.fi][cur.fi.se][cur.se].pb(mp(mp(i, j), 0));
            u = 1;
            break;
          }
        }
        if(!l)
          lw[i][j] = 1;
        if(!r) 
          rw[i][j] = 1;
        if(!d)
          dw[i][j] = 1;
        if(!u)
          uw[i][j] = 1;
      }
      else if(a[i][j] == '\\') {
        // left/up and right/down
        bool l = 0, u = 0, r = 0, d = 0;
        // left
        for(int k = j - 1; k >= 1; --k) {
          if(a[i][k] != '.') {
            edges[i][j][0].pb(mp(mp(i, k), 1));
            edges[i][k][1].pb(mp(mp(i, j), 0));
            l = 1;
            break;
          }
        }
        // right
        for(int k = j + 1; k <= c; ++k) {
          if(a[i][k] != '.') {
            edges[i][j][1].pb(mp(mp(i, k), 0));
            edges[i][k][0].pb(mp(mp(i, j), 1));
            r = 1;
            break;
          }
        }
        // down
        for(int k = i + 1; k <= limx; ++k) {
          if(a[k][j] != '.') {
            pair<pair<int, int>, int> cur = mp(mp(k, j), 1);
            if(a[k][j] == '/') {
              cur = mp(mp(k, j), 0);
            }
            edges[i][j][0].pb(cur);
            edges[cur.fi.fi][cur.fi.se][cur.se].pb(mp(mp(i, j), 0));
            d = 1;
            break;
          }
        }
        // up
        for(int k = i - 1; k >= 1; --k) {
          if(a[k][j] != '.') {
            pair<pair<int, int>, int> cur = mp(mp(k, j), 0);
            if(a[k][j] == '/') {
              cur = mp(mp(k, j), 1);
            }
            edges[i][j][1].pb(cur);
            edges[cur.fi.fi][cur.fi.se][cur.se].pb(mp(mp(i, j), 1));
            u = 1;
            break;
          }
        }
        if(!l)
          lw[i][j] = 1;
        if(!r) 
          rw[i][j] = 1;
        if(!d)
          dw[i][j] = 1;
        if(!u)
          uw[i][j] = 1;
      }
    }
  }
  int res = 0;
  vector<string> ans;
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(!vis[i][j][0]) {
        vector<pair<pair<int, int>, int>> cur;
        dfs(i, j, 0, cur);
        vector<pair<int, int>> m;
        for(auto p : cur)
          m.pb(p.fi);
        sort(m.begin(), m.end());
        m.resize(unique(m.begin(), m.end()) - m.begin());
        if(m.size() == cnt_mirror) {
          for(auto p : cur) {
            int x = p.fi.fi, y = p.fi.se;
            if(p.se == 0) {
              // left/up
              if(a[x][y] == '/') {
                if(lw[x][y])
                  ++res, ans.pb("W" + to_string(x));
                if(uw[x][y])
                  ++res, ans.pb("N" + to_string(y));
              }
              // left/down
              else {
                if(lw[x][y])
                  ++res, ans.pb("W" + to_string(x));
                if(dw[x][y])
                  ++res, ans.pb("S" + to_string(y));
              }
            }
            else {
              // right/down
              if(a[x][y] == '/') {
                if(rw[x][y])
                  ++res, ans.pb("E" + to_string(x));
                if(dw[x][y])
                  ++res, ans.pb("S" + to_string(y));
              }
              // right/up
              else {
                if(rw[x][y])
                  ++res, ans.pb("E" + to_string(x));
                if(uw[x][y])
                  ++res, ans.pb("N" + to_string(y));
              }
            }
          } 
        }
      }
      if(!vis[i][j][1]) {
        vector<pair<pair<int, int>, int>> cur;
        dfs(i, j, 1, cur);
        vector<pair<int, int>> m;
        for(auto p : cur)
          m.pb(p.fi);
        sort(m.begin(), m.end());
        m.resize(unique(m.begin(), m.end()) - m.begin());
        if(m.size() == cnt_mirror) {
          for(auto p : cur) {
            int x = p.fi.fi, y = p.fi.se;
            if(p.se == 0) {
              // left/up
              if(a[x][y] == '/') {
                if(lw[x][y])
                  ++res, ans.pb("W" + to_string(x));
                if(uw[x][y])
                  ++res, ans.pb("N" + to_string(y));
              }
              // left/down
              else {
                if(lw[x][y])
                  ++res, ans.pb("W" + to_string(x));
                if(dw[x][y])
                  ++res, ans.pb("S" + to_string(y));
              }
            }
            else {
              // right/down
              if(a[x][y] == '/') {
                if(rw[x][y])
                  ++res, ans.pb("E" + to_string(x));
                if(dw[x][y])
                  ++res, ans.pb("S" + to_string(y));
              }
              // right/up
              else {
                if(rw[x][y])
                  ++res, ans.pb("E" + to_string(x));
                if(uw[x][y])
                  ++res, ans.pb("N" + to_string(y));
              }
            }
          } 
        }
      }
    }
  }
  // for(int i = 1; i <= r; ++i) {
  //   for(int j = 1; j <= c; ++j) {
  //     cerr << lw[i][j] << " ";
  //   }
  //   cerr << endl;
  // }
  // cerr << endl;
  // for(int i = 1; i <= r; ++i) {
  //   for(int j = 1; j <= c; ++j) {
  //     cerr << rw[i][j] << " ";
  //   }
  //   cerr << endl;
  // }
  // cerr << endl;
  // for(int i = 1; i <= r; ++i) {
  //   for(int j = 1; j <= c; ++j) {
  //     cerr << dw[i][j] << " ";
  //   }
  //   cerr << endl;
  // }
  // cerr << endl;
  // for(int i = 1; i <= r; ++i) {
  //   for(int j = 1; j <= c; ++j) {
  //     cerr << uw[i][j] << " ";
  //   }
  //   cerr << endl;
  // }
  // cerr << endl;
  cout << res << endl;
  for(auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}