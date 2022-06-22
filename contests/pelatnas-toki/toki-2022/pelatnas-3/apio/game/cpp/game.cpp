#include "game.h"
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct node {
  int maxin = -3e5 - 5, minout = 3e5 + 5;
};
vector<node> a;
int N, K;
// pake pending update sqrt hrsnya 4e8
void init(int n, int k) {
  for(int i = 0; i < n; ++i)
    a.push_back(node());
  N = n, K = k;
}
int s = sqrt(500000);
// ijin ke toilet
vector<int> edges[300005], rev[300005];
vector<int> pending_edge[300005], pending_rev[300005];
vector<pair<int, int>> pending;
bool vis[300005];
bool dfs_maxin(int nd, int id) {
  a[nd].maxin = max(a[nd].maxin, id);
  bool ans = 0;
  for(auto i : edges[nd]) {
    if(a[i].maxin < a[nd].maxin)
      ans |= dfs_maxin(i, a[nd].maxin);
  }
  if(nd < K) {
    ans |= a[nd].maxin >= nd;
    ans |= nd >= a[nd].minout;
  }
  else
    ans |= a[nd].maxin >= a[nd].minout;
  return ans;
}
bool dfs_minout(int nd, int id) {
  a[nd].minout = min(a[nd].minout, id);
  bool ans = 0;
  for(auto i : rev[nd]) {
    if(a[i].minout > a[nd].minout)
      ans |= dfs_minout(i, a[nd].minout);
  }
  if(nd < K) {
    ans |= a[nd].maxin >= nd;
    ans |= nd >= a[nd].minout;
  }
  // ijin ke toilet
  else
    ans |= a[nd].maxin >= a[nd].minout;
  return ans;
}
int add_teleporter(int u, int v) {
  // min out -> reverse edge
  // max in -> same way edge
  // kalo udah di vis sm max in, gaperlu visit lagi
  // subtask 4 -> each node will be changed at most nk times
  // subtask 5 -> probably observation where we only change m times or k times
  edges[u].push_back(v);
  rev[v].push_back(u);
  bool ans = 0;
  if(u < K) 
    ans |= dfs_maxin(v, u);
  else
    ans |= dfs_maxin(v, a[u].maxin);
  if(v < K)
    ans |= dfs_minout(u, v);
  else
    ans |= dfs_minout(u, a[v].minout);
  return ans;
}
