#include "experiment.h"

#include <cstdio>
#include <vector>

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  std::vector<int> P(N), Q(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &Q[i]);
  }

  std::vector<int> L(M), R(M), D(M), U(M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d %d", &L[i], &R[i], &D[i], &U[i]);
  }

  std::vector<long long> ans = get_experiment_results(N, M, P, Q, L, R, D, U);
  for (int i = 0; i < M; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
