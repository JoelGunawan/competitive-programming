#include "training.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int lim = 3e5 + 5;
vector<pair<int, int>> edges[lim];
int disc[lim], low[lim], t;
bool vis[lim];
vector<pair<int, int>> bridge;
void dfs(int nd, int prev_edge = -1) {
  disc[nd] = low[nd] = t++;
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    // bridge tree -> disc[nd] > low[nd]
    // kalo back edge -> disc[i]
    // kalo bukan back edge -> low[i]
    // nanti pake dsu buat cari minimum
    if(i.second == prev_edge)
      continue;
    else if(vis[i.first]) {
      low[nd] = min(low[nd], disc[i.first]);
    }
    else {
      dfs(i.first, i.second);
      low[nd] = min(low[nd], low[i.first]);
    }
  }
  //cout << "DFS " << nd << " " << disc[nd] << " " << low[nd] << endl;
  for(auto i : edges[nd]) {
    if(low[i.first] > disc[nd])
      bridge.push_back({nd, i.first});
  }
}
struct disjoint_set {
  int head[lim], size[lim], minima[lim];
  disjoint_set() {
    memset(head, -1, sizeof(head));
    fill(size, size + lim, 1);
    fill(minima, minima + lim, 2e9);
  }
  int find_head(int nd) {
    while(head[nd] != -1)
      nd = head[nd];
    return nd;
  }
  void merge(int x, int y) {
    x = find_head(x), y = find_head(y);
    if(x != y) {
      if(size[x] < size[y])
        swap(x, y);
      size[x] += size[y], head[y] = x, minima[x] = min(minima[x], minima[y]);
    }
  }
};
disjoint_set dsu;
int ans[lim];
void get_res(int nd, int minima = 2e9) {
  dsu.minima[nd] = min(dsu.minima[nd], minima);
  minima = dsu.minima[nd];
  vis[nd] = 1;
  //cout << "GET_RES" << endl;
  //cout << nd << " " << minima << endl;
  for(auto i : edges[nd]) {
    //cout << i.first << endl;
    if(!vis[i.first]) {
      get_res(i.first, min(minima, i.second));
    }
  }
}
std::vector<int> find_training_routes(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  int M = A.size();
  vector<int> ret(N, 2e9);
  for(int i = 0; i < M; ++i) {
    edges[A[i]].push_back({B[i], i});
    edges[B[i]].push_back({A[i], i});
  }
  dfs(0);
  sort(bridge.begin(), bridge.end());
  for(int i = 0; i < N; ++i)
    edges[i].clear();
  for(int i = 0; i < M; ++i) {
    if(!binary_search(bridge.begin(), bridge.end(), make_pair(A[i], B[i])) && !binary_search(bridge.begin(), bridge.end(), make_pair(B[i], A[i]))) {
      // dsu kan
      //cout << "NOT BRIDGE " << A[i] << " " << B[i] << endl;
      dsu.merge(A[i], B[i]);
      dsu.minima[dsu.find_head(A[i])] = min(dsu.minima[dsu.find_head(A[i])], C[i]);
    }
  }
  for(int i = 0; i < M; ++i) {
    if(binary_search(bridge.begin(), bridge.end(), make_pair(A[i], B[i])) || binary_search(bridge.begin(), bridge.end(), make_pair(B[i], A[i]))) {
      // jadikan bridge edge
      //cout << "BRIDGE " << dsu.find_head(A[i]) << " " << dsu.find_head(B[i]) << endl;
      edges[dsu.find_head(A[i])].push_back({dsu.find_head(B[i]), C[i]});
      edges[dsu.find_head(B[i])].push_back({dsu.find_head(A[i]), C[i]});
    }
  }
  memset(vis, 0, sizeof(vis));
  get_res(dsu.find_head(0));
  // coba subtask 7
  // pakai semacam dfs tree
  // cari minimum edge
  // terus coba bisa sampai node mana aja dengan melewati edge itu
  // berarti cari di dfs tree low[nd] nya
  // untuk tiap CC tanpa bridge, cari edge minimumnya, maka bisa output edge minimum
  // jadikan bridge tree, dfs menurut bridge tree
  // bridge tree di dfs, tiap CC minimum berapa
  // dsu tiap edge
  // terus dfs dari tiap edge pake dsu
  ret[0] = 0;
  for(int i = 1; i < N; ++i)
    ret[i] = dsu.minima[dsu.find_head(i)] + 1e9;
  return ret;
}
