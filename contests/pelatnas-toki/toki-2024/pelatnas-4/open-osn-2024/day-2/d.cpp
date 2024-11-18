#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
int n, m;
int experiment(int x, int y) {
  cout << "EKSPERIMEN " << x + 1 << " " << y + 1 << endl;
  int ret;
  cin >> ret;
  return ret;
}
vector<vector<bool>> accelerate(int x) {
  cout << "AKSELERASI " << x << endl;
  vector<vector<bool>> v(n, vector<bool>(m));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      v[i][j] = x == '1';
    }
  }
  return v;
}
vector<int> shifts;
int check_next(vector<vector<bool>> b, int depth, int last) {
  int mx_shift = -1;
  pair<int, int> mx = mp(0, 0);
  vector<int> v;
  // first by num of zeros
  // second by potential next
  // how many is potential next?
  // avoid same row/columns if possible, find distribution that is most even (sd is highest?)
  for(int i = 0; i < n; ++i) {
    // try shift i vertical and j horizontal
    for(int j = 0; j < m; ++j) {
      bool can[n][m];
      memset(can, 0, sizeof(can));
      for(int x = 0; x < n; ++x) {
        for(int y = 0; y < m; ++y) {
          if(!b[x][y]) {
            can[(x + i) % n][y] = 1;
            can[x][(j + y) % m] = 1;
          }
        }
      }
      int cnt = 0;
      for(int x = 0; x < n; ++x)
        for(int y = 0; y < m; ++y)
          if(can[x][y])
            ++cnt;
      if(cnt > mx) {
        mx_shift = i * m + j;
        mx = cnt;
        v = {cnt};
      }
      else if(cnt == mx) 
        v.pb(cnt);
    }
  }
  if(depth == last)
    return mx;
  else {
    if(depth >= 2 && deph <= 4) {
      int ret = 0;
      for(auto x : v) {
        vector<vector<bool>> nb(n, vector<bool>(m));
        
        ret = max(ret, check_next(x, depth + 1, last));
      }
      return ret;
    }
    else {
      return check_next(v[0], depth + 1, last);
    }
  }
}
int main() {
  // cin >> n >> m;
  // assume at the start, boardnya ada yg ke kanan dan ada yg ke bawah
  // tugas kita, cari cara yg length <= 9
  int n = 23, m = 19;
  vector<vector<bool>> b(n, vector<bool>(m));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) {
      b[i][j] = 1;
    }
  b[0][0] = 0;
  cout << check_next(b, 1, 9) << endl;
}