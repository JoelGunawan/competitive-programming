#include "chanek.h"
#include "dengklek.h"

#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

static const int MAX_MOVE = 20000;

static int N, M, P, T;
static long long X;
static std::vector<int> A, B;

static std::vector<int> hints;
static std::vector<std::set<int>> adjList;
static int moveCount = 0;
static int currentPos;

static void wa() {
  puts("WA");
  exit(0);
}

void writeMessage(int P, int V) {
  if (P < 0 || P >= N) wa();
  if (V < 0 || V > 1) wa();
  if (hints[P] != -1) wa();

  hints[P] = V;
}

int move(int D) {
  if (!adjList[currentPos].count(D)) wa();
  moveCount += 1;

  if (moveCount > MAX_MOVE) {
    wa();
  }

  currentPos = D;
  return hints[D];
}

int main() {
  scanf("%d %d %lld %d %d", &N, &M, &X, &P, &T);

  A.resize(M);
  B.resize(M);
  adjList.resize(N);

  for (int i = 0 ; i < M ; i++) {
    scanf("%d %d", &A[i], &B[i]);

    adjList[A[i]].insert(B[i]);
    adjList[B[i]].insert(A[i]);
  }

  hints.resize(N, -1);
  giveHint(N, M, A, B, X, T);

  bool allHinted = all_of(hints.begin(), hints.end(), [](int x) {
    return x != -1;
  });
  if (!allHinted) {
    wa();
  }

  currentPos = P;

  long long ans = findNumber(N, M, A, B, P, hints[P], T);
  
  printf("%lld\n", ans);
  printf("%d\n", moveCount);

  return 0;
}
