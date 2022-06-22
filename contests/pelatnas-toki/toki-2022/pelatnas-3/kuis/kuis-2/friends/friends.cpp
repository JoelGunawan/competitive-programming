#include "friends.h"

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int mod = 1e9 + 7;
struct node {
  // fi -> count of on
  // se -> length of subarray
  int l_even_odd = 0, l_odd_even = 0, l_odd_odd = 0, l_even_even = 0, 
  r_even_odd = 0, r_odd_even = 0, r_odd_odd = 0, r_even_even = 0, 
  // l_r is always length of (r - l) + 1
  // and there is only 1 l_r
  // it is either even or odd len
  l_r_odd_odd = 0, l_r_odd_even = 0, l_r_even_even = 0, l_r_even_odd = 0
  , cnt = 0;
  // cnt -> propagate to top
  node *l, *r;
};
const int lim = 1e5 + 5;
struct dynamic_segment_tree {
  node *head = new node();
  int size, node_cnt = 0;
  vector<pair<node*, int>> merging;
  void update(node *cur, int cl, int cr, node *upd) {
    int mid = (cl + cr) >> 1;
    if(cl == mid) {
      if(upd->l && upd->l->l_r_odd_odd)
        cur->l = upd->l;
      else
        delete upd->l;
    }
    else if(upd->l) {
      if(!cur->l)
        cur->l = upd->l;
      else
        update(cur->l, cl, mid, upd->l);
    }
    if(mid + 1 == cr) {
      if(upd->r && upd->r->l_r_odd_odd)
        cur->r = upd->r;
      else
        delete upd->r;
    }
    else if(upd->r) {
      if(!cur->r)
        cur->r = upd->r;
      else {
        update(cur->r, mid + 1, cr, upd->r);
      }
    }
    if(!cur->l) {
      cur->l = new node();
      ++node_cnt;
      int len = mid - cl + 1;
      // give default values
      cur->l->l_even_odd = len >> 1;
      cur->l->r_even_odd = len >> 1;
      if(len > 0) {
        cur->l->l_even_even = (len - 1) >> 1;
        cur->l->r_even_even = (len - 1) >> 1;
      }
      if(len & 1)
        cur->l->l_r_even_odd = 1;
      else
        cur->l->l_r_even_even = 1;
    }
    if(!cur->r) {
      cur->r = new node();
      ++node_cnt;
      int len = cr - mid;
      cur->r->l_even_odd = len >> 1;
      cur->r->r_even_odd = len >> 1;
      if(len > 0) {
        cur->r->l_even_even = (len - 1) >> 1;
        cur->r->r_even_even = (len - 1) >> 1;
      }
      if(len & 1)
        cur->r->l_r_even_odd = 1;
      else
        cur->r->l_r_even_even = 1;
    }
    delete upd;
    // merge both child and count value
    // merge L, R
    cur->l_r_even_even = cur->l->l_r_even_even * cur->r->l_r_even_even + cur->l->l_r_even_odd * cur->r->l_r_even_odd
    + cur->l->l_r_odd_even * cur->r->l_r_odd_even + cur->l->l_r_odd_odd * cur->r->l_r_odd_odd;
    cur->l_r_even_odd = cur->l->l_r_even_odd * cur->r->l_r_even_even + cur->l->l_r_even_even * cur->r->l_r_even_odd
    + cur->l->l_r_odd_even * cur->r->l_r_odd_odd + cur->l->l_r_odd_odd * cur->r->l_r_odd_even;
    cur->l_r_odd_even = cur->l->l_r_odd_even * cur->r->l_r_even_even + cur->l->l_r_even_even * cur->r->l_r_odd_even
    + cur->l->l_r_even_odd * cur->r->l_r_odd_odd + cur->l->l_r_odd_odd * cur->r->l_r_even_odd;
    cur->l_r_odd_odd = cur->l->l_r_odd_even * cur->r->l_r_even_odd + cur->l->l_r_even_even * cur->r->l_r_odd_odd
    + cur->l->l_r_even_odd * cur->r->l_r_odd_even + cur->l->l_r_odd_odd * cur->r->l_r_even_even;
    //cout << "NODE" << endl;
    //cout << cl << " " << cr << endl;
    //cout << cur->l->l_r_odd_odd << " " << cur->r->l_r_odd_odd << endl;
    //cout << cur->l->l_r_odd_even << " " << cur->r->l_r_odd_even << endl;
    //cout << cur->l->l_r_even_odd << " " << cur->r->l_r_even_odd << endl;
    //cout << cur->l->l_r_even_even << " " << cur->r->l_r_even_even << endl;
    //cout << cur->l_r_even_even << " " << cur->l_r_even_odd << " " << cur->l_r_odd_even << " " << cur->l_r_odd_odd << endl;
    // merge L
    cur->l_even_even = (0ll + cur->l->l_r_even_even + cur->l->l_even_even + 1ll * cur->l->l_r_even_even * cur->r->l_even_even + 1ll * cur->l->l_r_even_odd * cur->r->l_even_odd
    + 1ll * cur->l->l_r_odd_even * cur->r->l_odd_even + 1ll * cur->l->l_r_odd_odd * cur->r->l_odd_odd) % mod;
    cur->l_even_odd = (0ll + cur->l->l_r_even_odd + cur->l->l_even_odd + 1ll * cur->l->l_r_even_odd * cur->r->l_even_even + 1ll * cur->l->l_r_even_even * cur->r->l_even_odd
    + 1ll * cur->l->l_r_odd_odd * cur->r->l_odd_even + 1ll * cur->l->l_r_odd_even * cur->r->l_odd_odd) % mod;
    cur->l_odd_even = (0ll + cur->l->l_r_odd_even + cur->l->l_odd_even + 1ll * cur->l->l_r_odd_even * cur->r->l_even_even + 1ll * cur->l->l_r_odd_odd * cur->r->l_even_odd
    + 1ll * cur->l->l_r_even_even * cur->r->l_odd_even + 1ll * cur->l->l_r_even_odd * cur->r->l_odd_odd) % mod;
    cur->l_odd_odd = (0ll + cur->l->l_r_odd_odd + cur->l->l_odd_odd + 1ll * cur->l->l_r_even_even * cur->r->l_odd_odd + 1ll * cur->l->l_r_even_odd * cur->r->l_odd_even
    + 1ll * cur->l->l_r_odd_even * cur->r->l_even_odd + 1ll * cur->l->l_r_odd_odd * cur->r->l_even_even) % mod;
    //cout << cur->l_even_even << " " << cur->l_even_odd << " " << cur->l_odd_even << " " << cur->l_odd_odd << endl;
    // merge R
    cur->r_even_even = (0ll + cur->r->l_r_even_even + cur->r->r_even_even + cur->r->l_r_even_even * cur->l->r_even_even + cur->r->l_r_even_odd * cur->l->r_even_odd
    + cur->r->l_r_odd_even * cur->l->r_odd_even + cur->r->l_r_odd_odd * cur->l->r_odd_odd) % mod;
    cur->r_even_odd = (0ll + cur->r->l_r_even_odd + cur->r->r_even_odd + cur->r->l_r_even_odd * cur->l->r_even_even + cur->r->l_r_even_even * cur->l->r_even_odd
    + cur->r->l_r_odd_odd * cur->l->r_odd_even + cur->r->l_r_odd_even * cur->l->r_odd_odd) % mod;
    cur->r_odd_even = (0ll + cur->r->l_r_odd_even + cur->r->r_odd_even + cur->r->l_r_odd_even * cur->l->r_even_even + cur->r->l_r_odd_odd * cur->l->r_even_odd
    + cur->r->l_r_even_even * cur->l->r_odd_even + cur->r->l_r_even_odd * cur->l->r_odd_odd) % mod;
    cur->r_odd_odd = (0ll + cur->r->l_r_odd_odd + cur->r->r_odd_odd + 1ll * cur->r->l_r_even_even * cur->l->r_odd_odd + 1ll * cur->r->l_r_even_odd * cur->l->r_odd_even
    + 1ll * cur->r->l_r_odd_even * cur->l->r_even_odd + 1ll * cur->r->l_r_odd_odd * cur->l->r_even_even) % mod;
    //cout << cur->r_even_even << " " << cur->r_even_odd << " " << cur->r_odd_even << " " << cur->r_odd_odd << endl;
    // merge C
    // antara R di kiri dan L di kanan doang
    cur->cnt = (0ll + cur->l->cnt + cur->r->cnt + 1ll * cur->l->r_even_even * cur->r->l_odd_even + 1ll * cur->l->r_even_odd * cur->r->l_odd_odd
    + 1ll * cur->l->r_odd_even * cur->r->l_even_even + 1ll * cur->l->r_odd_odd * cur->r->l_even_odd + cur->l->r_odd_even + cur->r->l_odd_even) % mod;
    //cout << cur->cnt << endl;
  }
  void get(node *nd, int cl, int cr) {
    if(cl == cr && nd->l_r_odd_odd)
      merging.push_back({nd, cl});
    else {
      int mid = (cl + cr) >> 1;
      if(nd->l)
        get(nd->l, cl, mid);
      if(nd->r)
        get(nd->r, mid + 1, cr);
      delete nd;
    }
  }
  void update(node *cur, int idx, int cl, int cr, node *upd) {
    if(cl == cr) {
      cur = upd;
    }
    else {
      int mid = (cl + cr) >> 1;
      if(!cur->l) {
        cur->l = new node();
        ++node_cnt;
        int len = mid - cl + 1;
        // give default values
        cur->l->l_even_odd = len >> 1;
        cur->l->r_even_odd = len >> 1;
        if(len > 0) {
          cur->l->l_even_even = (len - 1) >> 1;
          cur->l->r_even_even = (len - 1) >> 1;
        }
        if(len & 1)
          cur->l->l_r_even_odd = 1;
        else
          cur->l->l_r_even_even = 1;
      }
      if(!cur->r) {
        cur->r = new node();
        ++node_cnt;
        int len = cr - mid;
        cur->r->l_even_odd = len >> 1;
        cur->r->r_even_odd = len >> 1;
        if(len > 0) {
          cur->r->l_even_even = (len - 1) >> 1;
          cur->r->r_even_even = (len - 1) >> 1;
        }
        if(len & 1)
          cur->r->l_r_even_odd = 1;
        else
          cur->r->l_r_even_even = 1;
      }
      if(idx <= mid) {
        if(cl == mid)
          cur->l = upd;
        else
          update(cur->l, idx, cl, mid, upd);
      }
      else {
        if(mid + 1 == cr)
          cur->r = upd;
        else
          update(cur->r, idx, mid + 1, cr, upd);
      }
      // merge both child and count value
      // merge L, R
      cur->l_r_even_even = cur->l->l_r_even_even * cur->r->l_r_even_even + cur->l->l_r_even_odd * cur->r->l_r_even_odd
      + cur->l->l_r_odd_even * cur->r->l_r_odd_even + cur->l->l_r_odd_odd * cur->r->l_r_odd_odd;
      cur->l_r_even_odd = cur->l->l_r_even_odd * cur->r->l_r_even_even + cur->l->l_r_even_even * cur->r->l_r_even_odd
      + cur->l->l_r_odd_even * cur->r->l_r_odd_odd + cur->l->l_r_odd_odd * cur->r->l_r_odd_even;
      cur->l_r_odd_even = cur->l->l_r_odd_even * cur->r->l_r_even_even + cur->l->l_r_even_even * cur->r->l_r_odd_even
      + cur->l->l_r_even_odd * cur->r->l_r_odd_odd + cur->l->l_r_odd_odd * cur->r->l_r_even_odd;
      cur->l_r_odd_odd = cur->l->l_r_odd_even * cur->r->l_r_even_odd + cur->l->l_r_even_even * cur->r->l_r_odd_odd
      + cur->l->l_r_even_odd * cur->r->l_r_odd_even + cur->l->l_r_odd_odd * cur->r->l_r_even_even;
      //cout << "NODE" << endl;
      //cout << cl << " " << cr << endl;
      //cout << cur->l->l_r_odd_odd << " " << cur->r->l_r_odd_odd << endl;
      //cout << cur->l->l_r_odd_even << " " << cur->r->l_r_odd_even << endl;
      //cout << cur->l->l_r_even_odd << " " << cur->r->l_r_even_odd << endl;
      //cout << cur->l->l_r_even_even << " " << cur->r->l_r_even_even << endl;
      //cout << cur->l_r_even_even << " " << cur->l_r_even_odd << " " << cur->l_r_odd_even << " " << cur->l_r_odd_odd << endl;
      // merge L
      cur->l_even_even = (0ll + cur->l->l_r_even_even + cur->l->l_even_even + 1ll * cur->l->l_r_even_even * cur->r->l_even_even + 1ll * cur->l->l_r_even_odd * cur->r->l_even_odd
      + 1ll * cur->l->l_r_odd_even * cur->r->l_odd_even + 1ll * cur->l->l_r_odd_odd * cur->r->l_odd_odd) % mod;
      cur->l_even_odd = (0ll + cur->l->l_r_even_odd + cur->l->l_even_odd + 1ll * cur->l->l_r_even_odd * cur->r->l_even_even + 1ll * cur->l->l_r_even_even * cur->r->l_even_odd
      + 1ll * cur->l->l_r_odd_odd * cur->r->l_odd_even + 1ll * cur->l->l_r_odd_even * cur->r->l_odd_odd) % mod;
      cur->l_odd_even = (0ll + cur->l->l_r_odd_even + cur->l->l_odd_even + 1ll * cur->l->l_r_odd_even * cur->r->l_even_even + 1ll * cur->l->l_r_odd_odd * cur->r->l_even_odd
      + 1ll * cur->l->l_r_even_even * cur->r->l_odd_even + 1ll * cur->l->l_r_even_odd * cur->r->l_odd_odd) % mod;
      cur->l_odd_odd = (0ll + cur->l->l_r_odd_odd + cur->l->l_odd_odd + 1ll * cur->l->l_r_even_even * cur->r->l_odd_odd + 1ll * cur->l->l_r_even_odd * cur->r->l_odd_even
      + 1ll * cur->l->l_r_odd_even * cur->r->l_even_odd + 1ll * cur->l->l_r_odd_odd * cur->r->l_even_even) % mod;
      //cout << cur->l_even_even << " " << cur->l_even_odd << " " << cur->l_odd_even << " " << cur->l_odd_odd << endl;
      // merge R
      cur->r_even_even = (0ll + cur->r->l_r_even_even + cur->r->r_even_even + cur->r->l_r_even_even * cur->l->r_even_even + cur->r->l_r_even_odd * cur->l->r_even_odd
      + cur->r->l_r_odd_even * cur->l->r_odd_even + cur->r->l_r_odd_odd * cur->l->r_odd_odd) % mod;
      cur->r_even_odd = (0ll + cur->r->l_r_even_odd + cur->r->r_even_odd + cur->r->l_r_even_odd * cur->l->r_even_even + cur->r->l_r_even_even * cur->l->r_even_odd
      + cur->r->l_r_odd_odd * cur->l->r_odd_even + cur->r->l_r_odd_even * cur->l->r_odd_odd) % mod;
      cur->r_odd_even = (0ll + cur->r->l_r_odd_even + cur->r->r_odd_even + cur->r->l_r_odd_even * cur->l->r_even_even + cur->r->l_r_odd_odd * cur->l->r_even_odd
      + cur->r->l_r_even_even * cur->l->r_odd_even + cur->r->l_r_even_odd * cur->l->r_odd_odd) % mod;
      cur->r_odd_odd = (0ll + cur->r->l_r_odd_odd + cur->r->r_odd_odd + 1ll * cur->r->l_r_even_even * cur->l->r_odd_odd + 1ll * cur->r->l_r_even_odd * cur->l->r_odd_even
      + 1ll * cur->r->l_r_odd_even * cur->l->r_even_odd + 1ll * cur->r->l_r_odd_odd * cur->l->r_even_even) % mod;
      //cout << cur->r_even_even << " " << cur->r_even_odd << " " << cur->r_odd_even << " " << cur->r_odd_odd << endl;
      // merge C
      // antara R di kiri dan L di kanan doang
      cur->cnt = (0ll + cur->l->cnt + cur->r->cnt + 1ll * cur->l->r_even_even * cur->r->l_odd_even + 1ll * cur->l->r_even_odd * cur->r->l_odd_odd
      + 1ll * cur->l->r_odd_even * cur->r->l_even_even + 1ll * cur->l->r_odd_odd * cur->r->l_even_odd + cur->l->r_odd_even + cur->r->l_odd_even) % mod;
      //cout << cur->cnt << endl;
    }
  }
};
int sz;
struct disjoint_set {
  int head[lim], size[lim];
  dynamic_segment_tree a[lim];
  disjoint_set() {
    memset(head, -1, sizeof(head));
    fill(size, size + lim, 1);
  }
  int find_head(int nd) {
    while(head[nd] != -1)
      nd = head[nd];
    return nd;
  }
  bool merge(int x, int y) {
    x = find_head(x), y = find_head(y);
    if(x != y) {
      if(size[x] < size[y])
        swap(x, y);
      if(a[x].node_cnt < a[y].node_cnt) {
        swap(a[x], a[y]);
      }
      size[x] += size[y];
      head[y] = x;
      // merge every node of y to x
      // implement merging
      a[x].update(a[x].head, 0, sz, a[y].head);
    }
    return x != y;
  }
};
disjoint_set dsu;
vector<pair<int, int>> edges[lim];
bool vis[lim];
long long dfs(int nd) {
  vis[nd] = 1;
  int par_cost = 0;
  long long res = 0;
  for(auto i : edges[nd]) {
    if(!vis[i.first]) {
      res += dfs(i.first);
      dsu.merge(i.first, nd);
    }
    else
      par_cost = i.second;
  }
  node *tmp = dsu.a[dsu.find_head(nd)].head;
  //cout << nd << " " << (tmp->cnt + tmp->l_odd_even + tmp->r_odd_even + tmp->l_r_odd_even) << endl;
  return (res + 1ll * par_cost * ((0ll + tmp->cnt + tmp->l_odd_even + tmp->r_odd_even + tmp->l_r_odd_even) % mod)) % mod;
}
int pairing_sum(std::vector<int> U, std::vector<int> V, std::vector<int> W, std::vector<int> H) {
  int N = U.size() + 1;
  int M = H.size();
  for(int i = 0; i < N - 1; ++i) {
    edges[U[i]].push_back({V[i], W[i]});
    edges[V[i]].push_back({U[i], W[i]});
  }
  // initialize H[i] values
  sz = M - 1;
  for(int i = 0; i < M; ++i) {
    // add dynamic segment tree in ith index  
    node *tmp = new node();
    tmp->l_r_odd_odd = 1;
    //cout << "UPDATE " << H[i] << " " << i << endl;
    dsu.a[H[i]].update(dsu.a[H[i]].head, i, 0, M - 1, tmp);
  }
  // make a dynamic segment tree
  // merge in nodes * log(n)
  // each node in segment tree has 14 states? (since we need to maintain whether it's odd or even length segments)
  // try code O(m^2) solution first
  // in O(m^2), for each node, determine the count of children node
  // if it is odd, add count of odd segments
  return dfs(0);
}