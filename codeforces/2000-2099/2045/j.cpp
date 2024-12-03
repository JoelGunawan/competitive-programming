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
struct node {
  int l = -1, r = -1, cnt = 0;
};
struct binary_trie {
  vector<node> v = {node()};
  int add_node() {
    v.pb(node());
    return v.size() - 1;
  }
  int query(int nd, int depth, int target, int max_diff) {
    // find such that diff <= max_diff
    if(nd == -1 || max_diff < 0)
      return 0;
    else if((1 << (depth + 1)) <= max_diff)
      return v[nd].cnt;
    else if(depth == -1)
      return v[nd].cnt;
    if((1 << depth) & target) {
      // right max_diff doesn't change
      // left change
      return query(v[nd].r, depth - 1, target, max_diff) + query(v[nd].l, depth - 1, target, max_diff - (1 << depth));
    }
    else {
      return query(v[nd].l, depth - 1, target, max_diff) + query(v[nd].r, depth - 1, target, max_diff - (1 << depth));
    }
  }
  void update(int nd, int depth, int cur) {
    ++v[nd].cnt;
    if(depth == -1) {
      return;
    }
    if((1 << depth) & cur) {
      if(v[nd].r == -1)
        v[nd].r = add_node();
      update(v[nd].r, depth - 1, cur);
    }
    else {
      if(v[nd].l == -1)
        v[nd].l = add_node();
      update(v[nd].l, depth - 1, cur);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  int min_diff = (1 << 30) - 1;
  for(int i = 2; i <= n; ++i) 
    min_diff = min(min_diff, a[i] ^ a[i - 1]);
  ll res = 0;
  binary_trie t;
  for(int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    res += t.query(0, 29, x, min_diff);
    t.update(0, 29, x);
  }
  cout << res << endl;
  return 0;
}