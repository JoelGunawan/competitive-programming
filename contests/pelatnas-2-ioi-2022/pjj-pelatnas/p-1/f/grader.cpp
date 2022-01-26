#include "art.h"
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  
  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::vector<int> ans = calculate_steps(N, A);
  for (int i = 0; i < ans.size(); i++) {
    if (i != 0) std::cout << " ";
    std::cout << ans[i];
  }
  std::cout << "\n";
}
