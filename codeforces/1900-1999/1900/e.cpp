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
int t, low[lim], disc[lim];
bool active[lim];
vector<vector<int>> components;
vector<int> st, edges[lim];
void tarjan(int nd) {
  disc[nd] = low[nd] = ++t;
  active[nd] = 1;
  st.pb(nd);
  for(auto i : edges[nd]) {
    if(disc[i] == -1) {
      tarjan(i);
      low[nd] = min(low[nd], low[i]);
    }
    else if(active[i]) {
      // cerr << "TAKE FROM " << nd << " " << i << endl;
      low[nd] = min(low[nd], disc[i]);
    }
  }
  // cerr << nd << " " << low[nd] << " " << disc[nd] << endl;
  if(low[nd] == disc[nd]) {
    vector<int> nx;
    do {
      nx.pb(st.back());
      // cerr << "INACTIVE " << st.back() << endl;
      active[st.back()] = 0;
      st.pop_back();
    } while(nx.back() != nd);
    components.pb(nx);
  }
}
void tc() {
  t = 0;
  components.clear();
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    disc[i] = low[i] = -1;
    edges[i].clear();
  }
  vector<pair<int, int>> adj;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    adj.pb(mp(u, v));
  }
  // merge each scc into one, use DP DAG to find longest path, min value
  for(int i = 1; i <= n; ++i)
    if(disc[i] == -1) {
      // cerr << "TARJAN" << endl;
      tarjan(i);
    }
  int comp_num[n + 1];
  int sum = 0;
  for(int i = 0; i < components.size(); ++i) {
    sum += components[i].size();
    for(auto j : components[i])
      comp_num[j] = i;
  }
  ll val[components.size()];
  int in[components.size()], sz[components.size()];
  pair<int, ll> dp[components.size()];
  memset(val, 0, sizeof(val));
  memset(in, 0, sizeof(in));
  memset(sz, 0, sizeof(sz));
  // for(auto x : components) {
  //   for(auto y : x) {
  //     cerr << y << " ";
  //   }
  //   cerr << endl;
  // }
  for(int i = 1; i <= n; ++i)
    ++sz[comp_num[i]], val[comp_num[i]] += a[i];
  for(int i = 0; i < components.size(); ++i)
    edges[i].clear();
  for(auto p : adj) {
    if(comp_num[p.fi] != comp_num[p.se]) {
      ++in[comp_num[p.se]];
      edges[comp_num[p.fi]].pb(comp_num[p.se]);
    }
  }
  queue<int> q;
  for(int i = 0; i < components.size(); ++i) {
    dp[i] = mp(sz[i], -val[i]);
    if(in[i] == 0)
      q.push(i);
  }
  while(q.size()) {
    int nd = q.front();
    q.pop();
    for(auto i : edges[nd]) {
      dp[i] = max(dp[i], mp(sz[i] + dp[nd].fi, -val[i] + dp[nd].se));
      --in[i];
      if(in[i] == 0)
        q.push(i);
    }
  }
  pair<int, ll> res = mp(0, 0);
  for(int i = 0; i < components.size(); ++i) {
    res = max(res, dp[i]);
  }
  cout << res.fi << " " << -res.se << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}