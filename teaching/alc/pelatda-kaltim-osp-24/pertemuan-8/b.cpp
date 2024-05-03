#include <bits/stdc++.h>
using namespace std;
// utk unweighted, undirected/directed sama
vector<int> unweighted_edges[100005];
// utk weighted, undirected/directed sama
// (secara pribadi pair.first selalu node yg dituju pair.second bobot)
// jika mau implementasi dibalik silahkan 
// (kadang perlu bobot yg di pertama, kadang perlu bobot yg di kedua)
// 98% soal terserah representasinya gimana :)
// berdasarkan preferensi aja
vector<pair<int, int>> weighted_edges[100005];
int main() {
  // contoh untuk directed + unweighted
  unweighted_edges[1].push_back(2);
  unweighted_edges[2].push_back(3);
  unweighted_edges[2].push_back(4);
  unweighted_edges[3].push_back(4);
  unweighted_edges[3].push_back(1);
  unweighted_edges[4].push_back(5);
  // contoh untuk directed + weighted
  weighted_edges[1].push_back(make_pair(2, 3));
  weighted_edges[1].push_back(make_pair(3, 4));
  weighted_edges[2].push_back(make_pair(1, 3));
  weighted_edges[2].push_back(make_pair(4, 10));
  weighted_edges[2].push_back(make_pair(3, 2));
  weighted_edges[3].push_back(make_pair(2, 2));
  weighted_edges[3].push_back(make_pair(4, 5));
  weighted_edges[3].push_back(make_pair(1, 4));
  weighted_edges[4].push_back(make_pair(2, 10));
  weighted_edges[4].push_back(make_pair(3, 5));
  weighted_edges[4].push_back(make_pair(5, 6));
  weighted_edges[5].push_back(make_pair(4, 6));
}