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
#define getbit(x, i) (((x) >> (i)) & 1)
#define bit(x) (1LL << (x))
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int case_num = 0;
  START:
  int n, m;
  if(!(cin >> n >> m)) {
    return 0;
  }
  cout << "Case " << ++case_num << ": ";
  vector<pair<int, int>> edges[n + 1];
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
  }

  int dist[n][n];
  memset(dist, -1, sizeof(dist));
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for(int i = 0; i < n; ++i) {
    pq.push({0, i});
    while(pq.size()) {
      auto [d, nd] = pq.top();
      pq.pop();
      if(dist[i][nd] != -1)
        continue;
      dist[i][nd] = d;
      for (auto [i, c] : edges[nd]) {
        pq.push({d + c, i});
      }
    }
  }

  int src[n][1 << n], dst[n][1 << n];
  memset(src, -1, sizeof(src));
  memset(dst, -1, sizeof(dst));

  src[0][1] = 0; // mark 0 as visited
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int cur = 0; cur < n; cur++) if (src[cur][mask] != -1) {
        // cerr << cur << " " << mask << "\n";
        for (int nxt = 0; nxt < n; nxt++) if (!getbit(mask, nxt)) {
            if (src[nxt][mask | bit(nxt)] == -1 || 
                src[nxt][mask | bit(nxt)] > src[cur][mask] + dist[cur][nxt]) {
                    src[nxt][mask | bit(nxt)] = src[cur][mask] + dist[cur][nxt];
            }
        }
    }
  }

  dst[n - 1][bit(n - 1)] = 0; // mark n - 1 as visited
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int cur = 0; cur < n; cur++) if (dst[cur][mask] != -1) {
        for (int nxt = 0; nxt < n; nxt++) if (!getbit(mask, nxt)) {
            if (dst[nxt][mask | bit(nxt)] == -1 || 
                dst[nxt][mask | bit(nxt)] > dst[cur][mask] + dist[cur][nxt]) {
                    dst[nxt][mask | bit(nxt)] = dst[cur][mask] + dist[cur][nxt];
            }
        }
    }
  }

  int spmask = (1 << n) - 1;
  int g1sz = (n - 2) / 2, g2sz = (n - 2) - g1sz;
  int res = 1e9;
  for(int i = 0; i < 1 << n; ++i) {
    if(__builtin_popcount(i) == g1sz + 1) {
      bool l = i & 1;
      bool s = (1 << (n - 1)) & i;
      if(l == s)
        continue;
      if(!(i & 1))
        continue;
      // cerr << "DEBUG " << i << " " << l << " " << s << endl;
      int mn1 = 1e9, mn2 = 1e9;
      vector<int> g1, g2;
      int m = 0, inv = 0;
      for(int j = 1; j < n - 1; ++j) {
        if((1 << j) & i) {
          g1.push_back(j);
          m ^= 1 << j;
        }
        else {
          g2.push_back(j);
          inv ^= 1 << j;
        }
      }
      if(g1.empty()) {
        // cerr << "TEST " << m << endl;
        // cerr << i << endl;
        // cerr << __builtin_popcount(i) << endl;
        res = min(res, dist[0][1] + dist[1][2] + dist[2][1] + dist[1][0]);
      }
      else {
        for(auto e1 : g1) {
          for(auto e2 : g2) {
            mn1 = min(mn1, src[e1][m | 1] + dst[e2][inv | (1 << (n - 1))] + dist[e1][e2]);
            mn2 = min(mn2, src[e2][inv | 1] + dst[e1][m | (1 << (n - 1))] + dist[e1][e2]);
            // cerr << e1 << " " << e2 << " " << mn1 << " " << mn2 << endl;
          }
        }
        // cerr << m << " " << mn1 << " " << mn2 << endl;
        res = min(res, mn1 + mn2);
      }
    }
  }
  cout << res << endl;

  goto START;
  return 0;
}