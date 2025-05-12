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
  int n;
  cin >> n;
  int a[n + 1];
  a[0] = 0;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  pair<int, int> prmn[n + 1];
  prmn[0] = mp(0, 0);
  for(int i = 1; i <= n; ++i) {
    prmn[i] = min(prmn[i - 1], mp(a[i] - i, i));
  }
  ll pref[n + 1], suff[n + 5];
  suff[n + 1] = pref[0] = 0;
  for(int i = n; i >= 1; --i) {
    suff[i] = suff[i + 1] + prmn[i].fi;
  }
  for(int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + prmn[i].fi;
  }
  int q;
  cin >> q;
  vector<pair<pair<int, int>, int>> queries;
  for(int i = 0; i < q; ++i) {
    int pos, val;
    cin >> pos >> val;
    queries.pb(mp(mp(pos, val), i));
  }
  ll res[q];
  memset(res, -1, sizeof(res));
  sort(queries.begin(), queries.end());
  int prpos = 0;
  for(auto [p, q_idx] : queries) {
    auto [pos, val] = p;
    if(prpos != pos) {
      // redo all prpos
      int idx = n + 1;
      for(int i = prpos; i <= n; ++i) {
        if(i > 0)
          prmn[i] = min(mp(a[i] - i, i), prmn[i - 1]);
        if(prmn[i].se != prpos) {
          idx = i;
          break;
        }
      }
      for(int i = idx - 1; i >= prpos; --i) {
        suff[i] = suff[i + 1] + prmn[i].fi;
      }
      prpos = pos;
      idx = n + 1;
      for(int i = pos; i <= n; ++i) {
        if(prmn[i].se == pos) {
          prmn[i] = prmn[i - 1];
          if(i != pos) {
            prmn[i] = min(prmn[i], mp(a[i] - i, i));
          } 
        }
        else {
          // update everything from idx - 1 to pos
          idx = i;
          break;
        }
      }
      for(int i = idx - 1; i >= pos; --i) {
        suff[i] = suff[i + 1] + prmn[i].fi;
      }
    }
    int l = pos, r = n, ans = pos - 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(prmn[mid].fi > val - pos) {
        ans = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    res[q_idx] = 1ll * n * (n + 1) / 2 + pref[pos - 1] + suff[ans + 1] + 1ll * (val - pos) * (ans - pos + 1);
  }
  for(int i = 0; i < q; ++i) {
    cout << res[i] << endl;
  }
  return 0;
}