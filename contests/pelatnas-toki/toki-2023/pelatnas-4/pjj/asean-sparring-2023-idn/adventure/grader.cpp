#include "adventure.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N, K, Q;
  assert(3 == scanf("%d %d %d", &N, &K, &Q));

  std::vector<int> U(N - 1), V(N - 1);
  std::vector<char> C(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %c", &U[i], &V[i], &C[i]));
  }

  std::vector<int> X(Q), Y(Q);
  for (int i = 0; i < Q; ++i) {
    assert(2 == scanf("%d %d", &X[i], &Y[i]));
  }

  std::vector<long long> result = count_subpaths(N, K, Q, U, V, C, X, Y);

  for (int i = 0; i < (int) result.size(); ++i) {
    printf("%lld\n", result[i]);
  }

  return 0;
}
