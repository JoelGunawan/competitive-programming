#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges[n + 5];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].pb(mp(v, w));
  }
  ll res = 1e18;
  // fi -> dist
  // se.fi -> node
  // se.se -> ticket udah dipakai
  priority_queue<pair<ll, pair<int, bool>>, vector<pair<ll, pair<int, bool>>>, greater<pair<ll, pair<int, bool>>>> pq;
  pq.push(mp(0, mp(1, 0)));
  bool vis[n + 5][2];
  memset(vis, 0, sizeof(vis));
  while(pq.size()) {
    ll dist = pq.top().fi;
    int nd = pq.top().se.fi;
    bool ticket = pq.top().se.se;
    pq.pop();
    if(vis[nd][ticket])
      continue;
    vis[nd][ticket] = 1;
    if(nd == n)
      res = min(res, dist);
    for(auto i : edges[nd]) {
      if(ticket) {
        // ticket udah dipakai
        pq.push(mp(dist + i.se, mp(i.fi, 1)));
      }
      else {
        // ticket belum dipakai
        // ticket dipakai sekarang
        pq.push(mp(dist + i.se / 2, mp(i.fi, 1)));
        // ticket ga dipakai dulu
        pq.push(mp(dist + i.se, mp(i.fi, 0)));
      }
    }
  } 
  cout << res << endl;
}