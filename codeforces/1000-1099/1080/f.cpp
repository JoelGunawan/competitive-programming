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
const int lim = 1 << 17;
const int inf = 1e9 + 5;
struct segtree {
  vector<pair<int, int>> a[lim << 1];
  void build(int nd, int cl, int cr, vector<vector<pair<int, int>>> &arr) {
    if(cl == cr) {
      if(cl < arr.size())
        a[nd] = arr[cl]; 
      return;
    }
    int mid = (cl + cr) >> 1;
    build(nd << 1, cl, mid, arr);
    build((nd << 1) | 1, mid + 1, cr, arr);
    // merge
    // cerr << "START " << cl << " " << cr << endl;
    a[nd].clear();
    int idxl = 0, idxr = 0;
    int le = nd << 1, ri = (nd << 1) | 1;
    for(auto [l, r] : a[ri]) {
      while(idxl < a[le].size() && a[le][idxl].fi < l) 
        ++idxl;
      if(idxl != a[le].size())
        a[nd].pb(mp(l, max(a[le][idxl].se, r)));
    }
    int sz = a[nd].size();
    for(auto [l, r] : a[le]) {
      while(idxr < a[ri].size() && a[ri][idxr].fi < l)
        ++idxr;
      if(idxr != a[ri].size())
        a[nd].pb(mp(l, max(a[ri][idxr].se, r)));
    }
    inplace_merge(a[nd].begin(), a[nd].begin() + sz, a[nd].end());
    vector<pair<int, int>> nx;
    for(auto [l, r] : a[nd]) {
      while(nx.size() && r <= nx.back().se) {
        nx.pop_back();
      }
      nx.pb(mp(l, r));
    }
    // cerr << "END " << cl << " " << cr << endl;
    a[nd] = nx;
  }
  int query(int nd, int cl, int cr, int l, int r, int mn) {
    if(cl >= l && cr <= r) {
      auto it = lb(a[nd].begin(), a[nd].end(), mp(mn, 0));
      if(it == a[nd].end())
        return inf;
      else
        return it->se;
    }
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return max(query(nd << 1, cl, mid, l, r, mn), query((nd << 1) | 1, mid + 1, cr, l, r, mn));
    }
  }
} seg;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> a(n + 1);
  for(int i = 1; i <= k; ++i) {
    int l, r, p;
    cin >> l >> r >> p;
    a[p].pb(mp(l, r));
  }
  for(int i = 1; i <= n; ++i) {
    sort(a[i].begin(), a[i].end());
    vector<pair<int, int>> nx;
    for(int j = 0; j < a[i].size(); ++j) {
      while(nx.size() && nx.back().se >= a[i][j].se)
        nx.pop_back();
      nx.pb(a[i][j]);
    }
    a[i] = nx;
  }
  seg.build(1, 0, lim - 1, a);
  // cerr << "DONE BUILD" << endl;
  for(int i = 0; i < m; ++i) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int mn = seg.query(1, 0, lim - 1, a, b, x);
    // cerr << "OUTPUT " << a << " " << b << " " << x << " " << mn << endl;
    cout << (mn <= y ? "yes" : "no") << endl;
  }
  return 0;
}