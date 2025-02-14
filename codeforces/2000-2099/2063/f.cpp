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
int mod = 998244353;
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
const int lim = 6e5 + 5;
ll fact[lim], inv[lim];
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[b], inv[a - b]));
}
ll catalan(ll n) {
  return mul(combinmod(n, n / 2), powmod(n / 2 + 1, mod - 2)); 
}
ll ways;
struct disjoint_set {
  vector<int> sz, h, sf;
  disjoint_set(int n) {
    sf = vector<int>(n + 5, 0);
    sz = vector<int>(n + 5, 1);
    h = vector<int>(n + 5, -1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
  }
  void merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      if(sf[y])
        ways = mul(ways, powmod(catalan(sf[y]), mod - 2));
      if(sf[x])
        ways = mul(ways, powmod(catalan(sf[x]), mod - 2));
      sf[x] += sf[y];
      h[y] = x;
      sz[x] += sz[y];
      ways = mul(ways, catalan(sf[x]));
    }
  }
};
void tc() {
  int n;
  cin >> n;
  // fi -> r
  // se -> l 
  // do in reverse, each "deletion" frees up some space, later the spaces can be merged
  // use dsu, dsu maintain sum_free, (LR IS NOT IMPORTANT BCS WE KNOW STRUCT)
  // when adding sum free by 2, delete old way count and redo by the new one
  ways = 1;
  pair<int, int> a[n + 1];
  a[0] = mp(0, 2 * n + 1);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].fi >> a[i].se;
  }
  // get tree structure, and do deletion from behind
  // add to dsu.fh(par[x]) (or just merge with par[x] ig lol)
  pair<int, int> b[n + 1];
  for(int i = 0; i <= n; ++i)
    b[i] = a[i];
  sort(b + 1, b + n + 1);
  vector<int> st = {0};
  int par[n + 1];
  memset(par, 0, sizeof(par));
  for(int i = 1; i <= n; ++i) {
    while(b[st.back()].se < b[i].fi)
      st.pop_back();
    par[i] = st.back();
    st.pb(i);
  }
  int ans[n + 1];
  ans[0] = catalan(2 * n);
  disjoint_set dsu(n);
  for(int i = n; i >= 1; --i) {
    ans[i] = ways;
    int idx_del = lb(b, b + n + 1, a[i]) - b;
    if(dsu.sf[dsu.fh(idx_del)]) {
      ways = mul(ways, powmod(catalan(dsu.sf[dsu.fh(idx_del)]), mod - 2));
    }
    dsu.sf[dsu.fh(idx_del)] += 2;
    ways = mul(ways, catalan(dsu.sf[dsu.fh(idx_del)]));
    // cerr << "MERGE " << idx_del << " " << par[idx_del] << endl;
    dsu.merge(idx_del, par[idx_del]);
  }
  for(int i = 0; i <= n; ++i)
    cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = powmod(fact[i], mod - 2);
  }
  while(t--) {
    tc();
  }
  return 0;
}