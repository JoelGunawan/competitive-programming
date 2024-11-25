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
int mod = 1e9 + 7;
struct node {
  int l = -1, r = -1;
  ll val = 1;
};
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
const int lim = 1 << 17;
struct segment_tree {
  vector<node> v;
  vector<int> head;
  segment_tree() {
    v = vector<node>(lim << 1);
    v.reserve(1 << 23);
    head.pb(1);
    for(int i = 1; i < lim; ++i)
      v[i].l = i << 1, v[i].r = (i << 1) | 1;
  }
  void update(vector<pair<int, int>> &p) {
    head.pb(v.size());
    v.pb(node());
    update(v[head.back()], v[head[head.size() - 2]], 0, lim - 1, p);
  }
  void update(node &c, node &pr, int cl, int cr, vector<pair<int, int>> &p) {
    c = pr;
    // cerr << "UPDATE " << cl << " " << cr << endl;
    if(cl == cr) {
      // update
      while(p.size() && p.back().fi == cl)
        c.val = mul(c.val, p.back().se), p.pop_back();
      return;
    }
    int mid = (cl + cr) >> 1;
    if(p.size() && p.back().fi > mid) {
      c.r = v.size();
      v.pb(node());
      update(v[c.r], v[pr.r], mid + 1, cr, p);
    }
    if(p.size() && p.back().fi >= cl) {
      c.l = v.size();
      v.pb(node());
      update(v[c.l], v[pr.l], cl, mid, p);
    }
    c.val = mul(v[c.l].val, v[c.r].val);
  }
  ll query(node c, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r) {
      // cerr << cl << " " << cr << " " << c.val << endl;
      return c.val;
    }
    else if(cl > r || cr < l)
      return 1;
    else {
      int mid = (cl + cr) >> 1;
      return mul(query(v[c.l], cl, mid, l, r), query(v[c.r], mid + 1, cr, l, r));
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  vector<int> primes;
  const int lim2 = 2e5 + 5;
  bool prime[lim2];
  memset(prime, 1, sizeof(prime));
  for(int i = 2; i < lim2; ++i) {
    // cerr << i << endl;
    if(prime[i]) {
      primes.pb(i);
      for(ll j = 1ll * i * i; j < lim2; j += i)
        prime[j] = 0;
    }
  }
  // fi -> idx, se -> power
  vector<pair<int, int>> v[lim2];
  int n;
  cin >> n;
  segment_tree seg;
  for(int i = 1; i <= n; ++i) {
    ll cur;
    cin >> cur;
    vector<pair<int, int>> a;
    for(auto x : primes) {
      if(1ll * x * x > cur) {
        break;
      }
      else if(cur % x == 0) {
        int cnt = 0;
        while(cur % x == 0)
          ++cnt, cur /= x;
        a.pb(mp(x, cnt));
      }
    }
    if(cur > 1)
      a.pb(mp(cur, 1));
    vector<pair<int, int>> updates;
    // cerr << "FACTOR" << endl;
    for(auto p : a) {
      int prime = p.fi, power = p.se;
      // cerr << prime << " " << power << endl;
      // pop smaller
      while(v[prime].size() && v[prime].back().se <= power) {
        updates.pb(mp(v[prime].back().fi, powmod(powmod(prime, v[prime].back().se), mod - 2)));
        int last = v[prime].back().se;
        v[prime].pop_back();
        if(v[prime].size()) {
          updates.pb(mp(v[prime].back().fi, powmod(prime, last)));
          v[prime].back().se += last;
        }
      }
      if(v[prime].size()) { 
        // cerr << "OUT " << v[prime].back().se - power << endl;
        updates.pb(mp(v[prime].back().fi, powmod(powmod(prime, power), mod - 2))), v[prime].back().se -= power;
      }
      v[prime].pb(mp(i, power));
      updates.pb(mp(i, powmod(prime, power)));
    }
    sort(updates.begin(), updates.end());
    // cerr << "UPD" << endl;
    // for(auto x : updates) {
    //   cerr << x.fi << " " << x.se << endl;
    // }
    seg.update(updates);
  }
  int q;
  cin >> q;
  int last = 0;
  while(q--) {
    int l, r;
    cin >> l >> r;
    // cerr << l << " " << r << " " << last << endl;
    l += last, r += last;
    l %= n, r %= n;
    ++l, ++r;
    if(l > r)
      swap(l, r);
    last = seg.query(seg.v[seg.head[r]], 0, lim - 1, l, r);
    // cerr << "QUERYING " << l << " " << r << endl;
    cout << last << endl;
  }
  return 0;
}