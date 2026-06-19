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

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  // consider last prefix min
  // then, observe that either: it gets swapped to end OR doesn't get swapped at all
  ll pref[n + 5];
  memset(pref, 0, sizeof(pref));
  int mn = 1e9 + 5, cnt_mn = 0, lst = 0;
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }

  ll res[n + 5];
  for (int i = 1; i <= n; ++i) {
    if (a[i] == mn) {
      lst = i;
      ++cnt_mn;
    } else if (a[i] < mn) {
      mn = a[i];
      cnt_mn = 1;
      lst = i;
    }
    // first option: move minimum to end
    // second option: don't move minimum at all (only move forward)
    res[i] = min(1ll * mn * i + lst - cnt_mn + (i - lst) * 2, 1ll * mn * lst + lst - cnt_mn + pref[i] - pref[lst]);
  }

  for (int i = 1; i <= n; ++i) cout << res[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}