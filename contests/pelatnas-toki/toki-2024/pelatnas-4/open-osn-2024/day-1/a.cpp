#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
using namespace std;
const ll lim = 1e5 + 5;
vector<ll> child[lim];
ll w[lim], d[lim];
ll dp[lim][2];
void dfs(ll nd) {
  dp[nd][0] = w[nd];
  dp[nd][1] = w[nd];
  vector<pair<ll, ll>> f;
  for(auto i : child[nd]) {
    dfs(i);
    f.pb(mp(dp[i][0] + dp[i][1], i));
  }
  sort(f.begin(), f.end());
  reverse(f.begin(), f.end());
  // cout << "first" << endl;
  for(ll i = 0; i < d[nd]; ++i) {
    // cout << dp[f[i].se][1] << endl;
    dp[nd][0] -= dp[f[i].se][1];
  }
  // cout << "second" << endl;
  for(ll i = d[nd]; i < child[nd].size(); ++i) {
    // cout << dp[f[i].se][0] << endl;
    dp[nd][0] += dp[f[i].se][0];
  }
  reverse(f.begin(), f.end());
  // cout << "third" << endl;
  for(ll i = 0; i < d[nd]; ++i) {
    // cout << dp[f[i].se][0] << endl;
    dp[nd][1] -= dp[f[i].se][0];
  }
  // cout << "fourth" << endl;
  for(ll i = d[nd]; i < child[nd].size(); ++i) {
    // cout << dp[f[i].se][1] << endl;
    dp[nd][1] += dp[f[i].se][1];
  }
  // cout << endl;
  // cout << nd << " " << dp[nd][0] << " " << dp[nd][1] << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  for(ll i = 2; i <= n; ++i) {
    ll x;
    cin >> x;
    child[x].pb(i);
  }
  for(ll i = 1; i <= n; ++i)
    cin >> w[i];
  for(ll i = 1; i <= n; ++i)
    cin >> d[i];
  dfs(1);
  cout << max(-dp[1][0], dp[1][1]);
}