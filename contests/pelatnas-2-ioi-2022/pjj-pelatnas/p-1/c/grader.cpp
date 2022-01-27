#include "challenge.h"

#include <cstdio>
#include <vector>

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  initialize(N, A);
  for (int i = 0; i < Q; i++) {
    int x, t;
    scanf("%d %d", &x, &t);
    printf("%d\n", solve_challenge(x, t));
  }

  return 0;
}
