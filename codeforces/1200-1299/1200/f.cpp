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
int mod = 2520;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int k[n];
  for(int i = 0; i < n; ++i)
    cin >> k[i], k[i] %= mod, k[i] = k[i] < 0 ? k[i] + mod : k[i];
  vector<int> edges[n];
  int sz[n];
  for(int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    sz[i] = m;
    for(int j = 0; j < m; ++j) {
      int v;
      cin >> v;
      --v;
      edges[i].push_back(v);
    }
  }

  int modulo_table[mod][11];
  memset(modulo_table, -1, sizeof(modulo_table));
  for(int i = 0; i < mod; ++i) {
    for(int j = 1; j <= 10; ++j) {
      modulo_table[i][j] = i % j;
    }
  }

  // get all cycles
  // all other things -> get same answer as cycle
  // solution: pick random node and start point, find cycle -> answer in cycle
  int ans[n][mod];
  memset(ans, -1, sizeof(ans));

  bool active[n][mod];
  memset(active, 0, sizeof(active));

  // cerr << "HERE" << endl;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < mod; ++j) {
      // cerr << i << " " << j << endl;
      if(ans[i][j] == -1) {
        // cerr << "GO IN" << endl;
        vector<pair<int, int>> v;
        int cx = i, cy = j;
        while(true) {
          // cerr << cx << " " << cy << endl;
          if(active[cx][cy] || ans[cx][cy] != -1) {
            v.pb({cx, cy});
            break;
          }
          active[cx][cy] = 1;
          v.push_back({cx, cy});
          cy += k[cx];
          if(cy >= mod)
            cy -= mod;
          // cerr << cy << " " << sz[cx] << endl;
          int idx = modulo_table[cy][sz[cx]];
          // cerr << cx << " " << idx << endl;
          cx = edges[cx][idx];
        }
        int res;
        if(ans[cx][cy] == -1) {
          vector<int> a;
          int idx = v.size() - 1;
          pair<int, int> tmp = {cx, cy};
          do {
            a.pb(v[idx].fi);
            --idx;
          } while(idx >= 0 && v[idx] != tmp);
          sort(a.begin(), a.end());
          res = unique(a.begin(), a.end()) - a.begin();
        } else {
          res = ans[cx][cy];
        }
        for (auto [cx, cy] : v)
          active[cx][cy] = 0, ans[cx][cy] = res;
      }
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int x, y;
    cin >> x >> y;
    y %= mod;
    --x;
    if(y < 0)
      y += mod;
    cout << ans[x][y] << endl;
  }
  return 0;
}