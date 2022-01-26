#include "sum.h"

#include <stdio.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  printf("%lld\n", getSum(N, A));
  return 0;
}
