#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7; // 998244353 atau 1e9 + 9
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b / 2);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
int main() {
  string s;
  cin >> s;
  // counting array untuk kemunculan karakter
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  for(auto x : s) {
    ++cnt[x - 'a'];
  }
  int n = s.size();
  ll fact[n + 5];
  fact[0] = 1;
  for(int i = 1; i <= n; ++i)
    fact[i] = (fact[i - 1] * i) % mod;
  ll res = fact[n];
  for(int i = 0; i < 26; ++i) {
    res = mul(res, powmod(fact[cnt[i]], mod - 2));
  }
  cout << res << endl;
}