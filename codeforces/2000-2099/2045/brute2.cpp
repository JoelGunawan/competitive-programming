#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
struct string_hash {
  vector<ll> pref, power;
  vector<vector<ll>> ret;
  ll val[26];
  ll key;
  ll mod;
  string_hash() {
 
  }
  string_hash(string s, int mod) : mod(mod) {
    // build
    pref.resize(s.size());
    power = pref;
    key = rng();
    for(int i = 0; i < 26; ++i)
      val[i] = rng() % mod;
    power[0] = 1;
    for(int i = 1; i < power.size(); ++i)
      power[i] = (1ll * power[i - 1] * key) % mod;
    pref[0] = val[s[0] - 'A'];
    for(int i = 1; i < pref.size(); ++i)
      pref[i] = ((1ll * pref[i - 1] * key) + val[s[i] - 'A']) % mod;
    ret = vector<vector<ll>>(s.size(), vector<ll>(s.size(), 0));
    for(int i = 0; i < ret.size(); ++i) {
      for(int j = i; j < ret.size(); ++j)
        ret[i][j] = i == 0 ? pref[j] : red(pref[j] - 1ll * pref[i - 1] * power[j - i + 1]);
    }
  }
  ll red(ll x) {
    x %= mod;
    return x < 0 ? x + mod : x;
  }
  ll query(int l, int r) {
    return ret[l][r];
  }
};
string_hash h1, h2;
bool check_equal(int l1, int r1, int l2, int r2) {
  // try single hashing, maybe it is good enough, maybe not TLE in this case
  return h1.query(l1, r1) == h1.query(l2, r2) && h2.query(l1, r1) == h2.query(l2, r2);
}
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  h1 = string_hash(s, mod1), h2 = string_hash(s, mod2);
  // for every string l, r find longest common between r + 1 ... and l, r
  // fi -> first right that is allowed, se -> take dp[se][cur - 1]
  vector<pair<int, int>> trans[s.size()];
  for(int i = 0; i < s.size(); ++i) {
    for(int j = i; j + 1 < s.size(); ++j) {
      int lcp = 0;
      // just find longest common prefix
      int l = 0, r = min((int)s.size() - j - 2, j - i), ans = -1;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(check_equal(i, i + mid, j + 1, j + mid + 1))
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      int first_allow = j + ans + 2;
      if(first_allow != s.size() && (i + ans == j || s[i + ans + 1] < s[first_allow])) {
        // index of first allowed next element
        // if(i + ans + 1 != j)
        //   cerr << i << " " << j << " " << s[i + ans + 1] << " " << s[first_allow] << endl;
        trans[j + 1].pb(mp(first_allow, i)); 
      }
    }
  }
  // for(int i = 1; i < s.size(); ++i) {
  //   for(auto p : trans[i])
  //     cerr << p.se << " " << i - 1 << " " << i << " " << p.fi << endl;
  //   cerr << endl;
  // }
  int dp[s.size()][s.size()];
  memset(dp, 0, sizeof(dp));
  // observe that dp[0][i] = 1 is always true
  for(int i = 0; i < s.size(); ++i)
    dp[0][i] = 1; // always possible
  pair<int, int> pr[s.size()][s.size()];
  for(int i = 0; i < s.size(); ++i) 
    for(int j = i; j < s.size(); ++j)
      pr[i][j] = mp(-1, -1);
  for(int i = 0; i < s.size(); ++i) {
    // set i as left
    // what dp transition is possible?
    // when i is first element, trans it possible prevs, take dp[se][cur - 1]
    sort(trans[i].begin(), trans[i].end());
    reverse(trans[i].begin(), trans[i].end());
    pair<int, pair<int, int>> cur_mx = mp(0, mp(0, 0));
    for(int j = i; j < s.size(); ++j) {
      while(trans[i].size() && trans[i].back().fi <= j)
        cur_mx = max(cur_mx, mp(dp[trans[i].back().se][i - 1], mp(trans[i].back().se, i - 1))), trans[i].pop_back();
      if(cur_mx.fi != 0)
        dp[i][j] = cur_mx.fi + 1, pr[i][j] = cur_mx.se;
    }
  }
  pair<int, pair<int, int>> res = mp(0, mp(0, 0));
  for(int i = 0; i < s.size(); ++i)
    res = max(res, mp(dp[i][(int)s.size() - 1], mp(i, (int)(s.size() - 1))));
  cout << res.fi << endl;
  vector<pair<int, int>> v;
  while(true) {
    int cl = res.se.fi, cr = res.se.se;
    v.pb(mp(cl, cr));
    res.se = pr[cl][cr];
    if(res.se.fi == -1)
      break;
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  for(auto p : v) {
    for(int i = p.fi; i <= p.se; ++i)
      cout << s[i], ++cnt;
    cout << endl;
  }
  return 0;
}