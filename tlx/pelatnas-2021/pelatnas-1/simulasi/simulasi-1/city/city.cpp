#include <bits/stdc++.h>
#include "city.h"
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
struct disjoint_set {
  int head[(int)400], size[(int)400];
  disjoint_set() {
    memset(head, -1, sizeof(head));
    fill(size, size + 400, 1);
  }
  int find_head(int node) {
    while(head[node] != -1)
      node = head[node];
    return node;
  }
  bool merge(int a, int b) {
    int x = find_head(a), y = find_head(b);
    if(x != y) {
      if(size[x] < size[y])
        head[x] = y, size[y] += size[x];
      else
        head[y] = x, size[x] += size[y];
    }
    return x != y;
  }
};
int adj[400][400];
std::pair<int, int> getBestXY(int N, int M, int S, int T, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  // init edge
  vector<pair<int, pair<int, int>>> edg;
  memset(adj, -1, sizeof(adj));
  for(int i = 0; i < M; ++i) {
    adj[A[i]][B[i]] = C[i];
    adj[B[i]][A[i]] = C[i];
    edg.pb(mp(C[i], mp(A[i], B[i])));
  }
  sort(edg.begin(), edg.end());
  // go through every edge
  // and brute force
  int mst_val = INT_MAX, res_dist = INT_MAX;
  pair<int, int> res = {-1,-1};
  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j) {
      if(true) {
        // try to merge these 2 and see what happens
        disjoint_set dsu;
        dsu.merge(i, j);
        // find mst value
        int mst_size = 0;
        for(int i = 0; i < M; ++i) {
          if(dsu.merge(edg[i].se.fi, edg[i].se.se))
            mst_size += edg[i].fi;
          if(dsu.size[dsu.find_head(edg[i].se.fi)] == N)
            break;
        }
        // find distance between S and T
        priority_queue<pair<int, int>> dj;
        dj.push(mp(0, S));
        int cur_dist = -1;
        bool vis[N];
        memset(vis, 0, sizeof(vis));
        while(dj.size() > 0) {
          int dist = -dj.top().fi, node = dj.top().se;
          dj.pop();
          if(vis[node])
            continue;
          vis[node] = 1;
          if(node == i || node == j) {
            if(!vis[j])
              dj.push(mp(-dist, j));
            if(!vis[i])
              dj.push(mp(-dist, i));
          }
          if(node == T) {
            cur_dist = dist;
            break;
          }
          for(int edge = 0; edge < N; ++edge) {
           if(adj[node][edge] != -1 && !vis[edge])
            dj.push(mp(-(dist + adj[node][edge]), edge));
          }
        }
        //cout << mst_size << " " << mst_val << " " << cur_dist << " " << res_dist << " " << i << " " << j << endl;
        if(mst_size < mst_val || (mst_size == mst_val && cur_dist < res_dist) || (mst_size == mst_val && cur_dist == res_dist && (i < res.fi || (i == res.fi && j < res.se)))) {
          res.fi = i, res.se = j, mst_val = mst_size, res_dist = cur_dist;
        }
      }
    }
  }
  return res;
}