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
ll pmod[1000005];

struct segtree {
  int sz;
  vector<ll> a, lazy;
  segtree(int sz) {
    int asz = 1;
    while (asz < sz) asz <<= 1;
    this->sz = asz;
    asz <<= 1;
    a = vector<ll>(2 * asz + 5, 0);
    lazy = vector<ll>(2 * asz + 5, 0);
  }

  void propagate(int nd, int cl, int cr) {
    if (cl != cr) {
      lazy[nd << 1] += lazy[nd];
      lazy[(nd << 1) | 1] += lazy[nd];
    }
    // if (a[nd] > 0) {
    //   cerr << "propagate: " << a[nd] << " " << (a[nd] * pmod[lazy[nd]]) % mod << endl;
    // }
    a[nd] = (a[nd] * pmod[lazy[nd]]) % mod;
    lazy[nd] = 0;
  }

  void add(int nd, int cl, int cr, int idx, int val) {
    propagate(nd, cl, cr);
    if (cl == cr) {
      // cerr << "adding " << nd << endl;
      a[nd] += val;
      a[nd] %= mod;
      // cerr << "value is " << a[nd] << endl;
      return;
    }
    int mid = (cl + cr) >> 1;
    if (idx <= mid) {
      add(nd << 1, cl, mid, idx, val);
    } else {
      add((nd << 1) | 1, mid + 1, cr, idx, val);
    }
  }

  void add(int idx, int val) {
    return add(1, 0, sz - 1, idx, val);
  }

  void update(int nd, int cl, int cr, int l, int r) {
    propagate(nd, cl, cr);
    if (cl >= l && cr <= r) {
      ++lazy[nd];
      propagate(nd, cl, cr);
    } else if (cl > r || cr < l) {
      return;
    } else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r);
      update((nd << 1) | 1, mid + 1, cr, l, r);
    }
  }

  void update(int l, int r) {
    return update(1, 0, sz - 1, l, r);
  }
  
  ll query(int nd, int cl, int cr, int idx) {
    propagate(nd, cl, cr);
    if (cl == cr) {
      // cerr << "query " << nd << " " << a[nd] << endl;
      return a[nd];
    }

    int mid = (cl + cr) >> 1;
    if (idx <= mid) {
      return query(nd << 1, cl, mid, idx);
    } else {
      return query((nd << 1) | 1, mid + 1, cr, idx);
    }
  }

  ll query(int idx) {
    return query(1, 0, sz - 1, idx);
  }
};

void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; ++i) cin >> a[i];

  // must have common highest point (global max)
  // choose the global max
  // then find count of subseq?

  vector<int> fr, bk;

  int tmp = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > tmp) {
      fr.push_back(a[i]);
      tmp = a[i];
    }
  }

  tmp = 0;
  for (int i = n; i >= 1; --i) {
    if (a[i] > tmp) {
      bk.push_back(a[i]);
      tmp = a[i];
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; ++i) mx = max(mx, a[i]);

  segtree dpl(n + 5), dpr(n + 5);

  dpl.add(0, 1);  
  // cerr << "deb " << dpl.query(0) << endl;
  ll lval[n + 5];
  lval[0] = 0;
  for (int i = 1; i <= n; ++i) {
    // smaller -> add
    // larger -> don't add
    auto idx = lb(fr.begin(), fr.end(), a[i]) - fr.begin();
    ll cur_add = 0;
    if (fr[idx] == a[i]) {
      cur_add = dpl.query(idx);
      // cerr << "add " << i << " " << a[i] << " " << idx << " " << cur_add << endl;
    }
    dpl.update(idx + 1, fr.size() - 1);
    dpl.add(idx + 1, cur_add);

    // for (int j = 0; j <= fr.size(); ++j) {
    //   cerr << dpl.query(j) << " ";
    // }
    // cerr << endl;

    lval[i] = dpl.query(fr.size());
  }
  // for (int i = 1; i <= n; ++i) {
  //   cerr << lval[i] << " ";
  // }
  // cerr << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << dpl[i][fr.size()] << " ";
  // }
  // cout << endl;

  reverse(a + 1, a + n + 1);
  dpr.add(0, 1);
  ll rval1[n + 5], rval2[n + 5];
  rval1[0] = rval2[0] = 0;
  if (bk.size() == 1) {
    rval2[0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    // smaller -> add
    // larger -> don't add
    auto idx = lb(bk.begin(), bk.end(), a[i]) - bk.begin();
    ll cur_add = 0;
    if (bk[idx] == a[i]) {
      cur_add = dpr.query(idx);
    }
    dpr.update(idx + 1, bk.size());
    dpr.add(idx + 1, cur_add);
    rval1[i] = dpr.query(bk.size() - 1);
    rval2[i] = dpr.query(bk.size());
  }

  ll res = 0;
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (lval[i] != lval[i - 1]) {
      // cerr << "deb " << i << " " << (dpl[i][fr.size()] - dpl[i - 1][fr.size()]) << " " << dpr[n - i + 1][bk.size()] << endl;
      res += 1ll * (lval[i] - lval[i - 1]) * (rval1[n - i] + rval2[n - i]);
      res %= mod;
    }
  }
  if (res < 0)
    res += mod;
  cout << res << endl;
}

int main() {
  pmod[0] = 1;
  for (int i = 1; i < 1000000; ++i) {
    pmod[i] = pmod[i - 1] << 1;
    if (pmod[i] >= mod) pmod[i] -= mod;
  }

  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // front same and back same
  // consider front only + back only
  // then consider shared view
  int t;
  cin >> t;
  while (t--) {
    tc();
  }
  return 0;
}