#include "reverse.h"
#include <vector>
using namespace std;
vector<vector<int>> operations;
void solve(int l, int r) {
  if(l == r)
    return;
  else {
    int mid = (l + r) / 2;

  }
}
std::vector<std::vector<int>> reverse_array(int N) {
  // do a DNC algo
  // where we use part of an array and we swap half the array
  // just do 12 point solution
  // we need to swap 2 elements only in 1 move
  for(int i = 2; i <= N; ++i)
    operations.push_back({i, i, 0});
  return operations;
}