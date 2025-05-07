#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
int query(vector<int> &a) {
  cout << "? " << a.size() << " ";
  for(auto x : a) {
    cout << x << " ";
  }
  cout << endl;
  int x;
  cin >> x;
  return x;
}
int main() {
  int n;
  cin >> n;
  vector<int> edges[n + 1];
  vector<pair<int, int>> adj;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
    adj.push_back({u, v});
  }
  vector<int> tmp;
  for(int i = 1; i <= n; ++i)
    tmp.pb(i);
  int ans = query(tmp);
  int cnt_edges = n - 1;
  while(cnt_edges > 1) {
    int cur = 0;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<int> queries;
    while(cur < cnt_edges / 2) {
      for(int i = 1; i <= n; ++i) {
        if(!vis[i] && cur < cnt_edges / 2 && edges[i].size() > 0) {
          queue<int> bfs;
          bfs.push(i);
          --cur;
          while(bfs.size() && cur < cnt_edges / 2) {
            int nd = bfs.front();
            bfs.pop();
            if(vis[nd])
              continue;
            vis[nd] = 1;
            ++cur;
            queries.push_back(nd);
            for(auto x : edges[nd]) {
              if(!vis[x])
                bfs.push(x);
            }
          }
        }
      }
    }
    int cur_ans = query(queries);
    bool inq[n + 1];
    memset(inq, 0, sizeof(inq));
    for(auto x : queries)
      inq[x] = 1;
    vector<pair<int, int>> nx;
    if(cur_ans == ans) {
      // ans in query edges
      for(auto [x, y] : adj) {
        if(inq[x] && inq[y])
          nx.pb({x, y});
      }
    } else {
      // ans not in query edges
      for(auto [x, y] : adj) {
        if(!inq[x] || !inq[y])
          nx.pb({x, y});
      }
    }
    adj = move(nx);
    for(int i = 1; i <= n; ++i)
      edges[i].clear();
    for(auto [x, y] : adj) {
      edges[x].pb(y);
      edges[y].pb(x);
    }
    cnt_edges = adj.size();
  }
  cout << "! " << adj[0].first << " " << adj[0].second << endl;
  return 0;
}