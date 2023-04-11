#include "chanek.h"

// header file
#include <bits/stdc++.h>
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
const int lim = 2e5 + 5;
bool vis2[lim];
vector<int> edges2[lim], child2[lim];
int par2[lim];
vector<pair<int, int>> cur2;
int color2[lim];
vector<pair<int, int>> group2[lim];
int magic2 = 60;
bool ret_wrong2 = 0;
void create_tree2(int nd = 0) {
    vis2[nd] = 1;
    if(cur2.size() < magic2)
        cur2.pb(mp(nd, cur2.size()));
    for(auto i : edges2[nd]) {
        if(!vis2[i])
            child2[nd].pb(i), create_tree2(i), par2[i] = nd;
    }
    // cari edge cur2 yg connection
}
// a.fi -> nd, a.se -> color2
void get_ans2(int nd, vector<pair<int, int>> a, vector<int> s) {
    // get answer ini cara dapetnya pake
    // finding     
    if(color2[nd] == -1) {
        for(int i = 0; i < a.size(); ++i) {
          if(a[i].fi == par2[nd])
            ++s[i];
        }
        int del_idx = 0;
        for(int i = 0; i < s.size(); ++i) 
            if(s[i] == 1) {
                del_idx = i;
            }
        int del_nd = a[del_idx].fi, del_c = a[del_idx].se;
        // cari edge yang hubungin ke sekarang
        a.erase(a.begin() + del_idx), s.erase(s.begin() + del_idx);
        for(int i = 0; i < a.size(); ++i) {
            int tmp = a[i].fi;
            if(binary_search(child2[tmp].begin(), child2[tmp].end(), del_nd) || par2[tmp] == del_nd) {
                --s[i];
                break;
            }
        }
        a.pb(mp(nd, del_c));
        s.pb(1);
        color2[nd] = del_c;
        //cout << "NEW GROUP" << endl;
        //for(auto i : a)
        //    cout << i.fi << " " << i.se << endl;
    }
    group2[nd] = a;
    for(auto i : child2[nd])
        get_ans2(i, a, s);
}
int ans[100];
bool vis3[lim];
vector<int> fin_group;
void proc_ans(int nd) {
  vis3[nd] = 1;
  ans[color2[nd]] = move(nd);
  for(auto i : edges2[nd]) {
    if(!vis3[i] && binary_search(fin_group.begin(), fin_group.end(), i)) {
      proc_ans(i);
      ans[color2[nd]] = move(nd);
    }
  }
}
long long findNumber(int N, int M, std::vector<int> A, std::vector<int> B,
                     int P, int V, int T) {
  for(int i = 0; i < M; ++i) {
      edges2[A[i]].pb(B[i]);
      edges2[B[i]].pb(A[i]);
  }
  for(int i = 0; i < N; ++i)
      sort(edges2[i].begin(), edges2[i].end());
  create_tree2();
  memset(color2, -1, sizeof(color2));
  for(auto i : cur2)
      color2[i.fi] = i.se;
  vector<int> tmp;
  par2[0] = -1;
  sort(cur2.begin(), cur2.end());
  for(int i = 0; i < magic2; ++i) {
      // buat vector indegree
      int nd = cur2[i].fi, cnt = 0;
      for(auto j : child2[nd]) {
          if(lb(cur2.begin(), cur2.end(), mp(j, 0)) != cur2.end() && (*lb(cur2.begin(), cur2.end(), mp(j, 0))).fi == j)
              ++cnt;
      }
      if(lb(cur2.begin(), cur2.end(), mp(par2[nd], 0)) != cur2.end() && (*lb(cur2.begin(), cur2.end(), mp(par2[nd], 0))).fi == par2[nd])
          ++cnt;
      tmp.pb(cnt);
      //cout << i << " " << cnt << endl;
  }
  get_ans2(0, cur2, tmp);
  for(int i = 0; i < group2[P].size(); ++i) {
    fin_group.pb(group2[P][i].fi);
  }
  sort(fin_group.begin(), fin_group.end());
  ans[color2[P]] = V;
  int nd = P;
  vis3[nd] = 1;
  for(auto i : edges2[nd]) {
    //cout << i << endl;
    if(!vis3[i] && binary_search(fin_group.begin(), fin_group.end(), i)) {
      proc_ans(i);
      ans[color2[nd]] = move(nd);
    }
  }
  // nanti tinggal pergi ke ndoe yg kita perlu
  ll res = 0;
  for(ll i = 0; i < 60; ++i) {
    if(ans[i])
      res += 1ll << i;
  }
  return res;
}
