#include "rating.h"

#include <vector>
#include <cstdio>

int main() {
  int N, Q; 
  scanf("%d%d", &N, &Q);
  std::vector<int> P(N), A(N), B(N);
  std::vector<int> L(Q), R(Q);
  
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &P[i], &A[i], &B[i]);
  }
  
  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &L[i], &R[i]);
  }
  
  std::vector<long long> ratings = get_ratings(N, Q, P, A, B, L, R);  
  for (int i = 0; i < Q; i++) {
    printf("%lld\n", ratings[i]);
  }
  return 0;
}
