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
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i])
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
  vis[nd] = 1;
  for(auto i : rev[nd]) {
    if(!vis[i])
      ans |= dfs_minout(i, a[nd].minout);
  }
  if(nd < K) {
    ans |= a[nd].maxin >= nd;
    ans |= nd >= a[nd].minout;
  }
  else
    ans |= a[nd].maxin >= a[nd].minout;
  return ans;
}
vector<int> visited;
bool dfs1(int nd, int id) {
  a[nd].maxin = max(a[nd].maxin, id);
  bool ans = 0;
  vis[nd] = 1;
  visited.push_back(nd);
  for(auto i : pending_edge[nd]) {
    if(!vis[i])
      ans |= dfs1(i, a[nd].maxin);
  }
  //cout << "DFS1 " << nd << " " << a[nd].maxin << " " << a[nd].minout << endl;
  if(nd < K) {
    ans |= a[nd].maxin >= nd;
    ans |= nd >= a[nd].minout;
  }
  else
    ans |= a[nd].maxin >= a[nd].minout;
  return ans;
}
bool dfs2(int nd, int id) {
  a[nd].minout = min(a[nd].minout, id);
  bool ans = 0;
  vis[nd] = 1;
  visited.push_back(nd);
  for(auto i : pending_rev[nd]) {
    if(!vis[i])
      ans |= dfs2(i, a[nd].minout);
  }
  //cout << "DFS2 " << nd << " " << a[nd].maxin << " " << a[nd].minout << endl;
  if(nd < K) {
    ans |= a[nd].maxin >= nd;
    ans |= nd >= a[nd].minout;
  }
  else
    ans |= a[nd].maxin >= a[nd].minout;
  return ans;
}
int add_teleporter(int u, int v) {
  pending.push_back({u, v});
  pending_edge[u].push_back(v);
  pending_rev[v].push_back(u);
  // min out -> reverse edge
  // max in -> same way edge
  // kalo udah di vis sm max in, gaperlu visit lagi
  if(pending.size() == s) {
    // clear pending
    //cout << "TEST" << endl;
    for(auto i : pending) {
      rev[i.second].push_back(i.first);
      pending_rev[i.second].clear();
      edges[i.first].push_back(i.second);
      pending_edge[i.first].clear();
    }
    pending.clear();
    // update maxin/minout
    int ans = 0;
    for(int i = K - 1; i >= 0; --i) {
      for(auto j : edges[i])
        if(!vis[j])
          ans |= dfs_maxin(j, i);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < K; ++i) {
      for(auto j : rev[i])
        if(!vis[j])
          ans |= dfs_minout(j, i);
    }
    //for(int i = 0; i < N; ++i)
    //  cout << i << " " << a[i].minout << " " << a[i].maxin << endl;
    memset(vis, 0, sizeof(vis));
    return ans;
  }
  else {

    // dfs dari node u, v apakaha bisa modifikasi nilai minout/maxin dari new edges aja
    // yang keubah:
    // minout dari u bakal keganti dengan v
    // maxin dari v bakal keganti dengan u
    // dfs pending edge dari u ke v (maxin)
    // dfs rev pending dari v ke u (minout)
    int ans = 0;
    //cout << "SEP" << endl;
    if(u < K)
      ans |= dfs1(v, u);
    else
      ans |= dfs1(v, a[u].maxin);
    for(auto i : visited)
      vis[i] = 0;
    visited.clear();
    if(v < K)
      ans |= dfs2(u, v);
    else
      ans |= dfs2(u, a[v].minout);
    for(auto i : visited)
      vis[i] = 0;
    visited.clear();
    return ans;
  }
  return 0;
}
