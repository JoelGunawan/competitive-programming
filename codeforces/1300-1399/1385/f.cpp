// header file
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
void tc() {
  int n, k;
  cin >> n >> k;
  vector<int> edges[n + 1];
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  if(k == 1) {
    cout << n - 1 << endl;
    return;
  }
  // for each node that is leaf, add to count of leaf, for each node that is not 
  bool used[n + 1], leaf[n + 1];
  int adj[n + 1], rem[n + 1];
  memset(adj, 0, sizeof(adj));
  memset(rem, 0, sizeof(rem));
  memset(used, 0, sizeof(used));
  memset(leaf, 0, sizeof(leaf));
  for(int i = 1; i <= n; ++i) {
    if(edges[i].size() == 1)
      used[i] = 1;
  }
  set<pair<int, int>> s;
  for(int i = 1; i <= n; ++i) {
    int cur = 0;
    for(auto x : edges[i])
      if(used[x])
        ++cur;
    s.ins(mp(cur, i));
    adj[i] = cur;
  }
  int removed = 0;
  while(s.size()) {
    // cout << (*--s.end()).fi << " " << (*--s.end()).se << endl;
    // cout << pq.top().fi << endl;
    if((*--s.end()).fi >= k) {
      // cout << "REDUCE TOP" << endl;
      pair<int, int> tmp = (*--s.end());
      s.erase(--s.end());
      tmp.fi -= k;
      adj[tmp.se] -= k;
      ++removed;
      rem[tmp.se] += k;
      if(rem[tmp.se] == edges[tmp.se].size() - 1) {
        used[tmp.se] = 1;
        for(auto x : edges[tmp.se]) {
          if(!used[x]) {
            // cout << "update " << x << " " << adj[x] + 1 << endl;
            s.erase(s.find(mp(adj[x], x)));
            ++adj[x];
            s.ins(mp(adj[x], x));
          }
        }
      }
      else
        s.ins(tmp);
    }
    else {
      break;
    }
  }
  cout << removed << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) 
    tc();
  return 0;
}