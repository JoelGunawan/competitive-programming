#include <bits/stdc++.h>

#include "addition.h"
int mod = 998244353;
using namespace std;
struct node {
  int sum = 0, square_sum = 0, cur_res = 0;
  node *l, *r;
};
struct trie {
  node *head = new node();
};
int to_integer(string s) {
  int res = 0;
  for(int i = 0; i < s.size(); ++i) {
    res += (1ll << i) * (s[i] == '1');
  }
  return res;
}
int powmod(int a, int b) {
  int res = 1;
  for(int i = 0; i < b; ++i)
    res = (1ll * res * a) % mod;
  return res;
}
int power[300005];
int comp(string a, string b) {
  int res = 0;
  for(int i = 0; i < a.size(); ++i) {
    res += (1ll * power[i] * (a[i] != b[i])) % mod;
    if(res >= mod)
      res -= mod;
  }
  return res;
}
int count_addition(std::vector<std::string> S, int X) {
  power[0] = 1;
  for(int i = 1; i < 300005; ++i) {
    power[i] = ((long long)power[i - 1] << 1) % mod;
  }
  int N = S.size();
  int K = S[0].size();
  // do X <= 2 test case
  // use trie?
  // for x <= 2 
  // maintian a few states
  // sum of node, since we can merge the 2xy parts in O(1)/O(log)
  // sum of squares
  // sum of internal pairings
  // each n updates at most k
  // each update O(1)/O(log)
  // O(nklognk) ish? for x <= 2
  // 35 points :D
  // Maintain sum of squares, sum of internal pairing, sum of external pairing
  // have to do in some order, otherwise impossible to determine count
  int cnt[30];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < S.size(); ++i) {
    for(int j= 0; j < S[i].size(); ++j) {
      if(S[i][j] == '1')
        ++cnt[j];
    }
  }
  long long ret = 0;
  for(int i = 0; i < 30; ++i) {
    for(int j = i + 1; j < 30; ++j) {
      long long tmp = powmod(((power[i] * power[j]) % mod), X) * ((cnt[i] * cnt[j]) % mod);
      ret = (ret + tmp) % mod;
    }
  }
  return ret % mod;
} 