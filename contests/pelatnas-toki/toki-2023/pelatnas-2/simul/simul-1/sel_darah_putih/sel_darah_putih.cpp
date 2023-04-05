#include "sel_darah_putih.h"
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int lim = 1 << 18;
// nlog^2
struct segment_tree {
  int a[2 * lim];
  segment_tree() {
    memset(a, 0, sizeof(a));
  }
  void update(int nd, int cl, int cr, int l, int r, int val) {
    if(cl >= l && cr <= r) {
      a[nd] += val;
      return;
    }
    else if(cl > r || cr < l)
      return;
    else {
      int mid = (cl + cr) / 2;
      update(2 * nd, cl, mid, l, r, val);
      update(2 * nd + 1, mid + 1, cr, l, r, val);
    }
  }
  void update(int l, int r, int val) {
    update(1, 0, lim - 1, l, r, val);
  }
  // do something about the fact that it is range update point query
  // buat segment tree yg bs range update point query in O(log) exact same with this
  int query(int nd, int cl, int cr, int idx) {
    if(cl == cr)
      return a[nd];
    else {
      int mid = (cl + cr) / 2;
      if(idx <= mid)
        return a[nd] + query(2 * nd, cl, mid, idx);
      else
        return a[nd] + query(2 * nd + 1, mid + 1, cr, idx);
    }
  }
};
// HLD -> buat head tiap HLD
// buat binlift
// pilih subtree dengan node yang paling besar
// cari LCA yang punya angka 1 yang terdekat pakai metode binlift
// update tiap node di HLD pake seg
bool vis[lim];
int par[18][lim], subtree[lim], hld[lim], head[lim], depth[lim];
vector<int> edges[lim], child[lim];
// ada hld head, ada hld index
// get par and subtree size
void dfs(int nd) {
  vis[nd] = 1;
  //cout << nd << endl;
  for(int i = 1; i < 18; ++i) {
    par[i][nd] = par[i - 1][par[i - 1][nd]];
  }
  subtree[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      par[0][i] = nd;
      child[nd].pb(i);
      depth[i] = depth[nd] + 1;
      dfs(i);
      subtree[nd] += subtree[i];
    }
  }
}
void dfs2(int nd) {
  //cout << nd << endl;
  //for(auto i : child[nd])
  //  cout << i << " ";
  //cout << endl;
  for(int i = 0; i < child[nd].size(); ++i) {
    dfs2(child[nd][i]);
    if(subtree[child[nd][i]] > subtree[child[nd][0]])
      swap(child[nd][i], child[nd][0]);
  }
}
int t = 0;
void dfs3(int nd) {
  //cout << "DFS3 " << nd << endl;
  hld[nd] = t++;
  for(int i = 0; i < child[nd].size(); ++i) {
    if(i == 0) {
      head[child[nd][i]] = head[nd];
    }
    else {
      head[child[nd][i]] = child[nd][i];
    }
    dfs3(child[nd][i]);
  }
}
segment_tree seg;
void update_hld(int x, int y, int val) {
  // update from x to y val
  //cout << "UPDATE " << x << " " << y << endl;
  while(depth[head[x]] > depth[y]) {
    // continue to next decomp
    //cout << "CONTINUE " << hld[x] << " " << hld[x] - depth[x] + depth[head[x]] << " " << par[0][head[x]] << endl;
    seg.update(hld[x] - depth[x] + depth[head[x]], hld[x], val);
    x = par[0][head[x]];
  }
  // we are ending it in this decomp !!!
  //cout << "CUR DECOMP " << hld[x] << " " << hld[x] - depth[x] + depth[y] << endl;
  seg.update(hld[x] - depth[x] + depth[y], hld[x], val);
}
set<int> occur[200005];
int color[200005];
int get_lca(int x, int color) {
  // find
  for(int i = 17; i >= 0; --i) {
    if(par[i][x] == 0)
      continue;
    // cari highest yang ga memenuhi
    //cout << "GET LCA " << par[i][x] << " " << hld[par[i][x]] << " " << hld[par[i][x]] + subtree[par[i][x]] << endl;
      //cout << "EXTRA " << *occur[color].lower_bound(hld[par[i][x]]) << endl;
    if(occur[color].size() == 0 || occur[color].lower_bound(hld[par[i][x]]) == occur[color].end() || *occur[color].lower_bound(hld[par[i][x]]) >= hld[par[i][x]] + subtree[par[i][x]])
      x = par[i][x];
  }
  return x;
}
void init(int N, vector<int> u, vector<int> v, int K, vector<int> c) {
  // no reassign -> 2 set<int>, set<int> nya di merge
  // size set<int> -> answer
  // dia sama seperti operasi OR
  // mau cari hasil "bitwise OR" dr segment?
  // tp bitnya ada 2e5
  // update dimana? cari LCA yg ada i di mana
  // nanti update dr node sekarang ke LCAitu
  // kalo buat deletion jg cari LCA terdekat dimana
  // pake LCA buat tau update segment tree mana aja, jadi cuman perlu maintain count :D
  // nanti update yg O(log^2) pake HLD
  // maintain LCA di mana
  // find LCA quickly?
  // binser based on binlift aja pake teknik LCA normal cmn cari keberadaan nilai X di tempatnya dia
  // cari color ada atau ngga -> maintain tiap color di set, terus nanti cari lb itu <= ett nya atau ngga
  // query O(log)
  // butuh HLD but only range sum lazy update buat query hasil di akhir
  // actually gaperlu lazy, tinggal cari sum dari root ke path :D
  for(int i = 0; i < N - 1; ++i)
    edges[u[i]].push_back(v[i]), edges[v[i]].push_back(u[i]);
  depth[1] = 1;
  dfs(1);
  //cout << "DFS" << endl;
  dfs2(1);
  //cout << "DFS" << endl;
  head[1] = 1;
  dfs3(1);
  //cout << "DFS" << endl;
  for(int i = 0; i < N; ++i) {
    // belum tentu ada update
    int x = i + 1;
    if(occur[c[i]].size() && occur[c[i]].lower_bound(hld[x]) != occur[c[i]].end() 
    && *occur[c[i]].lower_bound(hld[x]) < hld[x] + subtree[x]) {

    }
    else {
      int tmp = get_lca(i + 1, c[i]);
      update_hld(i + 1, tmp, 1);
    }
    //cout << i + 1 << " " << tmp << endl;
    occur[c[i]].insert(hld[i + 1]);
    color[i + 1] = c[i];
  }
  //cout << "SET VALUES" << endl;
  //for(int i = 1; i <= N; ++i)
  //  cout << hld[i] << " ";
  //cout << endl;
  // construct tree
  // TO DO

  // construct assignments
  // TO DO
  // use pending update?
  // count of 0 inside a segment
  // tiap perubahan -> update tiap parent -> HLD
  // how to update tiap parent?
  // atau tiap parent yang query anaknya
  // masalah: colornya bs banyak
  // klo update tiap parent pake HLD, anggep aja update inside a 2d segment tree/using map bisa O(log^2)
  // problem -> can't find count
  // solution -> use map, trus nanti tinggal count aja !!!
  // update count of every parent, lazy segment update bs lgsg -1 for everything
  // implement HLD gmn yah dah lama :"D logic aja deh
  // count of unique???
  // how???
  return;
}

void reassign(int u, int k) {
  // assign k to u
  // TO DO
  // hapus occur
  // insert occur
  occur[color[u]].erase(occur[color[u]].find(hld[u]));
  if(occur[color[u]].size() && occur[color[u]].lower_bound(hld[u]) != occur[color[u]].end() 
  && *occur[color[u]].lower_bound(hld[u]) < hld[u] + subtree[u]) {
    // ada yang di childnya, jadi gaperlu update
  }
  else {
    int tmp = get_lca(u, color[u]);
    update_hld(u, tmp, -1);
  }
  color[u] = k;
  if(occur[color[u]].size() && occur[color[u]].lower_bound(hld[u]) != occur[color[u]].end() 
  && *occur[color[u]].lower_bound(hld[u]) < hld[u] + subtree[u]) {
    // ada yang di childnya, jadi gaperlu update
  }
  else {
    int tmp = get_lca(u, color[u]);
    update_hld(u, tmp, 1);
  }
  occur[color[u]].insert(hld[u]);
  return;
}

int reinforce(int u) {
  // reinforce to node u
  // TO DO
  return seg.query(1, 0, lim - 1, hld[u]);
}