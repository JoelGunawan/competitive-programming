#include "country.h"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

int main() {
  int N;
  assert(1 == scanf("%d", &N));
  
  char X[20];
  assert(1 == scanf("%19s", X));
  
  char same[] = "same";
  char diff[] = "diff";
  
  assert(std::strcmp(X, same) == 0 || std::strcmp(X, diff) == 0);
  
  std::vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &C[i]));
  }
  
  long long ans;
  if (std::strcmp(X, same) == 0) {
    ans = count_same_country(N, C);
  } else {
    ans = count_diff_country(N, C);
  }
  
  printf("%lld\n", ans);
  return 0;
}
