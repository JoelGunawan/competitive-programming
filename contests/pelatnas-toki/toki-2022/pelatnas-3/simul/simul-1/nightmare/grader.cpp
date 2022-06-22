#include <iostream>
#include <vector>

#include "nightmare.h"

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }
  std::cout << count_sequences(A) << '\n';
  return 0;
}
