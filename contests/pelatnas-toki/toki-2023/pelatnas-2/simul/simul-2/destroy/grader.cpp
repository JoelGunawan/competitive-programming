#include "destroy.h"

#include <stdio.h>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> U(N - 1), V(N - 1);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &U[i], &V[i]);
  }

  std::vector<int> answer = destroy(N, U, V);
  for (int x : answer) {
    printf("%d\n", x);
  }
  return 0;
}
