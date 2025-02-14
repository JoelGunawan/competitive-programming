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
struct disjoint_set {
  vector<int> h, sz;
  vector<map<ll, int>> cnt;
  disjoint_set(int n) {
    h = vector<int>(n + 5, -1);
    sz = vector<int>(n + 5, 1);
    cnt = vector<map<ll, int>>(n + 5);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  void merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
      for(auto p : cnt[y]) {
        cnt[x][p.fi] += p.se;
      }
    }
  }
};
void tc() {
  int n, q;
  cin >> n >> q;
  ll a[n + 2];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  a[0] = a[n + 1] = 1 << 20;
  pair<int, int> upd[q + 1];
  for(int i = 1; i <= q; ++i) {
    cin >> upd[i].fi >> upd[i].se;
  }
  for(int i = 1; i <= q; ++i)
    a[upd[i].fi] += upd[i].se;
  reverse(upd + 1, upd + q + 1);
  int ans[q + 1];
  memset(ans, 0, sizeof(ans));
  for(int k = 0; k < 17; ++k) {
    // initialize
    disjoint_set dsu(n);
    for(int i = 1; i <= n; ++i) {
      if(a[i] < 1 << k) {
        dsu.cnt[i][a[i]] = 1;
        if (a[i - 1] < (1 << k))
          dsu.merge(i - 1, i);
      }
    }

    set<int> used;
    multiset<int> valid;
    for(int i = 1; i <= n; ++i) {
      if(!used.count(dsu.fh(i)) && dsu.cnt[dsu.fh(i)].size() == (1 << k)) {
        valid.ins(dsu.sz[dsu.fh(i)]);
        used.ins(dsu.fh(i));
      }
    }

    for(int i = 1; i <= q; ++i) {
      ans[i] = max(ans[i], valid.size() ? *--valid.end() : 0);  
      // do the updates after
      int idx = upd[i].fi;
      ll pr = a[idx];
      ll nx = a[idx] - upd[i].se;
      int rep = dsu.fh(idx);
      if(dsu.cnt[rep].find(pr) != dsu.cnt[rep].end()) {
        --dsu.cnt[rep][pr];
        if(dsu.cnt[rep][pr] == 0) {
          dsu.cnt[rep].erase(pr);
          if(used.count(rep)) {
            used.erase(rep);
            valid.erase(valid.find(dsu.sz[rep]));
          }
        }
        ++dsu.cnt[rep][nx];
        if(!used.count(rep) && dsu.cnt[rep].size() == (1 << k)) {
          used.ins(rep);
          valid.ins(dsu.sz[rep]);
        }
      }
      else if(nx < (1 << k)) {
        // new, can merge with L or R
        ++dsu.cnt[idx][nx];
        if(a[idx - 1] < (1 << k)) {
          int rep = dsu.fh(idx - 1);
          if(used.count(rep)) {
            used.erase(rep);
            valid.erase(valid.find(dsu.sz[rep]));
          }
          dsu.merge(idx - 1, idx);
        }
        if(a[idx + 1] < (1 << k)) {
          int rep = dsu.fh(idx + 1);
          if(used.count(rep)) {
            used.erase(rep);
            valid.erase(valid.find(dsu.sz[rep]));
          }
          dsu.merge(idx, idx + 1);
        }
        if(dsu.cnt[dsu.fh(idx)].size() == (1 << k)) {
          used.ins(dsu.fh(idx));
          valid.ins(dsu.sz[dsu.fh(idx)]);
        }
      }
      a[idx] = nx;
    }
    // reset values of a
    for(int i = 1; i <= q; ++i)
      a[upd[i].fi] += upd[i].se;
  }
  reverse(ans + 1, ans + q + 1);
  for(int i = 1; i <= q; ++i)
    cout << ans[i] << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}