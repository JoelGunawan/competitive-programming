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
const int lim = 2e5 + 5;
int mod = 1e9 + 7;
ll dp[lim][5];
vector<int> edges[lim];
bool vis[lim];
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
void dfs(int nd) {
  vis[nd] = 1;
  vector<ll> pr0, pr1, pr2;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      dfs(x);
      pr0.pb(dp[x][0]);
      pr1.pb(dp[x][1]);
      pr2.pb(dp[x][2]);
    }
  }
  if(pr0.empty()) {
    dp[nd][1] = 1; // can extend 1
  }
  else if(pr0.size() == 1) {
    // all goes into can extend
    dp[nd][1] = pr0[0] + pr1[0] + pr2[0];
  }
  else {
    ll pref0[pr0.size()], suff0[pr0.size()], pref1[pr1.size()], suff1[pr1.size()];
    pref0[0] = pr0[0];
    pref1[0] = (pr0[0] + pr1[0]) % mod; 
    suff0[pr0.size() - 1] = pr0[pr0.size() - 1];
    suff1[pr1.size() - 1] = (pr0[pr0.size() - 1] + pr1[pr1.size() - 1]) % mod;
    for(int i = 1; i < pr0.size(); ++i) {
      pref0[i] = mul(pref0[i - 1], pr0[i]);
      pref1[i] = mul(pref1[i - 1], (pr0[i] + pr1[i]) % mod);
    }
    for(int i = pr0.size() - 2; i >= 0; --i) {
      suff0[i] = mul(suff0[i + 1], pr0[i]);
      suff1[i] = mul(suff1[i + 1], (pr0[i] + pr1[i]) % mod);
    }
    for(int i = 0; i < pr0.size(); ++i) {
      // must
      dp[nd][2] += mul(pr2[i], mul(i > 0 ? pref1[i - 1] : 1, i + 1 < pr0.size() ? suff1[i + 1] : 1));
      dp[nd][2] += mul(pr1[i], mul(i > 0 ? pref1[i - 1] : 1, i + 1 < pr0.size() ? suff1[i + 1] : 1));
      dp[nd][1] += mul(pr2[i], mul(i > 0 ? pref0[i - 1] : 1, i + 1 < pr0.size() ? suff0[i + 1] : 1));
      dp[nd][1] += mul(pr1[i], mul(i > 0 ? pref0[i - 1] : 1, i + 1 < pr0.size() ? suff0[i + 1] : 1));
    }
    dp[nd][2] -= dp[nd][1];
    dp[nd][1] += pref0[pr0.size() - 1];
    ll local_dp[pr0.size() + 1][3];
    memset(local_dp, 0, sizeof(local_dp));
    local_dp[0][0] = 1;
    for(int i = 1; i <= pr0.size(); ++i) {
      // select 2 from can/must extend
      // rest must be from not/can extend
      for(int j = 0; j < 3; ++j) {
        local_dp[i][j] = mul(local_dp[i - 1][j], (pr0[i - 1] + pr1[i - 1]) % mod);
        if(j > 0) 
          local_dp[i][j] += mul(local_dp[i - 1][j - 1], (pr1[i - 1] + pr2[i - 1]) % mod);
        local_dp[i][j] %= mod;
      }
    }
    dp[nd][0] = local_dp[pr0.size()][2];
  }
  // cerr << nd << " " << dp[nd][0] << " " << dp[nd][1] << " " << dp[nd][2] << endl;
  dp[nd][0] %= mod;
  dp[nd][1] %= mod;
  dp[nd][2] %= mod;
  if(dp[nd][2] < 0)
    dp[nd][2] += mod;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  dfs(1);
  cout << (dp[1][1] + dp[1][0]) % mod << endl;
  return 0;
}