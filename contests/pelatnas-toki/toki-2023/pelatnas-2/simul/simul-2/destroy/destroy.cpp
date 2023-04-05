#include "destroy.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool vis[lim], dstpar[lim], dstind[lim];
bool has_answer = 1;
void dfs(int nd) {
  vis[nd] = 1;
  int wpar = 0, ind = 0, bt = 0;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
      if(dstpar[i] && dstind[i])
        ++bt;
      else if(dstpar[i])
        ++wpar;
      else if(dstind[i])
        ++ind;
      else
        has_answer = 0;
    }
  }
  if(nd == 1) {
    // cmn perlu dstpar aja
    if((wpar % 2 == 0) || bt)
      dstpar[nd] = 1;
  }
  else {
    // klo mau parent yg wpar harus even atau boleh di assist sm yg bt
    if((wpar % 2 == 0) || bt)
      dstpar[nd] = 1;
    // kalo mau destroy parent, berarti yg wpar harus odd
    if((wpar & 1) || bt)
      dstind[nd] = 1;
  }
}
vector<int> ret;
void solve(int nd, bool par_edge = 0) {
  vis[nd] = 1;
  vector<int> wpar, ind, bt;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      if(dstpar[i] && dstind[i])
        bt.push_back(i);
      else if(dstpar[i])
        wpar.push_back(i);
      else
        ind.push_back(i);
    }
  }
  // nah nanti di sini
  // hancurkan edge sampai sisanya itu ganjil klo par_dest
  if((wpar.size() + par_edge) & 1)
    wpar.push_back(bt.back());
  // nah berarti sekarang yg wpar itu di destroy barengan sama parent, sisanya di destroy duluan
  for(auto i : ind)
    solve(i, 1);
  for(auto i : bt)
    solve(i, 1);
  ret.push_back(nd);
  for(auto i : wpar)
    solve(i, 0);
}

std::vector<int> destroy(int N, std::vector<int> U, std::vector<int> V) {
  for(int i = 0; i < N - 1; ++i) {
    edges[U[i]].push_back(V[i]);
    edges[V[i]].push_back(U[i]);
  }
  dfs(1);
  if(!dstpar[1] || !has_answer) {
    // no answer
    vector<int> ans;
    for(int i = 0; i < N; ++i)
      ans.push_back(-1);
    return ans;
  }
  // ada, berarti nanti tinggal bagi jadi beberapa grup
  // trus recursively solve aja
  memset(vis, 0, sizeof(vis));
  solve(1);
  return ret;
}
