// header file
#include <bits/stdc++.h>
// pragma
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC opitmize("Ofast")
#pragma GCC opitmize("unroll-loops")
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
const int lim = 6e5 + 5;
struct fenwick {
  int a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    // cerr << idx << endl;
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  void update(int l, int r, int val) {
    if(l <=r) {
      update(l, val);
      update(r + 1, -val);
    }
  }
  int query(int idx) {
    int res = 0;
    while(idx) {
      res += a[idx];
      idx -= idx&-idx;
    }
    return res;
  }
} cur;
struct disjoint_setr {
  int h[lim];
  void reset() {
    memset(h, -1, sizeof(h));
  }
  disjoint_setr() {
    reset();
  }
  int nxt(int x) {
    return h[x] == -1 ? x : h[x] = nxt(h[x]);
  }
  void erase(int x) {
    merge(x, x + 1);
  }
  void merge(int x, int y) {
    x = nxt(x), y = nxt(y);
    if(x != y) {
      if(x < y)
        swap(x, y);
      h[y] = x;
    }
  }
} redr, bluer;
struct disjoint_setl {
  int h[lim];
  void reset() {
    memset(h, -1, sizeof(h));
  }
  disjoint_setl() {
    reset();
  }
  int prv(int x) {
    return h[x] == -1 ? x : h[x] = prv(h[x]);
  }
  void erase(int x) {
    merge(x - 1, x);
  }
  void merge(int x, int y) {
    x = prv(x), y = prv(y);
    if(x != y) {
      if(x > y)
        swap(x, y);
      h[y] = x;
    }
  }
} redl, bluel;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[2 * n + 5];
  for(int i = 1; i <= 2 * n; ++i)
    cin >> a[i];
  int b[n + 5], c[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  for(int i = 1; i <= n; ++i)
    cin >> c[i];
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1);
  int l = 0, r = 1e9, res = -1;
  vector<pair<int, int>> v;
  for(int i = 1; i <= 2 * n; ++i)
    v.pb(mp(a[i], i));
  sort(v.begin(), v.end());
  pair<int, int> validb[2 * n + 5], validr[2 * n + 5];
  while(l <= r) {
    memset(cur.a, 0, sizeof(cur.a));
    redl.reset();
    redr.reset();
    bluel.reset();
    bluer.reset();
    int mid = (l + r) >> 1;
    // max diff -> mid
    // try each partition what is the max diff
    // nanti ada banyak validity test, tinggal cek validity testnya mana aja
    int b1 = 1, b2 = 1, r1 = 1, r2 = 1;
    for(auto p : v) {
      // cerr << p.fi << " " << mid << " " << b[b1] << endl;
      b2 = max(b2, 1), r2 = max(r2, 1);
      while(b1 <= n && p.fi - mid > b[b1])
        ++b1;
      while(b2 <= n && p.fi + mid >= b[b2])
        ++b2;
      while(r1 <= n && p.fi - mid > c[r1])
        ++r1;
      while(r2 <= n && p.fi + mid >= c[r2])
        ++r2;
      validb[p.se] = mp(b1, b2 - 1);
      validr[p.se] = mp(r1, r2 - 1);
      // cerr << b1 << " " << b2 << " " << r1 << " " << r2 << endl;
    }
    // for(int i = 1; i <= 2 * n; ++i) {
    //   // idx of element >= a[i] - mid
    //   validb[i].fi = lower_bound(b + 1, b + n + 1, a[i] - mid) - b;
    //   // idx of element <= a[i] + mid
    //   validb[i].se = upper_bound(b + 1, b + n + 1, a[i] + mid) - b - 1;
    //   // idx of element >= a[i] - mid
    //   validr[i].fi = lower_bound(c + 1, c + n + 1, a[i] - mid) - c;
    //   // idx of element <= a[i] + mid
    //   validr[i].se = upper_bound(c + 1, c + n + 1, a[i] + mid) - c - 1;
    //   // if(mid == 1) {
    //   //   cerr << a[i] + mid << " " << upper_bound(c + 1, c + n + 1, a[i] + mid) - c - 1 << " " << validr[i].se << endl;
    //   // }
    // }
    // cerr << "TEST" << endl;
    for(auto p : v) {
      // process
      // cerr << "UPDATE" << endl;
      cur.update(max(1, p.se - n + 1), p.se, 1);
      // observe that blue on left/right of that segment can be invalid
      int idx = p.se;
      // cerr << "TEST" << endl;
      int val;
      while((val = bluer.nxt(max(1, p.se - n + 1))) <= p.se && val > 0) {
        int tmp2 = cur.query(val);
        if(tmp2 < validb[idx].fi || tmp2 > validb[idx].se)
          bluer.erase(val), bluel.erase(val);
        else
          break;
      }
      while((val = bluel.prv(p.se)) >= max(1, p.se - n + 1)) {
        int tmp2 = cur.query(val);
        if(tmp2 < validb[idx].fi || tmp2 > validb[idx].se)
          bluer.erase(val), bluel.erase(val);
        else
          break;
      }
      // cerr << "DONE" << endl;
      if(p.se <= n) {
        cur.update(p.se + n + 1, 2 * n, 1);
        // observe that blue on left/right of that segment can be invalid
        while((val = bluer.nxt(p.se + n + 1)) <= 2 * n) {
          // cerr << val << endl;
          int tmp2 = cur.query(val);
          // cerr << "AFTER" << endl;
          if(tmp2 < validb[idx].fi || tmp2 > validb[idx].se) {
            bluer.erase(val), bluel.erase(val);
            // cerr << "HERE" << endl;
          }
          else
            break;
        }
        // cerr << "CHECK" << endl;
        while((val = bluel.prv(2 * n)) >= p.se + n + 1) {
          // cerr << val << endl;
          int tmp2 = cur.query(val);
          if(tmp2 < validb[idx].fi || tmp2 > validb[idx].se)
            bluer.erase(val), bluel.erase(val);
          else
            break;
        } 
      }
      // cerr << "TEST2" << endl;
      while((val = redr.nxt(max(1, p.se - n + 1))) <= p.se && val > 0) {
        // cerr << "check " << *it << " due to " << p.se << " " << cur.query(*it) << " " << validr[idx].fi << endl; 
        int tmp2 = cur.query(val);
        if(tmp2 < validr[idx].fi || tmp2 > validr[idx].se)
          redr.erase(val), redl.erase(val);
        else
          break;
      }
      while((val = redl.prv(p.se)) >= max(1, p.se - n + 1)) {
        // cerr << "check " << *it << " due to " << p.se << " " << cur.query(*it) << " " << validr[idx].se << endl; 
        int tmp2 = cur.query(val);
        if(tmp2 < validr[idx].fi || tmp2 > validr[idx].se)
          redr.erase(val), redl.erase(val);
        else
          break;
      }
      if(p.se <= n) {
        // observe that red on left/right of that segment can be invalid
        while((val = redr.nxt(p.se + n + 1)) <= 2 * n) {
          // cerr << "check " << *it << " due to " << p.se << " " << cur.query(*it) << " " << validr[idx].fi << endl; 
          int tmp2 = cur.query(val);
          if(tmp2 < validr[idx].fi || tmp2 > validr[idx].se)
            redr.erase(val), redl.erase(val);
          else
            break;
        }
        while((val = redl.prv(2 * n)) >= p.se + n + 1) {
          // cerr << "check " << *it << " due to " << p.se << " " << cur.query(*it) << " " << validr[idx].se << endl; 
          int tmp2 = cur.query(val);
          if(tmp2 < validr[idx].fi || tmp2 > validr[idx].se)
            redr.erase(val), redl.erase(val);
          else
            break;
        } 
      }
      // cerr << "FINISH" << endl;
    }
    // blue and red have to complement each other
    bool ans = 0;
    // cerr << "MID IS " << mid << endl;
    for(int i = 1; i + n <= 2 * n; ++i) {
      // cerr << i << " " << i + n << endl;
      // cerr << bluel.prv(i) << " " << bluel.prv(i + n) << endl;
      // cerr << redl.prv(i) << " " << redl.prv(i + n) << endl;
      if((bluel.prv(i) == i && redl.prv(i + n) == i + n) || (redl.prv(i) == i && bluel.prv(i + n) == i + n))
        ans = 1;
      // cerr << "DONE" << endl;
    }
    /*
    if(mid <= 20) {
      cerr << "DEBUG " << mid << endl;
      for(auto x : red) {
        cerr << x << " ";
      }
      cerr << endl;
      for(auto x : blue) {
        cerr << x << " ";
      }
      cerr << endl;
    }
    */
    if(ans) 
      r = mid - 1, res = mid;
    else
      l = mid + 1;
  }
  cout << res << endl;
  // choose a contiguous segment L to R such that we use one color
  // N^2 approach -> pair greedily (sorted)
  // int res = 1e9;
  // for(int i = 1; i + n <= 2 * n + 1; ++i) {
  //   vector<int> blue, red;
  //   for(int j = 1; j < i; ++j) {
  //     blue.pb(a[j]);
  //   }
  //   for(int j = i; j < i + n; ++j) {
  //     red.pb(a[j]);
  //   }
  //   for(int j = i + n; j <= 2 * n; ++j) {
  //     blue.pb(a[j]);
  //   }
  //   sort(blue.begin(), blue.end());
  //   sort(red.begin(), red.end());
  //   int mx = 0;
  //   for(int k = 1; k <= n; ++k) {
  //     mx = max({mx, abs(blue[k - 1] - b[k]), abs(red[k - 1] - c[k])});
  //   }
  //   res = min(res, mx);
  //   mx = 0;
  //   swap(red, blue);
  //   for(int k = 1; k <= n; ++k) {
  //     mx = max({mx, abs(blue[k - 1] - b[k]), abs(red[k - 1] - c[k])});
  //   }
  //   res = min(res, mx);
  // }
  // cout << res << endl;
  return 0;
}