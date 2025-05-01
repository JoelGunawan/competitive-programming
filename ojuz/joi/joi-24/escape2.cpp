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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, t;
  cin >> n >> t;
  // fi -> (city, next flight idx)
  // se -> (time of arrival, time elapsed)
  // each city has different number of flights
  vector<pair<pair<ll, ll>, pair<ll, ll>>> nxt[17][n + 1];
  vector<pair<ll, ll>> flights[n + 1];
  int sum_flights = 0;
  for (ll i = 1; i < n; ++i) {
    ll m;
    cin >> m;
    sum_flights += m;
    vector<pair<ll, ll>> a;
    for (ll i = 1; i <= m; ++i) {
      ll x, y;
      cin >> x >> y;
      a.pb(mp(x, y));
    }
    sort(a.begin(), a.end());
    priority_queue<pair<ll, ll>> pq;
    vector<pair<ll, ll>> res;
    for (auto [l, r] : a) {
      while (pq.size() && pq.top().fi < l) {
        res.push_back(mp(pq.top().se, pq.top().fi));
        pq.pop();
      }
      while (pq.size() && pq.top().fi >= r) {
        pq.pop();
        while (pq.size() && pq.top().fi < l) {
          res.push_back(mp(pq.top().se, pq.top().fi));
          pq.pop();
        }
      }
      pq.push({r, l});
    }
    while (pq.size()) {
      res.push_back(mp(pq.top().se, pq.top().fi));
      pq.pop();
    }
    sort(res.begin(), res.end());
    flights[i] = res;
  }
  for(ll i = n - 1; i >= 1; --i) {
    for (ll j = 0; j < 17; ++j) {
      nxt[j][i].resize(flights[i].size() + 1);
    }
    for (ll j = 0; j < 17; ++j) {
      for (ll k = 0; k < flights[i].size(); ++k) {
        if (j == 0) {
          nxt[j][i][k] = mp(mp(i + 1, lb(flights[i + 1].begin(), flights[i + 1].end(), mp(flights[i][k].se, 0ll)) - flights[i + 1].begin()), mp(flights[i][k].se, flights[i][k].se - flights[i][k].fi));
          // cerr << "DEB2 " << i << " " << k << " " << nxt[j][i][k].fi.fi << " " << nxt[j][i][k].fi.se << " " << nxt[j][i][k].se.fi << " " << nxt[j][i][k].se.se << endl;
        } else {
          auto [city, idx] = nxt[j - 1][i][k].fi;
          auto [toa, elapsed] = nxt[j - 1][i][k].se;
          if (city == n || city == 0) {
            // cerr << "NXT " << j << " " << i << " " << k << " " << city << endl;
            continue;
          }
          if (idx == flights[city].size()) {
            elapsed += t - toa + flights[city][0].fi;
            idx = 0;
          } else {
            elapsed += flights[city][idx].fi - toa;
          }
          nxt[j][i][k] = mp(nxt[j - 1][city][idx].fi, mp(nxt[j - 1][city][idx].se.fi, elapsed + nxt[j - 1][city][idx].se.se));
          // cerr << "DEB3 " << j << " " << i << " " << k << " " << nxt[j - 1][city][idx].fi.fi << " " << nxt[j - 1][city][idx].fi.se << endl;
        }
      }
    }
  }

  int blk = 150;
  // now calculate special
  bool special[n + 1];
  memset(special, 0, sizeof(special));
  vector<pair<ll, int>> memo_ans[n + 1];
  vector<pair<ll, int>> nxt_use[n + 1];
  int nxt_skip[n + 1];
  memset(nxt_skip, -1, sizeof(nxt_skip));
  ll ans[max(2000, 2 * n + 5)], use[max(2000, 2 * n + 5)];
  fill(ans, ans + n + 5, 1e18);
  fill(use, use + n + 5, 1e18);
  for (int i = n - 1; i >= 1; --i) {
    if (flights[i].size() >= blk) {
      special[i] = 1;
      // simulate all the flights until we find non-special
      for (int j = i; j <= i + 670; ++j) {
        ans[j] = 1e18;
      }
      for (int j = 0; j <= blk + 1; ++j) {
        use[j] = 1e18;
      }
      for (int j = 0; j < flights[i].size(); ++j) {
        ll time_used = 0;
        int city = i, idx = j, cur_t = flights[i][j].fi;
        while (flights[city].size() >= blk) {
          pair<pair<ll, ll>, pair<ll, ll>> tmp = nxt[0][city][idx];
          auto [nx_city, nx_idx] = tmp.fi;
          auto [toa, elapsed] = tmp.se;
          time_used += elapsed;
          // cerr << "GOT HERE" << endl;
          ans[nx_city] = min(ans[nx_city], time_used);
          // cerr << "CALC ANS" << endl;
          if (nx_city != n) {
            if (nx_idx == flights[nx_city].size()) {
              time_used += t - toa + flights[nx_city][0].fi;
              nx_idx = 0;
            } else {
              time_used += flights[nx_city][nx_idx].fi - toa;
            }
          } else {
            break;
          }
          // cerr << "REACHED THIS" << endl;
          if (!special[nx_city]) {
            nxt_skip[i] = nx_city;
            use[nx_idx] = min(use[nx_idx], time_used);
          }
          city = nx_city;
          idx = nx_idx;
        }
      }
      for (int j = i; j <= i + 670; ++j) {
        if (ans[j] < 1e18 - 5) {
          memo_ans[i].push_back({ans[j], j});
        }
      }
      for (int j = 0; j <= blk + 1; ++j) {
        if (use[j] < 1e18 - 5) {
          nxt_use[i].push_back({use[j], j});
        }
      }
    }
  }


  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    // binlift from l to r
    ll ans = 4e18;
    if (special[l]) {
      bool found_ans = 0;
      for (auto p : memo_ans[l]) {
        if (p.se == r) {
          found_ans = 1;
          cout << p.fi << endl;
        }
      }
      if (found_ans)
        continue;
      for (ll init = 0; init < nxt_use[l].size(); ++init) {
        ll res = nxt_use[l][init].first;
        ll pos = nxt_skip[l], idx = nxt_use[l][init].second;
        // cerr << res << " " << pos << " " << idx << endl;
        for (ll i = 16; i >= 0; --i) {
          if (nxt[i][pos][idx].fi.fi > 0 && nxt[i][pos][idx].fi.fi < r) {
            // cerr << "HERE" << endl;
            // cerr << i << " " << pos << " " << idx << " " << nxt[i][pos].size() << endl;
            res += nxt[i][pos][idx].se.se;
            pair<pair<ll, ll>, pair<ll, ll>> tmp = nxt[i][pos][idx];
            pos = tmp.fi.fi;
            idx = tmp.fi.se;
            auto [toa, elapsed] = tmp.se;
            // cerr << toa << " " << elapsed << endl;
            // cerr << "GOT VALUE" << endl;
            if (idx == flights[pos].size()) {
              // cerr << "HERE" << endl;
              // cerr << pos << " " << flights[pos].size() << endl;
              res += t - toa + flights[pos][0].fi;
              idx = 0;
            } else {
              res += flights[pos][idx].fi - toa;
            }
          }
        }
        // cerr << "NEW VALUE: " << 0 << " " << pos << " " << idx << endl;
        ans = min(ans, res + nxt[0][pos][idx].se.se);
      }
    } else {
      for (ll init = 0; init < flights[l].size(); ++init) {
        ll res = 0;
        ll pos = l, idx = init;
        for (ll i = 16; i >= 0; --i) {
          if (nxt[i][pos][idx].fi.fi > 0 && nxt[i][pos][idx].fi.fi < r) {
            // cerr << "HERE" << endl;
            // cerr << i << " " << pos << " " << idx << " " << nxt[i][pos].size() << endl;
            res += nxt[i][pos][idx].se.se;
            pair<pair<ll, ll>, pair<ll, ll>> tmp = nxt[i][pos][idx];
            pos = tmp.fi.fi;
            idx = tmp.fi.se;
            auto [toa, elapsed] = tmp.se;
            // cerr << toa << " " << elapsed << endl;
            // cerr << "GOT VALUE" << endl;
            if (idx == flights[pos].size()) {
              // cerr << "HERE" << endl;
              // cerr << pos << " " << flights[pos].size() << endl;
              res += t - toa + flights[pos][0].fi;
              idx = 0;
            } else {
              res += flights[pos][idx].fi - toa;
            }
          }
        }
        // cerr << "NEW VALUE: " << 0 << " " << pos << " " << idx << endl;
        ans = min(ans, res + nxt[0][pos][idx].se.se);
      }
    }
    cout << ans << endl;
  }
  return 0;
}