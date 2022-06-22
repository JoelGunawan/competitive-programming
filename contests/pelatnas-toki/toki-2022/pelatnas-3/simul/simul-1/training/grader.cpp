#include <iostream>
#include <vector>

#include "training.h"

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(M), B(M), C(M);
  for (int i = 0; i < M; i++) {
    std::cin >> A[i] >> B[i] >> C[i];
  }
  std::vector<int> D = find_training_routes(N, A, B, C);
  for (int i = 0; i < N; i++) {
    std::cout << D[i] << " \n"[i + 1 == N];
  }
  return 0;
}
