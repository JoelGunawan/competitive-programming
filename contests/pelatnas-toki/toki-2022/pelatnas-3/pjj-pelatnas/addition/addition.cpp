#include "addition.h"

#include <string>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll fact[200005];
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b / 2);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mulmod(ll a, ll b) {
  return (a * b) % mod;
}
ll submod(ll a, ll b) {
  return (((a - b) % mod) + mod) % mod;
}
ll addmod(ll a, ll b) {
  return (a + b) % mod;
}
ll combinmod(ll a, ll b) {
  return mulmod(fact[a], mulmod(powmod(fact[b], mod - 2), powmod(fact[a - b], mod - 2)));
}
int count_arrangements(std::string A, std::string B, std::string C) {
  int n = A.size();
  fact[0] = 1;
  for(int i = 1; i <= n; ++i)
    fact[i] = (fact[i - 1] * i) % mod;
  int cnt[2][4];
  // indeks 0 -> leading zero
  // indeks 1 -> bukan leading zero
  // 0 -> ga give ga acc
  // 1 -> give only
  // 2 -> acc only
  // 3 -> give and acc
  bool valid = 1;
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; ++i) {
    // find masuk kategori apa
    // buat digit 0 ntar buat exception case sendiri
    // (hitung permutation buat semua konfigurasi yang ada 0 di depan)
    int a = A[i] - '0', b = B[i] - '0', c = C[i] - '0';
    if((a + b) % 10 == c) {
      if(a == 0 || b == 0 || c == 0) {
        if(a + b >= 10)
          ++cnt[0][1];
        else
          ++cnt[0][0];
      } 
      else {
        if(a + b >= 10)
          ++cnt[1][1];
        else
          ++cnt[1][0];
      }      
    }
    else if((a + b + 1) % 10 == c) {
      // pasti accept
      if(a == 0 || b == 0 || c == 0) {
        // give
        if(a + b + 1 >= 10) {
          ++cnt[0][3];
        }
        else
          ++cnt[0][2];
      }
      else {
        if(a + b + 1 >= 10) {
          ++cnt[1][3];
        }
        else
          ++cnt[1][2];
      }
    }
    else
      valid = 0;
  }
  if(!valid)
    return 0;
  int tmp1 = cnt[0][1] + cnt[1][1], tmp2 = cnt[0][2] + cnt[1][2], tmp3 = cnt[0][3] + cnt[1][3];
  //cout << tmp1 << " " << tmp2 << endl;
  if(tmp1 != tmp2 || (tmp3 > 0 && tmp1 == 0)) {
    return 0;
  }
  ll dalam;
  // lupa kalikan pemasangan yang mungkin antara 2 give dan acc
  // jika kita give urutan tetap, maka ada n * n - 1 * n - 2 * ... * 1 pemasangan yang mungkin -> permutasi
  if(tmp1 > 0) {
    dalam = mulmod(fact[tmp1], mulmod(combinmod(tmp1 + tmp3 - 1, tmp1 - 1), fact[tmp3]));
  }
  else
    dalam = 1;
  //cout << dalam << endl;
  // handle case leading zero
  // kita gaboleh jadikan leading zero di depan
  // jadi kita cari cara yang kita anchor leading zero di depan
  int tmp4 = cnt[0][2] + cnt[0][0]; // berpotensi leading zero
  //cout << tmp4 << " " << cnt[0][0] + cnt[1][0] + tmp1 << endl;
  return submod(mulmod(dalam, fact[cnt[0][0] + cnt[1][0] + tmp1]), mulmod(dalam, mulmod(tmp4, fact[cnt[0][0] + cnt[1][0] + tmp1 - 1])));
}
