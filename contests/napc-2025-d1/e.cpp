#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const int lim = 1 << 20;
const int inf = 1e9;
struct segtree {
  int a[lim << 1];
  segtree() {
    memset(a, 0, sizeof(a));
  }
  void update(int idx, int val) {
    idx += lim;
    a[idx] += val;
    for(int i = idx >> 1; i > 1; i >>= 1) {
      a[i] = a[i << 1] + a[(i << 1) | 1];
    }
  }
  int query(int nd, int cl, int cr, int l) {
    if(a[nd] == 0)
      return inf;
    if(cl >= l) {
      for(;cl != cr;) {
        if(a[nd << 1])
          cr = (cl + cr) >> 1, nd <<= 1;
        else
          cl = ((cl + cr) >> 1) + 1, nd <<= 1, nd |= 1;
      }
      return cl;
    }
    else if(cr < l) {
      return inf;
    }
    else {
      int mid = (cl + cr) >> 1;
      int ret = query(nd << 1, cl, mid, l);
      if(ret != inf)
        return ret;
      else
        return query((nd << 1) | 1, mid + 1, cr, l);
    }
  }
} seg;
void tc() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n == k) {
      cout << 0 << endl;
      return;
    }
    auto add = [&] (int a, int b) -> int {
        a += b;
        if(a >= n)
          a -= n;
        return a;
    };
    auto sub = [&] (int a, int b) -> int {
        a -= b;
        if(a < 0)
            a += n;
        return a;
    };
    int pos[n + 1];
    for(int i = 0; i < n; ++i)
        pos[a[i]] = i;
    ll dp[n + 1][2];
    memset(dp, -1, sizeof(dp));
    if(n == k) {
        cout << 0 << endl;
        return;
    }

    int idxs = 0;
    for(int i = 1; i <= n; ++i) {
        if(pos[i] >= k) {
            dp[i][0] = min(pos[i], sub(n, pos[i]));
            dp[i][1] = min(sub(pos[i], k - 1), sub(n, sub(pos[i], k - 1)));
            // cerr << "VALS " << dp[i][0] << " " << dp[i][1] << endl;
            idxs = i;
            break;
        }
    }
    assert(idxs != 0);

    int vals[n + 1][2];
    vector<pair<int, int>> comp[n];
    for(int i = idxs; i <= n; ++i) {
      comp[pos[i]].push_back({i, 0});
      comp[sub(pos[i], k - 1)].push_back({i, 1});
    }

    // set<int> not_used;
    for(int i = k; i < n; ++i) {
      // not_used.insert(a[i]);
      // bit.update(a[i], 1);
      seg.update(a[i], 1);
    }

    // for large k, do binary search on fenwick/segtree?
    // find first 1 pos
    for(int i = 0; i < n; ++i) {
      for(auto [k1, k2] : comp[i]) {
        // int l = k1 + 1, r = n, ans = -1;
        // int base = bit.query(k1);
        // while(l <= r) {
        //   int mid = (l + r) >> 1;
        //   if(bit.query(mid) - base > 0) {
        //     r = mid - 1, ans = mid;
        //   }
        //   else {
        //     l = mid + 1;
        //   }
        // }
        // cerr << "Q" << endl;
        int ans = seg.query(1, 0, lim - 1, k1);
        if(ans == inf)
          ans = -1;
        // cerr << "SUCCESS" << endl;
        vals[k1][k2] = ans;
        // auto it = not_used.lower_bound(k1);
        // if(it == not_used.end())
        //   vals[k1][k2] = -1;
        // else
        //   vals[k1][k2] = *it;
      }
      // not_used.erase(a[add(i, k)]);
      // not_used.insert(a[i]);
      // bit.update(a[add(i, k)], -1);
      // bit.update(a[i], 1);
      seg.update(a[add(i, k)], -1);
      seg.update(a[i], 1);
    }

    for(int i = k; i < n; ++i) {
      // not_used.insert(a[i]);
      // bit.update(a[i], -1);
      seg.update(a[i], -1);
    }

    ll res = 1e18;
    // how to calculate shift?
    for(int i = idxs; i <= n; ++i) {
        if(dp[i][0] != -1) {
            // find next position that doesn't work given the shift
            int shift = pos[i], lim = vals[i][0];
            // cerr << "WHAT " << lim << endl;
            if(lim == -1) {
              res = min(res, dp[i][0]);
            }
            else {
              lim -= i;
              if(dp[i + lim][0] == -1)
                dp[i + lim][0] = 1e18;
              if(dp[i + lim][1] == -1)
                dp[i + lim][1] = 1e18;
              dp[i + lim][0] = min(dp[i + lim][0], dp[i][0] + min(sub(shift, pos[i + lim]), sub(n, sub(pos[i + lim], shift))));
              dp[i + lim][1] = min(dp[i + lim][1], dp[i][0] + min(sub(shift, sub(pos[i + lim], k - 1)), sub(n, sub(shift, sub(pos[i + lim], k - 1)))));
            }
            shift = sub(pos[i], k - 1), lim = vals[i][1];
            // cerr << "WHAT2 " << lim << endl;
            if(lim == -1) {
              res = min(res, dp[i][1]);
            }
            else {
              lim -= i;
              if(dp[i + lim][0] == -1)
                dp[i + lim][0] = 1e18;
              if(dp[i + lim][1] == -1)
                dp[i + lim][1] = 1e18;
              dp[i + lim][0] = min(dp[i + lim][0], dp[i][1] + min(sub(shift, pos[i + lim]), sub(n, sub(pos[i + lim], shift))));
              dp[i + lim][1] = min(dp[i + lim][1], dp[i][1] + min(sub(shift, sub(pos[i + lim], k - 1)), sub(n, sub(shift, sub(pos[i + lim], k - 1)))));
            }
          // cerr << i << " " << dp[i][0] << " " << dp[i][1] << endl;
        }
    }
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    seg.a[1] = 5;
    while(t--)
        tc();
}