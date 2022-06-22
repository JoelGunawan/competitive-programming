#include <iostream>
#include <vector>

#include "pekerjaan.h"

int main() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> C(N);
  for (int i = 0; i < N; i++) {
    std::cin >> C[i];
  }
  std::vector<int> U(N - 1), V(N - 1);
  for (int i = 0; i < N - 1; i++) {
    std::cin >> U[i] >> V[i];
  }
  init(C, U, V);
  for (int i = 0; i < Q; i++) {
    int K;
    std::cin >> K;
    std::vector<int> P(K);
    for (int j = 0; j < K; j++) {
      std::cin >> P[j];
    }
    std::cout << kerugian_minimum(P) << '\n';
  }
  return 0;
}
