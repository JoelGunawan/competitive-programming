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
  vector<pair<int, int>> edges[n + 5];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].pb(mp(v, w));
    edges[v].pb(mp(u, w));
  }
  priority_queue<pair<ll, pair<int, pair<int, int>>>, vector<pair<ll, pair<int, pair<int, int>>>>, greater<pair<ll, pair<int, pair<int, int>>>>> pq;
  pq.push(mp(0, mp(1, mp(0, 0))));
  ll dist[n + 5][2][2];
  memset(dist, -1, sizeof(dist));
  while(pq.size()) {
    ll d = pq.top().fi;
    int nd = pq.top().se.fi, red = pq.top().se.se.fi, inc = pq.top().se.se.se;
    // cerr << d << " " << nd << " " << red << " " << inc << endl;
    pq.pop();
    if(dist[nd][red][inc] != -1)
      continue;
    dist[nd][red][inc] = d;
    for(auto p : edges[nd]) {
      // cerr << p.fi << endl;
      if(!red && !inc) {
        // min and max cancel out
        if(dist[p.fi][1][1] == -1 || dist[p.fi][1][1] > d + p.se)
          pq.push(mp(d + p.se, mp(p.fi, mp(1, 1))));
      }
      if(!red) {
        // free
        if(dist[p.fi][1][inc] == -1 || dist[p.fi][1][inc] > d)
          pq.push(mp(d, mp(p.fi, mp(1, inc))));
      }
      if(!inc) {
        // extra cost
        if(dist[p.fi][red][1] == -1 || dist[p.fi][red][1] > d + (p.se << 1))
          pq.push(mp(d + (p.se << 1), mp(p.fi, mp(red, 1))));
      }
      if(dist[p.fi][red][inc] == -1 || dist[p.fi][red][inc] > d + p.se)
        pq.push(mp(d + p.se, mp(p.fi, mp(red, inc))));
    }
  }
  for(int i = 2; i <= n; ++i)
    cout << dist[i][1][1] << " ";
  cout << endl;
  return 0;
}