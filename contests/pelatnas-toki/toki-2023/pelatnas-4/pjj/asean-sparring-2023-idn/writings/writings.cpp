#include "writings.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 998244353;
const int lim = 2e5 + 5;
vector<int> child[lim];
int depth[lim];
void dfs(int nd) {
  for(auto i : child[nd])
    depth[i] = depth[nd] + 1, dfs(i);
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll fact[lim], inv[lim];
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[b], inv[a - b]));
}
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
int count_writings(int N, int K, std::vector<int> P, std::vector<int> A) {
  // k = 1 -> cari urutan depth aja
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i)
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  if(A[0] != 0) {
    return 0;
  }
  // simpan semua index a_i yg ada inversion, di index itu harus pisah
  // nnti jadi segments
  // tiap segment harus dipisah, di dalam segment bs dipisah tp optional
  // cek count of segments
  int cnt = 0;
  vector<int> v;
  for(int i = 1; i < N; ++i) {
    if(i != 1 && A[i] < A[i - 1]) {
      // berarti ada inversion
      v.push_back(cnt);
      cnt = 0;
    }
    ++cnt;
  }
  v.push_back(cnt);
  // buat cri jumlah kombin, tinggal pakai a_1 + a_2 + ... + a_k = c
  K -= v.size() - 1;
  if(K < 0)
    return 0;
  ll dp[v.size()][K + 1];
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i < v.size(); ++i) {
    if(i == 0) {
      for(int j = 0; j <= K; ++j) {
        // divide into j + 1 groups
        // sum harus jadi v[i]
        // v[i] + j, j
        // bukan v[i] -= j + 
        if(v[i] >= j + 1)
          dp[i][j] = combinmod(v[i] - 1, j);
      }
    }
    else {
      for(int j = 0; j <= K; ++j) {
        for(int k = 0; k <= j; ++k) {
          if(v[i] >= k + 1)
            dp[i][j] = (dp[i][j] + mul(dp[i - 1][j - k], combinmod(v[i] - 1, k))) % mod;
        }
      }
    }
  }
  // misal v[i] = 5, k = 4
  // harusnya C(4, 4)
  // misal v[i] = 6, k = 4
  // harusnya C(5, 4)
  ll ret = 0;
  for(int i = 0; i <= K; ++i)
    ret += dp[v.size() - 1][i], ret %= mod;
  return ret % mod;
  /*
  vector<int> a[N + 1];
  for(int i = 1; i < N; ++i) {
    //cout << depth[A[i]] << " " << depth[A[i - 1]] << endl;
    if(depth[A[i]] < depth[A[i - 1]]) { 
      return 0;
    }
  } 
  for(int i = 0; i < N; ++i) {
    a[depth[A[i]]].push_back(A[i]);
  }
  for(int i = 0; i < N; ++i) {
    for(int j = 1; j < a[i].size(); ++j) {
      if(a[i][j] < a[i][j - 1])
        return 0;
    }
  }
  */
  // sub 2: 
  // p[i] = 0 -> buat supaya nnti gaboleh ada inversion di segment yg dipilih, otherwise dp[n][k] normal
  // dp[n][k] = dp[n - i][k - 1] if i+1...n there are no inversions (i.e. a_i > a_j, i < j)
  // sub 3:
  // N - 2 different values: line graph except for 1 element?
  // sub 4: 
  // it is probably possible to do this using 
  // yg di kanan lexico harus >=
  // kalo = berarti value harus lebih besar
}
