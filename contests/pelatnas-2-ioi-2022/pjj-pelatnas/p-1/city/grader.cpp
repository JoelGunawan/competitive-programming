#include <cstdio>
#include <algorithm>
#include <vector>
#include "city.h"

int main() {
  int N, M, S, T;
  std::vector<int> A, B, C;

  scanf("%d %d %d %d", &N, &M, &S, &T);
  A.resize(M); B.resize(M); C.resize(M);

  for(int i = 0 ; i < M ; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
  }

  std::pair<int, int> answer = getBestXY(N, M, S, T, A, B, C);
  printf("%d %d\n", answer.first, answer.second);

  return 0;
}
