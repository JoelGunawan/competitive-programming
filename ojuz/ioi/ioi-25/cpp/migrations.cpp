#include "migrations.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

int x = 0, y = 1;
bool done_x = 0, done_y = 0;
int par[16][N + 5];
int depth[N + 5];

// calculate distance between two nodes
int dist(int x, int y) {
  if (depth[x] < depth[y]) {
    swap(x, y);
  }

  int res = 0;
  for (int i = 15; i >= 0; --i) {
    if (par[i][x] != -1 && depth[par[i][x]] >= depth[y]) {
      x = par[i][x];
      res += 1 << i;
    }
  }

  if (x == y) {
    return res;
  }

  for (int i = 15; i >= 0; --i) {
    if (par[i][x] != par[i][y]) {
      x = par[i][x];
      y = par[i][y];
      res += 1 << (i + 1);
    }
  }

  return res + 2;
}

int send_message(int N, int nd, int pr) {
  // special init case
  if (nd == 1) {
    memset(par, -1, sizeof(par));
    par[0][1] = 0;
    depth[1] = 1;
    return 0;
  }
  
  // calc binlift and depth
  depth[nd] = depth[pr] + 1;
  par[0][nd] = pr;
  for (int i = 1; i < 16; ++i) {
    if (par[i - 1][nd] != -1) {
      par[i][nd] = par[i - 1][par[i - 1][nd]];
    }
  }

  // check dist(x, nd), dist(y, nd), see if x or y changed
  bool cx = 0, cy = 0;
  if (dist(x, nd) > dist(x, y)) {
    cy = 1;
    y = nd;
  } else if (dist(y, nd) > dist(x, y)) {
    cx = 1;
    x = nd;
  }

  if (nd >= N - 20 && nd < N - 12) {
    // communicate x phase
    if (done_x) {
      return cx;
    } else if (cx) {
      done_x = 1;
      return 0;
    } else {
      int num = nd - (N - 20); // the num-th message we send for x, starting from 0
      int cur = (x >> (2 * num)) & 3;
      return cur + 1;
    }
  }  else if (nd >= N - 12) {
    // communicate y phase
    if (nd < N - 4) {
      if (done_y) {
        return cy;
      } else if (cy) {
        done_y = 1;
        return 0;
      } else {
        int num = nd - (N - 12); // the num-th message we send for x, starting from 0
        int cur = (y >> (2 * num)) & 3;
        return cur + 1;
      }
    } else {
      if (nd == N - 4) {
        // get x
        if (x == nd) {
          return 0; // reset to nd
        } else if (x < N - 12) {
          return 1; // no reset
        } else if (x >= N - 12) {
          return ((x - (N - 12)) / 3) + 2;
        } 
      } else if (nd == N - 3) {
        // get x
        if (x == nd) {
          return 0; // reset to nd
        } else if (x == nd - 1 || x < N - 12) {
          return 1; // no reset
        } else {
          return ((x - (N - 12)) % 3) + 2;
        }
      } else if (nd == N - 2) {
        // get y
        if (y < N - 4) {
          return 0;
        } else {
          return N - 1 - y; // N - 2 -> 1, N - 3 -> 2, N - 4 -> 3
        }
      } else if (nd == N - 1) {
        // get y cur, x last two
        // 1. y reset n - 1
        // 2. x reset n - 2, y reset n - 1
        // 3. x reset n - 2, y no reset
        // 4. x reset n - 1
        if (x == N - 2 && y == N - 1) {
          return 1;
        } else if (x == N - 2) {
          return 2;
        } else if (x == N - 1) {
          return 3;
        } else if (y == N - 1) {
          return 4;
        }
      }
    }
  }

  // default
  return 0;
}

std::pair<int, int> longest_path(std::vector<int> S) {
  int val_x = 0, val_y = 0, shift = 0;
  bool done_x = 0, done_y = 0;

  // communicate x phase
  for (int i = N - 20; i < N - 12; ++i) {
    if (done_x) {
      val_x = S[i] == 1 ? i : val_x;
    } else {
      if (S[i] == 0) {
        val_x = i, done_x = i;
      } else {
        val_x += (S[i] - 1) << shift;
        shift += 2;
      }
    }
  }

  shift = 0;
  // communicate y phase
  for (int i = N - 12; i < N - 4; ++i) {
    if (done_y) {
      val_y = S[i] == 1 ? i : val_y;
    } else {
      if (S[i] == 0) {
        val_y = i, done_y = i;
      } else {
        val_y += (S[i] - 1) << shift;
        shift += 2;
      }
    }
  }

  // N - 4
  {
    int idx = N - 4;
    if (S[idx] == 0) {
      val_x = idx;
    } else if (S[idx] != 1) {
      val_x = N - 12 + (S[idx] - 2) * 3;
    }
  }

  // N - 3
  {
    int idx = N - 3;
    if (S[idx] == 0) {
      val_x = idx;
    } else if (S[idx] != 1) {
      val_x += S[idx] - 2;
    }
  }
  
  // N - 2
  {
    int idx = N - 2;
    if (S[idx] > 0) {
      val_y = N - 1 - S[idx];
    }
  }

  // N - 1
  {
    int idx = N - 1;
    if (S[idx] == 1) {
      val_x = N - 2, val_y = N - 1;
    } else if (S[idx] == 2) {
      val_x = N - 2;
    } else if (S[idx] == 3) {
      val_x = N - 1;
    } else if (S[idx] == 4) {
      val_y = N - 1;
    }
  }

  return {val_x, val_y};
}