#include "spy.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> to_binary(int x) {
  if(x <= 1) {
    return {x & 1};
  }
  else {
    vector<int> res = to_binary(x / 2);
    res.push_back(x & 1);
    return res;
  }
}
std::vector<int> spy(std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  int N = A.size();
  int M = B.size();
  // divide N into groups of size 3
  vector<int> groups;
  int last = 0;
  // tiap grup isi 3 buat jadi group sendiri
  int idx = 0;
  for(int i = 0; i < ceil(N / 3.0); ++i) {
    int cur = 0;
    for(int j = 0; j + i * 3 < N && j < 3; ++j) {
      if(idx < C.size() && A[i * 3 + j] == C[idx]) {
        ++idx, ++cur;
      }
    }
    groups.push_back(cur);
  }
  // for each group, gabungkan ke res vektor
  vector<int> ret;
  for(auto i : groups) {
    vector<int> tmp = to_binary(i);
    while(tmp.size() < 12)
      tmp.insert(tmp.begin(), 0);
    for(auto j : tmp)
      ret.push_back(j);
  }
  return ret;
}
