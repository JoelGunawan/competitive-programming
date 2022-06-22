#include <iostream>
#include <string>
#include <vector>

#include "hacker.h"
#include "spy.h"

namespace {

void WA(std::string msg) {
  puts(("Wrong Answer: " + msg).c_str());
  exit(0);
}

void AC(int q) {
  puts(("Accepted: " + std::to_string(q)).c_str());
  exit(0);
}

bool isSubsequence(std::vector<int> X, std::vector<int> Y) {
  int p = 0;
  for (auto x : X) {
    if (p < (int)Y.size() && Y[p] == x) {
      p += 1;
    }
  }
  return p == (int)Y.size();
}

bool isBitString(std::vector<int> X) {
  for (int x : X) {
    if (x != 0 && x != 1) {
      return false;
    }
  }
  return true;
}

}  // namespace

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(N), B(M);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    std::cin >> B[i];
  }
  int K;
  std::cin >> K;
  std::vector<int> C(K);
  for (int i = 0; i < K; i++) {
    std::cin >> C[i];
  }
  std::vector<int> L = spy(A, B, C);
  if (L.size() > 1000000) {
    WA("L is too long");
  }
  if (!isBitString(L)) {
    WA("L consists of elements other than 0 or 1");
  }
  std::vector<int> D = hacker(A, B, L);
  if (!isSubsequence(A, D)) {
    WA("D is not a subsequence of A");
  }
  if (!isSubsequence(B, D)) {
    WA("D is not a subsequence of B");
  }
  if (D.size() < C.size()) {
    WA("D has length shorter than C");
  }
  AC(L.size());
  return 0;
}
