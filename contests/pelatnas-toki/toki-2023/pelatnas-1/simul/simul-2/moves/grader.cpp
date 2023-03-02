#include "moves.h"

#include <stdio.h>
#include <vector>

int main() {
  int N, Q, A, B;
  scanf("%d %d %d %d", &N, &Q, &A, &B);

  std::vector<int> X(Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d", &X[i]);
  }

  printf("%lld\n", minimum_time(N, Q, A, B, X));
  return 0;
}
