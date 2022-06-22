#include <iostream>
#include <vector>

#include "trainer.h"

int main() {
  int M, N, K;
  std::cin >> M >> N >> K;
  std::vector<int> L(K), R(K);
  std::vector<std::vector<int>> A(M, std::vector<int>(2 * N));
  for (int i = 0; i < K; i++) {
    std::cin >> L[i] >> R[i];
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 2 * N; j++) {
      std::cin >> A[i][j];
    }
  }
  long long p = minimize_penalty(L, R, A);
  std::cout << p << '\n';
  return 0;
}
