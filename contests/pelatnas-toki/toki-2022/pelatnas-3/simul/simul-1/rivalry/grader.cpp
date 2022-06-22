#include <iostream>
#include <vector>

#include "rivalry.h"

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    std::cin >> A[i] >> B[i];
  }
  std::vector<long long> S = find_final_scores(N, A, B);
  for (int i = 0; i < N; i++) {
    std::cout << S[i] << '\n';
  }
  return 0;
}
