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
const int lim = 1 << 10;
typedef uint32_t u32;

__attribute__((cold))
void factor_helper(vector<u32> &vec, u32 &x, u32 y)
{
	do {
		vec.push_back(y);
		x /= y;
	} while (x % y == 0);
}

const int maxp = 45000;
const int P = 4675; // number of primes below maxp

constexpr auto primes = []() constexpr {
    int idx = 0;
    array<int, P> res{};
    array<int, maxp> comp{};
    for(int p = 2; p < maxp; p++) {
        if(!comp[p]) {
            res[idx++] = p;
            for(int j = p; j < maxp; j += p) {
                comp[j] = 1;
            }
        }
    }
    return res;
}();

template<int L, int R>
constexpr void fact_p(auto& vec, u32 &x) {
    if(x % primes[L] == 0) {
        factor_helper(vec, x, primes[L]);
    }
    if constexpr(L + 1 < R) {
        fact_p<L+1, R>(vec, x);   
    }
}

vector<int> factor(u32 x) {
	vector<u32> vec;
	fact_p<0, 800>(vec, x);
	fact_p<800, 1600>(vec, x);
	fact_p<1600, 2400>(vec, x);
	fact_p<2400, 3200>(vec, x);
	fact_p<3200, 4000>(vec, x);
	fact_p<4000, 4675>(vec, x);
	if (x > 1)
		vec.push_back(x);
  vector<int> v;
  for(auto x : vec)
    v.pb(x);
  v.pb(1);
	return v;
}

struct segtree {
  int a[lim << 1];
  segtree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] = val;
    while(idx) {
      idx >>= 1;
      a[idx] = __gcd(a[idx << 1], a[(idx << 1) | 1]);
    }
  }
  int query(int nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)
      return a[nd];
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) >> 1;
      return __gcd(query(nd << 1, cl, mid, l, r), query((nd << 1) | 1, mid + 1, cr, l, r));
    }
  }
  int query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
} sega, segb;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    cerr << "DONE" << endl;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i], sega.update(i, a[i]);
    }
    for(int i = 1; i <= n; ++i)
      cin >> b[i], segb.update(i, b[i]);
    a[0] = b[0] = a[n + 1] = b[n + 1] = 0;
    cerr << "TWO" << endl;
    // only prefix/suffix gcd and it's factors are possible
    // at most log prefix/suffix gcd values
    // at most not much factors
    // 1e4.5 * log * t -> too much
    // observe that it is always optimal to maximize one of them
    // therefore try to maximize one of them and ignore the other
    // for each prefix, find maximum suffix that will work
    cerr << "TEST" << endl;
    int prefa[n + 5], suffa[n + 5], prefb[n + 5], suffb[n + 5];
    prefa[0] = suffa[n + 1] = prefb[0] = suffb[n + 1] = 0;
    for(int i = 1; i <= n; ++i)
      prefa[i] = __gcd(prefa[i - 1], a[i]), prefb[i] = __gcd(prefb[i - 1], b[i]);
    for(int i = n; i >= 1; --i)
      suffa[i] = __gcd(suffa[i + 1], a[i]), suffb[i] = __gcd(suffb[i + 1], b[i]);
    vector<int> fact = factor(a[1]);
    vector<int> fact2 = factor(a[n]);
    for(auto x : fact2)
      fact.pb(x);
    // find longest suffix ranges possible in a, then check b
    sort(fact.begin(), fact.end());
    fact.resize(unique(fact.begin(), fact.end()) - fact.begin());
    reverse(fact.begin(), fact.end());
    int res = 0;
    ll res2 = 0;
    cerr << "GOT FACTORS" << endl;
    pair<int, int> tmp;
    for(auto x : fact) {
      // check left longest using binser
      int la, ra;
      int cl = 1, cr = n;
      la = 0;
      while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(prefa[mid] % x == 0)
          cl = mid + 1, la = mid;
        else
          cr = mid - 1;
      }
      ra = n + 1;
      cl = 1, cr = n;
      while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(suffa[mid] % x == 0) {
          ra = mid, cr = mid - 1;
        }
        else
          cl = mid + 1;
      }
      cerr << "DONE A" << endl;
      if(segb.query(la + 1, ra - 1) % x == 0) {
        cerr << "FOUND " << x << endl;
        cerr << "CHECK " << la + 1 << " " << ra - 1 << " " << segb.query(la + 1, ra - 1) << " " << x << endl;
        // just try this as answer
        // pick optimal b, how?
        // try each factor of prefix and suffix at b, find which is most optimal
        int l = la, r = ra;
        while(l > 0 && segb.query(l, r - 1) % x == 0)
          --l;
        while(r <= n && segb.query(l + 1, r) % x == 0)
          ++r;
        // from l to la and ra to r
        cerr << "DEBUG " << l << " " << r << endl;
        vector<int> factors = factor(b[max(1, l)]);
        vector<int> factors2 = factor(b[min(n, r)]);
        // for each factor, do the same method as for finding a, find longest prefix/suffix possible bounded by la, ra
        for(auto x : factors2)
          factors.pb(x);
        sort(factors.begin(), factors.end());
        reverse(factors.begin(), factors.end());
        cerr << "FACTORING DONE" << endl;
        for(auto cur : factors) {
          int le = -1, re = -1;
          for(int i = l; i <= la; ++i) {
            if(prefb[i] % cur == 0)
              le = i;
            else
              break;
          }
          for(int i = r; i >= ra; --i) {
            if(suffb[i] % cur == 0)
              re = i;
            else
              break;
          }
          if(le != -1 && re != -1 && sega.query(le + 1, re - 1) % cur == 0) {
            cerr << x << " " << cur << endl;
            cerr << "LRB " << le + 1 << " " << re - 1 << endl;
            int ol = le, ro = re;
            while(le > 0 && sega.query(le + 1, ro - 1) % cur == 0)
              --le;
            while(re <= n && sega.query(ol + 1, re - 1) % cur == 0)
              ++re;
            res = max(res, x + cur);
            // between l to la and r to ra
            for(int i = max(l, le); i <= min(la, ol); ++i) {
              res2 += min(re, ra) - max(max(ro, r), i) + 1;
            }
            tmp = mp(x, cur);
            cerr << le << " " << ol << " " << ro << " " << re << endl;
            cerr << res2 << endl;
            // 0 -> 1, 2
            // 1 -> 2
            break;
          }
        }
        break;
      }
    }

    fact = factor(b[1]);
    fact2 = factor(b[n]);
    for(auto x : fact2)
      fact.pb(x);
    // find longest suffix ranges possible in a, then check b
    sort(fact.begin(), fact.end());
    fact.resize(unique(fact.begin(), fact.end()) - fact.begin());
    reverse(fact.begin(), fact.end());
    cerr << "GOT FACTORS" << endl;
    for(auto x : fact) {
      // check left longest using binser
      int la, ra;
      int cl = 1, cr = n;
      la = 0;
      while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(prefb[mid] % x == 0)
          cl = mid + 1, la = mid;
        else
          cr = mid - 1;
      }
      ra = n + 1;
      cl = 1, cr = n;
      while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(suffb[mid] % x == 0) {
          ra = mid, cr = mid - 1;
        }
        else
          cl = mid + 1;
      }
      cerr << "DONE A" << endl;
      if(sega.query(la + 1, ra - 1) % x == 0) {
        cerr << "FOUND " << x << endl;
        cerr << "CHECK " << la + 1 << " " << ra - 1 << " " << sega.query(la + 1, ra - 1) << " " << x << endl;
        // just try this as answer
        // pick optimal b, how?
        // try each factor of prefix and suffix at b, find which is most optimal
        int l = la, r = ra;
        while(l > 0 && sega.query(l, r - 1) % x == 0)
          --l;
        while(r <= n && sega.query(l + 1, r) % x == 0)
          ++r;
        // from l to la and ra to r
        cerr << "DEBUG " << l << " " << r << endl;
        vector<int> factors = factor(a[max(1, l)]);
        vector<int> factors2 = factor(a[min(n, r)]);
        // for each factor, do the same method as for finding a, find longest prefix/suffix possible bounded by la, ra
        for(auto x : factors2)
          factors.pb(x);
        sort(factors.begin(), factors.end());
        reverse(factors.begin(), factors.end());
        cerr << "FACTORING DONE" << endl;
        for(auto cur : factors) {
          int le = -1, re = -1;
          for(int i = l; i <= la; ++i) {
            if(prefa[i] % cur == 0)
              le = i;
            else
              break;
          }
          for(int i = r; i >= ra; --i) {
            if(suffa[i] % cur == 0)
              re = i;
            else
              break;
          }
          if(le != -1 && re != -1 && segb.query(le + 1, re - 1) % cur == 0) {
            cerr << x << " " << cur << endl;
            cerr << "LRB " << le + 1 << " " << re - 1 << endl;
            int ol = le, ro = re;
            while(le > 0 && segb.query(le + 1, ro - 1) % cur == 0)
              --le;
            while(re <= n && segb.query(ol + 1, re - 1) % cur == 0)
              ++re;
            if(res > x + cur)
              break;
            else if(res < x + cur)
              res2 = 0;
            else {
              if(mp(cur, x) == tmp)
                res2 = 0;
            }
            res = max(res, x + cur);
            // between l to la and r to ra
            for(int i = max(l, le); i <= min(la, ol); ++i) {
              res2 += max(0, min(re, ra) - max(max(ro, r), i) + 1);
            }
            cerr << max(l, le) << " " << min(la, ol) << " " << max(ro, r) << " " << min(re, ra) << endl;
            cerr << res2 << endl;
            // 0 -> 1, 2
            // 1 -> 2
            break;
          }
        }
        break;
      }
    }

    cout << res << " " << res2 << endl;
  }
  return 0;
}