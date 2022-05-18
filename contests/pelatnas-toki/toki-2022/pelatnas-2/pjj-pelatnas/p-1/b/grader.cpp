#include "reverse.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
  std::cin >> N;
  /*
  for(int i = 1; i <= N; ++i)
    reverse_array(i);
  */
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