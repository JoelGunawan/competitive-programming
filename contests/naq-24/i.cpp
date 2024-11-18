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
void inval() {
  cout << 0 << endl;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  char a[n + 2][n + 2];
  for(int i = 0; i <= n + 1; ++i)
    for(int j = 0; j <= n + 1; ++j)
      a[i][j] = 'X';
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j)
      cin >> a[i][j];
  }
  // check light bulb shining
  bool shine[n + 2][n + 2];
  memset(shine, 0, sizeof(shine));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(a[i][j] == '?') {
        // go down
        shine[i][j] = 1;
        int x = i, y = j;
        while(a[x + 1][y] == '.' || a[x + 1][y] == '?') {
          if(a[x + 1][y] == '?') {
            inval();
          }
          else {
            ++x;
            shine[x][y] = 1;
          }
        }
        x = i, y = j;
        // go up
        while(a[x - 1][y] == '.' || a[x - 1][y] == '?') {
          if(a[x - 1][y] == '?') {
            inval();
          }
          else {
            --x;
            shine[x][y] = 1;
          }
        }
        x = i, y = j;
        // go right
        while(a[x][y + 1] == '.' || a[x][y + 1] == '?') {
          if(a[x][y + 1] == '?') {
            inval();
          }
          else {
            ++y;
            shine[x][y] = 1;
          }
        }
        x = i, y = j;
        // go left
        while(a[x][y - 1] == '.' || a[x][y - 1] == '?') {
          if(a[x][y - 1] == '?') {
            inval();
          }
          else {
            --y;
            shine[x][y] = 1;
          }
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(!shine[i][j] && a[i][j] == '.') {
        inval();
      }
    }
  }
  // check adjacent bulbs
  vector<pair<int, int>> ad = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(a[i][j] == '0' || a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3' || a[i][j] == '4') {
        int req = a[i][j] - '0';
        for(auto p : ad) {
          if(a[p.fi + i][p.se + j] == '?')
            --req;
        }
        if(req != 0) 
          inval();
      }
    }
  }
  cout << 1 << endl;
  return 0;
}