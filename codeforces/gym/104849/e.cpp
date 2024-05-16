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
const int lim = 1e6 + 5;
struct fenwick {
  vector<pair<int, int>> points;
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    while(idx < lim) {
      a[idx] += val;
      if(a[idx] >= mod)
        a[idx] -= mod;
      else if(a[idx] <= -mod)
        a[idx] += mod;
      idx += idx&-idx;
    }
  }
  void update(pair<int, int> a, int val) {
    int idx = lb(points.begin(), points.end(), a) - points.begin();
    update(idx + 1, val);
  }
  int query(int idx) {
    int ret = 0;
    while(idx > 0) {
      ret += a[idx];
      if(ret >= mod)
        ret -= mod;
      else if(ret <= -mod)
        ret += mod;
      idx -= idx&-idx;
    }
    return ret;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
  int query(int x, int d, int u) {
    // for given x
    int idxr = ub(points.begin(), points.end(), mp(x, u)) - points.begin() - 1;
    int idxl = lb(points.begin(), points.end(), mp(x, d)) - points.begin();
    ++idxr, ++idxl;
    if(idxr < idxl)
      return 0;
    else
      return query(idxl, idxr);
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
  int last = 3;
  // cerr << "TEST" << endl;
  // cerr.flush();
  fenwick bit[3];
  // map of pr indicates the previous ones
  // for every difference, memo the indices and do the transitions like that, reset the bit
  // can not do (because it affects each other)
  vector<pair<int, int>> p[3];
  for(int i = 0; i <= n; ++i) {
    p[0].pb(mp(pref[i][1] - pref[i][0], pref[i][2] - pref[i][0]));
    p[1].pb(mp(pref[i][2] - pref[i][0], pref[i][1] - pref[i][0]));
    p[2].pb(mp(pref[i][2] - pref[i][1], pref[i][0] - pref[i][2]));
  }
  for(int i = 0; i < 3; ++i) {
    sort(p[i].begin(), p[i].end());
    p[i].resize(unique(p[i].begin(), p[i].end()) - p[i].begin());
    bit[i].points = p[i];
  }
  bit[0].update(mp(0, 0), 1);
  bit[1].update(mp(0, 0), 1);
  bit[2].update(mp(0, 0), 1);
  for(int i = 1; i <= n; ++i) {
    dp[i] = (dp[i] + (ll)bit[0].query(pref[i][1] - pref[i][0], -1e6, pref[i][2] - pref[i][0] - 1) + bit[1].query(pref[i][2] - pref[i][0], -1e6, pref[i][1] - pref[i][0] - 1) + bit[2].query(pref[i][2] - pref[i][1], -1e6, pref[i][0] - pref[i][2] - 1)) % mod;
    bit[0].update(mp(pref[i][1] - pref[i][0], pref[i][2] - pref[i][0]), dp[i]);
    bit[1].update(mp(pref[i][2] - pref[i][0], pref[i][1] - pref[i][0]), dp[i]);
    bit[2].update(mp(pref[i][2] - pref[i][1], pref[i][0] - pref[i][2]), dp[i]);
    // cout << dp[i] << " ";
  }
  if(dp[n] < 0)
    dp[n] += mod;
  cout << dp[n] << endl;
}