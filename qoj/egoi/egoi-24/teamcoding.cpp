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
int color[lim], subtree[lim], par[lim], depth[lim], cnt[lim];
vector<int> child[lim];
bool check[lim];
int res = 0, swp = 0;
void dfs1(int nd, multiset<int> &s) {
  if (s.find(color[nd]) == s.end()) {
    check[nd] = 1;
  }

  s.insert(color[nd]);
  subtree[nd] = 1;
  for (auto &c : child[nd]) {
    depth[c] = depth[nd] + 1;
    dfs1(c, s);
    subtree[nd] += subtree[c];
  }
  s.erase(s.find(color[nd]));
}

int threshold = 300;
unordered_map<int, int> global_cmap[lim];
// how to check how many we can swap without checking all heights manually?
// it takes a very long amount of time if we check all heights manually
pair<unordered_map<int, int>, unordered_map<int, int>> dfs2(int nd) {
  unordered_map<int, int> cur_cmap;
  unordered_map<int, int> cur_dmap;
  ++cur_cmap[color[nd]];
  ++cur_dmap[depth[nd]];
  for (auto &c : child[nd]) {
    auto [cmap, dmap] = dfs2(c);
    if (cur_cmap.size() < cmap.size()) {
      swap(cur_cmap, cmap); 
    }

    for (auto [k, v] : cmap) {
      cur_cmap[k] += v;
    }

    if (cur_dmap.size() < dmap.size()) {
      swap(cur_dmap, dmap);
    }

    for (auto [k, v] : dmap) {
      cur_dmap[k] += v;
    }
  }

  if (check[nd] && cnt[color[nd]] < threshold) {
    // calculate result by iterating through all depths that this color has
    int cur_swap = 0, cur_res = 0;
    for (auto &[k, v] : global_cmap[color[nd]]) {
      cur_res += min(v, cur_dmap[k]);
    }

    cur_swap = cur_res - cur_cmap[color[nd]];
    if (cur_res > res) {
      res = cur_res;
      swp = cur_swap;
    } else if (cur_res == res) {
      swp = min(cur_swap, swp);
    }
  }

  return move(make_pair(move(cur_cmap), move(cur_dmap)));
}

// first -> res
// second -> number in current subtree
pair<int, int> dfs3_helper(int nd, int c, unordered_map<int, int> &color_remaining, unordered_map<int, int> &color_used) {
  int res = 0, in_cur = 0;

  for (auto &x : child[nd]) {
    auto [cres, cin_cur] = dfs3_helper(x, c, color_remaining, color_used);
    res += cres;
    in_cur += cin_cur;
  }

  if (color[nd] == c) ++in_cur;
  auto it = color_remaining.find(depth[nd]);
  if (it != color_remaining.end()) {
    if (it->second > 0) {
      --it->second;
      ++res;
      ++color_used[depth[nd]];
    }
  }

  return {res, in_cur};
}

void dfs3(int nd, int c, unordered_map<int, int> &color_remaining) {
  if (color[nd] == c) {
    unordered_map<int, int> used;
    auto [cur_res, in_cur] = dfs3_helper(nd, c, color_remaining, used);
    for (auto [k, v] : used) {
      color_remaining[k] += v;
    }
    int cur_swap = cur_res - in_cur;

    // cerr << nd << " " << color[nd] << " " << cur_res << " " << cur_swap << endl;

    if (cur_res > res) {
      res = cur_res;
      swp = cur_swap;
    } else if (cur_res == res) {
      swp = min(swp, cur_swap);
    }
  } else {
    for (auto x : child[nd]) dfs3(x, c, color_remaining);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // obs: for each node, find count in that subtree for the color
  // only the top-most nodes of the color matters 
  // (if a node has a parent with the same color, ignore that node)
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> color[i];
    ++color[i];
  }

  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    ++x;
    par[i] = x;
    child[par[i]].push_back(i);
  }

  multiset<int> s;
  depth[1] = 1;
  dfs1(1, s);
  
  // if color has more than sqrt(n) values, then use dfs3()
  // else use dfs2()
  for (int i = 1; i <= n; ++i) {
    global_cmap[color[i]][depth[i]]++;
    ++cnt[color[i]];
  }

  dfs2(1);

  for (int i = 1; i <= n; ++i) {
    if (cnt[i] >= threshold) {
      dfs3(1, i, global_cmap[i]);
    }
  }

  cout << res << " " << swp << endl;

  return 0;
}