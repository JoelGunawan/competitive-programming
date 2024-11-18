#include "guess.h"

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

namespace {

void wrong_answer(string msg) {
  printf("Wrong Answer: ");
  puts(msg.c_str());
  exit(0);
}

const int QUERY_LIMIT = 2000;

int NA, NB, NC;
vector<int> A, B, C;

int Q;
int cnt_query = -1;
int max_query = 0;

}  // namespace

int ask(int a, int b, int c) {
  if (cnt_query == -1) wrong_answer("initialize() cannot call ask()");

  cnt_query += 1;
  if (cnt_query > QUERY_LIMIT) wrong_answer("over 2000 queries");
  if (0 <= a && a <= NA && 0 <= b && b <= NB && 0 <= c && c <= NC) {
    int valA = a == NA ? 1e8 : A[a];
    int valB = b == NB ? 2e8 : B[b];
    int valC = c == NC ? 3e8 : C[c];
    if (valA < valB && valA < valC) return 0;
    if (valB < valA && valB < valC) return 1;
    if (valC < valA && valC < valB) return 2;
    wrong_answer("arrays A, B, C did not satisfy constraint");
  } else {
    wrong_answer("a, b, c in ask() did not satisfy constraint");
  }
}

int main() {
  scanf("%d %d %d", &NA, &NB, &NC);

  A.resize(NA);
  B.resize(NB);
  C.resize(NC);
  std::vector<int> P(NA + NB + NC, -1);
  for (int i = 0; i < NA; i++) {
    scanf("%d", &A[i]);
    if (!(0 <= A[i] && A[i] < NA + NB + NC)) {
      wrong_answer("A[%d] did not satisfy constraint");
    }
    P[A[i]] = i;
    if (i > 0 && A[i - 1] > A[i]) {
      wrong_answer("array A is not sorted");
    }
  }
  for (int i = 0; i < NB; i++) {
    scanf("%d", &B[i]);
    if (!(0 <= B[i] && B[i] < NA + NB + NC)) {
      wrong_answer("B[%d] did not satisfy constraint");
    }
    P[B[i]] = NA + i;
    if (i > 0 && B[i - 1] > B[i]) {
      wrong_answer("array B is not sorted");
    }
  }
  for (int i = 0; i < NC; i++) {
    scanf("%d", &C[i]);
    if (!(0 <= C[i] && C[i] < NA + NB + NC)) {
      wrong_answer("C[%d] did not satisfy constraint");
    }
    P[C[i]] = NA + NB + i;
    if (i > 0 && C[i - 1] > C[i]) {
      wrong_answer("array C is not sorted");
    }
  }

  for (int i = 0; i < NA + NB + NC; i++) {
    if (P[i] == -1) {
      wrong_answer("arrays A, B, C did not satisfy constraint");
    }
  }

  initialize(NA, NB, NC);

  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int K;
    scanf("%d", &K);
    if (!(0 <= K && K < NA + NB + NC)) {
      wrong_answer("K did not satisfy constraint");
    }
    cnt_query = 0;
    if (guess(K) != P[K]) {
      wrong_answer("guess() is wrong");
    }
    max_query = max(max_query, cnt_query);
  }

  printf("Accepted: %d\n", max_query);
  return 0;
}
