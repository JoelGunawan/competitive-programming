#include "copper.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// for each button i maintain location of next button of type j
const int lim = 2e5 + 5;
bool vis[lim];
vector<int> edges[lim];
// fi -> risk taken
// se -> pos
pair<int, int> nxtU[17][lim], nxtD[17][lim];
int par[17][lim], depth[lim];
void dfs(int nd) {
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      
    }
  }
}
long long min_risk(int N, int M, int L, std::vector<int> U, std::vector<int> V,
                   std::vector<int> A, std::vector<int> S) {
  // nxtL and nxtR maintains the pos of the 2^i-th L/R buttons of the j-th button
  // full solution: lca both ways using the same concept
  vector<int> occ[N];
  for(int i = 0; i < M; ++i)
    occ[A[i]].pb(i);
  for(int i = 0; i < M; ++i) {
    int cur = A[i];
    // cout << i << endl;
    if(cur == N - 1)
      nxtR[0][i] = mp(-1, -1);
    else {
      if(lb(occ[cur + 1].begin(), occ[cur + 1].end(), i) == occ[cur + 1].end())
        nxtR[0][i] = mp(1, occ[cur + 1].front());
      else
        nxtR[0][i] = mp(0, *lb(occ[cur + 1].begin(), occ[cur + 1].end(), i));
    }
    if(cur == 0)
      nxtL[0][i] = mp(-1, -1);
    else {
      if(lb(occ[cur - 1].begin(), occ[cur - 1].end(), i) == occ[cur - 1].end())
        nxtL[0][i] = mp(1, occ[cur - 1].front());
      else
        nxtL[0][i] = mp(0, *lb(occ[cur - 1].begin(), occ[cur - 1].end(), i));
    }
  }
  // cout << "INIT BUILD DONE" << endl;
  for(int i = 1; i < 17; ++i) {
    for(int j = 0; j < M; ++j) {
      if(A[j] - (1 << i) >= 0)
        nxtL[i][j] = mp(nxtL[i - 1][j].fi + nxtL[i - 1][nxtL[i - 1][j].se].fi, nxtL[i - 1][nxtL[i - 1][j].se].se);
      else
        nxtL[i][j] = mp(-1, -1);
      if(A[j] + (1 << i) < N)
        nxtR[i][j] = mp(nxtR[i - 1][j].fi + nxtR[i - 1][nxtR[i - 1][j].se].fi, nxtR[i - 1][nxtR[i - 1][j].se].se);
      else
        nxtR[i][j] = mp(-1, -1);
    }
  }
  /*
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < M; ++j) {
      cout << nxtR[i][j].se << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < M; ++j) {
      cout << nxtR[i][j].fi << " ";
    }
    cout << endl;
  }
  */
  int cur = 0, curb = 0;
  ll res = 0;
  // cout << "TEST" << endl;
  for(auto x : S) {
    // go according to x
    if(x > cur) {
      // go right
      int diff = x - cur;
      for(int i = 16; i >= 0; --i) {
        if(diff - (1 << i) >= 0) {
          diff -= 1 << i;
          // cout << "moveR " << curb << " " << i << " " << nxtR[i][curb].fi << " " << nxtR[i][curb].se << endl;
          res += nxtR[i][curb].fi;
          curb = nxtR[i][curb].se;
        }
      }
    }
    else {
      // go left
      int diff = cur - x;
      for(int i = 16; i >= 0; --i) {
        if(diff - (1 << i) >= 0) {
          diff -= 1 << i;
          res += nxtL[i][curb].fi;
          // cout << "moveL " << i << " " << nxtL[i][curb].fi << " " << nxtL[i][curb].se << endl;
          curb = nxtL[i][curb].se;
        }
      }
    }
    cur = x;
  }
  return res;
}
