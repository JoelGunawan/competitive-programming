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
int mod = 1e9 + 9;
int key[] = {67, 69, 998244353, 420697367};
int p = 1e9 + 7;
const int lim = 1 << 12;
ll power[lim + 5];
vector<int> perms[24];
ll powmod(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
struct segtree {
  int lazy[lim << 1];
  vector<ll> cnt[lim << 1];
  segtree() {
    memset(lazy, 0, sizeof(lazy));
    for (int i = 0; i < lim << 1; ++i) cnt[i] = vector<ll>(4, 0), cnt[i][0] = 1;
  }

  void propagate(int nd, int cl, int cr) {
    lazy[nd] %= 4;
    if (cl != cr) {
      lazy[nd << 1] += lazy[nd];
      lazy[(nd << 1) | 1] += lazy[nd];
    }
    vector<ll> tmp = cnt[nd];
    for (int i = 0; i < 4; ++i) {
      cnt[nd][i] = tmp[(i + 4 - lazy[nd]) % 4];
    }
  }

  void update(int nd, int cl, int cr, int l, int r, int shift) {
    // cerr << __LINE__ << endl;
    propagate(nd, cl, cr);
    // cerr << __LINE__ << endl;
    if (cl >= l && cr <= r) {
      // cerr << __LINE__ << endl;
      lazy[nd] += shift;
      // cerr << __LINE__ << endl;
      return;
    } else if (cr < l ||cr > l) {
      return;
    } else {
      // cerr << __LINE__ << endl;
      int mid = (cl + cr) >> 1;
      // cerr << __LINE__ << endl;
      update(nd << 1, cl, mid, l, r, shift);
      // cerr << __LINE__ << endl;
      update((nd << 1) | 1, mid + 1, cr, l, r, shift);
      // cerr << __LINE__ << endl;
      // update cnt here
      for (int i = 0; i < 4; ++i) {
        // cerr << __LINE__ << endl;
        cnt[nd][i] = cnt[nd << 1][i] + cnt[(nd << 1) | 1][i] + cnt[nd << 1][i] * power[mid - cl + 1];
        // cerr << __LINE__ << endl;
        cnt[nd][i] %= mod;
        // cerr << __LINE__ << endl;
      }
      // cerr << __LINE__ << endl;
    }
  }

  pair<ll, int> query(int nd, int cl, int cr, int l, int r, int perm) {
    propagate(nd, cl, cr);
    if (cl >= l & cr <= r) {
      // get for permutation, then return cnt of elems
      ll cur = 0;
      auto cur_perm = perms[perm];
      for (int i = 0; i < 4; ++i) {
        cur += cnt[nd][i] * key[cur_perm[i]];
        cur %= mod;
      }
      return {cur, (cr - cl + 1)}; 
    } else if (cr < l || cr > l) {
      return {0, 0};
    } else {
      int mid = (cl + cr) >> 1;
      auto [lhs, lenl] = query(nd << 1, cl, mid, l, r, perm);
      auto [rhs, lenr] = query((nd << 1) | 1, mid + 1, cr, l, r, perm);
      return {(lhs + rhs + ((lhs * power[lenr]) % mod)) % mod, lenl + lenr};
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // match LHS with all possible permutations on RHS
  // use hashing for check?
  // range update: only change permutation values for that range? -> hard
  power[0] = 1;
  for (int i = 1; i <= lim; ++i) {
    power[i] = (power[i - 1] * p) % mod;
  }
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int val[n + 5];
  segtree seg;
  // cerr << "HERE" << endl;
  for (int i = 0; i < n; ++i) {
    val[i + 1] = s[i] - 'a';
    seg.update(1, 0, lim - 1, i + 1, i + 1, val[i + 1]);
  }

  // cerr << "HERE" << endl;

  vector<int> cur = {0, 1, 2, 3};
  int num = 0;
  do {
    perms[num++] = cur;
  } while (next_permutation(cur.begin(), cur.end()));

  for (int que = 0; que < q; ++que) {
    int t;
    cin >> t;
    if (t == 1) {
      int idx; char c;
      cin >> idx >> c;
      int v = c - 'a';
      int shift = 0;
      if (v < val[idx]) shift =  4 - val[idx] + v;
      else shift = v - val[idx];
      val[idx] = v;
      seg.update(1, 0, lim - 1, idx, idx, shift);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      seg.update(1, 0, lim - 1, l, r, 1);
    } else {
      int l, r, p;
      cin >> l >> r >> p;
      --p;
      auto [base, _] = seg.query(1, 0, lim - 1, l, l + p, 0);
      bool ans = false;
      for (int i = 0; i < 24; ++i) {
        auto [x, _] = seg.query(1, 0, lim - 1, r, r + p, i);
        if (x == base) {
          cerr << "DEB " << l << " " << r << " " << p << " " << i << " " << base << " " << x << endl;
          ans = true;
        }
      }

      cout << (ans ? "YA" : "TIDAK") << endl;
    }
  }

  return 0;
}