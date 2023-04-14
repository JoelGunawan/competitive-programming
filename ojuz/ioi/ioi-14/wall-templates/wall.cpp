#include "wall.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 21;
struct segment_tree {
  int lazymax[2 * lim], lazymin[2 * lim], a[2 * lim];
  segment_tree() {
    memset(a, 0, sizeof(a));
    fill(lazymin, lazymin + 2 * lim, INT_MAX);
    memset(lazymax, 0, sizeof(lazymax));
  }
  void propagate(int nd, int cl, int cr) {
    if(cl == cr) {
      a[nd] = max(lazymax[nd], a[nd]);
      a[nd] = min(lazymin[nd], a[nd]);
    }
    else {
      lazymax[2 * nd] = min(lazymin[nd], max(lazymax[2 * nd], lazymax[nd]));
      lazymin[2 * nd] = max(min(lazymin[2 * nd], lazymin[nd]), lazymax[nd]);
      lazymax[2 * nd + 1] = min(lazymin[nd], max(lazymax[2 * nd + 1], lazymax[nd]));
      lazymin[2 * nd + 1] = max(min(lazymin[2 * nd + 1], lazymin[nd]), lazymax[nd]);
    }
    lazymax[nd] = 0, lazymin[nd] = INT_MAX;
  }
  void update_max(int nd, int cl, int cr, int l, int r, int val) {
    propagate(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazymax[nd] = max(lazymax[nd], val);
      lazymin[nd] = max(lazymin[nd], val);
      propagate(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) / 2;
      update_max(2 * nd, cl, mid, l, r, val);
      update_max(2 * nd + 1, mid + 1, cr, l, r, val);
    }
  }
  void update_min(int nd, int cl, int cr, int l, int r, int val) {
    propagate(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazymax[nd] = min(lazymax[nd], val);
      lazymin[nd] = min(lazymin[nd], val);
      propagate(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) / 2;
      update_min(2 * nd, cl, mid, l, r, val);
      update_min(2 * nd + 1, mid + 1, cr, l, r, val);
    }
  }
  int query(int nd, int cl, int cr, int idx) {
    propagate(nd, cl, cr);
    if(cl == cr) {
      return a[nd];
    }
    else {
      int mid = (cl + cr) / 2;
      if(idx <= mid)
        return query(2 * nd, cl, mid, idx);
      else
        return query(2 * nd + 1, mid + 1, cr, idx);
    }
  }
};
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  segment_tree seg;
  //cout << "SUCCEED 1 " << endl;
  for(int i = 0; i < k; ++i) {
    //cout << i << endl;
    if(op[i] == 1) {
      // max
      seg.update_max(1, 0, lim - 1, left[i], right[i], height[i]);
    }
    else {
      seg.update_min(1, 0, lim - 1, left[i], right[i], height[i]);
    }
  }
  for(int i = 0; i < n; ++i)
    finalHeight[i] = seg.query(1, 0, lim - 1, i);
  return;
}

