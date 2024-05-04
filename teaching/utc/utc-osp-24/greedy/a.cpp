#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
bool compare(pair<int, ll> a, pair<int, ll> b) {
  return a.se > b.se;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges[n + 5];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].pb(mp(v, w));
  }
  // masalah: default priority queue -> paling besar
  // solusi 1: negatif
  // solusi 2: modifikasi jadi dari paling kecil
  // first -> node, second -> distance
  // prioritas berdasarkan first dulu, baru second (kecuali di modif, seperti ini contohnya)
  // otomatis yg top itu paling kecil
  // second sorted, tapi first dulu
  priority_queue<pair<int, ll>, vector<pair<int, ll>>, function<bool(pair<int, ll>&, pair<int, ll>&)>> pq(compare);
  pq.push(mp(1, 0));
  ll sp[n + 5];
  memset(sp, -1, sizeof(sp));
  // mirip bfs, cmn pake pq
  while(pq.size()) {
    // top -> paling kecil (kalo di pq normal paling besar)
    int nd = pq.top().fi;
    ll dist = pq.top().se; 
    pq.pop();
    if(sp[nd] != -1)
      continue;
    sp[nd] = dist;
    for(auto i : edges[nd]) {
      if(sp[i.fi] == -1) {
        pq.push(mp(i.fi, dist + i.se));
      }
    }
  }
  for(int i = 1; i <= n; ++i)
    cout << sp[i] << " ";
  cout << endl;
}