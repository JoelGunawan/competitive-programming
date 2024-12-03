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
  // x = 1 -> just diff between init height and final height
  // x = 3 -> get creative with up/downs
  // if negative cycle exists in the grid -> 
  // init -> low -> init such that the gaps going down are larger than the gaps going up
  // note that if there is no cycle -> "normal dijkstra" is good
  // if there is a cycle -> always invalid
  // heights -> only from 0 to 9 -> can help?
  int r, c, x;
  cin >> r >> c >> x;
  int a[r + 1][c + 1];
  for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j) {
      char tmp;
      cin >> tmp;
      a[i][j] = tmp - '0';
    }
  ll hor[r + 1][c + 1], ver[r + 1][c + 1];
  ll weight[10];
  for(int i = 0; i < 10; ++i) {
    int cur = 1;
    for(int j = 1; j <= x; ++j)
      cur *= i;
    weight[i] = cur;
  }
  memset(hor, 0, sizeof(hor));
  memset(ver, 0, sizeof(ver));
  for(int i = 2; i <= r; ++i) {
    for(int j = 1; j <= c; ++j)
      ver[i][j] = ver[i - 1][j] + (a[i][j] > a[i - 1][j] ? weight[a[i][j] - a[i - 1][j]] : -weight[a[i - 1][j] - a[i][j]]);
  }
  for(int i = 1; i <= r; ++i) {
    for(int j = 2; j <= c; ++j) {
      hor[i][j] = hor[i][j - 1] + (a[i][j] > a[i][j - 1] ? weight[a[i][j] - a[i][j - 1]] : -weight[a[i][j - 1] - a[i][j]]);
    }
  }
  // for(int i = 1; i <= r; ++i) {
  //   for(int j = 1; j <= c; ++j)
  //     cerr << ver[i][j] << " ";
  //   cerr << endl;
  // }
  // for(int i = 1; i <= r; ++i) {
  //   for(int j = 1; j <= c; ++j)
  //     cerr << hor[i][j] << " ";
  //   cerr << endl;
  // }
  bool valid = 1;
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(hor[1][j] + ver[i][j] != ver[i][1] + hor[i][j])
        valid = 0;
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(!valid) {
      cout << "INVALID" << endl;
      continue;
    }
    ll out = 0;
    // cerr << r2 << " " << r1 << endl;
    // cerr << ver[r2][c1] << " " << ver[r1][c1] << endl;
    out += ver[r2][c1] - ver[r1][c1];
    // cerr << out << endl;
    // cerr << hor[r2][c1] << " " << hor[r2][c2] << endl;
    out += hor[r2][c2] - hor[r2][c1];
    cout << -out << endl;
  }
}