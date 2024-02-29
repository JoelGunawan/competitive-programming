// header file
#include <bits/stdc++.h>
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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int a[8][4][4] = {{{0,1,1,0},
{1,0,0,1},
{0,1,1,0},
{1,0,0,1}},
{{0,1,0,1},
{1,0,1,0},
{1,0,1,0},
{0,1,0,1}},
{{0,1,0,1},
{0,1,0,1},
{1,0,1,0},
{1,0,1,0}},
{{0,0,1,1},
{1,1,0,0},
{0,0,1,1},
{1,1,0,0}},
{{1,1,0,0},
{0,0,1,1},
{1,1,0,0},
{0,0,1,1}},
{{1,0,1,0},
{1,0,1,0},
{0,1,0,1},
{0,1,0,1}},
{{1,0,1,0},
{0,1,0,1},
{0,1,0,1},
{1,0,1,0}},
{{1,0,0,1},
{0,1,1,0},
{1,0,0,1},
{0,1,1,0}}};
  int t;
  cin >> t;
  while(t--) {
    int n, m, q;
    cin >> n >> m >> q;
    bool pos[8];
    memset(pos, 1, sizeof(pos));
    cout << 8 << endl;
    for(int i = 0; i < q; ++i) {
      int x, y, z;
      cin >> x >> y;
      string s;
      cin >> s;
      if(s == "circle")
        z = 1;
      else
        z = 0;
      for(int i = 0; i < 8; ++i) {
        if(a[i][x % 4][y % 4] != z)
          pos[i] = 0;
      }
      int res = 0;
      for(int i = 0; i < 8; ++i)
        if(pos[i])
          ++res;
      cout << res << endl;
    }
  }
  return 0;
}