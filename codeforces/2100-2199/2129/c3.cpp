#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #define endl "\n"
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
int query(vector<int> &que) {
  cout << "? " << que.size() << " ";
  for (auto x : que) {
    cout << x << " ";
  }
  cout << endl;
  int x;
  cin >> x;
  return x;
}

const int lim = 1000;

int construct(int req, int x, int rhs, vector<int> &v) {
  v.push_back(x);
  v.push_back(rhs);

  int cnt = 1, cur = 1;
  while (req > 0) {
    req -= cnt + 1;
    cur += cnt + 1;
    ++cnt;
    v.push_back(x);
    v.push_back(rhs);
  }

  return cur;
}

void tc() {
  int n;
  cin >> n;
  // do ab, ac, ad, ae, af, .... for all values in one query
  // then do ba, ca, ...
  // then, binary search one valid value?
  // we can do it in 4 queries, then do binary search
  // that would be around 15 queries
  // deterministic, guaranteed to find something UNLESS all is ( or all is ) -> not possible
  
  // do abaca...a
  // guarantee to find all pairs ab, ba in one go :D
  // if nothing, then we actually immediately know they are all equal...
  // next two queries can be really wasteful lol

  vector<int> q;
  q.push_back(1);
  int last;
  for (int i = 2; i <= n; ++i) {
    if (q.size() + 2 > lim) {
      last = i;
      break;
    }
    q.push_back(i);
    q.push_back(1);
  }

  int ans = query(q);
  if (ans == 0) {
    // do another query on remainder
    q.clear();
    q.push_back(1);
    for (int i = last; i <= n; ++i) {
      if (q.size() + 2 > lim) {
        last = i;
        break;
      }
      q.push_back(i);
      q.push_back(1);
    }

    int ans2 = query(q);
    if (ans2 == 0) {
      // do another query on remainder
      int got_last = last;
      q.clear();
      q.push_back(1);
      for (int i = last; i <= n; +i) {
        if (q.size() + 2 > lim) {
          last = i;
          break;
        }
        q.push_back(i);
        q.push_back(1);
      }

      if (got_last != last) {
        // idk, just to be safe...
        assert(false);
      }

      // do binary search on this, guaranteed to exist? -> yes
    }
  }

  // do binary search on q
  int l = 0, r = q.size() - 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    // take mid to r, see if exists there
    // if no, then range becomes l to mid
    vector<int> cur;
    for (int i = mid; i <= r; ++i) {
      cur.push_back(q[i]);
    }
    if (query(cur) > 0) {
      l = mid;
    } else {
      r = mid;
    }
  }

  // yay, found l, r now :D
  int lhs = q[l], rhs = q[r];
  set<int> known, unknown;
  known.insert(lhs);
  known.insert(rhs);
  for (int i = 1; i <= n; ++i) {
    if (known.count(i) == 0) {
      unknown.insert(i);
    }
  }

  vector<int> ansl, ansr;
  ansl.push_back(lhs);
  ansr.push_back(rhs);

  // now, we can find the rest using the quadratic technique, make ()()()..()
  while (unknown.size() > 0) {
    vector<int> que;
    vector<int> vals;
    vector<int> thresholds;
    while (unknown.size() > 0) {
      int new_val = *unknown.begin();
      unknown.erase(unknown.begin());
      vals.push_back(new_val);
      int old_size = que.size();
      int req = 0;
      for (auto x : thresholds) req += x;
      thresholds.push_back(construct(req, new_val, rhs, que));
      que.push_back(rhs);
      if (que.size() > lim) {
        que.resize(old_size);
        vals.pop_back();
        thresholds.pop_back();
        unknown.insert(new_val);
        break;
      }
    }

    ll ans = query(que);
    for (int i = vals.size() - 1; i >= 0; --i) {
      // check if i is LHS or RHS
      // if LHS, should be large, else small
      // cerr << "deb " << vals[i] << " " << ans << " " << thresholds[i] << endl;
      if (ans >= thresholds[i]) {
        ansl.push_back(vals[i]);
        ans -= thresholds[i];
      } else {
        ansr.push_back(vals[i]);
      }
    }
  }


  char res[n + 5];
  for (auto x : ansl) {
    res[x] = '(';
  }

  for (auto x : ansr) {
    res[x] = ')';
  }

  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << res[i];
  }
  cout << endl;
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}