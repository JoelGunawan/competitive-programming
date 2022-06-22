#include <iostream>
#include <vector>

#include "fighters.h"

namespace {

static int N;
static int M;
static std::vector<int> A;
static std::vector<int> B;

static std::vector<std::vector<int>> operations;

static int call_count = 0;

static void WA(std::string msg) {
  std::cout << "Wrong Answer: " << msg << '\n';
  exit(0);
}

}

void fight(std::vector<int> P) {
  call_count++;
  if (call_count > (N - 1) / (M - 1)) {
    WA("fight is called too many times");
  }
  if (P.size() != M) {
    WA("fight is called with a parameter of the wrong size");
  }
  operations.push_back(P);
}

int main() {
  std::cin >> N >> M;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }
  B.resize(M);
  for (int i = 0; i < M; i++) {
    std::cin >> B[i];
  }
  std::cout << minimum_strength(A, B) << '\n';
  if (call_count != (N - 1) / (M - 1)) {
    WA("fight is called the wrong number of times");
  }
  for (int i = 0; i < call_count; i++) {
    for (int j = 0; j < M; j++) {
      if (j) std::cout << ' ';
      std::cout << operations[i][j];
    }
    std::cout << '\n';
  }
  return 0;
}
