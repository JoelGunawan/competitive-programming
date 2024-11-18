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
struct block {
  // v -> value
  // cnt -> count of larger value
  // up -> order of updating when change
  vector<lll> v, cnt;
  vector<pair<lll, lll>> up;
  lll larger = 0;
  lll cur = 0, upd = 0;
  ll get_result() {
    if(v.empty())
      return 0;
    // cerr << v[cur] << " " << upd << " " << cnt[cur] << endl;
    return v[cur] * (upd + cnt[cur]);
  }
  void inc() {
    ++upd;
    if(up.size()) {
      --up.back().se;
      if(up.back().se == 0)
        cur = up.back().fi, up.pop_back();
    }
  }
  void compute() {
    // compute 
    for(int i = 0; i < cnt.size(); ++i)
      cnt[i] += upd;
    // cerr << "HERE" << endl;
    larger += upd;
    upd = 0;
    // cerr << "NOT HERE" << endl;
    up.clear();
    // cerr << "CLEAR" << endl;
    // when will each number be maximum? largest will be max eventually
    for(int i = 0; i < v.size(); ++i) {
      // cerr << "HERE " << i << endl;
      while(up.size() && v[up.back().fi] * (cnt[up.back().fi] + up.back().se) <= v[i] * (cnt[i] + up.back().se)) {
        // cerr << "DELETE " << v[up.back().fi] << " " << v[i] << " " << v[up.back().fi] * (cnt[up.back().fi] + up.back().se) << " " << v[i] * (cnt[i] + up.back().se) << endl;
        up.pop_back();
      }
      // how to calculate point of intersect?
      // v[x] * (cnt[x] + k) <= v[y] * (cnt[y] + k)
      // k * (v[x] - v[y]) <= v[y] * cnt[y] - v[x] * cnt[x]
      // k >= (v[y] * cnt[y] - v[x] * cnt[x]) / (v[x] - v[y])
      if(up.empty())
        up.pb(mp(i, 0));
      else {
        up.pb(mp(i, ceil((v[i] * cnt[i] - v[up.back().fi] * cnt[up.back().fi]) / (double)(v[up.back().fi] - v[i]))));
      }
    }
    reverse(up.begin(), up.end());
    cur = up.back().fi;
    up.pop_back();
    for(int i = 0; i < (int)up.size() - 1; ++i)
      up[i].se -= up[i + 1].se;
    // for(int i = 0; i < up.size(); ++i) 
    //   cerr << up[i].se << " ";
    // cerr << endl;
  }
  void insert(ll x) {
    // add to cnt for <= x
    // cerr << x << " " << larger << endl;
    if(find(v.begin(), v.end(), x) == v.end()) {
      int idx = lower_bound(v.begin(), v.end(), x) - v.begin(); 
      v.insert(v.begin() + idx, x);
      cnt.insert(cnt.begin() + idx, 0);
      // find larger
      // cerr << idx << " " << cnt.size() << endl;
      if(idx != cnt.size() - 1)
        cnt[idx] = cnt[idx + 1] + 1;
      else
        cnt[idx] = larger + 1;
      // cerr << cnt[idx] << endl;
      for(int i = 0; i < v.size(); ++i) {
        if(v[i] < x)
          ++cnt[i];
      }
    }
    else {
      for(int i = 0; i < v.size(); ++i) {
        if(v[i] <= x)
          ++cnt[i];
      }
    }
    // cerr << "INS" << endl;
    // for(auto x : v)
    //   cerr << x << " ";
    // cerr << endl;
    // for(auto x : cnt)
    //   cerr << x << " ";
    // cerr << endl;
    // cerr << "BEFORE COMP" << endl;
    compute();
    // cerr << "AFTER COMP" << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  pair<int, int> a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi >> a[i].se;
  sort(a + 1, a + n + 1);
  int blk = sqrt(n);
  pair<int, int> b[n + 5];
  for(int i = 1; i <= n; ++i) 
    b[i] = mp(a[i].se, i);
  sort(b + 1, b + n + 1);
  int num[n + 1];
  for(int i = 1; i <= n; ++i) {
    num[b[i].se] = i / blk;
  }
  ll a_res[n + 2];
  memset(a_res, 0, sizeof(a_res));
  for(int i = n; i >= 1; --i) {
    a_res[i] = 1ll * (n - i + 1) * a[i].fi;
  }
  vector<block> v(n / blk + 1);
  ll res = a_res[1];
  for(int i = 1; i <= n; ++i) {
    // cerr << "CALC " << i << endl;
    for(int j = 0; j < num[i]; ++j)
      v[j].inc();
    v[num[i]].insert(a[i].se);
    ll cr = 0;
    for(int j = 0; j < v.size(); ++j)
      cr = max(cr, v[j].get_result());
    res = max(res, cr + a_res[i + 1]);
  } 
  cout << res << endl;
  return 0;
}