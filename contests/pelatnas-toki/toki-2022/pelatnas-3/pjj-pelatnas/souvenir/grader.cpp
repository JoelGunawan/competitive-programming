#include <stdio.h>

#include <vector>

#include "souvenir.h"

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  std::vector<int> A(N), X(N), B(M), Y(M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &B[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &Y[i]);
  }
  printf("%lld\n", buy_souvenir(A, X, B, Y));
  return 0;
}
