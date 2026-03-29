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
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim];
bool lg[lim];
bool simple[lim];
void dfs(int nd) {
  vis[nd] = 1;
  lg[nd] = 1;
  simple[nd] = 1;
  int cnt_child = 0;
  for (auto c : edges[nd]) {
    if (!vis[c]) {
      dfs(c);
      simple[nd] &= simple[c];
      lg[nd] &= lg[c];
      ++cnt_child;
    }
  }

  if (cnt_child > 2) {
    // not simple nor line graph
    simple[nd] = false;
    lg[nd] = false;
  } else if (cnt_child == 2) {
    // has two children
    // both must be lg for current to be simple
    if (!lg[nd]) simple[nd] = false;

    // obv not line graph
    lg[nd] = false;
  } else if (cnt_child == 1 && !lg[nd]) {
    simple[nd] = false;
  }
}

int dfs2(int nd) {
  // find furthest not simple node
  vis[nd] = 1;
  int cand = -1;
  if (!simple[nd]) cand = nd;
  for (auto c : edges[nd]) {
    // we return one arbitrary "furthest" non-simple candidate
    if (!vis[c]) {
      auto ret = dfs2(c);
      // cerr << "check child " << nd << " " << c << " " << ret << endl;
      if (ret != -1) cand = ret;
    }
  }

  // cerr << "val " << nd << " " << cand << endl;
  return cand;
}

int dfs3(int nd) {
  // find path with max number of non-simple nodes
  vis[nd] = 1;
  int ret = 0;
  for (auto c : edges[nd]) {
    if (!vis[c]) {
      ret = max(ret, dfs3(c));
    }
  }

  return ret + (!simple[nd]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  // choose vertex with max degree, try to solve children, find which ones are of form line + line, find which ones have more complex form
  // for each vertex, pick
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }

  pair<int, int> mx = {0, 0};
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, mp((int)edges[i].size(), i));
  }

  // line graph case
  if (mx.fi <= 2) {
    cout << "Yes" << endl;
    // cerr << "easy case" << endl;
    return 0;
  }

  // root has at least deg. 3
  dfs(mx.se);
  // check if root is simple
  int cnt_lg = 0;
  for (auto c : edges[mx.se]) {
    cnt_lg += lg[c];
  }

  if (edges[mx.se].size() == 3 && cnt_lg >= 2) simple[mx.se] = true;

  // find a path that contains all non simple nodes
  int cnt = 0;
  vector<int> ns;
  for (int i = 1; i <= n; ++i) {
    if (!simple[i]) {
      ++cnt;
      ns.pb(i);
    }
  }
  
  // for (auto c : ns) {
  //   cerr << c << " ";
  // }
  // cerr << endl;

  if (cnt == 0) {
    // cerr << "second easy case" << endl;
    cout << "Yes" << endl;
    return 0;
  }
  
  // cerr << mx.se << endl;
  // cerr << "cur root " << mx.se << endl;
  memset(vis, 0, sizeof(vis));
  int nx = dfs2(mx.se);
  // cerr << "got root " << nx << endl;
  
  // cerr << nx << endl;
  memset(vis, 0, sizeof(vis));
  int res = dfs3(nx);
  cout << (res != cnt ? "No" : "Yes") << endl;

  // do dfs 2x
  return 0;
}