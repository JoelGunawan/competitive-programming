#include "rook.h"

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int lim = 2e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    while(h[nd] != -1)
      nd = h[nd];
    return nd;
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
    }
    return x != y;
  }
};
int minimum_move(int N, std::vector<int> X, std::vector<int> Y,
                 std::vector<int> C) {
  // buat visited tiap x, tiap y, dan tiap color
  vector<int> x[N], y[N], c[N];
  // cari xgroup ygroup -> pakai map
  disjoint_set xdsu, ydsu, cdsu;  
  int cgroup[N], ygroup[N], xgroup[N];
  map<int, int> prc;
  for(int i = 0; i < N; ++i) {
    if(prc[C[i]]) {
      cdsu.merge(prc[C[i]] - 1, i);
    }
    prc[C[i]] = i + 1;
  }
  map<pair<int, int>, int> pr;
  for(int i = 0; i < N; ++i) {
    pr[make_pair(X[i], Y[i])] = i + 1;
    if(pr[mp(X[i] + 1, Y[i])]) {
      xdsu.merge(i, pr[mp(X[i] + 1, Y[i])] - 1);
    }
    if(pr[mp(X[i], Y[i] + 1)]) {
      ydsu.merge(i, pr[mp(X[i], Y[i] + 1)] - 1);
    }
    if(pr[mp(X[i] - 1, Y[i])]) {
      xdsu.merge(i, pr[mp(X[i] - 1, Y[i])] - 1);
    }
    if(pr[mp(X[i], Y[i] - 1)]) {
      ydsu.merge(i, pr[mp(X[i], Y[i] - 1)] - 1);
    }
  }
  pr.clear();
  for(int i = 0; i < N; ++i) {
    xgroup[i] = xdsu.fh(i);
    x[xgroup[i]].push_back(i);
    ygroup[i] = ydsu.fh(i);
    y[ygroup[i]].push_back(i);
    cgroup[i] = cdsu.fh(i);
    c[cgroup[i]].push_back(i);
    //cout << "GROUP " << xgroup[i] << " " << ygroup[i] << " " << cgroup[i] << endl;
  }
  /*
  for(int i = 0; i < N; ++i) {
    cout << "XCONTENT" << endl;
    for(auto j : x[i])
      cout << j << " ";
    cout << endl;
    cout << "YCONTENT" << endl;
    for(auto j : y[i])
      cout << j << " ";
    cout << endl;
    cout << "CCONTENT" << endl;
    for(auto j : c[i])
      cout << j << " ";
    cout << endl;
  }
  */
  // use xgroup ygroup and cgroup for bfs to avoid duplicate searching a lot
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    bool cvis[N], yvis[N], xvis[N], vis[N];
    memset(vis, 0, sizeof(vis));
    memset(cvis, 0, sizeof(cvis));
    memset(yvis, 0, sizeof(yvis));
    memset(xvis, 0, sizeof(xvis));
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(i, 0));
    int cur = 0;
    while(bfs.size()) {
      int idx = bfs.front().first, dist = bfs.front().second;
      bfs.pop();
      if(vis[idx])
        continue;
      vis[idx] = 1;
      //cout << "OUTPUT " << i << " " << idx << " " << dist << endl;
      cur = max(cur, dist);
      int curx = xgroup[idx], cury = ygroup[idx], curc = cgroup[idx];
      if(!xvis[curx]) {
        xvis[curx] = 1;
        for(auto j : x[curx]) {
          //cout << "X " << j << endl;
          if(!vis[j])
            bfs.push(make_pair(j, dist + 1));
        }
      }
      if(!yvis[cury]) {
        yvis[cury] = 1;
        for(auto j : y[cury]) {
          //cout << "Y " << j << endl;
          if(!vis[j])
            bfs.push(make_pair(j, dist + 1));
        }
      }
      if(!cvis[curc]) {
        cvis[curc] = 1;
        for(auto j : c[curc]) {
          //cout << "C " << j << endl;
          if(!vis[j])
            bfs.push(make_pair(j, dist + 1));
        }
      }
    }
    ans = max(ans, cur);
  }
  return ans;
}
