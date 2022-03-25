#include "client.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
int to_integer(string s) {
  int tmp = 1;
  int res = 0;
  for(int i = s.size() - 1; i >= 0; --i) {
    if(s[i] == '1')
      res += tmp;
    tmp *= 2;
  }
  return res;
}
int client(int N, std::vector<int> A, std::vector<int> B, int W) {
  int start = 9 * W;
  string res = "";
  for(int i = start; i < start + 9; ++i) {
    res += to_string(get_bit(i));
  }
  return to_integer(res);
  /*
  int size[N + 1];
  size[0] = 0;
  int sum = 0, m = 0;
  for(int i = 1; i < N; ++i) {
    size[i] = 1;
    for(int j = 0; j < 10; ++j) {
      if(i % (1 << j) == 0)
        size[i] = j + 1;
    }
    sum += size[i];
    m = max(m, size[i]);
  }
  for(int j = 0; j < 10; ++j) {
    if((1 << j) & N)
      size[N] = j + 1;
  }
  sum += size[N];
  int pref[N], nxt[N];
  pref[0] = 0;
  nxt[N] = 0;
  for(int i = 1; i < N; ++i)
    pref[i] = pref[i - 1] + size[i];
  for(int i = 1; i < N; ++i) {
    //cout << pref[i] << " ";
    int cnt = 0, tmp = 0, inverse = 0;
    for(int j = 0; j <= m; ++j) {
           if(i & (1 << j))
            tmp += j + 1;
          else
            inverse += j + 1;
    }
    inverse += size[i];
    if(tmp >= inverse) {
      // pergi ke bawah instead
      nxt[i] = min(N, i + (1 << (size[i] - 1)));
    }
    else
      nxt[i] = i - (1 << (size[i] - 1));
  }
  int res = 0;
  while(W > 0) {
    int start = pref[W - 1], cur_size = size[W];
    string tmp = "";
    for(int i = start; i < start + cur_size; ++i)
      tmp += to_string(get_bit(i));
    if(nxt[W] > W)
      res -= to_integer(tmp);
    else
      res += to_integer(tmp);
    //cout << res << " " << tmp << " " << W << " " << nxt[W] << endl;
    // reduce W by least significant bit
    W = nxt[W];
  }
  return res;
  */
}
