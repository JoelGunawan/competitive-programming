#include "client.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
int to_integer(string s) {
  int tmp = 1;
  int res = 0;
  for(int i = s.size() - 1; i >= 0; --i) {
    if(s[i] == '1')
      res += tmp;
    tmp *= 2;
  }
  return res;
}
vector<int> edges[500];
int par[500], depth[500];
bool vis[500];
void dfs(int nd, int d) {
  vis[nd] = 1;
  depth[nd] = d;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i, d + 1);
      par[i] = nd;
    }
  }
}
int client(int N, std::vector<int> A, std::vector<int> B, int W) {
  // get position for each number
  // read the position for each number
    
}