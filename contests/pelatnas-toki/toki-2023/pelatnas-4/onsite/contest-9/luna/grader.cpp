#include "luna.h"

#include <cassert>
#include <cstdio>
#include <vector>

int main() {
  int N;
  assert(1 == scanf("%d", &N));
  std::vector<int> A(N * 2);
  for (int i = 0; i < N * 2; ++i) {
    assert(1 == scanf("%d", &A[i]));
  }
  printf("%lld\n", minimum_actions(N, A));
  return 0;
}
