#include "adventure.h"

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
vector<pair<int, char>> edges[lim];
// cl -> simpan edge terdekat
// simpan node, bukan depth
int k;
int depth[lim], cl[26][lim], par[17][lim], lowd[lim];
ll cost[17][lim];
bool vis[lim];
void dfs(int nd) {
  vis[nd] = 1;
  bool valid = 1;
  pair<int, int> mn = mp(1000000, 10000000);
  for(int j = 0; j < k; ++j) {
    // cri yg depth paling rendah, lowd nya di situ
    if(cl[j][nd] == -1) {
      // no answer
      valid = 0;
    }
    else {
      // cri yg depth paling rendah
      mn = min(mn, mp(depth[cl[j][nd]], cl[j][nd]));
    }
  }
  if(valid) {
    // berarti lowdnya di mx.se
    // simpan cost ke parent nya itu berapa
    lowd[nd] = mn.se;
    cost[0][nd] = depth[lowd[nd]];
  }
  else
    lowd[nd] = -1;
  for(int i = 1; i < 17; ++i)
    par[i][nd] = par[i - 1][par[i - 1][nd]];
  for(int i = 1; i < 17; ++i) {
    cost[i][nd] = cost[i - 1][nd] + cost[i - 1][par[i - 1][nd]];
  }
  //cout << nd << " " << depth[nd] << " " << lowd[nd] << endl;
  for(auto i : edges[nd]) {
    if(!vis[i.fi]) {
      depth[i.fi] = depth[nd] + 1;
      par[0][i.fi] = nd;
      for(int j = 0; j < k; ++j) {
        cl[j][i.fi] = cl[j][nd];
      }
      cl[i.se - 'a'][i.fi] = nd;
      dfs(i.fi);
    }
  }
}
int lca(int u, int v) {
  if(depth[u] > depth[v]) 
    swap(u, v);
  //cout << u << " " << v << endl;
  for(int i = 16; i >= 0; --i) {
    if(depth[par[i][v]] >= depth[u])
      v = par[i][v];
  }
  //cout << u << " " << v << endl;
  if(u == v) {
    return u;
  }
  for(int i = 16; i >= 0; --i) {
    if(par[i][v] != par[i][u])
      v = par[i][v], u = par[i][u];
  }
  return par[0][u];
}
std::vector<long long> count_subpaths(int N, int K, int Q, std::vector<int> U,
                                      std::vector<int> V, std::vector<char> C,
                                      std::vector<int> X, std::vector<int> Y) {
  k = K;
  memset(cl, -1, sizeof(cl));
  for(int i = 0; i < N - 1; ++i)
    ++U[i], ++V[i];
  for(int i = 0; i < Q; ++i)
    ++X[i], ++Y[i];
  depth[1] = 1;
  for(int i = 0; i < N - 1; ++i) {
    edges[U[i]].push_back(mp(V[i], C[i]));
    edges[V[i]].push_back(mp(U[i], C[i]));
  }
  dfs(1);
  vector<ll> ans;
  for(int e = 0; e < Q; ++e) {
    int x = X[e], y = Y[e];
    // mau cari dr x sm y
    // cari lca
    int root = lca(x, y);
    int xm = x, ym = y;
    for(int i = 16; i >= 0; --i) {
      // calculate buat x sendiri
      if(depth[lowd[par[i][xm]]] >= depth[root]) {
        xm = par[i][xm];
      }
      if(depth[lowd[par[i][ym]]] >= depth[root]) {
        ym = par[i][ym];
      }
    }
    // calculate sampe ke dr x ke xm dan y ke ym
    ll res = 0;
    for(int i = 16; i >= 0; --i) {
      if(depth[par[i][x]] >= depth[xm]) {
        res += cost[i][x], x = par[i][x];
      }
      if(depth[par[i][y]] >= depth[ym]) {
        res += cost[i][y], y = par[i][y];
      }
    }
    x = X[e], y = Y[e];
    //cout << x << " "  << xm << " " << y << " " << ym << endl;
    //cout << "PRE ALL " << res << endl;
    //cout << depth[root] << " " << depth[x] << " " << depth[xm] << " " << depth[y] << " " << depth[ym] << endl;
    res -= 1ll * (depth[root] - 1) * (depth[x] - depth[xm] + depth[y] - depth[ym]);
    //cout << "MID " << res << endl;
    //cout << xm << " " << lowd[xm] << endl;
    if(depth[lowd[xm]] >= depth[root])
      res += depth[lowd[xm]] - depth[root] + 1;
    if(depth[lowd[ym]] >= depth[root])
      res += depth[lowd[ym]] - depth[root] + 1;
    //cout << "PRE ADD " << res << endl;
    //cout << x << " " << y << " " << root << endl;
    // intinya left exists sm right exists (bukan line)
    if(root != x && root != y) {
      // calculate gabungan dua"nya
      // coba sebanyak cntl
      // nanti reduce complexity by K
      // fi -> depth, se -> char number
      // nanti K^2+KlogN
      // pairing tiap r nanti sm l yg mana
      vector<pair<int, int>> l, r;
      for(int i = 0; i < k; ++i) {
        int tmp = x;
        for(int j = 16; j >= 0; --j) {
          if(cl[i][par[j][tmp]] != -1 && depth[cl[i][par[j][tmp]]] >= depth[root])
            tmp = par[j][tmp];
        }
        if(cl[i][tmp] != -1 && depth[cl[i][tmp]] >= depth[root])
          l.push_back(mp(depth[tmp], i));
      }
      for(int i = 0; i < k; ++i) {
        int tmp = y;
        for(int j = 16; j >= 0; --j) {
          if(cl[i][par[j][tmp]] != -1 && depth[cl[i][par[j][tmp]]] >= depth[root])
            tmp = par[j][tmp];
        }
        if(cl[i][tmp] != -1 && depth[cl[i][tmp]] >= depth[root])
          r.push_back(mp(depth[tmp], i));
      }
      sort(l.begin(), l.end());
      sort(r.begin(), r.end());
      for(int i = 0; i < l.size(); ++i) {
        // i -> count yg mau on
        // utk tiap "benda" cari first occur di mana
        bool done[k];
        memset(done, 0, sizeof(done));
        int cnt = 0;
        for(int j = 0; j <= i; ++j)
          done[l[j].se] = 1, ++cnt;
        if(cnt == k) {
          // semua r valid
          // pasti udah last element of l
          //cout << res << endl;
          //cout << (depth[y] - depth[root]) << " " << (depth[x] - l[i].fi + 1) << endl;
          res += 1ll * (depth[y] - depth[root]) * (depth[x] - l[i].fi + 1);
          //cout << res << endl;
          continue;
        }
        for(int j = 0; j < r.size(); ++j) {
          if(!done[r[j].se])
            done[r[j].se] = 1, ++cnt;
          if(cnt == k) {
            res += 1ll * (depth[y] - r[j].fi + 1) * ((i == l.size() - 1 ? depth[x] + 1 : l[i + 1].fi) - l[i].fi);
            break;
          }
        }
        //res += 1ll * (depth[y] - depth[root]) * (depth[x] - depth[root]);
        //assert(res == 1ll * (depth[y] - depth[root] + depth[x] - depth[root] + 1) * (depth[y] - depth[root] + depth[x] - depth[root] + 2) / 2);
      }
    }
    //res = 1ll * (depth[y] - depth[root] + depth[x] - depth[root] + 1) * (depth[y] - depth[root] + depth[x] - depth[root]) / 2;
    ans.push_back(res);
  }
  // nanti binlift buat cri yg internal, buat yg g setara nnti cari first index yg ada new
  return ans;
}
