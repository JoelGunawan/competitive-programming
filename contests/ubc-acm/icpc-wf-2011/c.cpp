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
int char_to_dec(char a) {
  if(a >= 'a' && a <= 'f') {
    return a - 'a' + 10;
  } else if (a >= '0' && a <= '9') {
    return a - '0';
  } else {
    assert(false);
  }
}
bool a[205][205];
bool vis[205][205];
int h, w;
vector<pair<int, int>> nxt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int x, int y) {
  return x >= 1 && x <= h && y >= 1 && y <= w && !vis[x][y];
}
void dfs_white(int x, int y) {
  vis[x][y] = 1;
  for(auto p : nxt) {
    if(valid(x + p.fi, y + p.se) && !a[x + p.fi][y + p.se]) {
      dfs_white(x + p.fi, y + p.se);
    }
  }
}
void dfs_black(int x, int y, vector<pair<int, int>> &v) {
  vis[x][y] = 1;
  for(auto p : nxt) {
    if(valid(x + p.fi, y + p.se) && a[x + p.fi][y + p.se]) {
      dfs_black(x + p.fi, y + p.se, v);
    }
  }

  for(auto p : nxt) {
    if(valid(x + p.fi, y + p.se) && !a[x + p.fi][y + p.se]) {
      v.emplace_back(x + p.fi, y + p.se);
    }
  }
}
int dfs_proc(int x, int y) {
  vector<pair<int, int>> v;
  dfs_black(x, y, v);
  int ret = 0;
  // cerr << "SEARCHING " << x << " " << y << endl;
  for(auto [cx, cy] : v) {
    if(!vis[cx][cy]) {
      // cerr << cx << " " << cy << endl;
      dfs_white(cx, cy);
      ++ret;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int tc_num = 0;
  while(cin >> h >> w) {
    if(h == 0 && w == 0) {
      break;
    }
    for(int i = 1; i <= h; ++i) {
      for(int j = 1; j <= 4 * w; ++j)
        a[i][j] = 0, vis[i][j] = 0;
    }
    for(int i = 1; i <= h; ++i) {
      for(int j = 1; j <= w; ++j) {
        char c;
        cin >> c;
        int num = char_to_dec(c);
        for(int k = 4 * j - 3, mask = 3; k <= 4 * j; ++k, --mask) {
          // cerr << i << " " << j << " " << num << " " << mask << endl;
          a[i][k] = num & (1 << mask);
        }
      }
    }
    w *= 4;
    // for(int i = 1; i <= h; ++i) {
    //   for(int j = 1; j <= w; ++j) {
    //     cerr << a[i][j];
    //   }
    //   cerr << endl;
    // }
    for(int i = 1; i <= h; ++i) {
      if(!a[i][1] && !vis[i][1])
        dfs_white(i, 1);
      if(!a[i][w] && !vis[i][w])
        dfs_white(i, w);
    }
    for(int i = 1; i <= w; ++i) {
      if(!a[1][i] && !vis[1][i])
        dfs_white(1, i);
      if(!a[h][i] && !vis[h][i])
        dfs_white(h, i);
    }
    vector<int> v;
    for(int i = 1; i <= h; ++i) {
      for(int j = 1; j <= w; ++j) {
        if(!vis[i][j]) {
          v.push_back(dfs_proc(i, j));
        }
      }
    }
    string s = "";
    for(auto x : v) {
      if(x == 0) {
        s += 'W';
      } else if(x == 1) {
        s += 'A';
      } else if(x == 2) {
        s += 'K';
      } else if(x == 3) {
        s += 'J';
      } else if(x == 4) {
        s += 'S';
      } else if(x == 5) {
        s += 'D';
      }
    }

    sort(s.begin(), s.end());
    cout << "Case " << ++tc_num << ": "  << s << endl;
  }
  return 0;
}