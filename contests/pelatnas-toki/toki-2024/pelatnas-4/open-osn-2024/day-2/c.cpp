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
int main() {
  cin >> n >> m;
  vector<vector<bool>> b(n, vector<bool>(m));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      b[i][j] = x == '1';
    }
  // semua petak yg ada di kanan/bawah sebuah petak 0 jika menjadi 1 maka pasti bisa di eksperimen
  // 2^8 = 256
  // bad cases exist (bisa jadi log^2)
  // try every shift, consider everything that is 1 has 2 elems in it
  // for every 0, we need to choose an optimal shift such that the number of boxes that are guaranteed to be at most 1 is maximum
  while(true) {
    int mx_shift = -1, mx = 0;
    for(int shift = 0; shift < n * m; ++shift) {
      // try shift i vertical and j horizontal

        int i = shift % n, j = shift % m;
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
        }
    }
    bool can[n][m];
    memset(can, 0, sizeof(can));
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(!b[i][j]) {
          can[(i + mx_shift / m) % n][j] = 1;
          can[i][(j + mx_shift % m) % m] = 1;
        }
      }
    }
    int acel = -1;
    for(int i = 0; i < n * m; ++i) {
      if(i % n == mx_shift / m && i % m == mx_shift % m) {
        acel = i;
        break;
      }
    }
    vector<vector<bool>> nb = accelerate(acel);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(can[i][j] && nb[i][j]) {
          experiment(i, j);
          nb[i][j] = 0;
        }
      }
    }
    b = nb;
    bool nxt = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(b[i][j])
          nxt = 1;
      }
    }
    if(!nxt)
      break;
  }
}