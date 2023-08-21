#include "bruno.h"
#include <bits/stdc++.h>
using namespace std;

long long Bruno( int N, int A[] ){
  //cout << "START BRUNO" << endl;
  long long ret = 0;
  vector<int> v;
  int idx = 0;
  while(idx < N && v.size() < 60) {
    while(idx < N && A[idx] != 1)
      ++idx;
    if(idx == N - 1)
      return 0;
    v.push_back(A[idx + 1]);
    idx += 2;
  }
  for(int i = 0; i < v.size(); ++i) {
    //cout << i << " " << v[i] << endl;
    //cout << v[i] << endl;
    ret += (0ll + v[i]) << i;
  }
  //cout << "BRUNO ONCE" << endl;
  //cout << ret << endl;
  return ret;
}
