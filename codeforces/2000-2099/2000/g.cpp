// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t2 >> t0 >> t1;
    // dijkstra reverse
    vector<pair<int, pair<int, int>>> edges[n + 5];
    for(int i = 1; i <= m; ++i) {
      int u, v, l1, l2;
      cin >> u >> v >> l1 >> l2;
      edges[u].pb(mp(v, mp(l1, l2)));
      edges[v].pb(mp(u, mp(l1, l2)));
    }
    t0 = t2 - t0, t1 = t2 - t1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(mp(0, n));
    ll res = 1e18;
    bool vis[n + 5];
    memset(vis, 0, sizeof(vis));
    while(pq.size()) {
      ll dist = pq.top().fi; int nd = pq.top().se;
      pq.pop();
      if(vis[nd])
        continue;
      vis[nd] = 1;
      // cout << nd << " " << dist << endl;
      if(nd == 1) {
        res = dist;
        break;
      }
      for(auto p : edges[nd]) {
        if(!vis[p.fi]) {
          // always can walk
          // check for bus
          if((dist <= t1 && dist + p.se.fi <= t1) || (dist >= t0 && dist + p.se.fi >= t0)) {
            pq.push(mp(dist + p.se.fi, p.fi));
          }
          else {
            // check how long to delay, go out at t0 
            pq.push(mp(min((ll)t0 + p.se.fi, dist + p.se.se), p.fi));
          }
        }
      }
    }
    if(res > t2) {
      cout << -1 << endl;
    }
    else {
      cout << t2 - res << endl;
    }
  }
  return 0;
}