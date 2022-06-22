#include <iostream>
#include <string>
#include <vector>

#include "species.h"

int main() {
  int N;
  std::cin >> N;
  std::string G;
  std::cin >> G;
  std::vector<int> P(N);
  for (int i = 0; i < N; i++) {
    std::cin >> P[i];
  }
  init(G, P);
  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; i++) {
    int S, T;
    std::cin >> S >> T;
    std::cout << count_species(S, T) << '\n';
  }
  return 0;
}
