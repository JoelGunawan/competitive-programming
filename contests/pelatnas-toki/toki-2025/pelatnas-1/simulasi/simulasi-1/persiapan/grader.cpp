#include "persiapan.h"

#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> X(N);
  for (int i = 0; i < N; i++) {
    std::cin >> X[i];
  }

  std::vector<int> Y = persiapan(N, X);
  for (auto y : Y) {
    std::cout << y << " ";
  }
  std::cout << std::endl;

  return 0;
}
