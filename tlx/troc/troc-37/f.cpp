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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  // sort by a
  vector<pair<int, pair<int, int>>> v;
  for(int i = 1; i <= n; ++i) {
    int p, q, r;
    cin >> p >> q >> r;
    p -= a, q -= b, r -= c;
    if(p > 0 && q > 0 && r > 0)
      v.pb(mp(p, mp(q, r)));
  }
  sort(v.begin(), v.end());
  n = v.size();
  // fi -> sum
  // se.fi -> b
  // se.se -> c
  multiset<int> price;
  set<pair<int, int>> o;
  o.ins(mp(0, 1e9 + 5));
  o.ins(mp(1e9 + 5, 0));
  price.ins(0);
  int res = 1e9, cost = 0;
  for(int i = n - 1; i >= 0; --i) {
    // consider use first i, find the min amount for the rest
    // insert to s, when inserting find > cur
    // cerr << i << " " << v[i].fi << " " << cost << endl;
    res = min(res, v[i].fi + cost);
    int b = v[i].se.fi, c = v[i].se.se;
    auto it = o.lb(mp(b, c));
    // cerr << "HERE" << endl;
    if((*it).se < c) {
      // insert
      // remove smaller while possible
      while((*--o.lb(mp(b, c))).se <= c) {
        // remove
        auto it = --o.lb(mp(b, c));
        price.erase(price.find((*it).se + (*--it).fi));
        ++it;
        price.erase(price.find((*it).fi + (*++it).se));
        --it;
        price.ins((*--it).fi + (*++(++it)).se);
        o.erase(--o.lb(mp(b, c)));
        // check previous
      }
      o.ins(mp(b, c));
      auto it = o.find(mp(b, c));
      price.erase(price.find((*--it).fi + (*++(++it)).se));
      --it;
      price.ins((*it).se + (*--it).fi);
      ++it;
      price.ins((*it).fi + (*++it).se);
    }
    cost = (*price.begin());
  }
  cout << min(res, cost) << endl;
  return 0;
}