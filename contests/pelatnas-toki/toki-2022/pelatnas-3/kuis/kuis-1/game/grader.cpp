#include <stdio.h>

#include <vector>

#include "game.h"

int main() {
  int N, Q, i, x;
  scanf("%d %d", &N, &Q);
  std::vector<int> B(N);
  for (int idx = 0; idx < N; ++idx) {
    scanf("%d", &B[idx]);
  }
  init(B);
  for (int idx = 0; idx < Q; ++idx) {
    scanf("%d %d", &i, &x);
    printf("%lld\n", modify(i, x));
  }
  return 0;
}
