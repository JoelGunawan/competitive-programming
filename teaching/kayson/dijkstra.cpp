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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n + 5];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }
  // vector<ll> dist(n + 1, -1);
  ll dist[n + 1];
  memset(dist, -1, sizeof(dist));
  // vector<bool> vis(n + 1, 0);
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  // starts at node 1
  pq.push({0, 1});
  while(pq.size()) {
    auto [d, nd] = pq.top();
    // ll d = pq.top().first;
    // int nd = pq.top().second;
    pq.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    dist[nd] = d;
    for(auto [dst, cost] : adj[nd]) {
      if(!vis[dst]) {
        pq.push({d + cost, dst});
      }
    }
  }
  cout << dist[n] << endl;
  return 0;
}