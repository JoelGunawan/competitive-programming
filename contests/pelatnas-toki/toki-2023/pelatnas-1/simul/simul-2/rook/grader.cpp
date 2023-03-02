#include "rook.h"

#include <stdio.h>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> X(N), Y(N), C(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d %d", &X[i], &Y[i], &C[i]);
  }

  printf("%d\n", minimum_move(N, X, Y, C));
  return 0;
}
