#include "buffet.h"

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
long long min_leftover(int N, std::vector<int> A) {
  ll ret = 0;
  for(auto x : A) {
    ret += max(x - A[0] - A[N - 1], 0);
  }
  return ret;
}
