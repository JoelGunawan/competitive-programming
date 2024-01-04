#include "Anna.h"
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

namespace {

int FunctionExample(int r, int c, int K) {
  return (r + c) % K + 1;
}

} // namespace

void Anna(int N, int K, std::vector<int> R, std::vector<int> C) {
  // bfs, dari index pertama pakai 1, 2, 3; index kedua pakai 4, 5, 6, ...
  // fi -> x, y, se -> cur_num
  
}
