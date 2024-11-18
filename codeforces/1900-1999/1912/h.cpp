#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int lim = 1e3 + 5;
bool vis[lim];
vector<int> edges[lim];
vector<int> current_nodes;
void findcc(int nd) {
  vis[nd] = 1;
  current_nodes.pb(nd);
  for(auto x : edges[nd]) {
    if(!vis[x])
      findcc(x);
  }
}
bool active[lim];
bool check_cycle(int nd) {
  vis[nd] = 1;
  active[nd] = 1;
  for(auto x : edges[nd]) {
    if(vis[x] && active[x]) {
      return true;
    }
    else if(!vis[x]) {
      if(check_cycle(x))
        return true;
    }
  } 
  active[nd] = 0;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
    adj.pb(mp(u, v));
  }
  vector<vector<int>> cc;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      findcc(i);
      cc.pb(current_nodes);
      current_nodes.clear();
    }
  }
  vector<pair<int, int>> res;
  memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= n; ++i) 
    edges[i].clear();
  for(auto x : adj)
    edges[x.fi].pb(x.se);
  int cnt[n + 1];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= n; ++i) {
    for(auto x : edges[i])
      ++cnt[x];
  }
  for(auto x : cc) {
    // check dag
    // case dag -> just any order
    // cerr << "CURRENT CC" << endl;
    // for(auto i : x)
    //   cerr << i << " ";
    // cerr << endl;
    bool cycle = 0;
    for(auto i : x) {
      if(!vis[i] && check_cycle(i)) {
        cycle = 1;
        break;
      }
    }
    if(!cycle) {
      // get toposorted
      vector<int> order;
      vector<int> pending;
      for(auto i : x) {
        if(cnt[i] == 0)
          pending.pb(i);
      }
      while(pending.size()) {
        int cur = pending.back();
        pending.pop_back();
        order.pb(cur);
        for(auto x : edges[cur]) {
          --cnt[x];
          if(cnt[x] == 0)
            pending.pb(x);
        }
      }
      for(int i = 0; i < order.size() - 1; ++i)
        res.pb(mp(order[i], order[i + 1]));
    }
    else {
      // do algorithm
      bool found = 0;
      vector<int> ret;
      for(auto i : x) {
        // set i as starting point
        vector<int> modify;
        vector<int> pending;
        vector<int> order;
        for(auto j : x) {
          if(i != j && cnt[j] == 0)
            pending.pb(j);
        }
        pending.pb(i);
        while(pending.size()) {
          int cur = pending.back();
          pending.pop_back();
          order.pb(cur);
          for(auto x : edges[cur]) {
            --cnt[x];
            modify.pb(x);
            if(cnt[x] == 0 && x != i) {
              // cerr << "REDUCED " << i << " " << x << endl;
              pending.pb(x);
            }
          }
        }
        if(order.size() == x.size()) {
          found = 1;
          ret = order;
        }
        for(auto x : modify)
          ++cnt[x];
      }
      if(!found) {
        cout << -1 << endl;
        exit(0);
      }
      else {
        for(int i = 0; i < ret.size(); ++i) {
          res.pb(mp(ret[i], ret[(i + 1) % ret.size()]));
        }
      }
    }
  }
  cout << res.size() << endl;
  for(auto x : res)
    cout << x.fi << " " << x.se << endl;
  return 0;
}