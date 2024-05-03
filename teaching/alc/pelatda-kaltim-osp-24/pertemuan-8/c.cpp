#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
int main() {
  // contoh input undirected + unweighted:
  // jika dikasih edge dari 1 ke 2, hanya diberi 1 2, tidak diberi 2 1
  // bagaimana cara buat supaya bisa 2 arah?
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}