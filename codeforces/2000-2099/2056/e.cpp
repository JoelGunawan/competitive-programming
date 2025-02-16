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
ll mod = 998244353;
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
const int lim = 4e5 + 5;
ll fact[lim], inv[lim];
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[b], inv[a - b]));
}
ll catalan(ll n) {
  n *= 2;
  return mul(powmod(n / 2 + 1, mod - 2), combinmod(n, n / 2));
}
void tc() {
  int n, m;
  cin >> n >> m;
  pair<int, int> a[m + 1];
  for(int i = 1; i <= m; ++i)
    cin >> a[i].fi >> a[i].se;
  for(int i = 1; i <= m; ++i)
    a[i].se = -a[i].se;
  sort(a + 1, a + m + 1);
  for(int i = 1; i <= m; ++i)
    a[i].se = -a[i].se;
  a[0] = mp(1, n);
  vector<int> st = {0};
  int par[m + 1], deg[m + 1], len[m + 1];
  ll ways[m + 1];
  fill(ways, ways + m + 1, 1);
  memset(par, 0, sizeof(par));
  memset(deg, 0, sizeof(deg));
  memset(len, 0, sizeof(len));
  len[0] = n - 1;
  for(int i = 1; i <= m; ++i) {
    while(a[st.back()].se < a[i].fi) {
      st.pop_back();
    }
    par[i] = st.back();
    len[par[i]] -= a[i].se - a[i].fi;
    deg[st.back()]++;
    len[i] = a[i].se - a[i].fi;
    // cerr << i << " " << len[i] << endl;
    st.pb(i);
  }
  queue<int> proc;
  for(int i = 0; i <= m; ++i) {
    if(deg[i] == 0)
      proc.push(i);
  }
  while(proc.size()) {
    int nd = proc.front();
    proc.pop();
    --deg[par[nd]];
    if(deg[par[nd]] == 0)
      proc.push(par[nd]);
    ways[nd] = mul(ways[nd], catalan(len[nd]));
    if(nd == 0)
      break;
    ways[par[nd]] = mul(ways[par[nd]], ways[nd]);
  }
  cout << ways[0] << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i)
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  while(t--)
    tc();
  return 0;
}