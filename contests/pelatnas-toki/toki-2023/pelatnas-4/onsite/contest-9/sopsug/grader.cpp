#include "sopsug.h"

#include <cassert>
#include <cstdio>

#include <vector>

bool calledBuild;

void build(std::vector<int> U, std::vector<int> V) {
  calledBuild = true;
  for (int i = 0; i < static_cast<int>(U.size()); ++i) {
    printf("%d %d\n", U[i], V[i]);
  }
}

int main() {
  int N, M, K;
  assert(3 == scanf("%d %d %d", &N, &M, &K));
  std::vector<int> A(M), B(M), C(K), D(K);
  for (int i = 0; i < M; ++i) {
    assert(2 == scanf("%d %d", &A[i], &B[i]));
  }
  for (int j = 0; j < K; ++j) {
    assert(2 == scanf("%d %d", &C[j], &D[j]));
  }

  calledBuild = false;

  build_tubes(N, M, K, A, B, C, D);

  if (!calledBuild) {
    printf("NO\n");
  }
  return 0;
}
