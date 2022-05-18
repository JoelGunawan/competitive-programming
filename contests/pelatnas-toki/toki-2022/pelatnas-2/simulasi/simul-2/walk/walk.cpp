#include "walk.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long find_best_walk(int N, long long K, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  // untuk tiap node, coba pilih node sebagai origin
  // iterasi tiap node dan coba tambahkan kepada graf
  // banyak cara pilih edge yang terhubung
  // untuk tiap edge, cari edge lain yang mungkin bisa dihubungkan dengan edge sekarang
  // subtask 4 -> consider tiap pair bisa dari depan ataupun belakang
  // jadikan dalam array
  // tidak terlalu banyak maksimalnya
  vector<int> ways = {0};
  for(int i = 0; i < N; ++i) {
    int cur = 0;
    for(int j = 0; j < N; ++j) {
      // query dari i to i + j
      //cout << i << " " << j << " " << cur << endl;
      cur += W[(i + j) % N];
      ways.push_back(cur);
    }
  }
  int tmp = 0;
  for(int i = 0; i < N; ++i)
    tmp += W[i];
  //ways.push_back(tmp);
  sort(ways.begin(), ways.end());
  if(K >= ways.size())
    return -1;
  // cara cari banyak walk dalam sebuah graf seperti soal vnoi
  // sebuah walk merupakan pemilihan beberapa edge sehingga tiap edge terhubung melalui beberapa pasange edge lain
  return ways[K];
}