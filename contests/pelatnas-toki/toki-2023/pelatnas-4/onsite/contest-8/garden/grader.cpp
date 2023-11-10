#include "garden.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N, M, D;
  assert(3 == scanf("%d %d %d", &N, &M, &D));
  std::vector<int> P(N), Q(N), R(M), S(M);
  for (int i = 0; i < N; ++i) {
    assert(2 == scanf("%d %d", &P[i], &Q[i]));
  }
  for (int j = 0; j < M; ++j) {
    assert(2 == scanf("%d %d", &R[j], &S[j]));
  }

  printf("%d\n", minimum_cells(N, M, D, P, Q, R, S));
}
