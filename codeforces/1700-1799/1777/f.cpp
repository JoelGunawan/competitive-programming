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
struct node {
  node *c[2];
  vector<int> v;
};
struct trie_obj {
  node *head = new node();
  int shift = 0;
  void update(node *nd, int depth, int val, int cnt) {
    nd->v.pb(cnt);
    if(depth == -1)
      return;
    bool x = (1 << depth) & val;
    if(!nd->c[x])
      nd->c[x] = new node();
    update(nd->c[x], depth - 1, val, cnt);
  }
  void update(int val, int cnt) {
    update(head, 29, val ^ shift, cnt);
  }
  int query(node *nd, int depth, int val, int l, int r) {
    if(!nd || depth == -1)
      return 0;
    bool x = (1 << depth) & val;
    if(nd->c[!x] && lb(nd->c[!x].begin(), nd->c[!x].end(), ))
      return query(nd->c[!x], depth - 1, val) + (1 << depth);
    else
      return query(nd->c[x], depth - 1, val);
  }
  int query(int val, int l, int r) {
    return query(head, 29, val ^ shift, l, r);
  }
  void clear(node *nd) {
    if(!nd)
      return;
    clear(nd->c[0]), clear(nd->c[1]);
    delete nd;
  }
  ~trie_obj() {
    clear(head);
  }
};
void tc() {
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  a[0] = 1e9;
  // v -> maintains maximum
  // query every time
  int res = 0;
  int pref[n + 1];
  memset(pref, 0, sizeof(pref));
  for(int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] ^ a[i];
    trie_obj cur;
    if(a[i] > a[v.back()]) {
      // cerr << "REMOVE " << (a[v.back()] ^ pref[v.back() - 1]) << endl;
      // old prefix changes to the dominant one
      merge(cur, v.back().se);
      v.pop_back();
    }
    // cerr << "INSERT " << (a[i] ^ pref[i - 1]) << endl;
    cur.update(pref[i - 1] ^ a[i]);
    v.pb(mp(i, cur));
    // cerr << "QUERY " << pref[i] << endl;
    res = max(res, trie.query(trie.head, 29, pref[i]));
    // cerr << res << endl;
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}