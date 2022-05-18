#include "server.h"

#include <vector>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
string to_binary(int number, int size) {
  string res = "";
  while(number > 0) {
    if(number & 1)
      res += '1';
    else
      res += '0';
    number /= 2;
  }
  while(res.size() < size)
    res += '0';
  reverse(res.begin(), res.end());
  return res;
}
vector<pair<int, int>> edges[500];
int dist[500], depth[500], par[500];
bool vis[500];
void dfs(int nd, int d, int dx) {
  vis[nd] = 1;
  dist[nd] = d;
  depth[nd] = dx;
  for(auto i : edges[nd]) {
    if(!vis[i.first]) {
      par[i.first] = i.second;
      dfs(i.first, d + i.second, dx + 1);
    }
  }
}
std::vector<int> server(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  // encode jadi tiap depth 10 itu kita buat jadi 10 bit integer
  // urutkan dari 1 ke 500
  for(int i = 0; i < A.size(); ++i) {
    edges[A[i]].pb({B[i], C[i]});
    edges[B[i]].pb({A[i], C[i]});
  }
  vector<int> ans(1000, 0);
  dfs(0, 0, 1);
  int cur_idx = 0;
  for(int i = 0; i <= N - 1; ++i) {
    if(depth[i] % 10)
      ans[cur_idx++] = par[i] == 1;
    else {
      string tmp = to_binary(dist[i], 10);
      for(auto j : tmp)
          ans[cur_idx++] = j == '1';
    }
  }
  for(int i = 0; i < cur_idx; ++i) {
    cout << ans[i];
  }
  cout << endl;
  return ans;
}