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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    // find node such that it's adjacent is the same
    // then find minimum odd path, even path
    // states: move both nodes to other nodes
    // combinations: n^2 nodes
    // edges: each edge can be multiplied by another, m^2 edges
    // then do dijkstra, move cost is difference between two nodes
    bool vis[n + 1][n + 1];
    bool end[n + 1];
    memset(vis, 0, sizeof(vis));
    memset(end, 0, sizeof(end));
    vector<int> edg1[n + 1], edg2[n + 1];
    int m1;
    cin >> m1;
    for(int i = 1; i <= m1; ++i) {
      int u, v;
      cin >> u >> v;
      edg1[u].pb(v);
      edg1[v].pb(u);
    }
    int m2;
    cin >> m2;
    for(int i = 1; i <= m2; ++i) {
      int u, v;
      cin >> u >> v;
      edg2[u].pb(v);
      edg2[v].pb(u);
    }
    for(int i = 1; i <= n; ++i) {
      sort(edg1[i].begin(), edg1[i].end());
      sort(edg2[i].begin(), edg2[i].end());
      for(auto j : edg1[i]) {
        if(binary_search(edg2[i].begin(), edg2[i].end(), j)) {
          end[i] = end[j] = 1;
        }
      }
    }
    int ans = -1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(mp(0, mp(s1, s2)));
    while(pq.size()) {
      int d = pq.top().fi, nd1 = pq.top().se.fi, nd2 = pq.top().se.se;
      pq.pop();
      if(vis[nd1][nd2])
        continue;
      if(nd1 == nd2 && end[nd1]) {
        ans = d;
        break;
      }
      vis[nd1][nd2] = 1;
      for(auto i : edg1[nd1]) {
        for(auto j : edg2[nd2]) {
          if(!vis[i][j])
            pq.push(mp(d + abs(i - j), mp(i, j)));
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}