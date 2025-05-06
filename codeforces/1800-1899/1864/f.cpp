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
const int lim = 1 << 20;
struct sum_segtree {
  int a[lim << 1];
  sum_segtree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] += val;
    while(idx) {
      idx >>= 1;
      a[idx] = a[idx << 1] + a[(idx << 1) | 1];
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd];
    }
    else if (cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return query(nd << 1, cl, mid, l, r) + query((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }
};
struct mn_segtree {
  pair<int, int> a[lim << 1];
  mn_segtree() {
    for(int i = 0; i < lim << 1; ++i)
      a[i] = mp(1e9, 1e9);
  }
  void update(int idx, pair<int, int> val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = min(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  pair<int, int> query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      return a[nd];
    }
    else if (cl > r || cr < l)
      return {1e9, 1e9};
    else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  int a[n + 2];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  a[0] = a[n + 1] = 1e9;
  vector<pair<pair<int, int>, int>> queries;
  for(int i = 1; i <= q; ++i) {
    int l, r;
    cin >> l >> r;
    queries.push_back({{l, r}, i});
  }
  sort(queries.begin(), queries.end());
  sum_segtree sum;
  int ans[q + 1];
  memset(ans, -1, sizeof(ans));
  vector<pair<int, int>> elems;
  for(int i = 1; i <= n; ++i) {
    elems.push_back({a[i], i});
  }
  sort(elems.begin(), elems.end());
  reverse(elems.begin(), elems.end());
  int last = n + 5, last_idx = 0;
  mn_segtree mn;
  for(auto [val, idx] : elems) {
    // cerr << "BACK " << queries.back().fi.fi << endl;
    while(queries.size() && queries.back().first.first > val) {
      auto [l, r] = queries.back().fi;
      auto idx = queries.back().se;
      ans[idx] = sum.query(1, 0, lim - 1, l, r);
      // cerr << "QUER " << l << " " << r << " " << ans[idx] << endl;
      queries.pop_back();
    }
    while(true) {
      auto [l, r] = mn.query(1, 0, lim - 1, idx + 1, n);
      if (r <= n && l < idx) {
        sum.update(a[r], 1);
        mn.update(r, {1e9, 1e9});
      }
      else
        break;
    }
    if(last == val) {
      mn.update(last_idx, {idx, last_idx});
    }
    else {
      // cerr << "MANUAL " << idx << " " << val << endl;
      sum.update(val, 1);
    }
    last = val;
    last_idx = idx;
  }
  while(queries.size()) {
    auto [l, r] = queries.back().fi;
    auto idx = queries.back().se;
    ans[idx] = sum.query(1, 0, lim - 1, l, r);
    queries.pop_back();
  }
  for(int i = 1; i <= q; ++i)
    cout << ans[i] << endl;
  return 0;
}