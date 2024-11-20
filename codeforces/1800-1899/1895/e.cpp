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
void tc() {
  int n;
  cin >> n;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi;
  for(int i = 1; i <= n; ++i)
    cin >> a[i].se;
  int m;
  cin >> m;
  pair<int, int> b[m + 1];
  for(int i = 1; i <= m; ++i)
    cin >> b[i].fi;
  for(int i = 1; i <= m; ++i)
    cin >> b[i].se;
  // different starting points -> only important thing is starting defense
  // p2 will use card s.t. att > enemy def with max def value
  // p1 will use card s.t. att > enemy def with max def value
  // becomes graphs, if it ends -> then whoever is last loses, never ends -> draw
  // nodes -> n + m
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  // maintain suff max of def
  pair<int, int> sufa[n + 2], sufb[m + 2];
  sufa[n + 1] = sufb[m + 1] = mp(0, 0);
  for(int i = n; i >= 1; --i) 
    sufa[i] = max(sufa[i + 1], mp(a[i].se, i));
  for(int i = m; i >= 1; --i)
    sufb[i] = max(sufb[i + 1], mp(b[i].se, i));
  int nxt[n + m + 1];
  memset(nxt, -1, sizeof(nxt));
  const int inf = 1e9;
  for(int i = 1; i <= n; ++i) {
    // given current defense, what is the attack that p2 can have, go to that card
    int idx = ub(b + 1, b + m + 1, mp(a[i].se, inf)) - b;
    nxt[i] = idx == m + 1 ? -1 : sufb[idx].se + n;
  }
  for(int i = 1; i <= m; ++i) {
    int idx = ub(a + 1, a + n + 1, mp(b[i].se, inf)) - a;
    nxt[i + n] = idx == n + 1 ? -2 : sufa[idx].se;
  }
  bool vis[n + m + 1], active[n + m + 1];
  memset(vis, 0, sizeof(vis));
  memset(active, 0, sizeof(active));
  int dp[n + m + 1];
  fill(dp, dp + n + m + 1, 1);
  for(int i = 1; i <= n + m; ++i) {
    if(!vis[i]) {
      int cur = i;
      vector<int> v;
      while(!vis[cur]) {
        active[cur] = 1;
        vis[cur] = 1;
        v.pb(cur);
        if(nxt[cur] == -1 || nxt[cur] == -2 || vis[nxt[cur]]) {
          if(nxt[cur] == -1 || nxt[cur] == -2) 
            dp[cur] = nxt[cur];
          else if(active[nxt[cur]])
            dp[cur] = 0;
          else if(vis[nxt[cur]])
            dp[cur] = dp[nxt[cur]];
          else
            assert(false);
          break;
        }
        cur = nxt[cur];
      }
      for(auto x : v)
        active[x] = 0;
      v.pop_back();
      reverse(v.begin(), v.end());
      for(auto x : v) {
        dp[x] = dp[nxt[x]];
      }
    }
  }
  int w = 0, l = 0, d = 0;
  for(int i = 1; i <= n; ++i) {
    if(dp[i] == 0)
      ++d;
    else if(dp[i] == -1)
      ++w;
    else
      ++l;
  }
  // for(int i = 1; i <= n + m; ++i)
  //   cerr << nxt[i] << " ";
  // cerr << endl;
  cout << w << " " << d << " " << l << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}