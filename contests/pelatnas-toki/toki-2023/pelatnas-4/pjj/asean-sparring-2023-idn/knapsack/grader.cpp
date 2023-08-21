#include "knapsack.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N;
  long long T;
  assert(2 == scanf("%d %lld", &N, &T));
  std::vector<int> W(N), V(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &W[i]));
  }
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &V[i]));
  }

  printf("%lld\n", find_maximum(N, T, W, V));
}
