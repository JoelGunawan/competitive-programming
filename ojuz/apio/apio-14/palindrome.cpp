// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
typedef uint64_t H;
int mod = 1e9 + 9, mod2 = 1e9 + 7;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
static const H C = rng() % mod, C2 = rng() % mod2;
struct HashInterval {
  vector<H> ha, pw;
  HashInterval(string& str) : ha(str.size()+1), pw(ha) {
    pw[0] = 1;
    for(int i = 0; i < str.size(); ++i) {
      ha[i + 1] = (ha[i] * C + str[i]) % mod;
      pw[i + 1] = (pw[i] * C) % mod;
    }
  }
  H hashInterval(int a, int b) {
    if(a < 0 || a >= b || b >= ha.size())
      assert(false);
    return (ha[b] - ha[a] * pw[b - a]) % mod >= 0 ? (ha[b] - ha[a] * pw[b - a]) % mod : ((ha[b] - ha[a] * pw[b - a]) % mod) + mod;
  }
};
struct HashInterval2 {
  vector<H> ha, pw;
  HashInterval2(string& str) : ha(str.size()+1), pw(ha) {
    pw[0] = 1;
    for(int i = 0; i < str.size(); ++i) {
      ha[i + 1] = (ha[i] * C2 + str[i]) % mod2;
      pw[i + 1] = (pw[i] * C2) % mod2;
    }
  }
  H hashInterval(int a, int b) {
    if(a < 0 || a >= b || b >= ha.size())
      assert(false);
    return (ha[b] - ha[a] * pw[b - a]) % mod2 >= 0 ? (ha[b] - ha[a] * pw[b - a]) % mod2 : ((ha[b] - ha[a] * pw[b - a]) % mod2) + mod2;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  HashInterval norm(s), rev(t);
  HashInterval2 norm2(s), rev2(t);
  int n = s.size();
  set<pair<H, H>> even_hash, odd_hash;
  map<pair<H, H>, int> even_cnt, odd_cnt, even_sz, odd_sz;
  map<pair<H, H>, vector<pair<H, H>>> even_edges, odd_edges;
  for(int i = 0; i < n; ++i) {
    if(i + 1 < n && s[i] == s[i + 1]) {
      // even size
      int l = 1, r = n, ans = 1;
      while(l <= r) {
        int mid = (l + r) / 2;
        if(i + mid + 1 <= n && i - mid >= -1 && norm2.hashInterval(i + 1, i + mid + 1) == rev2.hashInterval(n - i - 1, n - i - 1 + mid) && norm.hashInterval(i + 1, i + mid + 1) == rev.hashInterval(n - i - 1, n - i - 1 + mid))
          l = mid + 1, ans = mid;
        else
          r = mid - 1;
      }
      pair<H, H> cur = mp(norm.hashInterval(i + 1, i + 1 + ans), norm2.hashInterval(i + 1, i + 1 + ans));
      ++even_cnt[cur];   
      even_sz[cur] = 2 * ans;
      even_hash.insert(cur);
      while(ans-- != 1 && !even_edges[cur].size())
        even_edges[cur].pb(mp(norm.hashInterval(i + 1, i + 1 + ans), norm2.hashInterval(i + 1, i + 1 + ans))), even_hash.insert(mp(norm.hashInterval(i + 1, i + 1 + ans), norm2.hashInterval(i + 1, i + 1 + ans))), cur = mp(norm.hashInterval(i + 1, i + 1 + ans), norm2.hashInterval(i + 1, i + 1 + ans)), even_sz[cur] = 2 * ans;
    }
    // odd size
    int l = 1, r = n, ans = 1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(i + mid <= n && i - mid >= -1 && norm2.hashInterval(i, i + mid) == rev2.hashInterval(n - i - 1, n - i - 1 + mid) && norm.hashInterval(i, i + mid) == rev.hashInterval(n - i - 1, n - i - 1 + mid))
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    pair<H, H> cur = mp(norm.hashInterval(i, i + ans), norm2.hashInterval(i, i + ans));
    ++odd_cnt[cur];   
    odd_sz[cur] = 2 * ans - 1;
    // cout << "DEB " << i << " " << odd_sz[cur] << endl;
    odd_hash.insert(cur);
    while(ans-- != 1 && !odd_edges[cur].size())
      odd_edges[cur].pb(mp(norm.hashInterval(i, i + ans), norm2.hashInterval(i, i + ans))), odd_hash.insert(mp(norm.hashInterval(i, i + ans), norm2.hashInterval(i, i + ans))), cur = mp(norm.hashInterval(i, i + ans), norm2.hashInterval(i, i + ans)), odd_sz[cur] = 2 * ans - 1;
  }
  // process by largest size hash first
  vector<pair<int, pair<H, H>>> v;
  ll res = 0;
  for(auto x : odd_hash)
    v.pb(mp(odd_sz[x], x));
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for(auto x : v) {
    // cout << x.fi << " " << odd_cnt[x.se] << endl;
    res = max(res, 1ll * x.fi * odd_cnt[x.se]);
    for(auto y : odd_edges[x.se]) {
      // cout << "FROM " << x.se << " TO " << y << endl;
      odd_cnt[y] += odd_cnt[x.se];
    }
  }
  v.clear();
  for(auto x : even_hash) 
    v.pb(mp(even_sz[x], x));
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for(auto x : v) {
    res = max(res, 1ll * x.fi * even_cnt[x.se]);
    for(auto y : even_edges[x.se]) {
      even_cnt[y] += even_cnt[x.se];
    }
  }
  cout << res << endl;
  return 0;
}