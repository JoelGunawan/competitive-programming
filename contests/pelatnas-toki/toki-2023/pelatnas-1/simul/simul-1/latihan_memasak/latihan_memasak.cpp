#include "latihan_memasak.h"
#include <bits/stdc++.h>
using namespace std;

vector<long long> findY(int N, int M, int Y, vector<int> r, vector<int> h,
                        vector<int> L, vector<int> R) {
  // state -> ll pair<int, int>
  // ll menggambarkan cost
  // pair<int, int> menggambarkan state
  // untuk L = R dlu
  // general sol:
  // state -> ll pair<int, pair<int, int>>
  // ll -> cost
  // pair<int, pair<int, int>> 
  // pending dijkstra of pending dijkstra
  // tiap baris punya pending dijkstra yang berisi next edgenya dia
  // yang sudah ada disimpan ke vektor (pasti terurut)
  // vektor edge yang dipake buat pending dijkstra akhir
  // masuk ke petak -> pasti modify dengan elem itu
  // get smallest permutation of elements L, nanti bakal ada origin permutations and lanjutannya dari pending edges
}
