#include "challenge.h"
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int fact[5001], mod = 1e9 + 7;
int dp[1001][5001];
int dp1[1001][5001];
int maximum;
vector<int> b;
int solve1(int number, int index) {
  if(index == b.size() - 1)
    return number % b[index];
  else if(dp1[index][number] == -1) {
    // try to solve
    // we can choose to skip this index or not skip this index basically?
    dp1[index][number] = max(solve1(number % b[index], index + 1), solve1(number, index + 1));
  }  
  return dp1[index][number];
}
int solve(int number, int index) {
  // skipped is important as we need to multiply the result by fact[skipped]
  // but we need to precalc the amount of ways in a lower index, so that we can later do queries easily
  // we need to do O(n^2*maxA)
  // choose to skip or not skip current index
  // if we choose to skip, should we maintain "skipped" or no?
  // we should?
  // fi is value, se is counter
  // leverage solve1
  // since solve1 can be O(1) basically
  // since we know number will be <= maxA
  if(index == b.size() - 1)
    return 1;
  else if(dp[index][number] == -1) {
    dp[index][number] = 0;
    for(int i = index + 1; i < b.size(); ++i) {
      if(solve1(number % b[i], i) == maximum) {
        dp[index][number] = (dp[index][number] + (1ll * solve(number % b[i], i) * fact[i - index - 1]) % mod) % mod;
      }
    }
  }
  return dp[index][number];
}
void initialize(int N, std::vector<int> A) {
  // anggep Ai max 5000 terus
  // kita buat array 5000 yang bakal kita pake buat query
  // udah solve T[i] = 1
  // buat T[i] = 0? -> pake DP yang cuman boolean, buat DP ini bisa transisi O(n*maxA)
  // pakai DP beda lagi buat cari maximum?
  memset(dp, -1, sizeof(dp));
  memset(dp1, -1, sizeof(dp1));
  fact[0] = 1;
  for(int i = 1; i <= 5000; ++i) {
    fact[i] = (1ll * fact[i - 1] * i) % mod;
  }
  b = A;
  sort(b.begin(), b.end(), greater<int>());
}

int solve_challenge(int x, int t) {
  maximum = solve1(x, 0);
  if(t == 0) {
    int res = solve1(x, 0);
    return res;
  }
  else {
    // this should be solve able in O(n) as well?
    // banyak cara untuk membuat hasil yg ada di atas
    // cara untuk ngecek banyak cara gmn?
    int res = 0;
    for(int i = 0; i < b.size(); ++i)
      if(solve1(x % b[i], i) == maximum) {
        int tmp = (1ll * solve(x % b[i], i)) % mod;
        if(i != 0)
          tmp = (1ll * tmp * fact[i]) % mod;
        cout << tmp << " ";
        res = (res + tmp) % mod;
      }
    cout << endl;
    return res;
  }
  return -1;
}
