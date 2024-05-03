#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges[100005];
int main() {
  // contoh input undirected + weighted:
  // jika dikasih edge dari 1 ke 2, hanya diberi 1 2, tidak diberi 2 1
  // bagaimana cara buat supaya bisa 2 arah?
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    // u, v node
    // w bobot
    cin >> u >> v >> w;
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
  }
}