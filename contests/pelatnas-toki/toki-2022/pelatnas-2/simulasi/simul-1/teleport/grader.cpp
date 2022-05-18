#include <stdio.h>

#include <string>
#include <vector>

#include "teleport.h"

namespace {

static const int MAX_N = 200;

static int N;
static int M;
static int X;
static int R;
static int D[MAX_N];
static int E[MAX_N][MAX_N];
static int teleporter_idx[MAX_N][MAX_N];

static int current_hub;
static int last_teleporter;
static int news_channel[MAX_N];

static long long call_use;

static void WA(std::string msg) {
  puts(("Wrong Answer: " + msg).c_str());
  exit(0);
}

static void AC(double L) {
  printf("Accepted: %.9f\n", L);
  exit(0);
}

}  // namespace

void use_teleporter(int x) {
  if (x < 0 || x >= D[current_hub]) {
    WA("teleporter does not exist");
  }
  call_use += 1;
  last_teleporter = teleporter_idx[E[current_hub][x]][current_hub];
  current_hub = E[current_hub][x];
}

void change_news_channel(int x) {
  if (x < 0 || x >= X) {
    WA("news channel does not exist");
  }
  news_channel[current_hub] = x;
}

int ask_news_channel() {
  return news_channel[current_hub];
}

int ask_count_teleporters() {
  return D[current_hub];
}

int ask_last_teleporter() {
  return last_teleporter;
}

int main() {
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", &D[i]);
    for (int j = 0; j < N; j++) {
      teleporter_idx[i][j] = -1;
    }
    for (int j = 0; j < D[i]; j++) {
      scanf("%d", &E[i][j]);
      teleporter_idx[i][E[i][j]] = j;
      M += 1;
    }
  }

  for (int i = 0; i < N; ++i) {
    news_channel[i] = 0;
  }

  call_use = 0;
  current_hub = 0;
  last_teleporter = -1;

  std::vector<int> ans = explore(N, X);
  if (ans.size() != N) {
    WA("explore() returns array not of size N");
  }

  for (int i = 0; i < N; i++) {
    printf("%d", ans[i]);
    if (i + 1 == N) {
      printf("\n");
    } else {
      printf(" ");
    }
  }

  AC(2.0 * call_use / M);
  return 0;
}
