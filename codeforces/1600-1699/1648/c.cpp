// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
const int lim = 2e5 + 5;
int mod = 998244353;
struct fenwick {
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    int ret = 0;
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

ll mul(ll a, ll b) {
  return (a * b) % mod;
}

ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = mul(tmp, tmp);
    return b & 1 ? mul(tmp, a) : tmp;
  }
}

ll fact[lim], inv[lim];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  fact[0] = inv[0] = 1;
  for(int i = 1; i < lim; ++i)
    fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
  int n, m;
  cin >> n >> m;
  int s[n + 1], t[m + 1];
  for(int i = 1; i <= n; ++i)
    cin >> s[i];
  for(int i = 1; i <= m; ++i)
    cin >> t[i];
  // find count of less than or equal to x using fenwick
  fenwick bit;
  map<int, int> occur;
  for(int i = 1; i <= n; ++i) {
    ++occur[s[i]];
    bit.update(s[i], 1);
  }
  ll dupe = 1;
  for(auto p : occur) {
    dupe = mul(dupe, inv[p.se]);
  } 
  ll res = 0;
  bool to_end = 1;
  for(int i = 1; i <= min(n, m); ++i) {
    //cout << i << " " << mul(bit.query(1, t[i] - 1), mul(fact[n - i], dupe)) << endl;
    res += mul(bit.query(1, t[i] - 1), mul(fact[n - i], dupe));
    if(occur[t[i]]) {
      dupe = mul(dupe, fact[occur[t[i]]]);
      --occur[t[i]];
      dupe = mul(dupe, inv[occur[t[i]]]);
      bit.update(t[i], -1);
    }
    else {
      to_end = 0;
      break;
    }
  }
  if(to_end && n < m)
    ++res;
  cout << res % mod << endl;
  return 0;
}