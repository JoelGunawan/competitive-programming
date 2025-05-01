#include "island.h"
#include <bits/stdc++.h>
using namespace std;

void solve(int N, int L) {
  bool have_par[N + 1];
  memset(have_par, 0, sizeof(have_par));
  int dist[N + 1];
  int order[N + 1];
  dist[1] = 0;
  for (int i = 1; i < N; ++i) {
    int nx = query(1, i);
    dist[nx] = i;
    order[i] = nx;
  }
  for (int i = 1; i < N; ++i) {
    int cur = order[i];
    if (have_par[cur]) {
      continue;
    }
    for (int j = 1; j < N; ++j) {
      int nx = query(cur, j);
      if (dist[nx] < dist[cur]) {
        // found par, stop
        answer(nx, cur);
        have_par[cur] = 1;
        break;
      } else {
        // we are finding a child, so the child doesn't have to find par :D
        answer(nx, cur);
        have_par[nx] = 1;
      }
    }
  }
}