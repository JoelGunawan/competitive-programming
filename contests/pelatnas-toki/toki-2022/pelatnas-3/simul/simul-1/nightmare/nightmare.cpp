#include "nightmare.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
bool comp(pair<int, int> a, pair<int, int> b) {

}
int count_sequences(std::vector<int> A) {
  int N = A.size(), ret;
  // sekarang negatif berapa
  // string length sekarang
  // coba start 1 dulu
  // coba start 2 dulu
  int memo[N][N];
  memset(memo, 0, sizeof(memo));
  for(int i = 0; i < A.size(); ++i) {
    if(A[i] == -1) {
      memo[1][1] = 1;
      for(int j = 2; j < N / 2; ++j) {
        memo[1]
      }
    }
    else if(A[i] == 1) {

    }
    else if(A[i] == -2) {

    }
    else {

    }
  }
  return ret;
}
