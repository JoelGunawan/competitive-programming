#include "maze.h"

#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
struct node {
  int l = -1, r = -1;
  // fi -> dist
  // se.fi -> x
  // se.se -> y
  int cnt = 0;
};
struct rmq_seg {
  vector<node> a = {node()};
  void update(int nd, int cl, int cr, int idx, pair<int, pair<int, int>> val) {
    a[nd].cnt++;
    if(cl == cr) {
      return;
    }
    int mid = (cl + cr) / 2;
    if(idx <= mid) {
      if(a[nd].l == -1)
        a[nd].l = a.size(), a.push_back(node());
      update(a[nd].l, cl, mid, idx, val);
    }
    else {
      if(a[nd].r == -1)
        a[nd].r = a.size(), a.push_back(node());
      update(a[nd].r, mid + 1, cr, idx, val);
    }
  }
  void erase(int nd, int cl, int cr, int idx, pair<int, pair<int, int>> val) {
    //assert(nd != -1);
    //cout << a[nd].cnt << " " << val.se.fi << " " << val.se.se << endl;
    --a[nd].cnt;
    assert(a[nd].cnt >= 0);
    if(cl == cr) {
      return;
    }
    int mid = (cl + cr) / 2;
    if(idx <= mid) {
      erase(a[nd].l, cl, mid, idx, val);
    }
    else {
      erase(a[nd].r, mid + 1, cr, idx, val);
    }
  }
  pair<int, pair<int, int>> query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      //cout << "QUERY " << cl << " " << cr << " " << a[nd].cnt << endl;
      if(a[nd].cnt <= 0)
        return mp(0, mp(0, 0));
      else if(cl == cr) {
        return mp(1, mp(0, cl));
      }
      else {
        int mid = (cl + cr) / 2;
        if(a[nd].l != -1 && a[a[nd].l].cnt > 0) {
          return query(a[nd].l, cl, mid, l, r);
        }
        else {
          return query(a[nd].r, mid + 1, cr, l, r);
        }
      }
    }
    else if(cl > r || cr < l)
      return mp(0, mp(0, 0));
    else {
      int mid = (cl + cr) / 2;
      pair<int, pair<int, int>> ret = mp(0, mp(0, 0));
      if(a[nd].l != -1) {
        ret = max(ret, query(a[nd].l, cl, mid, l, r));
      }
      if(a[nd].r != -1) {
        ret = max(ret, query(a[nd].r, mid + 1, cr, l, r));
      }
      return ret;
    }
  }
};
struct segment_tree {
  vector<rmq_seg> segs = {rmq_seg()};
  vector<node> a = {node()};
  void update(int nd, int cl, int cr, int cu, int cd, int x, int y, int val) {
    segs[nd].update(0, cu, cd, y, mp(val, mp(x, y)));
    if(cl == cr) {
      return;
    }
    int mid = (cl + cr) / 2;
    if(x <= mid) {
      if(a[nd].l == -1)
        a[nd].l = a.size(), a.push_back(node()), segs.push_back(rmq_seg());
      update(a[nd].l, cl, mid, cu, cd, x, y, val);
    }
    else {
      if(a[nd].r == -1)
        a[nd].r = a.size(), a.push_back(node()), segs.push_back(rmq_seg());
      update(a[nd].r, mid + 1, cr, cu, cd, x, y, val);
    }
    // get dari query child nya? (gperlu krn lgsg update di sini)
  }
  void erase(int nd, int cl, int cr, int cu, int cd, int x, int y, int val) {
    //cout << x << " " << y << endl;
    segs[nd].erase(0, cu, cd, y, mp(val, mp(x, y)));
    if(cl == cr) {
      return;
    }
    int mid = (cl + cr) / 2;
    if(x <= mid) {
      erase(a[nd].l, cl, mid, cu, cd, x, y, val);
    }
    else {
      erase(a[nd].r, mid + 1, cr, cu, cd, x, y, val);
    }
    // get dari query child nya? (gperlu krn lgsg update di sini)
  }
  pair<int, pair<int, int>> query(int nd, int cl, int cr, int cu, int cd, int l, int r, int u, int d) {
    //cout << l << " " << r << " " << u << " " << d << endl;
    //cout << "CUR " << cl << " " << cr << " " << cu << " " << cd << endl;
    //cout << "TGT " << l << " " << r << " " << u << " " << d << endl;
    //cout << cl << " " << cr << " " << l << " " << r << endl;
    if(cr < l || cl > r) {
      return mp(0, mp(0, 0));
    }
    else if(cl >= l && cr <= r) {
      //cout << "RETURN VAL" << endl;
      //cout << segs[nd].query(0, cu, cd, u, d) << endl;
      pair<int, pair<int, int>> ret = segs[nd].query(0, cu, cd, u, d);
      //cout << "DEB " << ret.fi << " " << ret.se.fi << " " << ret.se.se << endl;
      if(ret.fi == 0)
        return ret;
      else if(cl == cr) {
        return mp(ret.fi, mp(cl, ret.se.se));
      }
      else {
        int mid = (cl + cr) / 2;
        if(a[nd].l != -1 && segs[a[nd].l].query(0, cu, cd, u, d).fi)
          return query(a[nd].l, cl, mid, cu, cd, l, r, u, d);
        else
          return query(a[nd].r, mid + 1, cr, cu, cd, l, r, u, d);
      }
    }
    else {
      int mid = (cl + cr) / 2;
      pair<int, pair<int, int>> ret = mp(0, mp(0, 0));
      if(a[nd].l != -1) {
        ret = max(ret, query(a[nd].l, cl, mid, cu, cd, l, r, u, d));
      }
      if(a[nd].r != -1) {
        ret = max(ret, query(a[nd].r, mid + 1, cr, cu, cd, l, r, u, d));
      }
      return ret;
    }
  }
};
int minimum_stamps(int R, int C, int N, int Sr, int Sc, int Gr, int Gc,
                   std::vector<std::vector<char>> A) {
  //cout << A.size() << endl;
  // dijkstra aja
  //--Sr, --Sc, --Gr, --Gc;
  deque<pair<int, pair<int, int>>> dq;
  int res[R][C];
  segment_tree seg;
  for(int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j)
      res[i][j] = 1e9, seg.update(0, 0, R - 1, 0, C - 1, i, j, 1e9);
  }
  // bfs 0-1 jg bisa?
  dq.push_back(mp(0, mp(Sr, Sc)));
  seg.erase(0, 0, R - 1, 0, C - 1, Sr, Sc, 0);
  vector<pair<int, int>> nxt = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
  while(dq.size()) {
    int dist = dq.front().fi, x = dq.front().se.fi, y = dq.front().se.se;
    dq.pop_front();
    if(res[x][y] != 1e9)
      continue;
    // consider all nodes within range N x N of this node
    // just create a while loop
    //cout << "PROC " << dist << " " << x << " " << y << endl;
    // (log max(r, c))^2
    res[x][y] = dist;
    for(auto p : nxt) {
      if(x + p.fi >= 0 && x + p.fi < R && y + p.se >= 0 && y + p.se < C && res[x + p.fi][y + p.se] == 1e9 && A[x + p.fi][y + p.se] != '#') {
        dq.push_front(mp(dist, mp(x + p.fi, y + p.se)));
        //res[x + p.fi][y + p.se] = dist;
        //seg.erase(0, 0, R - 1, 0, C - 1, x + p.fi, y + p.se, 0);
      }
    }
    //cout << "BEFORE" << endl;
    //cout << "NOT IN WHILE" << endl;
    while(seg.query(0, 0, R - 1, 0, C - 1, x - (N - 1), x + (N - 1), y + 1, y + N).fi) {
      //cout << "WHY ERROR" << endl;
      pair<int, pair<int, int>> tmp = seg.query(0, 0, R - 1, 0, C - 1, x - (N - 1), x + (N - 1), y + 1, y + N);
      //cout << "DEBUG " << tmp.se.fi << " " << tmp.se.se << endl;
      int d = tmp.fi, cx = tmp.se.fi, cy = tmp.se.se;
      dq.push_back(mp(dist + 1, mp(cx, cy)));
      seg.erase(0, 0, R - 1, 0, C - 1, cx, cy, 0);
   }
   while(seg.query(0, 0, R - 1, 0, C - 1, x - (N - 1), x + (N - 1), y - N, y - 1).fi) {
      //cout << "WHY ERROR" << endl;
      pair<int, pair<int, int>> tmp = seg.query(0, 0, R - 1, 0, C - 1, x - (N - 1), x + (N - 1), y - N, y - 1);
      //cout << "DEBUG " << tmp.se.fi << " " << tmp.se.se << endl;
      int d = tmp.fi, cx = tmp.se.fi, cy = tmp.se.se;
      dq.push_back(mp(dist + 1, mp(cx, cy)));
      seg.erase(0, 0, R - 1, 0, C - 1, cx, cy, 0);
   }
   while(seg.query(0, 0, R - 1, 0, C - 1, x + 1, x + N, y - (N - 1), y + (N - 1)).fi) {
      //cout << "WHY ERROR" << endl;
      pair<int, pair<int, int>> tmp = seg.query(0, 0, R - 1, 0, C - 1, x + 1, x + N, y - (N - 1), y + (N - 1));
      //cout << "DEBUG " << tmp.se.fi << " " << tmp.se.se << endl;
      int d = tmp.fi, cx = tmp.se.fi, cy = tmp.se.se;
      dq.push_back(mp(dist + 1, mp(cx, cy)));
      seg.erase(0, 0, R - 1, 0, C - 1, cx, cy, 0);
   }
   while(seg.query(0, 0, R - 1, 0, C - 1, x - N, x - 1, y - (N - 1), y + (N - 1)).fi) {
      //cout << "WHY ERROR" << endl;
      pair<int, pair<int, int>> tmp = seg.query(0, 0, R - 1, 0, C - 1, x - N, x - 1, y - (N - 1), y + (N - 1));
      //cout << "DEBUG " << tmp.se.fi << " " << tmp.se.se << endl;
      int d = tmp.fi, cx = tmp.se.fi, cy = tmp.se.se;
      dq.push_back(mp(dist + 1, mp(cx, cy)));
      seg.erase(0, 0, R - 1, 0, C - 1, cx, cy, 0);
   }
  }
  //for(int i = 0; i < R; ++i) {
  //  for(int j = 0; j < C; ++j) {
  //    cout << res[i][j] << " ";
  //  }
  //  cout << endl;
  //}
  //cout << res[Gr][Gc] << endl;
  //cout << Gr << " " << Gc << endl;
  return res[Gr][Gc];
}
