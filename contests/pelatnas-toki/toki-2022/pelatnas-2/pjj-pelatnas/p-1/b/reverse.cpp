#include "reverse.h"
#include <vector>
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
std::vector<std::vector<int>> reverse_array(int N) {
  vector<vector<int>> operations;
  if(N == 1)
    return vector<vector<int>>(0);
  if(N == 2)
    return {{2, 2, 0}};
  operations.pb({N / 2 + N % 2, N - 1, 0});
  int l = N / 2, r = N;
  while(l > 1) {
    operations.pb({l, l + 1, r});
    --l, --r;
  }
  if(N & 1) {
    operations.pb({l, l + 1, r});
  }
  else {
    operations.pb({l, l, r});
  }
  /*
  int a[N + 1], cur[N + 1];
  for(int i = 0; i <= N; ++i)
    a[i] = i;
  cur[0] = 0;
  for(auto ops : operations) {
    int idx = 1;
    for(int i = 1; i <= ops[2]; ++i) {
      if(i < ops[0] || i > ops[1])
        cur[idx++] = a[i];
    }
    for(int i = ops[0]; i <= ops[1]; ++i)
      cur[idx++] = a[i];
    for(int i = ops[2] + 1; i <= N; ++i) {
      if(i < ops[0] || i > ops[1])
        cur[idx++] = a[i];
    }
    for(int i = 0; i <= N; ++i)
      a[i] = cur[i];
  }
  ofstream fout;
  fout.open("output.txt",  ios_base::app);
  bool ans = 1;
  for(int i = 1; i <= N; ++i)
    if(a[i] != N - i + 1)
      ans = 0;
  if(ans)
    fout << "CORRECT" << endl;
  else
    fout << "FALSE" << endl;
  */
  return operations;
}