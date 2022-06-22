#include <iostream>
#include <vector>

#include "friends.h"

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; i++) {
    std::cin >> U[i] >> V[i] >> W[i];
  }
  std::vector<int> H(M);
  for (int i = 0; i < M; i++) {
    std::cin >> H[i];
  }
  std::cout << pairing_sum(U, V, W, H) << '\n';
  return 0;
}
