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
ll mod = 1e9 + 7;
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
struct disjoint_set {
  vector<int> h, sz, v;
  disjoint_set(int n) {
    h = vector<int>(n, -1);
    sz = vector<int>(n, 1);
    v = vector<int>(n, 0);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  int gv(int nd) {
    return h[nd] == -1 ? v[nd] : (v[nd] ^ gv(h[nd]));
  }
  int merge(int x, int y, int val) {
    int tmpx = x, tmpy = y;
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
      v[y] = val ^ gv(tmpy) ^ gv(tmpx);
      return 1;
    }
    else {
      if((gv(tmpx) ^ gv(tmpy)) != val) {
        return -1;
      }
      else {
        return 0;
      }
    }
  }
};
void tc() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<pair<pair<int, int>, int>> v;
  for(int i = 1; i <= k; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v.pb(mp(mp(a, b), c));
  }
  disjoint_set dsu(n + m + 5);
  ll res = n + m - 1;
  // need to check if equal to 0 for every thing
  bool ans = 1;
  for(auto p : v) {
    // cerr << "MERGE " << p.fi.fi << " " << p.fi.se + n << endl;
    int ret = dsu.merge(p.fi.fi, p.fi.se + n, p.se);
    if(ret == -1) {
      // unsuccessful
      ans = 0;
    }
    else {
      res -= ret;
    }
  }
  // need to check validity, how?
  // if merge success -> 100% valid
  // otherwise: check some reference values, is it a good merge?
  // cout << res << endl;
  cout << (ans ? powmod(1 << 30, res) : 0) << endl;
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