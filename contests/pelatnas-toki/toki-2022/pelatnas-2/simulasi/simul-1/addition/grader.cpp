#include <iostream>
#include <string>

#include "addition.h"

int main() {
  std::string A, B, C;
  std::cin >> A >> B >> C;
  std::cout << count_arrangements(A, B, C) << '\n';
  return 0;
}
