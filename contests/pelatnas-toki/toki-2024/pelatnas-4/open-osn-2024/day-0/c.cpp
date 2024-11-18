// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
ifstream fin;
ofstream fout;
void solve() {
  // cout << "SOLVING" << endl;
  int n, m;
  fin >> n >> m;
  // cout << "INPUTTING" << endl;
  // cout << n << " " << m << endl;
  bool a[n + 1][m + 1];
  char c[n + 1][m + 1];
  memset(a, 0, sizeof(a));
  // cout << "MEMSET" << endl;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      fin >> c[i][j], a[i][j] = c[i][j] == '.';
  int row[n + 1][2], col[m + 1][2];
  // cout << "TEST2" << endl;
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      ++row[i][a[i][j]];
      ++col[j][a[i][j]];
    }
  }
  int dh[2], dv[2];
  memset(dh, 0, sizeof(dh));
  memset(dv, 0, sizeof(dv));
  deque<pair<int, int>> hor, ver;
  for(int i = 1; i <= n; ++i)
    hor.pb(mp(row[i][0], i));
  for(int i = 1; i <= m; ++i)
    ver.pb(mp(col[i][0], i));
  for(int i = 0; i < 1; ++i) {
    sort(hor.begin(), hor.end());
    // reverse(hor[i].begin(), hor[i].end());
    sort(ver.begin(), ver.end());
    // reverse(ver[i].begin(), ver[i].end());
  }
  //  cout << "TEST" << endl;
  // fi -> row/col number
  // se.fi -> row/col
  // se.se -> black or white
  vector<pair<int, pair<bool, bool>>> ops;
  bool delh[n + 1], delv[m + 1];
  memset(delh, 0, sizeof(delh));
  memset(delv, 0, sizeof(delv));
  while(hor.size() || ver.size()) {
    bool valid = 0;
    cout << dh[0] << " " << dh[1] << " " << dv[0] << " " << dv[1] << endl;
    cout << hor.back().fi << " " << n - hor.front().fi << " " << ver.back().fi << " " << m - ver.front().fi << endl;
    cout << hor.back().fi << " " << hor.back().se << endl;
    if(hor.size() && hor.back().fi == m - dh[1]) {
      // hapus hor, berarti dv berkurang
      cout << "DELETE HOR0 " << hor.back().se << endl;
      valid = 1;
      ++dv[0];
      ops.pb(mp(hor.back().se, mp(0, 0)));
      hor.pop_back();
    }
    if(hor.size() && m - hor.front().fi == m - dh[0]) {
      cout << "DELETE HOR1 " << hor.front().se << endl;
      valid = 1;
      ++dv[1];
      ops.pb(mp(hor.front().se, mp(0, 1)));
      hor.pop_front();
    }
    if(ver.size() && ver.back().fi == n - dv[1]) {
      cout << "DELETE ver0 " << ver.back().se << endl;
      valid = 1;
      ++dh[0];
      ops.pb(mp(ver.back().se, mp(1, 0)));
      ver.pop_back();
    }
    if(ver.size() && n - ver.front().fi == n - dv[0]) {
      cout << "DELETE ver1 " << ver.front().se << endl;
      valid = 1;
      ++dh[1];
      ops.pb(mp(ver.front().se, mp(1, 1)));
      ver.pop_front();
    }
    if(!valid)  
      cout << "INVALID" << endl, exit(0);
  }
  reverse(ops.begin(), ops.end());
  fout << ops.size() << endl;
  for(auto x : ops) {
    fout << (x.se.fi ? "KOLOM" : "BARIS") << " " << x.fi << " " << (x.se.se ? '.' : '#') << endl;
  }
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  for(int i = 1; i <= 5; ++i) {
    fin.open("./mosaik_" + to_string(i) + ".in");
    fout.open("./mosaik_" + to_string(i) + ".out");
    solve();
    fin.close();
    fout.close();
  }
  return 0;
}