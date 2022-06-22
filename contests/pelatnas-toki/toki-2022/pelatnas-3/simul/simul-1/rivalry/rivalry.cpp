#include "rivalry.h"
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
std::vector<long long> find_final_scores(int N, std::vector<int> A, std::vector<int> B) {
  int M = A.size();
  set<pair<ll, pair<int, int>>> s;
  for(int i = 0; i < M; ++i)
    s.insert({A[i] + B[i], {i, 1}});
  vector<ll> ret(N);
  ll dp[N + 1], res = 00;
  memset(dp, 0, sizeof(dp));
  dp[2] = (*++s.begin()).first;
  for(int i = 1; i <= N; ++i) {
    res = max(res, (*s.begin()).first);
    int idx = (*s.begin()).second.first, cur_dp = (*s.begin()).second.second;
    if(i > 2)
      dp[i] = res;
    ret[i - 1] = res;
    s.insert({(*s.begin()).first + A[idx] + dp[cur_dp + 1] - dp[cur_dp], {idx, cur_dp + 1}});
    s.erase(s.begin());
  }
  ret[0] = 0;
  return ret;
}