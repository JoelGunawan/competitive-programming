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
const int lim = 1 << 18;
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
  ll a[lim << 1], b[lim << 1]; // a -> regular mul, b -> mul of p - 1 / p
  segment_tree() {
    fill(a, a + (lim << 1), 1);
    fill(b, b + (lim << 1), 1);
  }
  void updatea(int idx, int val) {
    idx += lim;
    a[idx] = mul(a[idx], val);
    while(idx) {
      idx >>= 1;
      a[idx] = mul(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  void updateb(int idx, int val) {
    idx += lim;
    b[idx] = mul(b[idx], val);
    while(idx) {
      idx >>= 1;
      b[idx] = mul(b[idx << 1], b[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      // cerr << a[nd] << " " << b[nd] << endl;
      return mul(a[nd], b[nd]);
    }
    else if(cl > r || cr < l)
      return 1;
    else {
      int mid = (cl + cr) >> 1;
      return mul(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int q;
  cin >> q;
  pair<pair<int, int>, int> que[q];
  int ans[q];
  const int lim2 = 1e6 + 5;
  vector<int> pf[lim2];
  bool prime[lim2];
  memset(prime, 1, sizeof(prime));
  prime[0] = prime[1] = 0;
  for(int i = 2; i < lim2; ++i) {
    if(prime[i]) {
      pf[i].pb(i);
      for(int j = 2 * i; j < lim2; j += i)
        pf[j].pb(i), prime[j] = 0;
    }
  }
  for(int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    que[i] = mp(mp(l, r), i);
  }
  sort(que, que + q);
  // put all first occur of primes in
  vector<int> primes[n + 1], po[lim2];
  segment_tree seg;
  for(int i = 1; i <= n; ++i) {
    seg.updatea(i, a[i]);
    for(auto j : pf[a[i]])
      po[j].pb(i);
    primes[i] = pf[a[i]];
  }
  int inv[lim2];
  for(int i = 2; i < lim2; ++i) {
      if(po[i].size()) {
        reverse(po[i].begin(), po[i].end());
        assert(po[i].size());
        seg.updateb(po[i].back(), (inv[i] = mul(i - 1, powmod(i, mod - 2))));
        po[i].pop_back();
        // cerr << i << " " << i - 1 << " " << powmod(i, mod - 2) << " " << inv[i] << " " << mul(i - 1, powmod(i, mod - 2)) << endl;
      }
  }
  int l = 1;
  for(auto p : que) {
    while(l < p.fi.fi) {
      for(auto i : primes[l]) {
        // find next occur of primes
        // cerr << "PRIME " << i << endl;
        if(po[i].size()) {
          seg.updateb(po[i].back(), inv[i]);
          po[i].pop_back();
        }
      }
      ++l;
    }
    ans[p.se] = seg.query(1, 0, lim - 1, p.fi.fi, p.fi.se);
    // cerr << "SEP" << endl;
  }
  // cerr << (2 * powmod(2, mod - 2)) % mod << endl;
  for(auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}