#include "art.h"
#include <bits/stdc++.h>
using namespace std;
int dp[5005][2505][2], height[5005];
std::vector<int> calculate_steps(int N, std::vector<int> A) {
  // represent DP as minimal amount of reductions
  // choose dp[i - 1][j - 2], dp[i - 2][j - 4], ... atau dp[i][j - 1]
  for(int i = 0; i < 5005; ++i)
    for(int j = 0; j < 2505; ++j)
      dp[i][j][0] = 1e9, dp[i][j][1] = 1e9;
  for(int i = 0; i < 5005; ++i)
    dp[i][0][0] = 0;
  vector<int> a(N + 2, 0);
  for(int i = 1; i <= N; ++i)
    a[i] = A[i - 1];
  // use prefix sums of sorts
  // since the k is the same for each i
  // we don't need to recalc every j
  for(int i = 2; i <= N + 1; ++i) {
    height[i] = min(a[i], a[i - 1] - 1);
    for(int j = 1; j <= i / 2 + i % 2; ++j) {
      // inactive transition
      dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);      
      int prev = height[i - 2], cur_cost = 0;
      if(a[i] >= a[i - 1])
        cur_cost += a[i] - a[i - 1] + 1;
      if(prev >= a[i - 1])
        cur_cost += prev - a[i - 1] + 1;
      // from active transition
      dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + cur_cost);
      // from inactive transition
      dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][0] + max(a[i] - a[i - 1] + 1, 0) + max(a[i - 2] - a[i - 1] + 1, 0));
      /*
      for(int k = i - 1; k > 0 && j - (i - k) / 2 - 1 >= 0; k -= 2) {
        // we need to reduce both left and right
        // check if we need to reduce from prev
        // bagian sini
        if(prev >= a[k]) {
          cur_cost += prev - (a[k] - 1);
        }  
        prev = a[k - 1];
        // reduce the left stack
        if(a[k - 1] >= a[k]) {
          cur_cost += a[k - 1] - (a[k] - 1);
          prev = a[k] - 1;
        }
        // sampai sini bisa di precalc
        // bagian ini susah :sob:
        // pake prefix?
        // atau pake DS :kekw:
        dp[i][j] = min(dp[i][j], dp[k - 1][j - (i - k) / 2 - 1] + cur_cost);
      }
      */
    }
  }
  vector<int> ans(N / 2 + N % 2);
  for(int i = 0; i < N / 2 + N % 2; ++i)
    ans[i] = min(dp[N + 1][i + 1][0], dp[N + 1][i + 1][1]);
  return ans;
}
