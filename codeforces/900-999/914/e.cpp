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
const int lim = 2e5 + 5;
vector<int> edges[lim], child[lim];
// from this node, find mask dist to all elements in that centroid
// fi -> nd, se -> mask dist
vector<pair<int, int>> masks[lim];
bool vis[lim];
int subtree[lim], val[lim];
// res -> total, cur -> just new
ll res[lim], cur[lim];
int cnt[1 << 20];
int get_subtree(int nd, int pr = -1) {
  subtree[nd] = 1;
  for(auto i : edges[nd]) {
    if(i != pr && !vis[i])
      subtree[nd] += get_subtree(i, nd);
  }
  return subtree[nd];
}
int get_centroid(int nd, int sz, int pr = -1) {
  for(auto i : edges[nd]) {
    if(i != pr && !vis[i] && subtree[i] * 2 > sz)
      return get_centroid(i, sz, nd);
  }
  return nd;
}
void calc(int nd, vector<pair<int, int>> &v, int pr = -1, int dist = 0) {
  dist ^= val[nd];
  v.pb(mp(nd, dist));
  for(auto i : edges[nd]) {
    if(i != pr && !vis[i]) {
      calc(i, v, nd, dist);
    }
  }
}
void construct(int nd, int pr = -1) {
  // cerr << "CONS " << nd << endl;
  int centroid = get_centroid(nd, get_subtree(nd));
  // cerr << "HERE " << centroid << endl;
  vis[centroid] = 1;
  if(pr != -1) {
    child[pr].pb(centroid);
  }
  calc(centroid, masks[centroid]);
  for(auto i : edges[centroid]) {
    if(!vis[i])
      construct(i, centroid);
  }
  // get child centroids
  // how to propagate all occurrences?
  // one idea: add all childs, path to current node (including current node)
  // for each child, remove all occurrences of that child, then we traverse that child
  // fi -> child, se -> distance to child
  vector<pair<int, int>> v, v2 = masks[centroid];
  sort(v2.begin(), v2.end());
  for(auto p : child[centroid]) {
    // get distance to each child, so we know what to calibrate by
    v.pb(mp(p, (*lb(v2.begin(), v2.end(), mp(p, 0))).se));
  }
  for(auto p : masks[centroid])
    ++cnt[p.se];
  for(auto p : v) {
    // actually just do the dfs at the end, maintain all childs
    // c.se -> dist from p.fi to nd, p.se -> dist from centroid to p.fi, p.fi duplicate
    // let's do bfs to determine this
    for(auto c : masks[p.fi])
      --cnt[(*lb(v2.begin(), v2.end(), mp(c.fi, 0))).se];
    for(auto c : masks[p.fi]) {
      // the mask can only differ by 1 position (or exact same)
      int now = (*lb(v2.begin(), v2.end(), mp(c.fi, 0))).se ^ val[centroid];
      for(int j = 0; j < 20; ++j) {
        // if(cnt[c.se ^ (1 << j)]) {
        //     // cerr << "OUT " << c.fi << " " << (c.se ^ (1 << j)) << " " << cnt[c.se ^ (1 << j)] << endl; 
        // }
        cur[c.fi] += cnt[now ^ (1 << j)];
      }
      // if(cnt[c.se]) {
      //   // cerr << "OUT " << c.fi << " " << c.se << " " << cnt[c.se] << endl;
      // }
      cur[c.fi] += cnt[now];
      // cerr << centroid << " " << now << " " << cur[c.fi] << endl;
      // special case for centroid, double the count so it is easier
      // overcounting?
      // some over counting
      // some under counting
      // rare case (error less than 10 on most things)
      if(__builtin_popcount(now ^ val[centroid]) <= 1)
        ++cur[centroid];
    }
    for(auto c : masks[p.fi])
      ++cnt[(*lb(v2.begin(), v2.end(), mp(c.fi, 0))).se];
  }
  set<int> used;
  // cerr << "CENTROID IS " << centroid << endl;
  // cerr << "ORDER: ";
  for(int i = masks[centroid].size() - 1; i >= 0; --i) {
    int nd = masks[centroid][i].fi;
    // cerr << nd << " ";
    for(auto j : edges[nd])
      if(used.count(j))
        cur[nd] += cur[j];
    used.ins(nd);
  }
  // cerr << endl;
  for(auto p : masks[centroid])
    --cnt[p.se];
  for(auto p : masks[centroid]) {
    // cerr << "DEB " << centroid << " " << p.fi << " " << p.se << " " << cur[p.fi] << endl;
    // for centroid, the issue is -> what about paths to centroid?
    // if(p.fi == centroid)
    //   assert(cur[p.fi] % 2 == 0);
    res[p.fi] += p.fi == centroid ? cur[p.fi] / 2 : cur[p.fi], cur[p.fi] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }
  string s;
  cin >> s;
  s = " " + s;
  for(int i = 1; i <= n; ++i)
    val[i] = 1 << (s[i] - 'a');
  construct(1);
  for(int i = 1; i <= n; ++i) 
    cout << res[i] + 1 << " ";
  cout << endl;
  return 0;
}