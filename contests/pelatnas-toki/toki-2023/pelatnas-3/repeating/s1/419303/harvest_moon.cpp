#include "harvest_moon.h"
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
int par[17][lim], depth[lim];
ll dist[lim];
bool vis[lim];
vector<pair<int, ll>> edges[lim], child[lim];
vector<int> leaf;
void dfs(int nd) {
  vis[nd] = 1;
  for(int i = 1; i < 17; ++i)
    par[i][nd] = par[i - 1][par[i - 1][nd]];
  for(auto i : edges[nd]) {
    if(!vis[i.fi]) {
      //cout << "EDGE " << nd << " " << i.fi << " " << i.se << endl;
      depth[i.fi] = depth[nd] + 1;
      dist[i.fi] = dist[nd] + i.se;
      par[0][i.fi] = nd;
      dfs(i.fi);
    }
  }
  if(edges[nd].size() == 1) {
    leaf.pb(nd);
  }
}
int lca(int u, int v) {
  if(depth[u] > depth[v])
    swap(u, v);
  for(int i = 16; i >= 0; --i) {
    if(depth[par[i][v]] >= depth[u])
      v = par[i][v];
  }
  if(u == v)
    return u;
  for(int i = 16; i >= 0; --i) {
    if(par[i][v] != par[i][u])
      v = par[i][v], u = par[i][u];
  }
  return par[0][u];
}
vector<long long> answer(int N, int K, int Q, vector<int> p,
                         vector<long long> c, vector<long long> w,
                         vector<int> u, vector<int> v) {
  // n <= 2000, dijkstra dr tiap node
  // dfs terus construct edge manual
  // k <= n - 1, star graph, nanti tiap gerakan pilih antara langsung ke target, pergi ke sebelah lewat atas, pergi ke sebelah lewat bawah
  // w[i] = 0 -> nanti semua leaf jadi 1 node
  // tiap node ada 2 pilihan, lewat lca atau lewat leaf terdekat (nanti tinggal dfs aja)
  // w[i] = 10^12 -> ignore edge baru
  for(int i = 0; i < N - 1; ++i) {
    edges[i + 1].pb(mp(p[i], c[i]));
    edges[p[i]].pb(mp(i + 1, c[i]));
  }
  for(int i = 0; i < N; ++i)
    sort(edges[i].begin(), edges[i].end());
  dfs(0);
  vector<ll> ret(Q, -1);
  //for(int i = 0; i < N; ++i)
  //  cout << dist[i] << " ";
  //cout << endl;
  for(int i = 0; i < Q; ++i) {
    // u, v querynya
    //cout << u[i] << " " << v[i] << " " << lca(u[i], v[i]) << endl;
    ret[i] = dist[u[i]] + dist[v[i]] - 2 * dist[lca(u[i], v[i])];
  }
  // w[i] = 0 -> cari min(dist[u[i]] + dist[v[i]] - 2 * dist[lca(u[i], v[i])], ldist[u[i]] + ldist[v[i]])
  ll suff[N];
  memset(suff, 0, sizeof(suff));
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  for(auto i : leaf)
    pq.push(mp(0, i));
  memset(vis, 0, sizeof(vis));
  while(pq.size()) {
    ll d = pq.top().fi; int nd = pq.top().se;
    pq.pop();
    if(vis[nd])
      continue;
    vis[nd] = 1;
    suff[nd] = d;
    for(auto i : edges[nd]) {
      if(!vis[i.fi])
        pq.push(mp(d + i.se, i.fi));
    }
  }
  for(int i = 0; i < Q; ++i) {
    ret[i] = min(ret[i], suff[u[i]] + suff[v[i]]);
  }
  return ret;
}