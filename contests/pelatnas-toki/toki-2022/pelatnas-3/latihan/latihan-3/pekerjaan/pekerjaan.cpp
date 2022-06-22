#include "pekerjaan.h"
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 5e5, lim2 = 1 << 19;
// get depth of every node, binlift of every node
// do HLD do get minimum in path excluding nd
// if is parent then we need special case where we cannot remove parent
// special case if last merge
// case if k == 1 -> 0
struct segment_tree {
  int a[2 * lim2], size = lim2;
  segment_tree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    a[idx + size] = val;
    while(idx > 1) {
      idx /= 2;
      a[idx] = min(a[2 * idx], a[2 * idx + 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    int m = (cl + cr) / 2;
    if(cl > r || cr < l)
      return INT_MAX;
    else if(cl >= l && cr <= r)
      return a[nd];
    else
      return min(query(2 * nd, cl, m, l, r), query(2 * nd + 1, m + 1, cr, l, r));
  }
  int query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }
};
int ett[lim], sz[lim], depth[lim], par[lim], val[lim], in[lim], out[lim], root[lim], binlift[lim][20], t;
vector<int> edges[lim], child[lim];
bool vis[lim];
void dfs_child(int nd = 0) {
  vis[nd] = 1;
  int cur = par[nd];
  binlift[nd][0] = cur;
  for(int i = 1; i < 20; ++i) {
    cur = binlift[cur][i - 1];
    binlift[nd][i] = cur;
  }
  for(auto i : edges[nd]) {
    if(!vis[nd])
      par[i] = nd, child[nd].pb(i), dfs_child(i);
  }
}
void dfs_sz(int nd = 0) {
  sz[nd] = 1;
  for(auto &u : child[nd]) {
    depth[u] = depth[nd] + 1;
    dfs_sz(u);
    sz[nd] += sz[u];
    if(sz[u] > sz[child[nd][0]])
      swap(u, child[nd][0]);
  }
}
void dfs_ett(int nd = 0, int idx = 0) {
  ett[nd] = idx;
  for(auto i : child[nd]) {
    dfs_ett(i, idx + 1);
    idx += sz[i];
  }
}

void dfs_hld(int nd = 0) {
  in[nd] = t++;
  for(auto u : child[nd]) {
    root[u] = (u == child[nd][0] ? root[nd] : u);
    dfs_hld(u);
  }
  out[nd] = t;
}
segment_tree segtree;
void update(int nd, int x) {
  segtree.update(in[nd], x);
}
int query(int u, int v) {
  int ans = -1;
  while(root[u] != root[v]) {
    if(depth[root[u]] > depth[root[v]]) 
      swap(u, v);
      ans = max(ans, segtree.query(in[root[v]], in[v]));
      v = par[root[v]];
    }
    if (depth[u] > depth[v]) {
    swap(u, v);
    }
    ans = max(ans, segtree.query(in[u], in[v]));
    return ans;
}
int lca(int u, int v) {
  if(depth[u] < depth[v])
    swap(u, v);
  for(int i = 19; i >= 0; --i) {
    if(depth[u] - depth[v] >= 1 << i)
      u = binlift[u][i];
  }
  if(u == v)
    return u;
  for(int i = 19; i >= 0; --i) {
    if(binlift[u][i] != binlift[v][i])
      u = binlift[u][i], v = binlift[v][i];
  }
  return par[u];
}
int n;
void precomp() {
  dfs_child();
  dfs_sz();
  dfs_ett();
  dfs_hld();
}
void init(std::vector<int> C, std::vector<int> U, std::vector<int> V) {
  n = C.size();
  for(int i = 0; i < n - 1; ++i)
    edges[U[i]].pb(V[i]), edges[V[i]].pb(U[i]);
  precomp();
}
bool comp(int a, int b) {
  return ett[a] < ett[b];
}
struct dp {
  int nd, target;
  long long zero = 0, one = 0;
  dp(int a, int b) {
    nd = a, target = b;
  }
  bool operator<(const dp& a) const {
    return true;
  }
};
long long kerugian_minimum(std::vector<int> P) {
  sort(P.begin(), P.end());
  for(auto i : P) {
    if(binary_search(P.begin(), P.end(), par[i]))
      return -1;
  }
  if(P.size() == 1)
    return 0;
  else {
    // sort P based on position in ett
    // case -> di root of query, tempat merging ada di P
    sort(P.begin(), P.end(), comp);
    set<int> f;
    for(auto i : P)
      f.ins(i);
    // fi -> position, se -> node
    set<pair<int, int>> s;
    for(int i = 0; i < P.size(); ++i)
      s.ins(mp(ett[i], P[i]));
    // fi -> depth in negative
    // se.fi -> node
    // se.se -> target 
    set<pair<int, dp>> l;
    for(auto it = s.begin(); it != s.end(); ++it) {
      int mlca = 0, mnode = 0;
      if(it != s.begin()) {
        _Rb_tree_const_iterator tmp = it;
        --tmp;
        int tmp2 = lca((*it).se, (*tmp).se);
        if(depth[tmp2] > mlca)
          mlca = depth[tmp2], mnode = tmp2;
      }
      if(it != --s.end()) {
        _Rb_tree_const_iterator tmp = it;
        ++tmp;
        int tmp2 = lca((*it).se, (*tmp).se);
        if(depth[tmp2] > mlca)
          mlca = depth[tmp2], mnode = tmp2;
      }
      l.ins(mp(-mlca, dp(0, 0)));
    }
    map<int, vector<dp>> a;
    while(l.size() > 1) {
      int maxi = -(*l.begin()).fi;
      while(l.size() && (*l.begin()).fi == -maxi) {
        a[(*l.begin()).se.target].pb((*l.begin()).se);
        s.erase(s.lb(mp(ett[(*l.begin()).se.nd], 0)));
        l.erase(l.begin());
      }
      // merge all the a
      // each merge will have 2 states, a off and on state
      // on state means one of them is still active
      // off state means non are active
      if(a.size() == 1 && !l.size()) {
        bool isi = 0;
        for(auto i : a) {
          for(auto j : i.se)
            if(j.nd == i.fi) 
              isi = 1;
        }
        ll res = 0;
        if(isi) {
          // cari min dari semua anak antara 1 state atau 0 state
          for(auto i : a) {
            for(auto j : i.se) {
              if(j.nd != i.fi) {
                int second_nd = j.nd;
                for(int k = 19; k >= 0; --k) {
                  if(depth[binlift[second_nd][k]] > depth[i.fi])
                    second_nd = binlift[second_nd][k];
                }
                if(j.nd == second_nd)
                  res += j.zero;
                else
                  res += min(j.zero, j.one + query(par[j.nd], second_nd));
              }
            }
          }
        }
        // buat 0 state dan 1 state
        // kita boleh pilih antara remove root and all problems solved atau buat set of 0 and 1
        // di set of 0 and 1 pilih yang paling optimal
        else {
          ll tmp_res;
          // get 0 state and get 1 state values
          // choose the 0 state that grants maximum
          // or destroy the root
          vector<int> zero, one;
          for(auto i : a) {
            for(auto j : i.se)
              zero.pb(j.zero), one.pb(j.one);
          }
          // get sum of zero
          ll zero_sum = 0;
          for(auto i : zero)
            zero_sum += i;
          zero.clear();
          tmp_res = zero_sum + query((*a.begin()).fi, (*a.begin()).fi);
          for(auto i : a) {
            for(auto j : i.se) {
              // actually try and get more optimal zero value
              int second_nd = j.nd;
              for(int k = 19; k >= 0; --k) {
                if(depth[binlift[second_nd][k]] > depth[i.fi])
                  second_nd = binlift[second_nd][k];
              }
              ll best;
              if(j.nd == second_nd)
                best = j.zero;
              else
                best = min(j.zero, j.one + query(par[j.nd], second_nd));
              zero.pb(best);
            }
          }
          zero_sum = 0; ll highest = 0;
          for(int i = 0; i < zero.size(); ++i) {
            highest = max(highest, 0ll + one[i] - zero[i]);
            zero_sum += zero[i];
          }
          res = max(tmp_res, 0ll + zero_sum - highest);
        }
        return res;
      }
      else {
        for(auto i : a) {
          vector<dp> tmp = i.se;
          int nd = i.fi;
          bool isi = 0;
          for(auto j : tmp)
            if(j.nd == nd)
              isi = 1;
          if(isi) {
            // get 1 state
          }
          else {
            // get 0 state and 1 state 
          }
          // add ke pos
        }
      }
    }
    // query tiap depth barengan, simpan nodes di map, iterate through map
  }
  return 42;
}