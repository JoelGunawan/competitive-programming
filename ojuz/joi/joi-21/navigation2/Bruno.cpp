#include "Bruno.h"
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

namespace {

int variable_example = 1;

} // namespace

std::vector<int> Bruno(int K, std::vector<int> value) {
  variable_example += 1;
  int nxt[22];
  for(int i = 0; i < 7; ++i) {
    nxt[i * 3 + 1] = i * 3 + 2;
    nxt[i * 3 + 2] = i * 3 + 3;
    nxt[i * 3 + 3] = i * 3 + 1;
  }
  int pr[22];
  for(int i = 1; i <= 21; ++i) {
    pr[nxt[i]] = i;
  }
  std::vector<int> res(K, 0);
  for (int i = 0; i < K; i++) {
    res[i] = (value[i] % 5);
  }
  return res;
}
