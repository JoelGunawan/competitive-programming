#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  pair<int, int> koordinat_a;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 'A')
        koordinat_a = make_pair(i, j);
    }
  }
  // pair.first -> koordinat 
  // pair.first.first -> koordinat x
  // pair.first.second -> koordinat y
  // pair.second -> jarak
  queue<pair<pair<int, int>, int>> bfs;
  bfs.push(make_pair(koordinat_a, 0));
  bool vis[n + 1][m + 1];
  memset(vis, 0, sizeof(vis));
  int d[n + 1][m + 1];
  memset(d, -1, sizeof(d));
  while(bfs.size()) {
    int x = bfs.front().first.first, y = bfs.front().first.second, jarak = bfs.front().second;
    bfs.pop();
    if(vis[x][y]) {
      continue;
    }
    vis[x][y] = 1;
    d[x][y] = jarak;
    // coba ke atas di grid
    if(x > 1 && (a[x - 1][y] == '.' || a[x - 1][y] == 'B') && !vis[x - 1][y]) {
      bfs.push(make_pair(make_pair(x - 1, y), jarak + 1));
    }
    // coba ke kanan di grid
    if(y < m && (a[x][y + 1] == '.' || a[x][y + 1] == 'B') && !vis[x][y + 1]) {
      bfs.push(make_pair(make_pair(x, y + 1), jarak + 1));
    }
    // coba ke bawah di grid
    if(x < n && (a[x + 1][y] == '.' || a[x + 1][y] == 'B') && !vis[x + 1][y]) {
      bfs.push(make_pair(make_pair(x + 1, y), jarak + 1));
    }
    // coba ke kiri di grid
    if(y > 1 && (a[x][y - 1] == '.' || a[x][y - 1] == 'B') && !vis[x][y - 1]) {
      bfs.push(make_pair(make_pair(x, y - 1), jarak + 1));
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      //cout << d[i][j] << " ";
    }
    //cout << endl;
  }
  // backtrack (mencari cara dari jawaban optimal)
  pair<int, int> posisi;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 'B')
        posisi = make_pair(i, j);
    }
  }
  // kasus tidak ada jalan dari A -> B
  if(d[posisi.first][posisi.second] == -1) {
    cout << "NO" << endl;
    return 0;
  }
  vector<char> gerakan;
  while(posisi != koordinat_a) {
    int x = posisi.first, y = posisi.second;
    //cout << x << " " << y << " " << koordinat_a.first << " " << koordinat_a.second << endl;
    if(d[x][y] - 1 == d[x - 1][y]) {
      // yg di atas itu jaraknya jarak skrg dikurang 1
      // sebelumnya itu dari atas ke bawah
      posisi = make_pair(x - 1, y);
      gerakan.push_back('D');
    }
    else if(d[x][y] - 1 == d[x + 1][y]) {
      // yg di bawah itu jaraknya jarak skrg dikurang 1
      // sebelumnya itu dari bawah ke atas
      posisi = make_pair(x + 1, y);
      gerakan.push_back('U');
    }
    else if(d[x][y] - 1 == d[x][y + 1]) {
      // sebelumnya dari kanan ke kiri
      posisi = make_pair(x, y + 1);
      gerakan.push_back('L');
    }
    else {
      // sebelumnya dari kiri ke kanan
      posisi = make_pair(x, y - 1);
      gerakan.push_back('R');
    }
  }
  cout << "YES" << endl;
  cout << gerakan.size() << endl;
  reverse(gerakan.begin(), gerakan.end());
  for(auto x : gerakan) {
    cout << x;
  }
  cout << endl;
}