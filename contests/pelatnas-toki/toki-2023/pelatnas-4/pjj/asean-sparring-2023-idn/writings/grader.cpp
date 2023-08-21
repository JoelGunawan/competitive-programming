#include "writings.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N, K;
  assert(2 == scanf("%d %d", &N, &K));
  std::vector<int> P(N), A(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &P[i]));
  }
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &A[i]));
  }

  printf("%d\n", count_writings(N, K, P, A));
}
