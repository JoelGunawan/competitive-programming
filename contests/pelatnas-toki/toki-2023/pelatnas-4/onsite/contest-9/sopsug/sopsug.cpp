#include "sopsug.h"
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int lim = 3e5 + 5;
vector<int> undir[lim];
bool vis[lim], active[lim];
vector<int> curcc;
struct cc {
  vector<int> nodes;
  vector<int> pr;
};
bool valid = 1;
void dfs(int nd, int pr) {
  vis[nd] = 1, active[nd] = 1;
  curcc.push_back(nd);
  int cnt = 0;
  for(auto i : undir[nd]) {
    if(i != pr) {
      if(active[i]) {
        valid = 0;
        break;
      }
      else if(vis[i]) {
        continue;
      }
      else {
        dfs(i, nd);
      }
    }
    else
      ++cnt;
  }
  if(cnt == 2)
    valid = 0;
  active[nd] = 0;
}
int outdegree[lim];
bool comp(cc a, cc b) {
  return outdegree[a.pr.back()] < outdegree[b.pr.back()];
}
void build_tubes(int N, int M, int K, std::vector<int> A, std::vector<int> B,
                 std::vector<int> C, std::vector<int> D) {
  if(M >= N)
    return;
  memset(outdegree, 0, sizeof(outdegree));
  vector<int> edges[N];
  for(int i = 0; i < K; ++i) {
    edges[C[i]].push_back(D[i]);
  }
  for(int i = 0; i < N; ++i)
    sort(edges[i].begin(), edges[i].end());
  for(int i = 0; i < M; ++i) {
    undir[A[i]].pb(B[i]);
    undir[B[i]].pb(A[i]);
    //cout << outdegree[A[i]] << endl;
    ++outdegree[A[i]];
    //cout << "OUT " << A[i] << " " << outdegree[A[i]] << endl;
    if(outdegree[A[i]] == 2) {
      return;
    }
  }
  vector<cc> ccs;
  for(int i = 0; i < N; ++i) {
    if(!vis[i])
      dfs(i, -1);
    else
      continue;
    if(!valid)
      return;
    ccs.push_back(cc());
    for(auto i : curcc) {
      //cout << "OUT2 " << i << " " << outdegree[i] << endl;
      if(outdegree[i] == 0) {
        ccs.back().pr.push_back(i);
      }
      ccs.back().nodes.push_back(i);
    }
    curcc.clear();
    //cout << ccs.back().pr.size() << endl;
    //for(auto i : ccs.back().pr)
    //  cout << i << " ";
    //cout << endl;
    assert(ccs.back().pr.size() == 1);
  }
  // buat k = 0 dlu
  vector<int> u, v;
  for(int i = 0; i < M; ++i) {
    u.push_back(A[i]);
    v.push_back(B[i]);
  }
  // k = 2 -> cek indegree
  /*
  if(K == 2) {
    if(N == 2) 
      return;
    else {
      int in[N];
      memset(in, 0, sizeof(in));
      for(int i = 0; i < K; ++i)
        ++in[D[i]];
      for(int i = 0; i < N; ++i) {
        if(in[i] == 0) {
          vector<int> u, v;
          for(int j = 0; j < N; ++j) {
            if(i != j)
              u.push_back(j), v.push_back(i);
          }
          build(u, v);
          return;
        }
      }
    }
  }
  */
  //assert(ccs[0].pr.back() == 0);
  memset(outdegree, 0, sizeof(outdegree));
  for(int i = 0; i < K; ++i)
    ++outdegree[C[i]];
  sort(ccs.begin(), ccs.end(), comp);
  reverse(ccs.begin(), ccs.end());
  vector<cc> memo = ccs;
  // coba cc by maximum outdegree disallow for root
  for(int chosen = 0; chosen < memo.size(); ++chosen) {
    ccs = memo;
    set<int> untaken;
    for(int i = 0; i < ccs.size(); ++i)
      if(i != chosen)
        untaken.insert(i);
    vector<int> pu, pv;
    for(int te = 0; te < ccs[chosen].nodes.size(); ++te) {
      int i = ccs[chosen].nodes[te];
      //cout << "PROC " << i << endl;
      vector<int> er;
      for(auto j : untaken) {
        int tmp = ccs[j].pr.back();
        if(!binary_search(edges[tmp].begin(), edges[tmp].end(), i)) {
          er.push_back(j);
          pu.push_back(tmp);
          pv.push_back(i);
        }
      }
      for(auto j : er) {
        //cout << "ERASE " << j << endl;
        for(auto k : ccs[j].nodes) {
          //cout << "PUSH " << k << endl;
          ccs[chosen].nodes.push_back(k);
        }
        untaken.erase(untaken.lower_bound(j));
      }
    }
    if(ccs[chosen].nodes.size() == N) {
      for(auto i : pu)
        u.push_back(i);
      for(auto i : pv)
        v.push_back(i);
      build(u, v);
      return;
    }
  }
  return;
}
