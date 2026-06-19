#include "country.h"

#include <cassert>
#include <cstdio>
#include <vector>

int main() {
  int N,T;
  assert(1 == scanf("%d",&T));
  assert(1 == scanf("%d",&N));
  std::vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &C[i]));
    C[i]--;
  }

  long long ans1 = 0;
  if(T <= 6 || !T)ans1 = count_same_country(N,C);
  long long ans2 = 0;
  if(T>6 || !T)ans2 = count_diff_country(N,C);
  printf("%lld %lld\n", ans1,ans2);
  return 0;
}