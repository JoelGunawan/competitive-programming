#include "knapsack.h"

#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long find_maximum(int N, long long T, std::vector<int> W, std::vector<int> V) {
  // nyampah -> buat transisi, tp manual
  // buat size 2000, nnti klo misal yg T kecil tp W besar, tinggal completely ignore W besar
  ll dp[2][2000];
  memset(dp, -1, sizeof(dp));
  // max nya cmn 2000
  ll curw = 0, curv = 0;
  ll res = 0;
  for(int i = 0; i < N; ++i) {
    // di luar ini ttp ada
    ll lim = T - curw;
    lim = min(lim, 1999ll);
    int cur = i & 1, pr = cur ^ 1;
    for(int j = 0; j < 2000; ++j)
      dp[cur][j] = -1;
    for(int j = 0; j < 2000; ++j) {
      if(j >= W[i]) {
        if(dp[pr][j] != -1)
          dp[cur][j - W[i]] = max(dp[cur][j - W[i]], dp[pr][j] + V[i]);
      }
      else {
        if(dp[pr][j] != -1)
          dp[cur][j] = max(dp[cur][j], dp[pr][j]);
      }
    }
    for(int j = 0; j <= min((ll)W[i] - 1, lim); ++j) {
      dp[cur][j] = max(dp[cur][j], curv);
    }
    for(int j = 0; j < 2000; ++j)
      res = max(res, dp[cur][j]);
    //for(int j = 1; j <= 20; ++j)
    //  cout << dp[cur][j] << " ";
    //cout << endl;
    if(curw + W[i] <= T) {
      curw += W[i], curv += V[i];
    }
    //cout << curv << endl;
    res = max(res, curv);
  }
  return res;
}
