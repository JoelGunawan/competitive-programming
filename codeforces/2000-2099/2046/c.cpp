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
struct fenwick {
  int sz;
  vector<int> a;
  fenwick(int n) {
    sz = n;
    a = vector<int>(sz, 0);
  }
  void upd(int idx, int val) {
    while(idx < sz) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int q(int idx) {
    int ret = 0;
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
  int q(int l, int r) {
    return q(r) - q(l - 1);
  }
};  
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
void tc() {
  int n;
  cin >> n;
  pair<int, int> a[n + 1];
  vector<int> xc, yc;
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi >> a[i].se, xc.pb(a[i].fi), yc.pb(a[i].se);
  sort(xc.begin(), xc.end());
  sort(yc.begin(), yc.end());
  xc.resize(unique(xc.begin(), xc.end()) - xc.begin());
  yc.resize(unique(yc.begin(), yc.end()) - yc.begin());
  for(auto &p : a)
    p.fi = lb(xc.begin(), xc.end(), p.fi) - xc.begin(), p.se = lb(yc.begin(), yc.end(), p.se) - yc.begin();
  for(auto &p : a)
    ++p.fi, ++p.se;
  sort(a + 1, a + n + 1);
  fenwick st(n + 5), en(n + 5);
  for(int i = 1; i <= n; ++i) {
    en.upd(a[i].se, 1);
  }
  pair<int, pair<int, int>> res = mp(0, mp(0, 0));
  for(int i = 1; i <= n; ++i) {
    // update i to st, note that if there are equal x coords -> change too
    st.upd(a[i].se, 1);
    en.upd(a[i].se, -1);
    while(i + 1 <= n && a[i].fi == a[i + 1].fi) {
      ++i;
      st.upd(a[i].se, 1);
      en.upd(a[i].se, -1);
    }
    // binser min diff in st and end
    int cl = 0, cr = n, ans = -1, totl = st.q(n), totr = en.q(n), yans = -1;
    while(cl <= cr) {
      int mid = (cl + cr) >> 1;
      // go left/right
      int ul = st.q(mid), ur = en.q(mid), dl = totl - ul, dr = totr - ur;
      if(min({ul, ur, dl, dr}) == min(ul, ur)) {
        // go down
        cl = mid + 1;
        // try to set ans
        if(min(ul, ur) > ans)
          ans = min(ul, ur), yans = mid;
      }
      else {
        // go up
        cr = mid - 1;
        if(min(dl, dr) > ans)
          ans = min(dl, dr), yans = mid;
      }
    }
    // cerr << i << " " << ans << " " << a[i].fi << " " << yans << endl;
    res = max(res, mp(ans, mp(a[i].fi, yans)));
  }
  cout << res.fi << endl << xc[res.se.fi - 1] + 1 << " " << yc[res.se.se - 1] + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}