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
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
const int lim = 6e5 + 500;
ll bank[lim];
ll powmod(ll a, ll b) {
  if (a == 2 && b < lim) {
    return bank[b];
  }
  if (b == 0) {
    return 1;
  } else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll fact[lim], inv[lim];
ll combinmod(ll a, ll b) {
  return mul(fact[a], mul(inv[a - b], inv[b]));
}
int main() {
  fact[0] = inv[0] = 1, bank[0] = 1;
  for (int i = 1; i < lim; ++i) {
    bank[i] = (bank[i - 1] * 2) % mod;
  }
  for (int i = 1; i < lim; ++i) {
    fact[i] = mul(i, fact[i - 1]);
    inv[i] = powmod(fact[i], mod - 2);
  }
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int c[n + 5];
  for (int i = 1; i <= n; ++i) cin >> c[i];

  // recompute for every query, each recompute is O(n^2)?
  int cnt[61];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) ++cnt[c[i]];

  for (int que = 1; que <= m; ++que) {
    int t;
    ll x;
    cin >> t >> x;
    if (t == 1) {
      ++cnt[x];
    } else if (t == 2) {
      --cnt[x];
    } else {
      // calculate dp
      // must be at least x
      // observe that we only consider the "submask"
      // too small -> never possible...
      // dp[n][2]
      // dp[n][0] -> == to submask
      // dp[n][1] -> > then submask
      // change to bit rep.
      // cerr << __LINE__ << endl;
      vector<int> vals;
      for (int i = 0; i < 61; ++i) {
        if ((1ll << i) & x) {
          vals.push_back(i);
        }
      }
      // cerr << __LINE__ << endl;

      int tmp[61];
      memset(tmp, 0, sizeof(tmp));
      reverse(vals.begin(), vals.end());
      // add "padding" to "normalize"
      for (int i = 0; i < vals.size(); ++i) {
        vals[i] += i;
        tmp[vals[i]]++;
      }
      // cerr << __LINE__ << endl;

      vector<pair<int, int>> a;
      for (int i = 0; i <= 60; ++i) {
        if (tmp[i] > 0) {
          a.emplace_back(i, tmp[i]);
        }        
      }
      reverse(a.begin(), a.end());
      // cerr << __LINE__ << endl;

      a.insert(a.begin(), {61, 0});
      ll preq = 1; // previous exact equal
      int suff[65]; // suff of cnt
      memset(suff, 0, sizeof(suff));
      for (int i = 60; i >= 0; --i) {
        suff[i] = suff[i + 1] + cnt[i];
      }
      // cerr << __LINE__ << endl;

      int pref[65]; // pref of cnt
      memset(pref, 0, sizeof(pref));
      for (int i = 0; i <= 60; ++i) {
        pref[i] = (i == 0 ? 0 : pref[i - 1]) + cnt[i];
      }
      // cerr << __LINE__ << endl;

      ll res = 0;
      for (int i = 1; i < a.size(); ++i) {
        // cerr << __LINE__ << " " << i << endl;
        int lgcnt = suff[a[i].fi + 1] - suff[a[i - 1].fi];
       
        // count of larger:
        // - choose something larger than we should
        // - choose more of current than we should
        // cerr << __LINE__ << " " << lgcnt << endl;
        ll choose_larger = mul(preq, powmod(2, lgcnt) - 1);
        // cerr << __LINE__ << endl;
        choose_larger %= mod;
        // can choose any smaller
        choose_larger = mul(choose_larger, powmod(2, pref[a[i].fi]));
        // cerr << __LINE__ << endl;
        // add choose_larger
        res += choose_larger;

        int need = a[i].se;
        if (cnt[a[i].fi] < need) {
          preq = 0;
          break;
        }
        // cerr << __LINE__ << endl;
        // choose more than need:
        ll choose_more = 0;
        // use binom theorem + combin
        // cerr << __LINE__ << endl;
        for (int j = 0; j <= need; ++j) {
          choose_more += combinmod(cnt[a[i].fi], j);
        }
        // cerr << __LINE__ << endl;

        choose_more %= mod;
        // get sum of choose vals > need
        choose_more = powmod(2, cnt[a[i].fi]) - choose_more;
        // cerr << __LINE__ << endl;
        // multiply by choose any smaller value
        // cerr << "choose more cnt " << cnt[a[i].fi] << " " << need << " " << choose_more << endl;
        choose_more = mul(choose_more, powmod(2, a[i].fi == 0 ? 0 : pref[a[i].fi - 1]));
        choose_more = mul(choose_more, preq);
        // cerr << __LINE__ << endl;
        res += choose_more;

        // chose exactly equal to need:
        // cerr << __LINE__ << endl;
        preq = mul(preq, combinmod(cnt[a[i].fi], need));
        // cerr << i << " " << a[i].fi << " " << choose_larger << " " << choose_more << endl;
        // cerr << __LINE__ << endl;
      }
      // cerr << __LINE__ << endl;
      // add any smaller values between a.back().fi - 1 ... 0
      // cerr << "DEB " << preq << endl;
      res += mul(preq, powmod(2, a.back().fi == 0 ? 0 : pref[a.back().fi - 1]));
      res %= mod;
      if (res < 0) res += mod;

      cout << res << endl;
    }
  }

  return 0;
}