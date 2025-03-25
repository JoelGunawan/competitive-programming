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
const ll inf = 2e18;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  // r, l, level
  set<pair<pair<ll, ll>, ll>> s;
  s.insert(mp(mp(inf, -(ll)1e18), 0));
  for(int i = 1; i <= n; ++i) {
    char c;
    ll l, p;
    cin >> c >> l >> p;
    if (c == '-') {
      ll cl = p, cr = p + l - 1;
      if(*s.lb(mp(mp(cl, -inf), 0)) == *s.lb(mp(mp(cr, -inf), 0))) {
        auto cur = *s.lb(mp(mp(cl, -inf), 0));
        s.erase(cur);
        auto pr = cur, nx = cur;
        pr.fi.fi = cl - 1, nx.fi.se = cr + 1;
        cur.fi.se = cl, cur.fi.fi = cr, cur.se += 1;
        s.ins(cur);
        if(pr.fi.fi >= pr.fi.se)
          s.ins(pr);
        if(nx.fi.fi >= nx.fi.se)
          s.ins(nx);
        while(s.lb(cur) != s.begin()) {
          auto pr = *--s.lb(cur);
          if(pr.se == cur.se) {
            s.erase(s.lb(cur));
            s.erase(s.lb(pr));
            cur.fi.se = pr.fi.se;
            s.ins(cur);
          }
          else
            break;
        }
        while(s.ub(cur) != s.end()) {
          auto nxt = *s.ub(cur);
          if(nxt.se == cur.se) {
            s.erase(s.lb(cur));
            s.erase(s.lb(nxt));
            cur.fi.fi = nxt.fi.fi;
            s.ins(cur);
          }
          else 
            break;
        }
        cout << "S";
      }
      else {
        cout << "U";
      }
    }
    else {
      cout << "S";
      auto cur = *s.lb(mp(mp(p, -inf), 0));
      s.erase(s.lb(mp(mp(p, -inf), 0)));
      // split current segment into 3
      auto pr = cur, nx = cur;
      pr.fi.fi = p - 1, nx.fi.se = p + 1;
      cur.fi.fi = cur.fi.se = p, cur.se += l;
      s.ins(cur);
      if(pr.fi.fi >= pr.fi.se)
        s.ins(pr);
      if(nx.fi.fi >= nx.fi.se)
        s.ins(nx);
      while(s.lb(cur) != s.begin()) {
        // cerr << cur.fi.se << " " << cur.fi.fi << endl;
        auto pr = *--s.lb(cur);
        if(pr.se == cur.se) {
          s.erase(s.lb(cur));
          s.erase(s.lb(pr));
          cur.fi.se = pr.fi.se;
          s.ins(cur);
        }
        else
          break;
      }
      while(s.ub(cur) != s.end()) {
        // cerr << "L2 " << cur.fi.se << " " << cur.fi.fi << endl;
        auto nxt = *s.ub(cur);
        if(nxt.se == cur.se) {
          s.erase(s.lb(cur));
          s.erase(s.lb(nxt));
          cur.fi.fi = nxt.fi.fi;
          s.ins(cur);
        }
        else
          break;
      }
    }
  }
  return 0;
}