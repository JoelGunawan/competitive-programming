#include <iostream>
#include <vector>
#include <string>

#include "addition.h"

int main() {
  int N, K, X;
  std::cin >> N >> K >> X;
  std::vector<std::string> S(N);
  for (int i = 0; i < N; i++) {
    std::cin >> S[i];
  }
  int ans = count_addition(S, X);
  std::cout << ans << "\n";
  return 0;
}
