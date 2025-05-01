#include <bits/stdc++.h>
#include "game.h"
#pragma GCC optimize("O2")
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second
using namespace std;
const int lim = 1e9;
long long gcd2(long long X, long long Y) {
  long long tmp;
  while (X != Y && Y != 0) {
    tmp = X;
    X = Y;
    Y = tmp % Y;
  }
  return X;
}
const int limx = 1e6 + 5;
const int limy = 1.3e7 + 5;
int lx[limx], rx[limx], nx[limx], ly[limy], ry[limy];
ll v[limy];
int xs = 0, ys = 0;
int leftx(int nd) {
  if(lx[nd] == -1)
    lx[nd] = ++xs;
  return lx[nd];
}
int rightx(int nd) {
  if(rx[nd] == -1)
    rx[nd] = ++xs;
  return rx[nd];
}
int lefty(int nd) {
  if(ly[nd] == -1)
    ly[nd] = ++ys;
  return ly[nd];
}
int righty(int nd) {
  if(ry[nd] == -1)
    ry[nd] = ++ys;
  return ry[nd];
}
int next(int nd) {
  if(nx[nd] == -1)
    nx[nd] = ++ys;
  return nx[nd];
}
ll getly(int nd) {
  return ly[nd] == -1 ? 0 : v[ly[nd]];
}
ll getry(int nd) {
  return ry[nd] == -1 ? 0 : v[ry[nd]];
}
ll query_y(int nd, int yl, int yr, int y1, int y2) {
  if(nd == -1 || yl > y2 || yr < y1)
    return 0;
  else if(yl >= y1 && yr <= y2) {
    // cerr << "QY " << nd << " " << yl << " " << yr << " " << v[nd] << endl;
    return v[nd];
  }
  else {
    int mid = (yl + yr) >> 1;
    return gcd2(query_y(ly[nd], yl, mid, y1, y2), query_y(ry[nd], mid + 1, yr, y1, y2));
  }
}
void update_y(int nd, int yl, int yr, int ndx, int y, ll val) {
  if(yl == yr) {
    if(lx[ndx] == -1 && rx[ndx] == -1) {
      v[nd] = val;
    }
    else {
      v[nd] = gcd2((lx[ndx] == -1 ? 0 : query_y(nx[lx[ndx]], 0, lim - 1, y, y)), (rx[ndx] == -1 ? 0 : query_y(nx[rx[ndx]], 0, lim - 1, y, y)));
    }
    // cerr << "UY " << nd << " " << yl << " " << yr << " " << v[nd] << endl;
  }
  else {
    int mid = (yl + yr) >> 1;
    if(y <= mid)
      update_y(lefty(nd), yl, mid, ndx, y, val);
    else
      update_y(righty(nd), mid + 1, yr, ndx, y, val);
    v[nd] = gcd2(getly(nd), getry(nd));
    // cerr << "UY " << nd << " " << yl << " " << yr << " " << v[nd] << endl;
  }
}
void update_x(int nd, int xl, int xr, int x, int y, ll val) {
  if(xl == xr) {
    // cerr << "UX " << nd << " " << xl << " " << xr << endl;
    update_y(next(nd), 0, lim - 1, nd, y, val);
  }
  else {
    int mid = (xl + xr) >> 1;
    if(x <= mid) {
      update_x(leftx(nd), xl, mid, x, y, val);
    }
    else {
      update_x(rightx(nd), mid + 1, xr, x, y, val);
    }
    // cerr << "UX " << nd << " " << xl << " " << xr << endl;
    update_y(next(nd), 0, lim - 1, nd, y, val);
  }
}
ll query_x(int nd, int xl, int xr, int x1, int x2, int y1, int y2) {
  // cerr << nd << " " << xl << " " << xr << " " << x1 << " " << x2 << endl;
  if(nd == -1 || xl > x2 || xr < x1) {
    return 0;
  }
  else if(xl >= x1 && xr <= x2) {
    // cerr << "QX " << nd << " " << xl << " " << xr << endl;
    return query_y(nx[nd], 0, lim - 1, y1, y2);
  }
  else {
    int mid = (xl + xr) >> 1;
    return gcd2(query_x(lx[nd], xl, mid, x1, x2, y1, y2), query_x(rx[nd], mid + 1, xr, x1, x2, y1, y2));
  }
} 
void init(int R, int C) {
  memset(lx, -1, sizeof(lx));
  memset(rx, -1, sizeof(rx));
  memset(nx, -1, sizeof(nx));
  memset(ly, -1, sizeof(ly));
  memset(ry, -1, sizeof(ry));
  memset(v, 0, sizeof(v));
}

void update(int P, int Q, long long K) {
  update_x(0, 0, lim - 1, P, Q, K);
}

long long calculate(int P, int Q, int U, int V) {
  // // cerr << "QUERY " << endl;
  return query_x(0, 0, lim - 1, P, U, Q, V);
}
