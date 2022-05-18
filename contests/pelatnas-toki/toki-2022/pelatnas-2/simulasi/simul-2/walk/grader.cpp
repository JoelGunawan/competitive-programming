#include <stdio.h>

#include <vector>

#include "walk.h"

int main() {
  int N, M;
  long long K;
  scanf("%d %d %lld", &N, &M, &K);
  std::vector<int> U(M), V(M), W(M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &U[i], &V[i], &W[i]);
  }
  printf("%lld\n", find_best_walk(N, K, U, V, W));
  return 0;
}
