#include "virus.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
// di tiap hld root, memo apa aja yang ada -1
set<int> memo[lim];
// pr_contrib -> previous contribution to par
// ch_contrib -> previous contribution from par to node i
// val -> nilai sekarang, kalo misal bukan root ya ga usah ikut di update sih, nanti waktu lepas ngikut root aja
int par[lim], subtree[lim], head[lim], hld[lim], val[lim], pr_contrib[lim], ch_contrib[lim], to_nd[lim];
bool vis[lim];
vector<int> edges[lim], child[lim];
void dfs1(int nd = 1) {
  vis[nd] = 1;
  for(int i = 0; i < edges[nd].size(); ++i) {
    int x = edges[nd][i];
    if(!vis[x]) {
      dfs1(x);
      subtree[nd] += subtree[x];
      par[x] = nd;
      child[nd].push_back(x);
    }
  }
  //cout << "PARENT " << nd << " " << par[nd] << endl;
}
int cur = 0;
void dfs2(int nd = 1) {
  for(int i = 1; i < child[nd].size(); ++i) {
    if(subtree[child[nd][i]] > subtree[child[nd][0]])
      swap(child[nd][i], child[nd][0]);
  }
  // process bawahnya
  hld[nd] = ++cur;
  to_nd[hld[nd]] = nd;
  //cout << nd << " " << hld[nd] << endl;
  memo[head[nd]].insert(hld[nd]);
  for(int i = 0; i < child[nd].size(); ++i) {
    int x = child[nd][i];
    if(i == 0) {
      head[x] = head[nd];
      dfs2(x);
    }
    else {
      head[x] = x;
      dfs2(x);
    }
  }
}
int find_root(int nd) {
  // find di memo nya head[nd] yg kurang dr nd
  //cout << "WHAT " << nd << endl;
  while(memo[head[nd]].upper_bound(hld[nd]) == memo[head[nd]].begin()) {
    //cout << nd << endl;
    nd = par[head[nd]];
  }
  //cout << head[nd] << " " << hld[nd] << endl;
  return to_nd[*--memo[head[nd]].upper_bound(hld[nd])];
}
vector<int> countViruses(int N, int M, int Q, vector<int> u, vector<int> v,
                         vector<int> D, vector<int> C) {
  for(int i = 0; i < N - 1; ++i) {
    edges[u[i]].push_back(v[i]);
    edges[v[i]].push_back(u[i]);
  }
  dfs1();
  head[1] = 1;
  dfs2();
  // d -> operations
  // m operations
  int cnt[N + 1];
  memset(cnt, 0, sizeof(cnt));
  //cout << "AFTER" << endl;
  for(int i = 1; i <= N; ++i)
    val[i] = 1;
  for(int i = 0; i < M; ++i) {
    int x = u[D[i] - 1], y = v[D[i] - 1];
    // x itu yg lebih atas
    if(par[x] == y)
      swap(x, y);
    // par[y] = x
    int he = find_root(x);
    //cout << "PROC " << x << " " << y << " " << he << endl;
    if(cnt[D[i]] & 1) {
      // deletion
      // val[y] pasti indicate di bawahnya ada berapa
      pr_contrib[y] = val[y] - ch_contrib[y];
      ch_contrib[y] = val[he] - pr_contrib[y];
      val[y] = val[he];
      memo[head[y]].insert(hld[y]);
      //cout << "UPD " << ch_contrib[y] << " " << pr_contrib[y] << " " << val[y] << endl;
    }
    else {
      // insertion
      val[he] += val[y] - pr_contrib[y] - ch_contrib[y];
      //cout << "UPD " << val[he] << endl;
      memo[head[y]].erase(hld[y]);
    }
    ++cnt[D[i]];
    //cout << "DONE " << i << endl;
  }
  vector<int> ans(Q);
  for(int i = 0; i < Q; ++i) {
    int x = C[i], he = find_root(x);
    //cout << x << " " << he << endl;
    ans[i] = val[he];
  }
  return ans;
  // buat hld buat simpan parent root
  // nanti update tiap koneksi di root masing-masing new connection
  // updatenya adalah previousnya ada update berapa, terus yg baru akan ada update berapa
  // jadi nanti akan beda connectednya berapa, itu dijumlahkan ke rootnya
  // buat hld, find closest parent yang punya tanda -1

}
