// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// pragma
// macros
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
using namespace __gnu_pbds;
int mod = 998244353;
// dynamic fenwick
struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};
const int lim = 2e6 + 10;
gp_hash_table<ll, int, chash> a;
struct fenwick {
  int num;
  void update(int idx, int val) {
    idx += 1e6 + 5;
    while(idx < lim) {
      a[1ll * num * (ll)(2e6 + 10) + idx] += val;
      if(a[1ll * num * (ll)(2e6 + 10) + idx] >= mod)
        a[1ll * num * (ll)(2e6 + 10) + idx] -= mod;
      else if(a[1ll * num * (ll)(2e6 + 10) + idx] <= -mod)
        a[1ll * num * (ll)(2e6 + 10) + idx] += mod;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    idx += 1e6 + 5;
    int ret = 0;
    while(idx > 0) {
      if(a.find(1ll * num * (ll)(2e6 + 10) + idx) != a.end())
        ret += a[1ll * num * (ll)(2e6 + 10) + idx];
      if(ret >= mod)
        ret -= mod;
      else if(ret <= -mod)
        ret += mod;
      idx -= idx&-idx;
    }
    return ret;
  }
  int query(int l, int r) {
    if(l > r)
      return 0;
    return query(r) - query(l - 1);
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  int pref[n + 1][3];
  memset(pref, 0, sizeof(pref));
  char arr[] = {'I', 'C', 'P'};
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 3; ++j) {
      pref[i][j] = pref[i - 1][j];
      if(s[i] == arr[j])
        ++pref[i][j];
    }
  }
  s.clear();
  int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  gp_hash_table<int, int, chash> pr[3][3];
  pr[0][1][0] = 1;
  pr[0][2][0] = 2;
  pr[1][2][0] = 3;
  int last = 3;
  fenwick bit[n + 5];
  for(int i = 0; i < n + 5; ++i)
    bit[i].num = i;
  bit[1].update(0, 1);
  bit[2].update(0, 1);
  bit[3].update(0, 1);
  // map of pr indicates the previous ones
  // for every difference, memo the indices and do the transitions like that, reset the bit
  // can not do (because it affects each other)
  for(int i = 1; i <= n; ++i) {
    dp[i] = (dp[i] + (ll)bit[pr[0][1][pref[i][1] - pref[i][0]]].query(-1e6, pref[i][2] - pref[i][0] - 1) + bit[pr[0][2][pref[i][2] - pref[i][0]]].query(-1e6, pref[i][1] - pref[i][0] - 1) + bit[pr[1][2][pref[i][2] - pref[i][1]]].query(-1e6, pref[i][0] - pref[i][2] - 1)) % mod;
    if(pr[0][1][pref[i][1] - pref[i][0]] == 0)
      pr[0][1][pref[i][1] - pref[i][0]] = ++last;
    if(pr[0][2][pref[i][2] - pref[i][0]] == 0)
      pr[0][2][pref[i][2] - pref[i][0]] = ++last;
    if(pr[1][2][pref[i][2] - pref[i][1]] == 0)
      pr[1][2][pref[i][2] - pref[i][1]] = ++last;
    bit[pr[0][1][pref[i][1] - pref[i][0]]].update(pref[i][2] - pref[i][0], dp[i]);
    bit[pr[0][2][pref[i][2] - pref[i][0]]].update(pref[i][1] - pref[i][0], dp[i]);
    bit[pr[1][2][pref[i][2] - pref[i][1]]].update(pref[i][0] - pref[i][2], dp[i]);
    // cout << dp[i] << " ";
  }
  if(dp[n] < 0)
    dp[n] += mod;
  cout << dp[n] << endl;
}