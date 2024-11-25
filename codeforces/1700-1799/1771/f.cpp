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
const int lim = 1 << 18;
struct node {
  node *l, *r;
  int hash = 0;
};
int mod = 1e9 + 9;
ll key[lim], pw[lim];
struct segment_tree {
  node *head[lim];
  int cnt = 0;
  segment_tree() {
    node *init[2 * lim];
    init[1] = head[0] = new node();
    for(int i = 1; i < lim; ++i) {
      init[i << 1] = new node();
      init[(i << 1) | 1] = new node();
      init[i]->l = init[i << 1];
      init[i]->r = init[(i << 1) | 1];
    }
  }
  void update(int idx) {
    node *nd1 = new node();
    head[++cnt] = nd1;
    node *nd2 = head[cnt - 1];
    update(nd1, nd2, 0, lim - 1, idx);
  }
  void update(node *nd1, node *nd2, int cl, int cr, int idx) {
    *nd1 = *nd2;
    if(cl == cr) {
      // cerr << cl << " " << key[cl] << endl;
      if(nd1->hash)
        nd1->hash = 0;
      else
        nd1->hash = key[cl];
    }
    else {
      int mid = (cl + cr) >> 1;
      if(idx <= mid) {
        // go left
        nd1->l = new node();
        update(nd1->l, nd2->l, cl, mid, idx);
      }
      else {
        // go right
        nd1->r = new node();
        update(nd1->r, nd2->r, mid + 1, cr, idx);
      }
      nd1->hash = (1ll * nd1->l->hash * pw[mid - cl + 1] + nd1->r->hash) % mod;
    }
    // cerr << "UP " << cl << " " << cr << " " << nd1->hash << endl;
  }
  // find left most that is not equal
  int query(node *nd1, node *nd2) {
    int cl = 0, cr = lim - 1;
    // cerr << "Q " << nd1->hash << " " << nd2->hash << endl;
    while(nd1->hash != nd2->hash) {
      // cerr << "BINSER " << cl << " " << cr << endl;
      if(cl == cr)
        break;
      int mid = (cl + cr) >> 1;
      // cerr << "CHECK " << nd1->l->hash << " " << nd2->l->hash << " " << nd1->r->hash << " " << nd2->r->hash << endl;
      if(nd1->l->hash != nd2->l->hash)
        cr = mid, nd1 = nd1->l, nd2 = nd2->l;
      else
        cl = mid + 1, nd1 = nd1->r, nd2 = nd2->r;
    }
    return cl == cr ? cl : -1;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  vector<int> v;
  for(int i = 1; i <= n; ++i)
    cin >> a[i], v.pb(a[i]);
  sort(v.begin(), v.end());
  // check if subtree is equal using persistent seg
  // seg -> maintain seg hash for left/right
  // how to maintain seg hash?
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for(int i = 1; i <= n; ++i)
    a[i] = lb(v.begin(), v.end(), a[i]) - v.begin();
  segment_tree seg;
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  pw[0] = 1;
  pw[1] = rng() % mod;
  for(int i = 2; i < lim; ++i)
    pw[i] = (1ll * pw[i - 1] * pw[1]) % mod;
  for(int i = 0; i <= n; ++i)
    key[i] = rng() % mod;
  for(int i = 1; i <= n; ++i)
    seg.update(a[i]);
  int q;
  cin >> q;
  int pr = 0;
  while(q--) {
    int l, r;
    cin >> l >> r;
    l ^= pr, r ^= pr;
    // cerr << "Query " << l << " " << r << endl;
    pr = seg.query(seg.head[l - 1], seg.head[r]);
    pr = pr == -1 ? 0 : v[pr];
    cout << pr << endl;
  }
  return 0;
}