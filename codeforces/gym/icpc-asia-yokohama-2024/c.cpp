#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  vector<pair<int, int>> edges[n + 1];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].pb({v, w});
    edges[v].pb({u, w});
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push(mp(0, 1));
  ll res = 0; 
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  while(pq.size()) {
    ll dist = pq.top().fi; int nd = pq.top().se;
    pq.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    res += 1ll * a[nd] * dist;
    for(auto i : edges[nd]) {
      if(!vis[i.fi]) {
        pq.push(mp(dist + i.se, i.fi));
      }
    }
  }
  cout << res << endl;
}