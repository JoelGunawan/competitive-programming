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
const int lim = 1 << 19;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mul(ll a, ll b) {
  return (a * b) % mod;

}
struct segment_tree {
  ll a[lim << 1], lazy[lim << 1];
  ll b[lim << 1], lazyb[lim << 1];
  segment_tree() {
    fill(a, a + (lim << 1), 1);
    fill(lazy, lazy + (lim << 1), 1);
    memset(b, 0, sizeof(b));
  }
  void build() {
    for(int i = lim - 1; i >= 1; --i) {
      a[i] = mul(a[i << 1], a[(i << 1) | 1]);
      b[i] = b[i << 1] | b[(i << 1) | 1];
    }
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      lazy[nd << 1] = mul(lazy[nd << 1], lazy[nd]);
      lazy[(nd << 1) | 1] = mul(lazy[(nd << 1) | 1], lazy[nd]);
      lazyb[nd << 1] |= lazyb[nd];
      lazyb[(nd << 1) | 1] |= lazyb[nd];
    }
    a[nd] = mul(a[nd], powmod(lazy[nd], cr - cl + 1));
    b[nd] |= lazyb[nd];
    lazy[nd] = 1;
    lazyb[nd] = 0;
  }
  void update(int nd, int cl, int cr, int l, int r, int val, ll prime) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazy[nd] = mul(lazy[nd], val);
      lazyb[nd] |= prime;
      // cerr << "LAZY UP " << cl << " " << cr << " " << lazyb[nd] << endl;
      // cerr << prime << endl;
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l) {
      return;
    }
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val, prime);
      update((nd << 1) | 1, mid + 1, cr, l, r, val, prime);
      a[nd] = mul(a[nd << 1], a[(nd << 1) | 1]);
      b[nd] = b[nd << 1] | b[(nd << 1) | 1];
    }
    // cerr << "UP " << cl << " " << cr << " " << b[nd] << endl;
  }
  int query(int nd, int cl, int cr, int l, int r, ll &primes) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      // // cerr << "Q " << cl << " " << cr << " " << b[nd] << endl;
      primes |= b[nd];
      return a[nd];
    }
    else if(cl > r || cr < l)
      return 1;
    else {
      int mid = (cl + cr) >> 1;
      return mul(query(nd << 1, cl, mid, l, r, primes), query((nd << 1) | 1, mid + 1, cr, l, r, primes));
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  vector<int> primes;
  for(int i = 2; i <= 300; ++i) {
    int tmp = sqrt(i);
    bool prime = 1;
    for(int j = 2; j <= tmp; ++j) {
      if(i % j == 0)
        prime = 0;
    }
    if(prime)
      primes.pb(i);
  }
  int n, q;
  cin >> n >> q;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  segment_tree seg;
  for(int i = 1; i <= n; ++i) {
    ll y = 0;
    for(int j = 0; j < primes.size(); ++j) {
      if(a[i] % primes[j] == 0) {
        y |= 1ll << j;
      }
    }
    // cerr << "UP " << y << endl;
    seg.b[i + lim] = y;
    seg.a[i + lim] = a[i];
  }
  seg.build();
  vector<int> inv(primes.size());
  for(int i = 0; i < primes.size(); ++i)
    inv[i] = mul(primes[i] - 1, powmod(primes[i], mod - 2));
  while(q--) {
    string s;
    cin >> s;
    if(s == "MULTIPLY") {
      int l, r, x;
      cin >> l >> r >> x;
      ll y = 0;
      for(int i = 0; i < primes.size(); ++i) {
        if(x % primes[i] == 0)
          y |= 1ll << i;
      }
      seg.update(1, 0, lim - 1, l, r, x, y);
    }
    else {
      ll cur = 0;
      int l, r;
      cin >> l >> r;
      ll res = seg.query(1, 0, lim - 1, l, r, cur);
      // cerr << res << " " << cur << endl;
      for(int i = 0; i < primes.size(); ++i) {
        if((1ll << i) & cur)
          res = mul(res, inv[i]);
      }
      cout << res << endl;
    }
  }
  return 0;
}