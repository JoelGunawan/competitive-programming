#include "reverse.h"
#include <iostream>
#include <vector>

int N;

int main() {
  std::cin >> N;
  std::vector<std::vector<int>> operations = reverse_array(N);
  std::cout << operations.size() << "\n";
  for (std::vector<int> operation : operations) {
    for (int i = 0; i < operation.size(); i++) {
      if (i != 0) std::cout << " ";
      std::cout << operation[i];
    }
    std::cout << "\n";
  }
}