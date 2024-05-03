#include <bits/stdc++.h>
using namespace std;
int main() {
  // representasi di graf menggunakan edge list
  // first dan second melambangkan node yg dihubungkan
  // unweighted:
  // jika directed:
  // node pair.first itu asal dari edge, node pair.second itu tujuan dari edge
  // jika undirected:
  // tidak ada arahnya
  vector<pair<int, int>> unweighted_edge_list;
  // contoh directed
  // kalau mau jadi undirected isinya sama, hanya beda cara pakai
  unweighted_edge_list.push_back(make_pair(1, 2));
  unweighted_edge_list.push_back(make_pair(2, 3));
  unweighted_edge_list.push_back(make_pair(3, 1));
  unweighted_edge_list.push_back(make_pair(2, 4));
  unweighted_edge_list.push_back(make_pair(3, 4));
  unweighted_edge_list.push_back(make_pair(4, 5));
  pair<int, int> unweighted_edge_list[100];
  // weighted:
  // pair.first -> bobot/weight
  // pair.second itu isinya seperti yg unweighted
  // directed: 
  // pair.first menuju ke pair.second
  // undirected:
  // tidak ada arah
  // note: jika mau dibalik, misal jadi pair<pair<int, int>, int> juga boleh
  // khusus utk masuk ke algoritma min. spanning tree (yg tdk akan dibahas, materi osn)
  // lebih gampang jika bobotnya yang di depan
  vector<pair<int, pair<int, int>>> weighted_edge_list;
  weighted_edge_list.push_back(make_pair(make_pair(3, make_pair(1, 2))));
  weighted_edge_list.push_back(make_pair(make_pair(4, make_pair(1, 3))));
  weighted_edge_list.push_back(make_pair(make_pair(2, make_pair(3, 2))));
  weighted_edge_list.push_back(make_pair(make_pair(10, make_pair(2, 4))));
  weighted_edge_list.push_back(make_pair(make_pair(6, make_pair(4, 5))));
  weighted_edge_list.push_back(make_pair(make_pair(5, make_pair(4, 3))));
  pair<int, pair<int, int>> weighted_edge_list[100];

}