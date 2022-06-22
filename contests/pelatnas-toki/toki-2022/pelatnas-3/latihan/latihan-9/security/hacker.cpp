#include "hacker.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
int to_int(vector<int> a) {
  int res = 0;
  for(int i = 0; i < a.size(); ++i) {
    res = 2 * res + a[i];
  }
  return res;
}
std::vector<int> hacker(std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  int N = A.size();
  int M = B.size();
  // method: divide into 53 groups
  // each group size 3
  // do iteration of 3*3*53
  // for determine next, do iteration by max_size
  // so prev min is always increasing
  vector<int> loc[M];
  for(int i = M - 1; i >= 0; --i) {
    loc[B[i]].push_back(i);
  }
  vector<int> ret;
  int prev_min = -1;
  int dp[3][3], idx[3][3], pr[3][3];
  for(int i = 0; i < ceil(N / 3.0); ++i) {
    vector<int> tmp;
    for(int j = i * 12; j < i * 12 + 12; ++j) {
      tmp.push_back(C[j]);
    }
    int sz = to_int(tmp);
    if(!sz)
      continue;
    memset(dp, 0, sizeof(dp));
    memset(idx, -1, sizeof(idx));
    memset(pr, -1, sizeof(pr));
    for(int j = 0; j < sz; ++j) {
      int cur_min = M, val = -1;
      for(int k = i * 3; (k + i * 3 < N && k < i * 3 + 3); ++k) {
        int tmp;
        if(j == 0 || k == i * 3)
          tmp = prev_min;
        else
          tmp = dp[j - 1][k - i * 3 - 1];
        while(loc[A[k]].size() && loc[A[k]].back() <= tmp)
          loc[A[k]].pop_back();
        if(loc[A[k]].size()) {
          if(loc[A[k]].back() < cur_min)
            cur_min = loc[A[k]].back(), val = k - i * 3;
        }
        //cout << j << " " << k << " " << i * 3 + 3 << endl;
        dp[j][k - i * 3] = cur_min;
        idx[j][k - i * 3] = val;
        if(j != 0 && k != i * 3)
          pr[j][k - i * 3] = idx[j - 1][k - i * 3 - 1];
      }
    }
    int mini = M, sel = -1;
    cout << sel << endl;
    for(int k = 3 - 1; k >= 0; --k) {
      if(idx[sz - 1][k] != -1 && dp[sz - 1][k] <= mini) {
        mini = dp[sz - 1][k], sel = k;
        prev_min = dp[sz - 1][k];
      }
    }
    cout << sel << endl;
    tmp.clear();
    for(int j = sz - 1; j >= 0; --j) {
      tmp.push_back(A[sel + i * 3]);
      cout << j << " " << sel << " " << pr[j][sel] << endl;
      sel = pr[j][sel];
    }
    cout << "TEST" << endl;
    reverse(tmp.begin(), tmp.end());
    for(auto i : tmp)
      ret.push_back(i);
  }
  return ret;
}
