#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
char s[5005];
short dp[5005][5005], prx[5005][5005], pry[5005][5005], lcp[5005][5005];
vector<int> trans[5005];
vector<short> nx[5005];
const int mod = 1e9 + 7;
ll red(ll x) {
  x %= mod;
  return x < 0 ? x + mod : x;
}
int main() {
  int n = -1;
  while((s[++n] = getchar()) != '\n');
  // for every string l, r find longest common between r + 1 ... and l, r
  // fi -> first right that is allowed, se -> take dp[se][cur - 1]
  int l, r, ans, mid;
  // lcp[i][j] = lcp[i + 1][j + 1] + 1 IF s[i] = s[j]
  memset(lcp, 0, sizeof(lcp));
  for(short i = n - 1; i >=0; --i) {
    for(int j = i; j + 1 < n; ++j) {
      if(s[i] == s[j])
        lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }
  for(short i = 0; i < n; ++i) {
    for(short j = i; j + 1 < n; ++j) {
      ans = min({j - i, lcp[i][j + 1] - 1, n - j - 1});
      // cerr << i << " " << j << " " << ans << endl;
      int first_allow = j + ans + 2;
      // if(i == 0 && j == 5) {
      //   cerr << i << " " << j << " " << j + 1 << " " << first_allow << endl;
      // }
      if(first_allow != n && (i + ans == j || s[i + ans + 1] < s[first_allow])) {
        // index of first allowed next element
        // if(i + ans + 1 != j)
        //   cerr << i << " " << j << " " << s[i + ans + 1] << " " << s[first_allow] << endl;
        trans[j + 1].pb((first_allow << 15) + i); 
        // cerr << i << " " << j << " " << j + 1 << " " << first_allow << endl;
        // cerr << (((first_allow << 16) + i) & ((1 << 16) - 1)) << endl;
      }
    }
  }
  // for(int i = 1; i < n; ++i) {
  //   for(auto p : trans[i])
  //     cerr << p.se << " " << i - 1 << " " << i << " " << p.fi << endl;
  //   cerr << endl;
  // }
  // observe that dp[0][i] = 1 is always true
  for(int i = 0; i < n; ++i)
    dp[0][i] = 1; // always possible
  const int tmp = (1 << 15) - 1;
  for(short i = 1; i < n; ++i) {
    // set i as left
    // what dp transition is possible?
    // when i is first element, trans it possible prevs, take dp[se][cur - 1]
    // sort(trans[i].begin(), trans[i].end());
    // reverse(trans[i].begin(), trans[i].end());
    for(auto p : trans[i]) {
      // cerr << "DEB " << i << " " << p << " " << (p >> 16) << " " << tmp << " " << (p & tmp) << endl;
      nx[p >> 15].pb(p & tmp);
    }
    short mx = 0, x, y;
    for(short j = i; j < n; ++j) {
      for(auto p : nx[j]) {
        // cerr << j << " " << p << endl;
        // cerr << p << " " << i - 1 << " " << dp[p][i - 1] << endl;
        if(dp[p][i - 1] > mx) {
          mx = dp[p][i - 1], x = p, y = i - 1;
        }
      }
      if(mx != 0)
        dp[i][j] = mx + 1, prx[i][j] = x, pry[i][j] = y;
    }
    for(auto p : trans[i])
      nx[p >> 15].pop_back();
  }
  pair<short, pair<short, short>> res = mp(0, mp(0, 0));
  for(short i = 0; i < n; ++i)
    res = max(res, mp(dp[i][n - 1], mp(i, (short)(n - 1))));
  int out = res.fi;
  char chars[10];   // Max int = 2147483647
  int digits = 0;
   do
   {
      chars[digits++] = ((out % 10) + 0x30);
      out /= 10;
   }while (out && digits < 10);

   while (digits>0)
   {
      putchar(chars[--digits]);
   }
   putchar('\n');
  vector<pair<int, int>> v;
  while(true) {
    int cl = res.se.fi, cr = res.se.se;
    v.pb(mp(cl, cr));
    res.se = mp(prx[cl][cr], pry[cl][cr]);
    if(res.se.se >= cl)
      break;
  }
  sort(v.begin(), v.end());
  for(auto p : v) {
    for(int i = p.fi; i <= p.se; ++i)
      putchar(s[i]);
    putchar('\n');
  }
  return 0;
}