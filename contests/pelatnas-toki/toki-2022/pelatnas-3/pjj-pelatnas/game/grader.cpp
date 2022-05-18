#include <stdio.h>

#include <algorithm>
#include <string>
#include <vector>

#include "game.h"

namespace {

static const int NMAX = 10000;
static const int AMAX = 1 << 30;

static const int L = 20000;

static int N;
static std::vector<int> X;

static int ask_count;

static void WA(std::string msg) {
  puts(("Wrong Answer: " + msg).c_str());
  exit(0);
}

static void AC() {
  puts("Accepted");
  exit(0);
}

}  // namespace

int ask_minimum_xor(int x) {
  ask_count += 1;
  if (ask_count > L) {
    WA("you asked Pak Dengklek more than L times");
  }
  if (x < 0 || x >= AMAX) {
    WA("x in ask_minimum_xor(x) does not satisfy constraints");
  }
  int ret = AMAX;
  for (int i = 0; i < N; i++) {
    ret = std::min(ret, X[i] ^ x);
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  X.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }
  std::vector<int> Y = play_game(N);
  std::sort(X.begin(), X.end());
  std::sort(Y.begin(), Y.end());
  if (X != Y) {
    WA("you guessed X incorrectly");
  }
  AC();
  return 0;
}
