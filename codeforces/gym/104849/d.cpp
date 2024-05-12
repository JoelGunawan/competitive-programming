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
void rot(pair<int, int> &a, int times, int n, int m) {
  for(int i = 0; i < times; ++i) {
    int x = a.fi, y = a.se;
    if(i & 1) {
      a.fi = n - y - 1;
      a.se = x;
    }
    else {
      a.fi = m - y - 1;
      a.se = x;
    }
  }
}
void rot(vector<pair<int, int>> &a, int n, int m) {;
  for(auto &p : a) {
    rot(p, 1, n, m);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // observe: only need to check if 8 patterns match each other
  // to check if they match, we can use help of bitset
  // use left top most and 2nd left top most as the reference 
  // observe that one move always satisfies the requirement
  // use bitset.count()
  // dont even need bitset -> check in O(N^2)
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int h, w;
  cin >> h >> w;
  char b[h][w];
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      cin >> b[i][j];
    }
  }
  vector<pair<int, int>> c, d;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(a[i][j] == 'o')
        c.pb(mp(i, j));
    }
  }
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      if(b[i][j] == 'o')
        d.pb(mp(i, j));
    }
  }
  // try every rotation of c
  sort(c.begin(), c.end());
  if(c.size() == 1) {
    cout << c[0].fi << " " << c[0].se << endl;
  }
  for(int i = 0; i < 4; ++i) {
    sort(d.begin(), d.end());
    // try this rotation
    // either remove first or remove something else
    // remove something else:
    pair<int, int> out; int cnt = 0;
    pair<int, int> shift = mp(d[0].fi - c[0].fi, d[0].se - c[0].se);
    for(auto p : c) {
      if(!binary_search(d.begin(), d.end(), mp(p.fi + shift.fi, p.se + shift.se))) {
        // doesn't exist
        ++cnt;
        out = mp(p.fi, p.se);
      }
    }
    if(cnt == 0) {
      cout << c[0].se << " " << c[0].fi << endl;
      cout << c[0].se << " " << c[0].fi << endl;
      exit(0);
    }
    else if(cnt == 1) {
      // find the out of position
      for(auto p : d) {
        if(!binary_search(c.begin(), c.end(), mp(p.fi - shift.fi, p.se - shift.se))) {
          //cout << "HERE: " << i << endl;
          cout << out.se << " " << out.fi << endl;
          cout << p.se - shift.se << " " << p.fi - shift.fi << endl;
          exit(0);
        }
      }
    }
    cnt = 0;
    shift = mp(d[1].fi - c[0].fi, d[1].se - c[0].se);
    for(auto p : c) {
      if(!binary_search(d.begin(), d.end(), mp(p.fi + shift.fi, p.se + shift.se))) {
        // doesn't exist
        ++cnt;
        out = mp(p.fi, p.se);
      }
    }
    if(cnt == 0) {
      cout << c[0].se << " " << c[0].fi << endl;
      cout << c[0].se << " " << c[0].fi << endl;
      exit(0);
    }
    else if(cnt == 1) {
      // find the out of position
      for(auto p : d) {
        if(!binary_search(c.begin(), c.end(), mp(p.fi - shift.fi, p.se - shift.se))) {
          cout << out.se << " " << out.fi << endl;
          cout << p.se - shift.se << " " << p.fi - shift.fi << endl;
          exit(0);
        }
      }
    }
    cnt = 0;
    shift = mp(d[0].fi - c[1].fi, d[0].se - c[1].se);
    for(auto p : c) {
      if(!binary_search(d.begin(), d.end(), mp(p.fi + shift.fi, p.se + shift.se))) {
        // doesn't exist
        ++cnt;
        out = mp(p.fi, p.se);
      }
    }
    if(cnt == 0) {
      cout << c[0].se << " " << c[0].fi << endl;
      cout << c[0].se << " " << c[0].fi << endl;
      exit(0);
    }
    else if(cnt == 1) {
      // find the out of position
      for(auto p : d) {
        if(!binary_search(c.begin(), c.end(), mp(p.fi - shift.fi, p.se - shift.se))) {
          cout << out.se << " " << out.fi << endl;
          cout << p.se - shift.se << " " << p.fi - shift.fi << endl;
          exit(0);
        }
      }
    }
    cnt = 0;
    shift = mp(d[1].fi - c[1].fi, d[1].se - c[1].se);
    for(auto p : c) {
      if(!binary_search(d.begin(), d.end(), mp(p.fi + shift.fi, p.se + shift.se))) {
        // doesn't exist
        ++cnt;
        out = mp(p.fi, p.se);
      }
    }
    if(cnt == 0) {
      cout << c[0].se << " " << c[0].fi << endl;
      cout << c[0].se << " " << c[0].fi << endl;
      exit(0);
    }
    else if(cnt == 1) {
      // find the out of position
      for(auto p : d) {
        if(!binary_search(c.begin(), c.end(), mp(p.fi - shift.fi, p.se - shift.se))) {
          cout << out.se << " " << out.fi << endl;
          cout << p.se - shift.se << " " << p.fi - shift.fi << endl;
          exit(0);
        }
      }
    }
    if(i & 1)
      rot(d, w, h);
    else
      rot(d, h, w);
  }
  assert(false);
  return 0;
}