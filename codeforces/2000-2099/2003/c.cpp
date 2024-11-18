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
int a[lim], b[lim], dist[2 * lim], k;
vector<int> edges[2 * lim];
bool vis[2 * lim];
void dfs(int nd) {
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
      dist[i] = (dist[nd] + 1) % k, dfs(i);
  }
}
int m(int x) {
  x %= k;
  return x < 0 ? x + k : x;
}
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
int arr[lim];
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
void tc() {
  int n;
  cin >> n >> k;
  for(int i = 1; i <= 2 * n; ++i)
    edges[i].clear();
  for(int i = 1; i <= 2 * n; ++i)
    vis[i] = 0;
  for(int i = 1; i <= 2 * n; ++i)
    dist[i] = 0;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int m1;
  cin >> m1;
  for(int i = 1; i <= m1; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
  }
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  int m2;
  cin >> m2;
  for(int i = 1; i <= m2; ++i) {
    int u, v;
    cin >> u >> v;
    edges[n + u].pb(n + v);
  }
  dist[1] = dist[n + 1] = 0;
  dfs(1), dfs(n + 1);
  // cerr << "POST DFS" << endl;
  vector<int> in[2], out[2];
  int tmpcnt[2][2];
  memset(tmpcnt, 0, sizeof(tmpcnt));
  for(int i = 1; i <= n; ++i) {
    // cerr << "TEST" << endl;
    if(a[i])
      in[0].pb(i), ++tmpcnt[0][1];
    else
      out[0].pb(i), ++tmpcnt[0][0];
  }
  for(int i = 1; i <= n; ++i) {
    // cerr << "TEST" << endl;
    if(b[i])
      in[1].pb(i), ++tmpcnt[1][1];
    else
      out[1].pb(i), ++tmpcnt[1][0];
  }
  if(tmpcnt[0][0] != tmpcnt[1][1] || tmpcnt[0][1] != tmpcnt[1][0]) {
    // cout << tmpcnt[0][0] << " " << tmpcnt[1][1] << " " << tmpcnt[0][1] << " " << tmpcnt[1][0] << endl;
    cerr << "NO" << endl;
    return;
  }
  if(in[0].empty() || in[1].empty()) {
    cout << "YES" << endl;
    return;
  }
  // choose some out[0], in[1] arbitrarily
  int g1 = out[0][0], g2 = in[1][0];
  int cnto[n + 1], cnti[n + 1];
  memset(cnto, 0, sizeof(cnto));
  memset(cnti, 0, sizeof(cnti));
  // cerr << "HERE" << endl;
  int key = rng() % mod;
  int itemo[n + 1], itemi[n + 1];
  memset(itemo, -1, sizeof(itemo));
  memset(itemi, -1, sizeof(itemi));
  for(int i = 1; i <= n; ++i) {
    if(!a[i])
      ++cnto[m(dist[i] + dist[g1])], itemo[m(dist[i] + dist[g1])] = i;
  }
  for(int i = 1; i <= n; ++i) {
    if(b[i])
      ++cnti[m(dist[i + n] + dist[g2 + n])], itemi[m(dist[i + n] + dist[g2 + n])] = i;
  }
  ll hash0 = 0;
  ll hash1 = 0;
  // cerr << "HERE" << endl;
  reverse(cnti, cnti + k);
  for(int i = 0; i < k; ++i) {
    hash0 = (hash0 * key) + arr[cnto[i]];
    hash0 %= mod;
  }
  for(int i = 0; i < k; ++i) {
    hash1 = (hash1 * key) + arr[cnti[i]];
    hash1 %= mod;
  }
  // find cyclic shifts of o that equals i
  ll p = powmod(key, k - 1);
  vector<pair<int, int>> s1;
  int idx;
  for(int i = 0; i < k; ++i) {
    if(cnto[i]) {
      idx = i;
      break;
    }
  }
  for(int i = 0; i < k; ++i) {
    // first ... -> anything in first with dist = 
    // second ... -> 
    if(hash1 == hash0) {
      if(itemi[i + idx] != -1)
        s1.pb(mp(i, m(dist[g1] + dist[itemo[idx]] + dist[g2 + n] + dist[itemi[i + idx]])));
    }
    hash1 = (hash1 - p * arr[cnti[i]]) * key + arr[cnti[i]];
    hash1 %= mod;
  }
  swap(in[0], in[1]);
  swap(out[0], out[1]);
  g1 = out[0][0], g2 = in[1][0];
  memset(cnto, 0, sizeof(cnto));
  memset(cnti, 0, sizeof(cnti));
  // cerr << "HERE" << endl;
  memset(itemo, -1, sizeof(itemo));
  memset(itemi, -1, sizeof(itemi));
  for(int i = 1; i <= n; ++i)
    swap(dist[i], dist[i + n]);
  for(int i = 1; i <= n; ++i) {
    if(!a[i])
      ++cnto[m(dist[i] + dist[g1])], itemo[m(dist[i] + dist[g1])] = i;
  }
  for(int i = 1; i <= n; ++i) {
    if(b[i])
      ++cnti[m(dist[i + n] + dist[g2 + n])], itemi[m(dist[i + n] + dist[g2 + n])] = i;
  }
  hash0 = 0;
  hash1 = 0;
  // cerr << "HERE" << endl;
  reverse(cnti, cnti + k);
  for(int i = 0; i < k; ++i) {
    hash0 = (hash0 * key) + arr[cnto[i]];
    hash0 %= mod;
  }
  for(int i = 0; i < k; ++i) {
    hash1 = (hash1 * key) + arr[cnti[i]];
    hash1 %= mod;
  }
  // find cyclic shifts of o that equals i
  p = powmod(key, k - 1);
  vector<pair<int, int>> s2;
  idx;
  for(int i = 0; i < k; ++i) {
    if(cnto[i]) {
      idx = i;
      break;
    }
  }
  for(int i = 0; i < k; ++i) {
    // first ... -> anything in first with dist = 
    // second ... -> 
    if(hash1 == hash0) {
      if(itemi[i + idx] != -1) 
        s2.pb(mp(i, m(dist[g1] + dist[itemo[idx]] + dist[g2 + n] + dist[itemi[i + idx]])));
    }
    hash1 = (hash1 - p * arr[cnti[i]]) * key + arr[cnti[i]];
    hash1 %= mod;
  }
  cout << "FIRST" << endl;
  for(auto p : s1)
    cout << p.fi << " " << p.se << endl;
  cout << "SECOND" << endl;
  for(auto p : s2)
    cout << p.fi << " " << p.se << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  set<int> s;
  for(int i = 0; i < lim; ++i) {
    int cur = rng() % mod;
    while(s.count(cur))
      cur = rng() % mod;
    arr[i] = cur;
  }
  while(t--)
    tc();
  return 0;
}