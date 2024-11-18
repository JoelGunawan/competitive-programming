// header file
#include <bits/stdc++.h>
// pragma
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
const int lim = 1 << 21;
const int lim2 = 4e6 + 5;
const int inf = 1e9 + 5;
// find min index that has value >= x
int a[lim << 1];
void update(int idx, int val) {
  if(idx < 0)
    return;
  idx += lim;
  a[idx] = val;
  while(idx > 0) {
    idx >>= 1;
    a[idx] = max(a[idx << 1], a[(idx << 1) | 1]);
  }
}
// return index, guaranteed to exist
int query(int x) {
  int nd = 1, cl = 0, cr = lim - 1;
  while(cl != cr) {
    int mid = (cl + cr) >> 1;
    if(a[nd << 1] >= x) {
      cr = mid;
      nd = nd << 1;
    }
    else {
      cl = mid + 1;
      nd = (nd << 1) | 1;
    }
  }
  return cl;
}
int main() {
  memset(a, 0, sizeof(a));
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    set<pair<int, int>> s;
    s.insert(mp(-1, -1));
    s.insert(mp(1, lim2));
    update(1, lim2);
    auto it = s.begin();
    pair<int, int> a;
    for(int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      // split at x
      // find first segment that has l <= x
      it = --s.ub(mp(x, inf));
      pair<int, int> cur = *it;
      pair<int, int> nl, nr;
      nl = mp(cur.fi, x - 1);
      nr = mp(x + 1, cur.se);
      s.erase(it);
      update(cur.fi, 0);
      if(nl.fi <= nl.se)
        s.ins(nl), update(nl.fi, nl.se - nl.fi + 1);
      if(nr.fi <= nr.se)
        s.ins(nr), update(nr.fi, nr.se - nr.fi + 1);
    }
    // segment of non existent
    int m;
    cin >> m;
    while(m--) {
      char t;
      int x;
      cin >> t >> x;
      if(t == '+') {
        // add
        // check split segment
        // split this segment
        it = --s.ub(mp(x, inf));
        pair<int, int> cur = *it;
        pair<int, int> nl, nr;
        nl = mp(cur.fi, x - 1);
        nr = mp(x + 1, cur.se);
        s.erase(it);
        update(cur.fi, 0);
        if(nl.fi <= nl.se)
          s.ins(nl), update(nl.fi, nl.se - nl.fi + 1);
        if(nr.fi <= nr.se)
          s.ins(nr), update(nr.fi, nr.se - nr.fi + 1);
      }
      else if(t == '-') {
        // reduce
        // check merge segment
        pair<int, int> cur = mp(x, x);
        it = --s.ub(mp(x, inf)); 
        if((*it).se == x - 1) {
          a = *it;
          update(a.fi, 0);
          cur.fi = (*it).fi;
          s.erase(it);
        }
        // check merge with nx only
        it = s.ub(mp(x, inf));
        if((*it).fi == x + 1) {
          a = *it;
          update(a.fi, 0);
          cur.se = (*it).se;
          s.erase(it);
        }
        s.ins(cur);
        update(cur.fi, cur.se - cur.fi + 1);
      }
      else {
        // find k-load
        // for(auto p : s) {
        //   cout << p.fi << " " << p.se << endl;
        // }
        cout << query(x) << " ";
      }
    }
    cout << endl;
    for(auto p : s) {
      update(p.fi, 0);
    }
  }
  return 0;
}